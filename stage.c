
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"


/* =================================== */ 
/* === stage operations => stage.c === */ 
/* =================================== */ 

char *stage_tos(stage stg);

void stage_show(FILE *f, stage stg)
{

	fprintf(f, "%f\n", stg.c);
	fprintf(f, "%f\n\n", stg.s);

}

/* The function get_stage just needs to return a valid stage. */
/* The argument may be used, or not, at your discretion. */
stage get_stage(unsigned int selection)
{
	stage s;
	return s;

}