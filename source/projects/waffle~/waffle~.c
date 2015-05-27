// waffle~ -- interpolates between two or more wavetable 'frames' stored in a buffer.

#include "ext.h"
#include "z_dsp.h"

#define MAXFRAMES 32

void *waffle_class;

typedef struct _waffle
{
    t_pxobject l_obj;
} t_waffle;

float FConstrain(float v, float lo, float hi);
long IConstrain(long v, long lo, long hi);
t_int *waffle_perform(t_int *w);
void waffle_dsp(t_waffle *x, t_signal **sp);
void *waffle_new(void);
void waffle_assist(t_waffle *x, void *b, long m, long a, char *s);

t_symbol *ps_buffer;

void ext_main(void* p)
{
	setup((t_messlist **)&waffle_class, (method)waffle_new, (method)dsp_free, (short)sizeof(t_waffle), 0L, 0);
	addmess((method)waffle_dsp, "dsp", A_CANT, 0);
	addmess((method)waffle_assist, "assist", A_CANT, 0);
	dsp_initclass();
	post("waffle waffle waffle...");
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

t_int *waffle_perform(t_int *w)
{
    t_waffle *x = (t_waffle *)(w[1]);
    t_float *in = (t_float *)(w[2]);
    t_float *cross = (t_float *)(w[3]);
    t_float *sync = (t_float *)(w[4]);
    t_float *out1 = (t_float *)(w[5]);
    t_float *out2 = (t_float *)(w[6]);
    int n = (int)(w[7]);
	if (x->l_obj.z_disabled)
	goto out;

	while (--n) {
		if(*++sync<*++cross) {
		*++out1 = *++in;
		*++out2 = 0.;
		}
		else {
		*++out1 = 0;
		*++out2 = *++in;
		}
	}
	return (w+8);

out:
	return (w+8);
}


void waffle_dsp(t_waffle *x, t_signal **sp)
{
    dsp_add(waffle_perform, 7, x, sp[0]->s_vec-1, sp[1]->s_vec-1, sp[2]->s_vec-1, sp[3]->s_vec-1, sp[4]->s_vec-1, sp[0]->s_n+1);
}


void waffle_assist(t_waffle *x, void *b, long m, long a, char *s)
{
	switch(m) {
		case 1: // inlet
			switch(a) {
				case 0:
				sprintf(s, "(signal) Input");
				break;
				case 1:
				sprintf(s, "(signal) Crossover");
				break;
				case 2:
				sprintf(s, "(signal) Sync");
				break;
			}
		break;
		case 2: // outlet
			switch(a) {
				case 0:
				sprintf(s, "(signal) Low Output");
				break;
				case 1:
				sprintf(s, "(signal) High Output");
				break;
			}
		break;
	}

}

void *waffle_new(void)
{
	t_waffle *x = (t_waffle *)newobject(waffle_class);
	dsp_setup((t_pxobject *)x, 3);
	outlet_new((t_object *)x, "signal");
	outlet_new((t_object *)x, "signal");
	return (x);
}
