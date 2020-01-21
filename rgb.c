
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"


/* =============================== */ 
/* === rgb operations => rgb.c === */ 
/* =============================== */ 


/* reject if any component is outside [0.0,1.0] */
rgb rgb_expr(double r, double g, double b)
{
	if(1.0 >= r >= 0.0 &&
	   1.0 >= g >= 0.0 &&
	   1.0 >= b >= 0.0)
	{
		rgb color;
		color.r = r;
		color.g = g;
		color.b = b;
		return color;

	} else {
		fprintf(stderr,"out of range");
		exit(0);
	}

}

/* rgb_modulate : multiply the components or two rgbs */
/* (r,g,b) * (R,G,B) = (rR,gG,bB) */
rgb rgb_modulate(rgb c1, rgb c2)
{
	rgb color;
	color.r = c1.r * c2.r;
	color.g = c1.g * c2.g;
	color.b = c1.b * c2.b;
	return color;
}

/* rgb_scale : scale each component by given scalar, but */
/* don't allow any component in the result to fall outside [0,1] */
rgb rgb_scale(double s, rgb c)
{
	rgb_expr(s*c.r, s*c.g, s*c.b);
}

/* add components of colors, but */
/* don't allow any component in the result to exceed 1 */
rgb rgb_add(rgb c1, rgb c2)
{
	rgb_expr(c1.r + c2.r,
			 c1.g + c2.g,
			 c1.b + c2.b);

}

char *rgb_tos(rgb c);

void rgb_show(FILE *f, rgb c);

/* rgb_show_bytes */
/* print three integers on [0,255] with spaces in between and a newline */
/* suitable for use in a PPM */
void rgb_show_bytes(FILE *f, rgb c)
{
  int r = (((c.r+1)/2)*255);
  int g = (((c.g+1)/2)*255);
  int b = (((c.b+1)/2)*255);
  fprintf(f, "%d %d %d", r, g, b);
  fprintf(f, "\n");
}


/*
int main(int argc, char* argv[])
{
	return 0;
}

*/




