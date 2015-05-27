//Shakers; all them shakers
//second port of an STK instrument using the original C++ classes
//(as opposed to downporting to C, blah.....)
//
//dt 2005; yet another PeRColate hack
//

//here are the notes from the original STK instrument

#define __cplusplus

extern "C" {
#include "ext.h"
#include "z_dsp.h"
#include "ext_strings.h"
}

#include <math.h>
//#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Shakers.h"

#define MAX_INPUTS 10 	//arbitrary
#define MAX_OUTPUTS 10	//also arbitrary

void *shakers_class;

typedef struct _shakers
{
	//header
    t_pxobject x_obj;
    
    //variables specific to this object
    float srate, one_over_srate;  	//sample rate vars
    long num_inputs, num_outputs; 	//number of inputs and outputs
    float in[MAX_INPUTS];			//values of input variables
    float in_connected[MAX_INPUTS]; //booleans: true if signals connected to the input in question
    //we use this "connected" boolean so that users can connect *either* signals or floats
    //to the various inputs; sometimes it's easier just to have floats, but other times
    //it's essential to have signals.... but we have to know. 
    
    Shakers *myshakers;
    
    short power;					//i like objects, especially CPU intensive ones, to have their own
    								//"power" messages so that you can bypass them individually

    
} t_shakers;


/****PROTOTYPES****/

//setup funcs; this probably won't change, unless you decide to change the number of
//args that the user can input, in which case shakers_new will have to change
void *shakers_new(long num_inputs, long num_outputs);
void shakers_free(t_shakers *x);
void shakers_dsp(t_shakers *x, t_signal **sp, short *count); 
t_int *shakers_perform(t_int *w);
void shakers_assist(t_shakers *x, void *b, long m, long a, char *s);

//for getting floats at inputs
void shakers_float(t_shakers *x, double f);

//for custom messages
void shakers_setpower(t_shakers *x, Symbol *s, short argc, Atom *argv);
void shakers_settype(t_shakers *x, Symbol *s, short argc, Atom *argv);
void shakers_setenergy(t_shakers *x, Symbol *s, short argc, Atom *argv);
void shakers_setdecay(t_shakers *x, Symbol *s, short argc, Atom *argv);
void shakers_setnumobjects(t_shakers *x, Symbol *s, short argc, Atom *argv);
void shakers_setresfreq(t_shakers *x, Symbol *s, short argc, Atom *argv);
void shakers_noteOn(t_shakers *x, Symbol *s, short argc, Atom *argv);

/****FUNCTIONS****/

//primary MSP funcs
void ext_main(void* p)
{
	//the two A_DEFLONG arguments give us the two arguments for the user to set number of ins/outs
	//change these if you want different user args
    setup((struct messlist **)&shakers_class, (method)shakers_new, (method)shakers_free, (short)sizeof(t_shakers), 0L, A_DEFLONG, A_DEFLONG, 0);
   
	//standard messages; don't change these  
    addmess((method)shakers_dsp, "dsp", A_CANT, 0);
    addmess((method)shakers_assist,"assist", A_CANT,0);
    
    //our own messages
    addmess((method)shakers_setpower, "power", A_GIMME, 0);
    addmess((method)shakers_settype, "type", A_GIMME, 0);
    addmess((method)shakers_setenergy, "energy", A_GIMME, 0);
    addmess((method)shakers_setdecay, "decay", A_GIMME, 0);
    addmess((method)shakers_setnumobjects, "numobjects", A_GIMME, 0);
    addmess((method)shakers_setresfreq, "resfreq", A_GIMME, 0);
    addmess((method)shakers_noteOn, "noteon", A_GIMME, 0);
    
    //so we know what to do with floats that we receive at the inputs
    addfloat((method)shakers_float);
    
    //gotta have this one....
    dsp_initclass();
}

//this gets called when the object is created; everytime the user types in new args, this will get called
void *shakers_new(long xD, long yD)
{
	int i;
	
	//leave this; creates our object
    t_shakers *x = (t_shakers *)newobject(shakers_class);
    
    //zero out the struct, to be careful (takk to jkclayton)
    if (x) { 
        for(i=sizeof(t_pxobject);i<sizeof(t_shakers);i++)  
                ((char *)x)[i]=0; 
	} 

	x->num_inputs = 1;
	x->num_outputs = 1;

	//setup up inputs and outputs, for audio
	
	//inputs
    dsp_setup((t_pxobject *)x, x->num_inputs);
    //if you just need one input for message (not using audio), you can just set num_inputs = 1
    //i don't think this causes a performance hit.
    
    //outputs
    for (i=0;i<x->num_outputs;i++) {
    	outlet_new((t_object *)x, "signal");
    }   
    //can use intin, floatout, listout, etc... for setting up non-audio ins and outs.
    //but, the order in which you call these funcs is important.
    //for instance, from gQ~
    /*    
    x->outfloat = floatout((t_object *)x);
    x->outlist = listout((t_object *)x);
    outlet_new((t_object *)x, "signal");
    outlet_new((t_object *)x, "signal");
   */
   //this will create four outputs, *rightmost* created first, so the outlets, from left to right, will look like
   //(signal) (signal) (list) (float)
   //when you instantiate gQ~ in Max/MSP.
    
    //initialize some variables; important to do this!
    for (i=0;i<x->num_inputs;i++){
    	x->in[i] = 0.;
    	x->in_connected[i] = 0;
    }
    x->power = 1;

	//occasionally this line is necessary if you are doing weird asynchronous things with the in/out vectors
	//x->x_obj.z_misc = Z_NO_INPLACE;
	
	x->myshakers = new Shakers();
	x->myshakers->setupName("Maraca");

    return (x);
}


//this gets called when an object is destroyed. do stuff here if you need to clean up.
void shakers_free(t_shakers *x)
{
	//gotta call this one, *before* you free other resources! thanks to Rob Sussman for pointing this out to me.
	dsp_free((t_pxobject *)x);
	delete x->myshakers;
}


//this gets called everytime audio is started; even when audio is running, if the user
//changes anything (like deletes a patch cord), audio will be turned off and
//then on again, calling this func.
//this adds the "perform" method to the DSP chain, and also tells us
//where the audio vectors are and how big they are
void shakers_dsp(t_shakers *x, t_signal **sp, short *count)
{
	void *dsp_add_args[MAX_INPUTS + MAX_OUTPUTS + 2];
	int i;

	//set sample rate vars
	x->srate = sp[0]->s_sr;
	x->one_over_srate = 1./x->srate;
	
	Stk::setSampleRate(x->srate);
	
	//check to see if there are signals connected to the various inputs
	for(i=0;i<x->num_inputs;i++) x->in_connected[i]	= count[i];
	
	//construct the array of vectors and stuff
	dsp_add_args[0] = x; //the object itself
    for(i=0;i< (x->num_inputs + x->num_outputs); i++) { //pointers to the input and output vectors
    	dsp_add_args[i+1] = sp[i]->s_vec;
    }
    dsp_add_args[x->num_inputs + x->num_outputs + 1] = (void *)sp[0]->s_n; //pointer to the vector size
	dsp_addv(shakers_perform, (x->num_inputs + x->num_outputs + 2), dsp_add_args); //add them to the signal chain
	
}

//this is where the action is
//we get vectors of samples (n samples per vector), process them and send them out
t_int *shakers_perform(t_int *w)
{
	t_shakers *x = (t_shakers *)(w[1]);

	float *in[MAX_INPUTS]; 		//pointers to the input vectors
	float *out[MAX_OUTPUTS];	//pointers to the output vectors

	long n = w[x->num_inputs + x->num_outputs + 2];	//number of samples per vector
	
	//random local vars
	int i;
	float temp;
	
	//check to see if we should skip this routine if the patcher is "muted"
	//i also setup of "power" messages for expensive objects, so that the
	//object itself can be turned off directly. this can be convenient sometimes.
	//in any case, all audio objects should have this
	if (x->x_obj.z_disabled || (x->power == 0)) goto out;
	
	//check to see if we have a signal or float message connected to input
	//then assign the pointer accordingly
	for (i=0;i<x->num_inputs;i++) {
		in[i] = x->in_connected[i] ? (float *)(w[i+2]) : &x->in[i];
	}
	
	//assign the output vectors
	for (i=0;i<x->num_outputs;i++) {
		out[i] = (float *)(w[x->num_inputs+i+2]);
	}
	
	while(n--) {
	
		*out[0]++ = x->myshakers->tick();

	}
	
	//return a pointer to the next object in the signal chain.
out:
	return w + x->num_inputs + x->num_outputs + 3;
}	


//tells the user about the inputs/outputs when mousing over them
void shakers_assist(t_shakers *x, void *b, long m, long a, char *s)
{
	int i, j;
	//could use switch/case inside for loops, to give more informative assist info....
	if (m==1) {
		for(i=0;i<x->num_inputs;i++) 
			if (a==i) sprintf(s, "control messages");
	}
	if (m==2) {
		for(i=0;i<x->num_outputs;i++)
			if (a==i) sprintf(s, "output (signal)");
	}
}


//this gets called when ever a float is received at *any* input
void shakers_float(t_shakers *x, double f)
{
	int i;
	
	//check to see which input the float came in, then set the appropriate variable value
	for(i=0;i<x->num_inputs;i++) {
		if (x->x_obj.z_in == i) {
			x->in[i] = f;
			post("template~: setting in[%d] =  %f", i, f);
		} 
	}
}


//what to do when we get the message "mymessage" and a value (or list of values)
void shakers_settype(t_shakers *x, Symbol *s, short argc, Atom *argv)
{
	if (argc<1) {
		post("skakers: need to specify instrument name\n");
		return;
	}
	post("shakers: setting to %s\n", argv[0].a_w.w_sym->s_name);
	x->myshakers->setupName(argv[0].a_w.w_sym->s_name);
}

void shakers_setenergy(t_shakers *x, Symbol *s, short argc, Atom *argv)
{
	short i;
	long temp; 
	for (i=0; i < argc; i++) {
		switch (argv[i].a_type) {
			case A_LONG:
				temp = argv[i].a_w.w_long;
				//probably should comment these out when the object is debugged.
    			//post("template~: power = %d", x->power);
				break;
			case A_FLOAT:
				temp = (long)argv[i].a_w.w_float;
    			//post("template~: received argument %d of mymessage with value %f", i+1, temp);
				break;
		}
	}
	
	x->myshakers->controlChange(2, temp);
}

void shakers_setdecay(t_shakers *x, Symbol *s, short argc, Atom *argv)
{
	short i;
	long temp; 
	for (i=0; i < argc; i++) {
		switch (argv[i].a_type) {
			case A_LONG:
				temp = argv[i].a_w.w_long;
				//probably should comment these out when the object is debugged.
    			//post("template~: power = %d", x->power);
				break;
			case A_FLOAT:
				temp = (long)argv[i].a_w.w_float;
    			//post("template~: received argument %d of mymessage with value %f", i+1, temp);
				break;
		}
	}
	
	x->myshakers->controlChange(11, temp);
}

void shakers_setnumobjects(t_shakers *x, Symbol *s, short argc, Atom *argv)
{
	short i;
	long temp; 
	for (i=0; i < argc; i++) {
		switch (argv[i].a_type) {
			case A_LONG:
				temp = argv[i].a_w.w_long;
				//probably should comment these out when the object is debugged.
    			//post("template~: power = %d", x->power);
				break;
			case A_FLOAT:
				temp = (long)argv[i].a_w.w_float;
    			//post("template~: received argument %d of mymessage with value %f", i+1, temp);
				break;
		}
	}
	
	x->myshakers->controlChange(4, temp);
}

void shakers_setresfreq(t_shakers *x, Symbol *s, short argc, Atom *argv)
{
	short i;
	long temp; 
	for (i=0; i < argc; i++) {
		switch (argv[i].a_type) {
			case A_LONG:
				temp = argv[i].a_w.w_long;
				//probably should comment these out when the object is debugged.
    			//post("template~: power = %d", x->power);
				break;
			case A_FLOAT:
				temp = (long)argv[i].a_w.w_float;
    			//post("template~: received argument %d of mymessage with value %f", i+1, temp);
				break;
		}
	}
	
	x->myshakers->controlChange(1, temp);
}

void shakers_noteOn(t_shakers *x, Symbol *s, short argc, Atom *argv)
{
	short i;
	float temp[2];

	if(argc<2) {
		post("shakers~ error: need two arguments, freq and amp\n");
		return;
	}

	for(i=0;i<2;i++) {
		switch (argv[i].a_type) {
			case A_LONG:
				temp[i] = (float)argv[i].a_w.w_long;
				//probably should comment these out when the object is debugged.
				//post("template~: received argument %d of mymessage with value %d", i+1, temp2);
				break;
			case A_FLOAT:
				temp[i] = argv[i].a_w.w_float;
				//post("template~: received argument %d of mymessage with value %f", i+1, temp);
				break;
		}
	}
	
	x->myshakers->noteOn(temp[0], temp[1]);
}



//what to do when we get the message "mymessage" and a value (or list of values)
void shakers_setpower(t_shakers *x, Symbol *s, short argc, Atom *argv)
{
	short i;
	float temp;
	long temp2; 
	for (i=0; i < argc; i++) {
		switch (argv[i].a_type) {
			case A_LONG:
				temp2 = argv[i].a_w.w_long;
				//probably should comment these out when the object is debugged.
				x->power = temp2;
    			post("template~: power = %d", x->power);
				break;
			case A_FLOAT:
				temp = argv[i].a_w.w_float;
    			//post("template~: received argument %d of mymessage with value %f", i+1, temp);
				break;
		}
	}
}