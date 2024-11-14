#include "Vektory.h"
#include <math.h>

struct vektor3d operace(struct vektor3d u, struct vektor3d v, enum typOperace typ) {
	struct vektor3d w;
	switch (typ) {
	case 1: {
		w.x = u.x + v.x;
		w.y = u.y + v.y;
		w.z = u.z + v.z;
		break;
	}
	case 3: {
		w.x = (u.y * v.z) - (u.z * v.y);
		w.y = (u.z * v.x) - (u.x * v.z);
		w.z = (u.x * v.y) - (u.y * v.x);
		break;
	default: {
		w.x = 0;
		w.y = 0;
		w.z = 0;
		break;
	}
	}
	}
	return w;
}

double skSoucin(struct vektor3d u, struct vektor3d v) {
	double soucin = (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
	return soucin;
}


void tisk(struct vektor3d w) {
	printf("w = (%lf, %lf, %lf)\n", w.x, w.y, w.z);
	double velikost = sqrt((w.x) * (w.x) + (w.y) * (w.y) + (w.z) * (w.z));
	printf("|w| = %lf", velikost);
}