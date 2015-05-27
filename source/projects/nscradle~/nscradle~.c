//Newton's Cradle; a model of newton's cradle. choose number of balls, their sizes, masses
//strings lengths, etc...., set them colliding. sends out impulses for each collision out
//individual outputs for each pair of balls. 

#include "ext.h"
#include "z_dsp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUTS 10 //arbitrary
#define MAX_BALLS 10

void *nscradle_class;

typedef struct _nscradle
{
	//header
    t_pxobject x_obj;
    
    long num_balls;
    long current_ball; //which one are we manipulating; 0-->all
    double delta_t, put, push;
    double theta[MAX_BALLS], omega[MAX_BALLS];
    double L[MAX_BALLS], mass[MAX_BALLS], radius[MAX_BALLS+1], damping[MAX_BALLS];
    
    double srate, one_over_srate;
    long num_inputs, num_outputs;
    
} t_nscradle;

/****PROTOTYPES****/

//setup funcs
void *nscradle_new(long num_inputs, long num_outputs);
void nscradle_dsp(t_nscradle *x, t_signal **sp, short *count); 
t_int *nscradle_perform(t_int *w);
void nscradle_assist(t_nscradle *x, void *b, long m, long a, char *s);
void nscradle_which(t_nscradle *x, Symbol *s, short argc, Atom *argv);
void nscradle_put(t_nscradle *x, Symbol *s, short argc, Atom *argv);
void nscradle_push(t_nscradle *x, Symbol *s, short argc, Atom *argv);
void nscradle_L(t_nscradle *x, Symbol *s, short argc, Atom *argv);
void nscradle_mass(t_nscradle *x, Symbol *s, short argc, Atom *argv);
void nscradle_radius(t_nscradle *x, Symbol *s, short argc, Atom *argv);
void nscradle_damping(t_nscradle *x, Symbol *s, short argc, Atom *argv);
void nscradle_zero(t_nscradle *x, Symbol *s, short argc, Atom *argv);


/****FUNCTIONS****/

void nscradle_assist(t_nscradle *x, void *b, long m, long a, char *s)
{
	int i;
	//could use switch/case inside for loops, to give more informative assist info....
	if (m==1) {
		for(i=0;i<x->num_inputs;i++)
			if (a==i)  sprintf(s, "input %d", i);
	}
	if (m==2) {
		for(i=0;i<x->num_outputs;i++)
			if (a==i)  sprintf(s, "output %d", i);
	}
}


//primary MSP funcs
void main(void)
{
	//the two A_DEFLONG arguments give us the two arguments for the user to set number of ins/outs
	//change these if you want differen user args
    setup((struct messlist **)&nscradle_class, (method)nscradle_new, (method)dsp_free, (short)sizeof(t_nscradle), 0L, A_DEFLONG, A_DEFLONG, 0);
    addmess((method)nscradle_dsp, "dsp", A_CANT, 0);
    addmess((method)nscradle_assist,"assist",A_CANT,0);
    addmess((method)nscradle_which, "which", A_GIMME, 0);
    addmess((method)nscradle_put, "put", A_GIMME, 0);  //put a ball to a certain angle
    addmess((method)nscradle_push, "push", A_GIMME, 0); //push a ball
    addmess((method)nscradle_L, "length", A_GIMME, 0); //set the length
    addmess((method)nscradle_mass, "mass", A_GIMME, 0); //set the mass
    addmess((method)nscradle_radius, "radius", A_GIMME, 0); //set the radius
    addmess((method)nscradle_damping, "damping", A_GIMME, 0); //set the damping
    addmess((method)nscradle_zero, "zero", A_GIMME, 0); //set the damping
    dsp_initclass();
}


void *nscradle_new(long num_balls, long nothing)
{
	int i;

    t_nscradle *x = (t_nscradle *)newobject(nscradle_class);
    
    //zero out the struct, to be careful (takk to jkclayton)
    if (x) { 
        for(i=sizeof(t_pxobject);i<sizeof(t_nscradle);i++)  
                ((char *)x)[i]=0; 
	} 
	
	if (num_balls < 1) num_balls = 2;
	if (num_balls > MAX_BALLS) num_balls = 2;
	
	x->num_inputs = 1; //only need one input for messages
	x->num_balls = num_balls;
	x->num_outputs = num_balls - 1; //one less output than number of balls

	//setup up inputs and outputs, for audio
    dsp_setup((t_pxobject *)x, x->num_inputs);
    for (i=0;i<x->num_outputs;i++) {
    	outlet_new((t_object *)x, "signal");
    }
    
    for(i=0;i<x->num_balls;i++) {
    	x->theta[i] = x->omega[i] = 0.;
    	x->L[i] = 1.;
    	x->mass[i] = 1.;
    	x->radius[i] = 0.1;
    	x->damping[i] = 0.;
    }
    x->put = x->push = 0.;
    x->current_ball = -1;
    
    
    //can use intin, floatout, listout, etc... for setting up non-audio ins and outs.
    //but, the order in which you call these funcs is important.
    //check various other objects; gQ~, recordf~, etc... for examples.
    
    x->srate = 44100.; //set for now, if things need it when initializing
	x->one_over_srate = 1./x->srate;

    return (x);
}


void nscradle_dsp(t_nscradle *x, t_signal **sp, short *count)
{
	void *dsp_add_args[MAX_INPUTS + MAX_BALLS + 2];
	int i;

	x->srate = sp[0]->s_sr;
	x->one_over_srate = 1./x->srate;
	x->delta_t = 1./x->srate;
	
	dsp_add_args[0] = x;
    for(i=0;i< (x->num_inputs + x->num_outputs); i++) {
    	dsp_add_args[i+1] = sp[i]->s_vec;
    }
    dsp_add_args[x->num_inputs + x->num_outputs + 1] = (void *)sp[0]->s_n;
	dsp_addv(nscradle_perform, (x->num_inputs + x->num_outputs + 2), dsp_add_args);	
}

t_int *nscradle_perform(t_int *w)
{
	t_nscradle *x = (t_nscradle *)(w[1]);

	float *in[MAX_INPUTS];
	#define NC_LENGTH 0 //so in[NC_LENGTH] --> length input
	#define NC_MASS 1
	#define NC_RADIUS 2
	#define NC_DAMPING 3
	
	float *out[MAX_BALLS];

	long n = w[x->num_inputs + x->num_outputs + 2];
	int i, j;
	
	double half_theta, sin_halftheta, xdiff, ydiff; 
	double delta_t, x_pos[MAX_BALLS], y_pos[MAX_BALLS];
	double offset[MAX_BALLS], L[MAX_BALLS], mass[MAX_BALLS], radius[MAX_BALLS+1], damping[MAX_BALLS];
	double g, D[MAX_BALLS], T, M, omega_save;
	
	if (x->x_obj.z_disabled) goto out;
	
	
	g = -9.8; 				//acceleration of gravity, meters/sec^2
	delta_t = x->delta_t; 	//seconds per sample
	
	for (i=0;i<x->num_inputs;i++) {
		in[i] = (float *)(w[i+2]);
	}
	
	for (i=0;i<x->num_outputs;i++) {
		out[i] = (float *)(w[x->num_inputs+i+2]);
	}
	
	if(x->put != 0.) {
		if(x->current_ball == -1) {
			for(i=0;i<x->num_balls;i++) {
				x->theta[i] = x->put;
			}
		} else x->theta[x->current_ball] = x->put;
		x->put = 0.;
	}
	
	if(x->push != 0.) {
		if(x->current_ball == -1) {
			for(i=0;i<x->num_balls;i++) {
				x->omega[i] = x->push;
			}
		} else x->omega[x->current_ball] = x->push;
		x->push = 0.;
	}
	
	offset[0] = 0.; //zero x_pos offset for first ball
	
	for(i=0;i<x->num_balls;i++) {
		L[i] 					= x->L[i];
		mass[i] 				= x->mass[i];
		radius[i] 				= x->radius[i];
		damping[i] 				= x->damping[i];
	}
	radius[i+1] = 0.; //placeholder for collisions....
	
	while(n--) {
		
		for(i=0;i<x->num_balls;i++) {
		
			//calculate angular position and velocity
			x->theta[i] = delta_t * x->omega[i] + x->theta[i];
			x->omega[i] = delta_t * (g/L[i]) * (double)sin(x->theta[i]*TWOPI) + x->omega[i]*(1. - damping[i]);
			
			//calculate x/y cartesian coordinates, with offset determined by radii of balls
			half_theta = 0.5*x->theta[i];
			sin_halftheta = sin(half_theta*TWOPI);
			x_pos[i] = 2.*L[i] * sin_halftheta*cos(half_theta*TWOPI);
			y_pos[i] = 2.*L[i] * sin_halftheta*sin_halftheta;
			
			//offset so balls are just touching at rest 			
			if(i>0) {
				offset[i] = offset[i-1] + radius[i] + radius[i-1];
				x_pos[i] += offset[i];
			} 
		}
		
		//calculate distance between balls, exchange momenta if they collide and send out an impulse
		//if one or more balls get sandwiched (collisions on both sides simultaneously), then the "bread"
		//(outside balls) exchange momenta and the "cheese" is left unchanged
		for(i=0;i<x->num_outputs;i++) {
			xdiff = x_pos[i+1] - x_pos[i];
			ydiff = y_pos[i+1] - y_pos[i];
			D[i] = sqrt(xdiff*xdiff + ydiff*ydiff);
		}
		D[i+1] = 100000.; //absurd large number; place holder for last one
		
		i=0;
		while(i<x->num_outputs) {
			if (D[i]<(radius[i]+radius[i+1])) {
				j=i+1;
				while (D[j]<(radius[j]+radius[j+1]) && j<x->num_outputs) {
					j++;
				}
				
				//exchange i and j's momenta
				T = (mass[j]*L[j]*cos(x->theta[j]*TWOPI)) / (mass[i]*L[i]*cos(x->theta[i]*TWOPI));
				M = x->omega[i+1]*cos(x->theta[i+1]*TWOPI) - x->omega[i]*cos(x->theta[i]*TWOPI);
				omega_save = x->omega[i];
				x->omega[i] = x->omega[j] * T;
				x->omega[j] = omega_save / T;
				*out[i] = M; 
				if(j > i+1) { //have both click if they are not adjacent
					M = x->omega[j]*cos(x->theta[j]*TWOPI) - x->omega[j-1]*cos(x->theta[j-1]*TWOPI);	
					*out[j-1] = M;
				}				
				i=j; //skip to the next ball
			} else {
				*out[i++] = 0.;
			}
		}
		
		for(i=0;i<x->num_outputs;i++) *out[i]++;
	}
	
out:
	return w + x->num_inputs + x->num_outputs + 3;
}	


void nscradle_which(t_nscradle *x, Symbol *s, short argc, Atom *argv)
{
	short i;
	int temp;
	for (i=0; i < argc; i++) {
		switch (argv[i].a_type) {
			case A_LONG:
				temp = argv[i].a_w.w_long;
				if(temp < 0) temp = 0;
				if(temp > x->num_balls) temp = 0;
				x->current_ball = temp - 1;
    			post("nscradle: setting current ball to: %d ", x->current_ball + 1);
				break;
			case A_FLOAT:
				temp = (int)argv[i].a_w.w_float;
				if(temp < 0) temp = 0;
				if(temp > x->num_balls) temp = 0;
				x->current_ball = temp - 1;
    			post("nscradle: setting current ball to: %d ", x->current_ball + 1);
				break;
		}
	}
}

/*
void nscradle_put(t_nscradle *x, Symbol *s, short argc, Atom *argv)
{
	short i;
	double temp;
	for (i=0; i < argc; i++) {
		switch (argv[i].a_type) {
			case A_LONG:
				temp = (double)argv[i].a_w.w_long;
				x->put = temp;
    			post("nscradle: putting current ball to: %f ", x->put);
				break;
			case A_FLOAT:
				temp = (double)argv[i].a_w.w_float;
				x->put = temp;
    			post("nscradle: putting current ball to: %f ", x->put);
				break;
		}
	}
}

void nscradle_push(t_nscradle *x, Symbol *s, short argc, Atom *argv)
{
	short i;
	double temp;
	for (i=0; i < argc; i++) {
		switch (argv[i].a_type) {
			case A_LONG:
				temp = (double)argv[i].a_w.w_long;
				x->push = temp;
    			post("nscradle: pushing current ball with: %f", x->push);
				break;
			case A_FLOAT:
				temp = (double)argv[i].a_w.w_float;
				x->push = temp;
    			post("nscradle: pushing current ball with: %f ", x->push);
				break;
		}
	}
}
*/

void nscradle_put(t_nscradle *x, Symbol *s, short argc, Atom *argv)
{
	int i;
	
	if(argc < 2) {
		post("nscradle: need 2 args -- ballNum Length");
		return;
	}
	
	switch (argv[0].a_type) {
		case A_LONG:
			i = (int)argv[0].a_w.w_long - 1; 
			break;
		case A_FLOAT:
			i = (int)argv[0].a_w.w_float - 1;
			break;
	}
	
	if(i >= x->num_balls) {
		post("nscradle: too many balls, isaac");
	} else if(i==-1) { //set them all
		switch (argv[1].a_type) {
			case A_LONG:
				for (i=0;i<x->num_balls;i++) {
					x->theta[i] = (double)argv[1].a_w.w_long; 
					//post("setting length %d to %f", i, (float)x->L[i]);
				}
				break;
			case A_FLOAT:
				for (i=0;i<x->num_balls;i++) {
					x->theta[i] = (double)argv[1].a_w.w_float;
					//post("setting length %d to %f", i, (float)x->L[i]);
				}
				break;
		}
	} else { //set individual ones	
		switch (argv[1].a_type) {
			case A_LONG:
				x->theta[i] = (double)argv[1].a_w.w_long; 
				break;
			case A_FLOAT:
				x->theta[i] = (double)argv[1].a_w.w_float;
				break;
		}
	}
}

void nscradle_push(t_nscradle *x, Symbol *s, short argc, Atom *argv)
{
	int i;
	
	if(argc < 2) {
		post("nscradle: need 2 args -- ballNum Length");
		return;
	}
	
	switch (argv[0].a_type) {
		case A_LONG:
			i = (int)argv[0].a_w.w_long - 1; 
			break;
		case A_FLOAT:
			i = (int)argv[0].a_w.w_float - 1;
			break;
	}
	
	if(i >= x->num_balls) {
		post("nscradle: too many balls, isaac");
	} else if(i==-1) { //set them all
		switch (argv[1].a_type) {
			case A_LONG:
				for (i=0;i<x->num_balls;i++) {
					x->omega[i] = (double)argv[1].a_w.w_long; 
					//post("setting length %d to %f", i, (float)x->L[i]);
				}
				break;
			case A_FLOAT:
				for (i=0;i<x->num_balls;i++) {
					x->omega[i] = (double)argv[1].a_w.w_float;
					//post("setting length %d to %f", i, (float)x->L[i]);
				}
				break;
		}
	} else { //set individual ones	
		switch (argv[1].a_type) {
			case A_LONG:
				x->omega[i] = (double)argv[1].a_w.w_long; 
				break;
			case A_FLOAT:
				x->omega[i] = (double)argv[1].a_w.w_float;
				break;
		}
	}
}

void nscradle_L(t_nscradle *x, Symbol *s, short argc, Atom *argv)
{
	int i;
	
	if(argc < 2) {
		post("nscradle: need 2 args -- ballNum Length");
		return;
	}
	
	switch (argv[0].a_type) {
		case A_LONG:
			i = (int)argv[0].a_w.w_long - 1; 
			break;
		case A_FLOAT:
			i = (int)argv[0].a_w.w_float - 1;
			break;
	}
	
	if(i >= x->num_balls) {
		post("nscradle: too many balls, isaac");
	} else if(i==-1) { //set them all
		switch (argv[1].a_type) {
			case A_LONG:
				for (i=0;i<x->num_balls;i++) {
					x->L[i] = (double)argv[1].a_w.w_long; 
					//post("setting length %d to %f", i, (float)x->L[i]);
				}
				break;
			case A_FLOAT:
				for (i=0;i<x->num_balls;i++) {
					x->L[i] = (double)argv[1].a_w.w_float;
					//post("setting length %d to %f", i, (float)x->L[i]);
				}
				break;
		}
	} else { //set individual ones	
		switch (argv[1].a_type) {
			case A_LONG:
				x->L[i] = (double)argv[1].a_w.w_long; 
				break;
			case A_FLOAT:
				x->L[i] = (double)argv[1].a_w.w_float;
				break;
		}
	}
}

void nscradle_mass(t_nscradle *x, Symbol *s, short argc, Atom *argv)
{
	int i;
	
	if(argc < 2) {
		post("nscradle: need 2 args -- ballNum mass");
		return;
	}
	
	switch (argv[0].a_type) {
		case A_LONG:
			i = (int)argv[0].a_w.w_long - 1; 
			break;
		case A_FLOAT:
			i = (int)argv[0].a_w.w_float - 1;
			break;
	}
	
	if(i>x->num_balls) {
		post("nscradle: too many balls, isaac");
	} else if(i==-1) { //set them all
		switch (argv[1].a_type) {
			case A_LONG:
				for (i=0;i<x->num_balls;i++) 
					x->mass[i] = (double)argv[1].a_w.w_long; 
				break;
			case A_FLOAT:
				for (i=0;i<x->num_balls;i++) 
					x->mass[i] = (double)argv[1].a_w.w_float;
				break;
		}
	} else { //set individual ones	
		switch (argv[1].a_type) {
			case A_LONG:
				x->mass[i] = (double)argv[1].a_w.w_long; 
				break;
			case A_FLOAT:
				x->mass[i] = (double)argv[1].a_w.w_float;
				break;
		}
	}
}

void nscradle_radius(t_nscradle *x, Symbol *s, short argc, Atom *argv)
{
	int i;
	
	if(argc < 2) {
		post("nscradle: need 2 args -- ballNum radius");
		return;
	}
	
	switch (argv[0].a_type) {
		case A_LONG:
			i = (int)argv[0].a_w.w_long - 1; 
			break;
		case A_FLOAT:
			i = (int)argv[0].a_w.w_float - 1;
			break;
	}
	
	if(i>x->num_balls) {
		post("nscradle: too many balls, isaac");
	} else if(i==-1) { //set them all
		switch (argv[1].a_type) {
			case A_LONG:
				for (i=0;i<x->num_balls;i++) 
					x->radius[i] = (double)argv[1].a_w.w_long; 
				break;
			case A_FLOAT:
				for (i=0;i<x->num_balls;i++) 
					x->radius[i] = (double)argv[1].a_w.w_float;
				break;
		}
	} else { //set individual ones	
		switch (argv[1].a_type) {
			case A_LONG:
				x->radius[i] = (double)argv[1].a_w.w_long; 
				break;
			case A_FLOAT:
				x->radius[i] = (double)argv[1].a_w.w_float;
				break;
		}
	}
}

void nscradle_damping(t_nscradle *x, Symbol *s, short argc, Atom *argv)
{
	int i;
	
	if(argc < 2) {
		post("nscradle: need 2 args -- ballNum damping");
		return;
	}
	
	switch (argv[0].a_type) {
		case A_LONG:
			i = (int)argv[0].a_w.w_long - 1; 
			break;
		case A_FLOAT:
			i = (int)argv[0].a_w.w_float - 1;
			break;
	}
	
	if(i>x->num_balls) {
		post("nscradle: too many balls, isaac");
	} else if(i==-1) { //set them all
		switch (argv[1].a_type) {
			case A_LONG:
				for (i=0;i<x->num_balls;i++) 
					x->damping[i] = (double)argv[1].a_w.w_long; 
				break;
			case A_FLOAT:
				for (i=0;i<x->num_balls;i++) 
					x->damping[i] = (double)argv[1].a_w.w_float;
				break;
		}
	} else { //set individual ones	
		switch (argv[1].a_type) {
			case A_LONG:
				x->damping[i] = (double)argv[1].a_w.w_long; 
				break;
			case A_FLOAT:
				x->damping[i] = (double)argv[1].a_w.w_float;
				break;
		}
	}
}

void nscradle_zero(t_nscradle *x, Symbol *s, short argc, Atom *argv)
{
	int i;
	
	for (i=0;i<x->num_balls;i++) {
		x->theta[i] = 0.;
		x->omega[i] = 0.;
	}

}
