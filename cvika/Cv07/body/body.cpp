

#include "body.h"
#include "body2d.h"

#define POCET_BODU 10

using namespace std;

#include <math.h>

int indexNejblizsi(int velikost, int(*poleBodu)[2], int referencniX, int referencniY) {
	double vzdalenost;
	double nejblizsi = 100;
	int indexX, indeXY;
	for (int i = 0; i <= velikost; i++)
	{
		vzdalenost = sqrt(((referencniX - poleBodu[i][0]) ^ 2) + ((referencniY - poleBodu[i][1]) ^ 2));
		if (vzdalenost < nejblizsi)
		{
			nejblizsi = vzdalenost;
			indexX = poleBodu[i][0];
			indexY = poleBodu[i][1];
		}
	}

	return index;
}

double prumernaVzdalenost(int velikost, int(*poleBodu)[2], int referencniX, int referencniY) {
	double vzdalenost;
	double soucet = 0;
	for (int i = 0; i <= velikost; i++)
	{
		vzdalenost = sqrt(((referencniX - poleBodu[i][0]) ^ 2) + ((referencniY - poleBodu[i][1]) ^ 2));
		soucet = soucet + vzdalenost;
	}

	return (soucet / velikost);
}

int main()
{
	int body[POCET_BODU][2] = {
		5,10,
		-14,2,
		45,4,
		-9,8,
		58,-3,
		47,5,
		47,5,
		-18,-86,
		75,7,
		-25,51,
		17,98 };
	int X, Y;
	printf("Zadejte souradnice referencniho bodu X: \n");
	scanf("%d\n", &X);
	printf("Zadejte souradnice referencniho bodu Y: \n");
	scanf("%d\n", &Y);

	indexNejblizsi(10, body, X, Y);

	printf("nejblizsi bod je: %d\n", indexNejblizsi);
	printf("prumerna vzdalenost od referencniho bodu je: %d\n", prumernaVzdalenost);

	return 0;
}
