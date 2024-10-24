// veta.cpp : Defines the entry point for the application.
//

#include "veta.h"
#include <ctype.h>

using namespace std;

int pismena(char *veta)
{
	int i;
	int pocet = 0;
	for (i = 0; i <= strlen(veta); i++)
	{
		if (isalpha(veta[i]) != 0)
		{
			pocet += 1;
		}
	}
	printf("pocet pismen v textu je: %d\n", pocet);

	return pocet;
}

int cisla(char* veta)
{
	int i;
	int pocet = 0;
	for (i = 0; i <= strlen(veta); i++)
	{
		if (isdigit(veta[i]) != 0)
		{
			pocet += 1;
		}
	}
	printf("pocet cisel v textu je: %d\n", pocet);

	return pocet;
}

int main()
{
	char text[] = "Toto jsou 2 vzorove vety, ktere budou zpracovavany Vasemi funkcemi. Auto Hyundai ix35 ma pres 120 konskych sil.";
	pismena(text);
	cisla(text);

	return 0;
}
