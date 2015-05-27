//expands or contracts a signal vector. good for transposing fft bins
//another PeRColate hack: dan trueman, 2002

#include "stk_c.h"
//#define TWOPI 6.283185307
#define RSRC_ID 12105
#define INT_LINEAR 0
#define INT_POLY 1
#define INT_SPLINE 2

typedef struct _vectorstretch
{
	//header
    t_pxobject x_obj;    
	
	float stretch;	//stretch factor for bins
	short interp_method; //0=linear (default), 1=polynomial, 2=spline (eventually)
	short polylen;
    
} t_vectorstretch;


//setup funcs
void *vectorstretch_new(double val);
void vectorstretch_dsp(t_vectorstretch *x, t_signal **sp, short *count); 
t_int *vectorstretch_perform(t_int *w);
void vectorstretch_assist(t_vectorstretch *x, void *b, long m, long a, char *s);
void vectorstretch_setstretch(t_vectorstretch *x, Symbol *s, short argc, Atom *argv);
void vectorstretch_setlinear(t_vectorstretch *x, Symbol *s, short argc, Atom *argv);
void vectorstretch_setpoly(t_vectorstretch *x, Symbol *s, short argc, Atom *argv);
void vectorstretch_setpoly2(t_vectorstretch *x, Symbol *s, short argc, Atom *argv);


//t_symbol *ps_spvector;
void *vectorstretch_class;


//primary MSP funcs
void ext_main(void* p)
{
    setup((struct messlist **)&vectorstretch_class, (method)vectorstretch_new, (method)dsp_free, (short)sizeof(t_vectorstretch), 0L, A_GIMME, 0);
    addmess((method)vectorstretch_dsp, "dsp", A_CANT, 0);
    addmess((method)vectorstretch_assist,"assist",A_CANT,0);
    addmess((method)vectorstretch_setstretch, "stretch", A_GIMME, 0);
    addmess((method)vectorstretch_setlinear, "linear", A_GIMME, 0);
    addmess((method)vectorstretch_setpoly, "poly", A_GIMME, 0);
    addmess((method)vectorstretch_setpoly, "poly2", A_GIMME, 0);
    dsp_initclass();
 
    rescopy('STR#',RSRC_ID);
}

void vectorstretch_assist(t_vectorstretch *x, void *b, long m, long a, char *s)
{
	assist_string(RSRC_ID,m,a,1,2,s);
}

void *vectorstretch_new(double initial_coeff)
{
	int i;

    t_vectorstretch *x = (t_vectorstretch *)newobject(vectorstretch_class);
    //zero out the struct, to be careful (takk to jkclayton)
    if (x) { 
        for(i=sizeof(t_pxobject);i<sizeof(t_vectorstretch);i++)  
                ((char *)x)[i]=0; 
	} 
	
    dsp_setup((t_pxobject *)x, 1);
	x->x_obj.z_misc = Z_NO_INPLACE;	
	outlet_new((t_object *)x, "signal");


	x->stretch = 1.;
	x->interp_method = 0;
	x->polylen = 3;
    
    return (x);
}


void vectorstretch_dsp(t_vectorstretch *x, t_signal **sp, short *count)
{
		dsp_add(vectorstretch_perform, 4, x, sp[0]->s_vec, sp[1]->s_vec, sp[0]->s_n);	
}

t_int *vectorstretch_perform(t_int *w)
{
	t_vectorstretch *x = (t_vectorstretch *)(w[1]);

	long i;

	float *in = (float *)(w[2]);
	float *out = (float *)(w[3]);
	long n = w[4];
	
	double temp, temp2;
	long stretchStart, stretchEnd;
	double stretchOffset;
	
	if (x->x_obj.z_disabled)
		goto out;
	
	if (x->interp_method == INT_LINEAR) {	
		for(i=0;i<n;i++) {
			temp = (double)i*(double)x->stretch; 			//float index for startpoint
			stretchStart = (long)temp;						//integer value of index
			stretchOffset = temp - (double)stretchStart;	//interpolation factor 
			stretchEnd = stretchStart + 1;					//interpolation endpoint index
			
			//could add an if(stretchOffset == 0.) *out++ = in[stretchStart];
			//              else.... interpolation stuff.
			if (stretchStart >= n) temp = 0.;				//requests for frames above max are set to 0.
				else temp = in[stretchStart];
			
			if (stretchEnd >= n) temp2 = 0.;
				else temp2 = in[stretchEnd];

			*out++ = temp + stretchOffset * (temp2 - temp);
		}
	}
	
	else if(x->interp_method == INT_POLY) {
		for(i=0;i<n;i++) {
			temp = (double)i*(double)x->stretch; 					//what's the index we want
			*out++ = polyinterpolate(in, x->polylen, n, temp);		//2nd order poly interpolate
		}	
	}

out:
	return w + 5;
}	

void vectorstretch_setstretch(t_vectorstretch *x, Symbol *s, short argc, Atom *argv)
{
	short i;
	float temp;
	for (i=0; i < argc; i++) {
		switch (argv[i].a_type) {
			case A_LONG:
				temp = (float)argv[i].a_w.w_long;
				if (temp < 0.) temp = 0.;
    			//post("vectorstretch: setting stretch to: %f ", temp);
    			x->stretch = temp;
				break;
			case A_FLOAT:
				temp = argv[i].a_w.w_float;
				if (temp < 0.) temp = 0.;
				//post("vectorstretch: setting stretch to: %f ", temp);
				x->stretch = temp;
				break;
		}
	}
}

void vectorstretch_setlinear(t_vectorstretch *x, Symbol *s, short argc, Atom *argv)
{
	x->interp_method = INT_LINEAR;
}

void vectorstretch_setpoly(t_vectorstretch *x, Symbol *s, short argc, Atom *argv)
{
	x->interp_method = INT_POLY;
	x->polylen = 3;
}

void vectorstretch_setpoly2(t_vectorstretch *x, Symbol *s, short argc, Atom *argv)
{
	x->interp_method = INT_POLY;
	x->polylen = 4;
}