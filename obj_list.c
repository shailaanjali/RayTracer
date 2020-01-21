// PROJECT A

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"




/* ======================================== */ 
/* === object list ops => obj_list.c === */ 
/* ======================================== */ 

obj_list *ol_cons(object o, obj_list *os)
{
	obj_list *oss;
	oss->obj = o;
	oss->next = os;

	return oss; 
}

obj_list *ol_singleton(object s)
{
	obj_list *oss;
	oss->obj = s;
	oss->next = NULL;
	return oss;
}

void ol_show(FILE *f, obj_list *os);

void ol_free(obj_list *ss);
