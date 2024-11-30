#include "Hra_had.h"

#define MAX_HRACU 10
#define MAX_JMENO 50

struct Skore
{
	char jmeno[MAX_JMENO];
	int skore;
};

void konec_hry()
{
	do
		; // vykresleni mapy, ktera se zastavi na pozici narazu
	while (getchar() == 0);
}

void vykresleni(int (*okraj)[VELIKOST_POLE])
{
	for (int i = 0; i < VELIKOST_POLE; i++)
	{
		for (int j = 0; j < VELIKOST_POLE; j++)
		{
			switch (okraj[i][j])
			{
			case 2:
				printf("# ");
				break; // Stena
			case 1:
				printf("* ");
				break; // Ovocie
			case 3:
				printf("O ");
				break; // Had
			default:
				printf("  ");
				break; // Prázdne pole
			}
		}
		printf("\n");
	}
}

void hraci_pole(int (*okraj)[VELIKOST_POLE], struct had *H)
{
	// Inicializácia hracieho poľa s hranicami
	for (int i = 0; i < VELIKOST_POLE; i++)
	{
		for (int j = 0; j < VELIKOST_POLE; j++)
		{
			if (i == 0 || i == VELIKOST_POLE - 1 || j == 0 || j == VELIKOST_POLE - 1)
				okraj[i][j] = 2; // Stena
			else
				okraj[i][j] = 0; // Voľné pole
		}
	}

	// Inicializácia hada do stredu hracieho poľa
	H->delka = 3;
	H->smer = 'V';
	int stred_x = VELIKOST_POLE / 2;
	int stred_y = VELIKOST_POLE / 2;

	for (int i = 0; i < H->delka; i++)
	{
		H->telo.x[i] = stred_x;
		H->telo.y[i] = stred_y - i;
		okraj[stred_x][stred_y - i] = 3; // 3 znamená telo hada
	}
}

void aktualizuj_ovoce(int (*okraj)[VELIKOST_POLE])
{
	int r1, r2;
	do
	{
		r1 = rand() % (VELIKOST_POLE - 2) + 1;
		r2 = rand() % (VELIKOST_POLE - 2) + 1;

	} while (okraj[r1][r2] != 0); // Uistíme sa, že ovocie nepadne na hada ani na stenu

	okraj[r1][r2] = 1;
}

void pohyb_hada(struct had *H, int (*okraj)[VELIKOST_POLE])
{
	int Ax = H->telo.x[0];
	int Ay = H->telo.y[0];

	// Aktualizácia hlavy hada podľa smeru
	switch (H->smer)
	{
	case 'S':
		Ax -= 1;
		break;
	case 'J':
		Ax += 1;
		break;
	case 'Z':
		Ay -= 1;
		break;
	case 'V':
		Ay += 1;
		break;
	}

	// Kontrola kolízie s prekážkami alebo zjedenia ovocia
	if (okraj[Ax][Ay] == 2 || okraj[Ax][Ay] == 3)
	{
		// Kolízia so stenou alebo vlastným telom
		printf("Game Over!\n");
		exit(0);
	}
	else if (okraj[Ax][Ay] == 1)
	{
		// Zjedenie ovocia - had sa predĺži
		H->delka++;
		H->skore++;
		aktualizuj_ovoce(okraj);
	}

	// Posun tela hada
	okraj[H->telo.x[H->delka - 1]][H->telo.y[H->delka - 1]] = 0; // Vymaže posledný diel

	for (int i = H->delka - 1; i > 0; i--)
	{
		H->telo.x[i] = H->telo.x[i - 1];
		H->telo.y[i] = H->telo.y[i - 1];
	}

	H->telo.x[0] = Ax;
	H->telo.y[0] = Ay;
	okraj[Ax][Ay] = 3; // Aktualizácia novej hlavy
}

void zmena_smeru(int WSAD, struct had H) // WSAD reprezentovane jako 0,1,2,3 respektive. Nejspis to lze udelat lepe?
// smer reprezentovany jako 'S','J','V','Z' podle svet stran
{
	switch (H.smer)
	{
	case 'S':
	case 'J':
	{
		if (WSAD == 2)
			H.smer = 'Z';
		else if (WSAD == 3)
			H.smer = 'V';
		// else neplatna klavesa?
		break;
	}
	case 'V':
	case 'Z':
	{
		if (WSAD == 0)
			H.smer = 'S';
		else if (WSAD == 1)
			H.smer = 'J';
		// else neplatna klavesa?
		break;
	}
	}
}

int kontrola_prekazky(int (*okraj)[VELIKOST_POLE], struct had *H)
{
	int Ax = H->telo.x[0];
	int Ay = H->telo.y[0];

	if (okraj[Ax][Ay] == 2 || okraj[Ax][Ay] == 3)
		return 1;

	if (okraj[Ax][Ay] == 1)
	{
		H->delka++;
		H->skore++;
		aktualizuj_ovoce(okraj);
	}
	return 0;
}

void nacti_vysledky(Skore vysledky[], int *pocet)
{
	FILE *soubor = fopen("vysledky.txt", "r");
	if (soubor != NULL)
	{
		*pocet = 0;
		while (fscanf(soubor, "%49s %d", vysledky[*pocet].jmeno, &vysledky[*pocet].skore) == 2)
		{
			(*pocet)++;
			if (*pocet >= MAX_HRACU)
				break;
		}
		fclose(soubor);
	}
	else
	{
		*pocet = 0;
	}
}

void uloz_vysledky(Skore vysledky[], int pocet)
{
	FILE *soubor = fopen("vysledky.txt", "w");
	if (soubor != NULL)
	{
		for (int i = 0; i < pocet; i++)
		{
			fprintf(soubor, "%s %d\n", vysledky[i].jmeno, vysledky[i].skore);
		}
		fclose(soubor);
	}
}

void zobraz_vysledky(Skore vysledky[], int pocet)
{
	printf("Top 10 skore:\n");
	for (int i = 0; i < pocet && i < MAX_HRACU; i++)
	{
		printf("%d. %s: %d\n", i + 1, vysledky[i].jmeno, vysledky[i].skore);
	}
}

void serad_vysledky(Skore vysledky[], int *pocet)
{
	for (int i = 0; i < *pocet - 1; i++)
	{
		for (int j = i + 1; j < *pocet; j++)
		{
			if (vysledky[j].skore > vysledky[i].skore)
			{
				Skore temp = vysledky[i];
				vysledky[i] = vysledky[j];
				vysledky[j] = temp;
			}
		}
	}
	if (*pocet > MAX_HRACU)
		*pocet = MAX_HRACU; // Limit to top 10
}