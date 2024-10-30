// Hra had.cpp : Defines the entry point for the application.
//

#include "Hra had.h"

#define VYSKA_POLE 10
#define SIRKA_POLE 20

using namespace std;

void hraci_pole() { // zkousel jsem, jestli umim vykreslit pole, reseni asi bude jine
	int i, j;
	for (i = 0; i < SIRKA_POLE; i++)
		printf(".");
	for (j = 0; j < VYSKA_POLE - 2; j++)
	{
		printf("\n.");
		for (i = 0; i < SIRKA_POLE - 2; i++)
			printf(" ");
		printf(".");
	}
	printf("\n");
	for (i = 0; i < SIRKA_POLE; i++)
		printf(".");
	printf("\n");
}

void had(int (*pole)[VYSKA_POLE]) { // zatim jen generovani hada, urceni smeru jindy
	int rngX = rand() % 20;
	int rngY = rand() % 20;
	for (int i = 0; i < SIRKA_POLE; i++)
		for (int j = 0; j < VYSKA_POLE; j++)
		{
			if (i == 0 || i == (SIRKA_POLE - 1))
				printf(".");
			if (j == 0)
				printf(".");
			if (j == (VYSKA_POLE - 1))
				printf(".\n");
			if (i == rngX && j == rngY)
				printf(".");
			if (i != 0 || j != 0 || i != (SIRKA_POLE - 1) || j != (VYSKA_POLE - 1)) // hrozna notace, bude zmeneno casem
				printf(" ");
		}
	printf("%d\n", rngX);
	printf("%d", rngY);
}

int main()
{
	//hraci_pole();
	int pole[SIRKA_POLE][VYSKA_POLE];
	had(pole);
	return 0;
}