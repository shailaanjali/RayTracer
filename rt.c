
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"




/* === rt.c === */

int main(int argc, char *argv[])
{
  unsigned sel = argc>1 ? atoi(argv[1]) : 0;
  stage stg = get_stage(sel);
  render(stdout,stg);
  stage_show(stderr,stg);
  return 0;
}