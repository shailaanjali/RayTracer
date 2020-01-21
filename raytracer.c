// PROJECT A

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"



/* ================================================ */ 
/* ================================================ */ 
/* === RAY TRACER LOGIC and MAIN => raytracer.c === */ 
/* ================================================ */ 
/* ================================================ */ 

/* === project 1 operations === */


/* === raytracer.c === */


int shadow(v3 p, light l, obj_list *objs)
{
	
	v3 nudge = v3_scale(0.0001, l.direction);
	v3 lifted = v3_add(p, nudge);

	ray r;
	r.origin = lifted;
	r.direction = v3_norm(v3_sub(lifted, l.direction));

	int counter = 0;

	while(objs->next != NULL)
	{
		hit_test ht = intersect(r, objs->obj);

		if(ht.miss == HIT)
		{
			counter++;

		}
	}

	if (counter>0)
	{
		return 1;
	} else {
		return 0;
	}
	
}


hit_test small_hit(ray r, obj_list *objs)
{
	double t = 0;
	hit_test htemp;


	while(objs->next != NULL)
	{
		hit_test ht = intersect(r, objs->obj);

		if(ht.miss == HIT)
		{
			if (t==0){
				htemp = ht;
				t = ht.t;
			} else {
				if(ht.t>t){
					// do nothing
				} else {
					htemp = ht;
					t = ht.t;
				}
			}

		}
	}

	return htemp;
}




double max(double x, double y)
{
	if (x>y){
		return x;
	} else {
		return y;
	}
}



rgb lighting(scene s, ray r, hit_test h)
{
	if(h.miss == MISS)
	{
		return s.bg;

	} else if (shadow(r.origin, s.light, s.objects) == 1) {

		return rgb_modulate(s.amb, h.surf);

	} else {

		rgb dif = 
			rgb_scale(max(0,v3_dot(h.surf_norm,s.light.direction)),
									s.light.color);
		return rgb_modulate(rgb_add(dif, s.amb), h.surf);
	}
}



v3 logical_loc(camera c, unsigned int x, unsigned int y)
{
	int max = 0;

	if (c.h >= c.w){
		max = c.h;
	} else {
		max = c.w;
	}

	x = (x * (2/max)) - (c.w/max) + (1/max);
	y = ((-1) * (y * (2/max))) + (c.h/max) - (1/max);

	v3_expr(x, y, 0);

}


int list_len(obj_list *objs)
{
	int counter = 0;
	while(objs != NULL)
	{
		counter ++;
		objs = objs->next;
	}

	return counter;
}




rgb trace_ray(scene s, ray r)
{
	if (list_len(s.objects) == 0)
	{
		return s.bg;
	} else {
		return lighting(s, r, small_hit(r, s.objects));
	}
}


void render(FILE *f, stage g)
{
	//header of ppm file
	fprintf(f, "P3\n");
	fprintf(f, "%d %d", g.c.w, g.c.h); 
	fprintf(f, "\n255\n");

	for(int i = 0; i<g.c.w; i++)
	{
		for(int j=0; j<g.c.h; j++)
		{

			ray r;
			r.direction = logical_loc(g.c, i, j);
			r.origin = g.c.loc;
			rgb_show_bytes(f, trace_ray(g.s, r)); 
		}
	}
}


