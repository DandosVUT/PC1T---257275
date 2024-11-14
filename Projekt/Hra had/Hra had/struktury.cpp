
#include "Hra_had.h"


void hraci_pole(int (*okraj)[VELIKOST_POLE])
{
	for (int i = 0; i < VELIKOST_POLE; i++) // zajisteni zdi
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
	okraj[rand() % (VELIKOST_POLE - 1)][rand() % (VELIKOST_POLE - 1)] = 2; //generovani ovoce
}

void vykresleni(int (*okraj)[VELIKOST_POLE])
{
	for (int i = 0; i < VELIKOST_POLE; i++)
		for (int j = 0; j < VELIKOST_POLE; j++)
		{
			if (okraj[i][j] = 1)
				printf(".");
			else if (okraj[i][j] == 2)
				printf("*");
			else printf(" ");
		}
}

void pohyb(int WSAD, struct had H) //WSAD reprezentovane jako 0,1,2,3 respektive. Nejspis to lze udelat lepe? 
								   //smer reprezentovany jako 'S','J','V','Z' podle svet stran
{
	switch (H.smer) {
	case 'S':
	case 'J':
	{
		if (WSAD == 2)
			H.smer = 'Z';
		else if (WSAD == 3)
			H.smer = 'V';
		//else neplatna klavesa?
		break;
	}
	case 'V':
	case 'Z':
	{
		if (WSAD == 0)
			H.smer = 'S';
		else if (WSAD == 1)
			H.smer = 'J';
		//else neplatna klavesa?
		break;
	}

}