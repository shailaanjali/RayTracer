
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"


/* ================================== */ 
/* === vector operations => v3.c === */ 
/* ================================== */ 

v3 v3_expr(double x, double y, double z)
{
	v3 vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	//v3_show(vec);
	return vec;
}
 
/* v3_add : add two vectors */
/* (x,y,z) + (X,Y,Z) = (x+X,y+Y,z+Z) */
v3 v3_add(v3 v1, v3 v2)
{
	v3 vec;
	vec.x = v1.x + v2.x;
	vec.y = v1.y + v2.y;
	vec.z = v1.z + v2.z;
	//v3_show(vec);
	return vec;
}


/* v3_sub : subtract the second vector from the first */
/* (x,y,z) - (X,Y,Z) = (x-X,y-Y,z-Z) */
v3 v3_sub(v3 v1, v3 v2)
{
	v3 vec;
	vec.x = v1.x - v2.x;
	vec.y = v1.y - v2.y;
	vec.z = v1.z - v2.z;
	//v3_show(vec);
	return vec;
}


/* v3_neg : negate a vector */
/* -(x,y,z) = (-x,-y,-z) */
v3 v3_neg(v3 v)
{
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	//v3_show(v);
	return v;

}

/* v3_scale : scale the components of a vector by scalar s */
/* s(x,y,z) = (sx,sy,sz) */
v3 v3_scale(double s, v3 v)
{
	v.x = s * v.x;
	v.y = s * v.y;
	v.z = s * v.z;
	//v3_show(v);
	return v;

}

/* v3_dot : compute the dot product of two vectors */
/* (x,y,z) dot (X,Y,Z) = xX+yY+zZ */
double v3_dot(v3 v1, v3 v2)
{
	double x = v1.x * v2.x;
	double y = v1.y * v2.y;
	double z = v1.z * v2.z;
	return (x+y+z);

}

/* v3_mag : compute the magnitude of a vector */
/* the square root of the sum of the squares of the components */
double v3_mag(v3 v)
{
	double ss = pow(v.x, 2) +
				pow(v.y, 2) +
				pow(v.z, 2);

	return sqrt(ss);
}


/* v3_norm : normalize the vector */
/* i.e., a vector pointing in the same direction whose magnitude is 1 */
/* - normalize a vector by scaling by 1 over its magnitude */
/* - if a vector's magnitude is zero, it can't be normalized; return it */
v3 v3_norm(v3 v)
{
	double mag = v3_mag(v);
	if (mag == 0)
	{
		return v;
	} else {
		v.x = v.x/mag;
		v.y = v.y/mag;
		v.z = v.z/mag;
		return v;
	}
}



char *v3_tos(v3 v)
{
	 char* p = (char*)malloc(5 * sizeof(char));
	 char x = (char)v.x;
	 char y = (char)v.y;
	 char z = (char)v.z;
	 p[0] = '(';
	 p[1] = x;
	 p[2] = y;
	 p[3] = z;
	 p[4] = ')';

	//return p;


}

void v3_show(FILE *f, v3 v)
{
	fprintf(f, "%f\n", v.x);
	fprintf(f, "%f\n", v.y);
	fprintf(f, "%f\n\n", v.z);
}


/*
int main(int argc, char* argv[])
{
	v3 vec1 = v3_expr(2, 3, 4);
	v3 vec2 = v3_expr(1, 1, 1);
	//v3_add(vec1, vec2);
	//v3_sub(vec1, vec2);
	v3_neg(vec1);
	v3_scale(2.0, vec1);
	printf("%f\n", v3_dot(vec1, vec2));
	printf("%f\n", v3_mag(vec1));
	printf("%s\n",v3_tos(vec1));
	

	return 0;
}

*/

