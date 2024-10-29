
#pragma once
#include <math.h>

int indexNejblizsi(int velikost, int (*poleBodu)[2], int referencniX, int referencniY) {
	double vzdalenost;
	double nejblizsi = 100;
	int index;
	for (int i = 0; i <= velikost; i++)
	{
		vzdalenost = sqrt(((referencniX - (poleBodu)[2]) ^ 2) + ((referencniY - (poleBodu)[2]) ^ 2));
		if (vzdalenost < nejblizsi)
		{
			nejblizsi = vzdalenost;
			index = poleBodu[2];
		}
	}

	return index;
}

double prumernaVzdalenost(int velikost, int (*poleBodu)[2], int referencniX, int referencniY) {
	double vzdalenost;
	double soucet = 0;
	for (int i = 0; i <= velikost; i++)
	{
		vzdalenost = sqrt(((referencniX - (poleBodu)[2]) ^ 2) + ((referencniY - (poleBodu)[2]) ^ 2));
		soucet = soucet + vzdalenost;
	}

	return (soucet / velikost);
}

	

	

