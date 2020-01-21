
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"


/* =============================== */ 
/* === ray operations => ray.c === */ 
/* =============================== */ 



v3 ray_position(ray r, double t)
{
  return v3_add(r.origin, v3_scale(t, r.direction));
}



char *ray_tos(ray r);

void ray_show(FILE *f, ray r);


