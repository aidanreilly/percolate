// returns the minimum value of a signal based on absolute values.
// by r. luke dubois, cmc/cu, 2001.

#include <math.h>
#include "ext.h"
#include "z_dsp.h"

void *sigabsmin_class;

typedef struct _sigabsmin
{
    t_pxobject x_obj;
    t_float x_val;
} t_sigabsmin;

void *sigabsmin_new(double val);
t_int *offset_perform(t_int *w);
t_int *sigabsmin2_perform(t_int *w);
void sigabsmin_float(t_sigabsmin *x, double f);
void sigabsmin_int(t_sigabsmin *x, long n);
void sigabsmin_dsp(t_sigabsmin *x, t_signal **sp, short *count);
void sigabsmin_assist(t_sigabsmin *x, void *b, long m, long a, char *s);

void ext_main(void* p)
{
    setup((t_messlist **)&sigabsmin_class, (method)sigabsmin_new, (method)dsp_free, (short)sizeof(t_sigabsmin), 0L, A_DEFFLOAT, 0);
    addmess((method)sigabsmin_dsp, "dsp", A_CANT, 0);
    addfloat((method)sigabsmin_float);
    addint((method)sigabsmin_int);
    addmess((method)sigabsmin_assist,"assist",A_CANT,0);
    dsp_initclass();
    
    post("absmin~: by r. luke dubois, cmc");
}

void sigabsmin_assist(t_sigabsmin *x, void *b, long m, long a, char *s)
{
	switch(m) {
		case 1: // inlet
			switch(a) {
				case 0:
				sprintf(s, "(Signal) Input 1");
				break;
				case 1:
				sprintf(s, "(Signal) Input 2");
				break;
			}
		break;
		case 2: // outlet
			switch(a) {
				case 0:
				sprintf(s, "(Signal) Output");
				break;
			}
		break;
	}
}

void *sigabsmin_new(double val)
{
    t_sigabsmin *x = (t_sigabsmin *)newobject(sigabsmin_class);
    dsp_setup((t_pxobject *)x,2);
    outlet_new((t_pxobject *)x, "signal");
    x->x_val = val;
    return (x);
}

// this routine covers both inlets. It doesn't matter which one is involved

void sigabsmin_float(t_sigabsmin *x, double f)
{
	x->x_val = f;
}

void sigabsmin_int(t_sigabsmin *x, long n)
{
	x->x_val = (float)n;
}

t_int *offset_perform(t_int *w)
{
    t_float *in = (t_float *)(w[1]);
    t_float *out = (t_float *)(w[2]);
	t_sigabsmin *x = (t_sigabsmin *)(w[3]);
	float val2 = fabs(x->x_val);
	float val1;
	int n = (int)(w[4]);
	
	if (x->x_obj.z_disabled)
		goto out;
	
	while (--n) {
		val1 = *++in;
    	if (fabs(val1)<=fabs(val2)) {
	    		*++out = val1;
    	}
		else {
    		*++out = val2;
    	}
	}
    
out:
    return (w+5);
}

t_int *sigabsmin2_perform(t_int *w)
{
	t_float *in1,*in2,*out;
	int n;
	float val1, val2;

	if (*(long *)(w[1]))
	    goto out;

	in1 = (t_float *)(w[2]);
	in2 = (t_float *)(w[3]);
	out = (t_float *)(w[4]);
	n = (int)(w[5]);
	while (--n) {
		val1 = *++in1;
		val2 = *++in2;
    	if (fabs(val1)<=fabs(val2)) {
	    		*++out = val1;
    	}
		else {
    		*++out = val2;
    	}
	}
out:
	return (w+6);
}		

void sigabsmin_dsp(t_sigabsmin *x, t_signal **sp, short *count)
{
	long i;
		
	if (!count[0])
		dsp_add(offset_perform, 4, sp[1]->s_vec-1, sp[2]->s_vec-1, x, sp[0]->s_n+1);
	else if (!count[1])
		dsp_add(offset_perform, 4, sp[0]->s_vec-1, sp[2]->s_vec-1, x, sp[0]->s_n+1);
	else
		dsp_add(sigabsmin2_perform, 5, &x->x_obj.z_disabled, sp[0]->s_vec-1, sp[1]->s_vec-1, sp[2]->s_vec-1, sp[0]->s_n+1);
}
