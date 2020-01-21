
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"



/* ===================================== */ 
/* === slab operations => poster.c ===== */ 
/* ===================================== */ 

poster poster_expr(v3 ulc, double w, double h, rgb(*sc)(v3,v3), rgb sh)
{

	poster p;
	p.upper_left = ulc;
	p.w = w;
	p.h = h;
	p.surface_color = sc;
	p.shine = sh;
	return p;

}

char *poster_tos(poster s);

void poster_show(FILE *f, poster s);