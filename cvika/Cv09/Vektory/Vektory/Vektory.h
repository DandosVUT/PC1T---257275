// Vektory.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

enum typOperace { soucet = 1, skalarniSoucin, vektorovySoucin };

struct vektor3d
{
	double x;
	double y;
	double z;
};

struct vektor3d operace(struct vektor3d u, struct vektor3d v, enum typOperace typ);

double skSoucin(struct vektor3d u, struct vektor3d v);

void tisk(struct vektor3d u);


// TODO: Reference additional headers your program requires here.
