

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"




/* ===================================== */ 
/* === sphere operations => sphere.c === */ 
/* ===================================== */ 

sphere sphere_expr(v3 v, double r, rgb(*sc)(v3,v3), rgb sh)
{
	sphere sp;
	sp.center = v;
	sp.radius = r;
	sp.surface_color = sc;
	sp.shine = sh; 
	return sp;

}

char *sphere_tos(sphere s);

void sphere_show(FILE *f, sphere s);
