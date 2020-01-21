
// PROJECT A

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"


/* === intersect.c === */




hit_test intersect(ray r, object obj)
{
	if(obj.tag == SPHERE){
		intersect_sphere(r, obj.o.s);
	} else {
		intersect_poster(r, obj.o.p);
	}
}




hit_test intersect_sphere(ray r, sphere sp)
{
	v3 ro = r.origin;
	v3 rd = r.direction;
	v3 sc = sp.center;
	double sr = sp.radius;

	v3 A = v3_sub(ro, sc);
	double B = v3_dot(A, rd);
	double C = v3_dot(A, A) - (sr * sr);
	double D = (B * B) - C;
	double t = ((-1) * B) - sqrt(D);

	hit_test ht;

	if(D<= 0){
		ht.miss = MISS;
	} else if (t<= 0) {
		ht.miss = MISS;

	} else {

		ht.miss = HIT;
		ht.t = t;
		
		v3 pos = ray_position(r, t);
		ht.hit_point = pos;

		//ht.surf = ;
		ht.shine = sp.shine;
		ht.surf_norm = v3_norm(v3_sub(pos, sc));
	}

	return ht;
}






hit_test intersect_poster(ray r, poster p)
{
	v3 ro = r.origin;
	v3 rd = r.direction;
	v3 n = v3_expr(0, 0, -1);
	double d = p.upper_left.z;
	double t = (-1 * (v3_dot(ro, n) + d)) /  v3_dot(rd, n);

	hit_test ht;

	if(t>0){

		ht.miss = HIT;
		ht.t = t;
		
		v3 pos = ray_position(r, t);
		ht.hit_point = pos;

		//ht.surf = ;
		ht.shine = p.shine;
		ht.surf_norm = n;

	} else {
		ht.miss = MISS;
	}

	return ht;

}



hit_test intersect_cylinder(ray r, cylinder c)
{
	v3 ro = r.origin;
	v3 rd = r.direction;

	v3 rp = v3_expr(rd.x, 0, rd.z);
	double mp = v3_mag(rp);
	v3 np = v3_norm(rp);

	double vx = np.x;
	double vz = np.z;
	double sx = ro.x;
	double xz = ro.z;

	v3 cc = c.center;
	double cr = c.radius;


	double xbar = (sx-cc.x);
	double zbar = (sz-cc.z);

	double A = vx*vx + vz*vz;
	double B = 2*(xbar*vz + zbar*vz);
	double C = xbar*xbar + zbar*zbar - cr*cr;
	double D = (B*B) - (4*A*C);

	hit_test ht;

	if(D>=0)
	{

		ht.miss = HIT;

		double t_front = ((-1)*B - sqrt(D)) / (2*A);
		double t_back = ((-1)*B + sqrt(D)) / (2*A);
		v3 p_front = ray_position(r, (t_front/mp));
		v3 p_back = ray_position(r, (t_back/mp));

		if(p_front > r.origin.z)



	} else {

		ht.miss = MISS;
	}
}

























