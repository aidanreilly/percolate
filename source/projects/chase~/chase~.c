// chase~ -- uses a sync signal to determine who gets out which outlet.

#include "ext.h"
#include "z_dsp.h"
#include <math.h>

#define MAXFRAMES 32

void *chase_class;

typedef struct _chase
{
    t_pxobject l_obj;
} t_chase;

float FConstrain(float v, float lo, float hi);
long IConstrain(long v, long lo, long hi);
t_int *chase_perform(t_int *w);
void chase_dsp(t_chase *x, t_signal **sp);
void *chase_new(void);
void chase_assist(t_chase *x, void *b, long m, long a, char *s);

t_symbol *ps_buffer;

void ext_main(void* p)
{
	setup((t_messlist **)&chase_class, (method)chase_new, (method)dsp_free, (short)sizeof(t_chase), 0L, 0);
	addmess((method)chase_dsp, "dsp", A_CANT, 0);
	addmess((method)chase_assist, "assist", A_CANT, 0);
	dsp_initclass();
	post("chase chase chase...");
}

long IConstrain(long v, long lo, long hi)
{
	if (v < lo)
		return lo;
	else if (v > hi)
		return hi;
	else
		return v;
}

float FConstrain(float v, float lo, float hi)
{
	if (v < lo)
		return lo;
	else if (v > hi)
		return hi;
	else
		return v;
}

t_int *chase_perform(t_int *w)
{
    t_chase *x = (t_chase *)(w[1]);
    t_float *in1 = (t_float *)(w[2]);
    t_float *in2 = (t_float *)(w[3]);
    t_float *sync = (t_float *)(w[4]);
    t_float *out1 = (t_float *)(w[5]);
    t_float *out2 = (t_float *)(w[6]);
    int n = (int)(w[7]);
    float dist1, dist2;
	if (x->l_obj.z_disabled)
	goto out;

	while (--n) {
		if(*++sync>*++in1) {
		dist1 = fabs(*sync-*in1);
		}
		else {
		dist1 = fabs(*in1-*sync);
		}
		if(*sync>*++in2) {
		dist2 = fabs(*sync-*in1);
		}
		else {
		dist2 = fabs(*in2 - *sync);
		}
		if(dist1>dist2) {
		*++out1 = dist1;
		*++out2 = dist2;
		}
		else {
		*++out1 = dist2;
		*++out2 = dist1;
		}
	}
	return (w+8);

out:
	return (w+8);
}


void chase_dsp(t_chase *x, t_signal **sp)
{
    dsp_add(chase_perform, 7, x, sp[0]->s_vec-1, sp[1]->s_vec-1, sp[2]->s_vec-1, sp[3]->s_vec-1, sp[4]->s_vec-1, sp[0]->s_n+1);
}


void chase_assist(t_chase *x, void *b, long m, long a, char *s)
{
	switch(m) {
		case 1: // inlet
			switch(a) {
				case 0:
				sprintf(s, "(signal) Input 1");
				break;
				case 1:
				sprintf(s, "(signal) Input 2");
				break;
				case 2:
				sprintf(s, "(signal) Sync");
				break;
			}
		break;
		case 2: // outlet
			switch(a) {
				case 0:
				sprintf(s, "(signal) Near Output");
				break;
				case 1:
				sprintf(s, "(signal) Far Output");
				break;
			}
		break;
	}

}

void *chase_new(void)
{
	t_chase *x = (t_chase *)newobject(chase_class);
	dsp_setup((t_pxobject *)x, 3);
	outlet_new((t_object *)x, "signal");
	outlet_new((t_object *)x, "signal");
	return (x);
}
