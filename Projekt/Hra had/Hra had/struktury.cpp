
#include "Hra_had.h"

void hraci_pole(int (*okraj)[VELIKOST_POLE])
{
	for (int i = 0; i < VELIKOST_POLE; i++)
		for (int j = 0; j < VELIKOST_POLE; j++)
		{
			if (i == 0)
				okraj[0][j] = 1;
			if (i == VELIKOST_POLE - 1)
				okraj[VELIKOST_POLE - 1][j] = 1;
			if (j == 0)
				okraj[i][0] = 1;
			if (j == VELIKOST_POLE - 1)
				okraj[i][VELIKOST_POLE - 1] = 1;
		}
}

void vykresleni(int (*okraj)[VELIKOST_POLE])
{
	for (int i = 0; i < VELIKOST_POLE; i++)
		for (int j = 0; j < VELIKOST_POLE; j++)
		{
			if (okraj[i][j] = 1)
				printf(".");
			else printf(" ");
		}
}