#include "Hra_had.h"
#include <conio.h>
#include <time.h>

#define MAX_HRACU 10
#define MAX_JMENO 50


void hraci_pole(int(*okraj)[VELIKOST_POLE], struct had* H)
{
	// Inicializácia hracieho poľa s hranicami
	for (int i = 0; i < VELIKOST_POLE; i++)
	{
		for (int j = 0; j < VELIKOST_POLE; j++)
		{
			if (i == 0 || i == VELIKOST_POLE - 1 || j == 0 || j == VELIKOST_POLE - 1)
				okraj[i][j] = 2; // Zeď
			else if (okraj[i][j] != 1)
				okraj[i][j] = 0; // Voľné pole
		}
	}

	// zadani hada do hr.pole
	for (int i = 0; i < H->delka - 1; i++)
	{
		okraj[H->telo.x[i]][H->telo.y[i]] = 3;
	}
}

void vykresleni(int(*okraj)[VELIKOST_POLE], struct had* H)
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
				printf("\033[31m *\033[0m");
				break; // Ovocie
			case 3:
				if (H->telo.x[0] == i && H->telo.y[0] == j)
				{
					printf("\033[32mO \033[0m");
				}
				else
				{
					printf("O ");
				}
				break; // Had
			default:
				printf("  ");
				break; // Prázdne pole
			}
		}
		printf("\n");
	}
}

void aktualizuj_ovoce(int(*okraj)[VELIKOST_POLE])
{
	int r1, r2;
	do
	{
		srand(time(NULL));
		r1 = rand() % (VELIKOST_POLE - 2) + 1;
		r2 = rand() % (VELIKOST_POLE - 2) + 1;

	} while (okraj[r1][r2] == 2 || okraj[r1][r2] == 3); // Uistíme sa, že ovocie nepadne na hada ani na stenu

	okraj[r1][r2] = 1;

}

int WSAD()
{
	char ch;
	if (kbhit() != 0)
	{
		ch = getch();
		return (int)ch;
	}
	return 0;
}

void zmena_smeru(int vstup, struct had* H) // smer reprezentovany jako 'S','J','V','Z' podle svet stran
{
	if (H->smer == 'S')
	{
		if (vstup == 65 || vstup == 97)  // A alebo a
			H->smer = 'Z';
		else if (vstup == 68 || vstup == 100)  // D alebo d
			H->smer = 'V';
	}
	else if (H->smer == 'J')
	{
		if (vstup == 65 || vstup == 97)  // A alebo a
			H->smer = 'Z';
		else if (vstup == 68 || vstup == 100)  // D alebo d
			H->smer = 'V';
	}
	else if (H->smer == 'V')
	{
		if (vstup == 87 || vstup == 119)  // W alebo w
			H->smer = 'S';
		else if (vstup == 83 || vstup == 115)  // S alebo s
			H->smer = 'J';
	}
	else if (H->smer == 'Z')
	{
		if (vstup == 87 || vstup == 119)  // W alebo w
			H->smer = 'S';
		else if (vstup == 83 || vstup == 115)  // S alebo s
			H->smer = 'J';
	}
}

void pohyb_hada(struct had* H, int(*okraj)[VELIKOST_POLE])
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

	// Posun tela hada
	for (int i = H->delka - 1; i > 0; i--)
	{
		H->telo.x[i] = H->telo.x[i - 1];
		H->telo.y[i] = H->telo.y[i - 1];
	}

	H->telo.x[0] = Ax;
	H->telo.y[0] = Ay;
}

int kontrola_prekazky(int(*okraj)[VELIKOST_POLE], struct had* H)
{
	int Ax = H->telo.x[0];
	int Ay = H->telo.y[0];

	// Kontrola kolízie s prekážkami alebo zjedenia ovocia
	if (okraj[Ax][Ay] == 2 || okraj[Ax][Ay] == 3) // Kolízia so stenou alebo vlastným telom
		return 0;

	else if (okraj[Ax][Ay] == 1)
	{
		// Zjedenie ovocia - had sa predĺži
		H->delka++;
		H->skore++;
		aktualizuj_ovoce(okraj);
	}

	return 1;
}

void nacti_vysledky(Skore vysledky[], int* pocet)
{
	FILE* soubor;
	const char* inputFilePath = "C:/Users/lewro/source/repos/DandosVUT/PC1T---257275/Projekt/Hra had/Hra had/vysledky.txt";
	fopen_s(&soubor, inputFilePath, "r");
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
	FILE* soubor;
	const char* inputFilePath = "C:/Users/lewro/source/repos/DandosVUT/PC1T---257275/Projekt/Hra had/Hra had/vysledky.txt";
	fopen_s(&soubor, inputFilePath, "w");
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

void serad_vysledky(Skore vysledky[], int* pocet)
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