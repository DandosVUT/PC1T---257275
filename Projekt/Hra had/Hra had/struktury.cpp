
#include "Hra_had.h"

void uvodni_menu()
{
	printf("				 Vitejte ve hre HAD \n\n\n");
	printf("	zacit hrat \n");
	printf("	tabulka vysledku \n");
	printf("	kredity \n");
	printf("nivjdfnkjv");
}

void konec_hry()
{
	do
		;//vykresleni mapy, ktera se zastavi na pozici narazu
	while (getchar() == 0);
}

void hraci_pole(int (*okraj)[VELIKOST_POLE], struct had H)
{
	for (int i = 0; i < VELIKOST_POLE; i++) // zajisteni zdi
		for (int j = 0; j < VELIKOST_POLE; j++)
		{
			if (i == 0)
				okraj[0][j] = 2;
			if (i == VELIKOST_POLE - 1)
				okraj[VELIKOST_POLE - 1][j] = 2;
			if (j == 0)
				okraj[i][0] = 2;
			if (j == VELIKOST_POLE - 1)
				okraj[i][VELIKOST_POLE - 1] = 2;
		}

	// for (int i = 0; i < VELIKOST_POLE; i++) // zadani hada do hr.pole
	// {
	// 	okraj[H.telo.x[i]][H.telo.y[i]] = 3;
	// }

	int r1 = rand() % (VELIKOST_POLE - 1); // generovani ovoce
	int r2 = rand() % (VELIKOST_POLE - 1);
	if ((okraj[r1][r2] != 2) && (okraj[r1][r2] != 3))
		okraj[r1][r2] = 1;
}

void vykresleni(int (*okraj)[VELIKOST_POLE])
{
	for (int i = 0; i < VELIKOST_POLE; i++)
		for (int j = 0; j < VELIKOST_POLE; j++)
		{
			
			if (okraj[i][j] == 2)
				printf(".");
			else if (okraj[i][j] == 1)
				printf("*");
			else printf(" ");
			if (j == VELIKOST_POLE - 1)
			{
				printf("\n");
			}
		}
}

void zmena_smeru(int WSAD, struct had H) //WSAD reprezentovane jako 0,1,2,3 respektive. Nejspis to lze udelat lepe? 
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
}

int kontrola_prekazky(int(*okraj)[VELIKOST_POLE], struct had H)
{
	switch (okraj[H.telo.x[0]][H.telo.y[0]]) {
	case 2:
	case 3:
		return 1;
	case 1:
	{
		//had se prodlouzi (sezral ovoce)
		// pridat do pole tela hada dalsi dilek
		//skore se zvysi o 1;
		break;
	}
	}

	return 0;
}

void pohyb_hada(struct had H)
{
	int Ax = H.telo.x[0];
	int Ay = H.telo.y[0];

	switch (H.smer) {
	case 'S':
	{
		H.telo.x[0] -= 1;
		break;
	}
	case 'J':
	{
		H.telo.x[0] += 1;
		break;
	}
	case 'Z':
	{
		H.telo.y[0] -= 1;
		break;
	}
	case 'V':
	{
		H.telo.y[0] += 1;
		break;
	}
	}

	int Bx, By;
	for (int i = 1; i < H.delka; i++)
	{
		Bx = H.telo.x[i];
		By = H.telo.y[i];
		H.telo.x[i] = Ax;
		H.telo.y[i] = Ay;
		Ax = Bx;
		Ay = By; // had se po castech posouva na souradnici predchoziho dilku
	}
}