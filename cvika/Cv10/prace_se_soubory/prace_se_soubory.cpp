// prace_se_soubory.cpp: Definuje vstupní bod pro aplikaci.
//

#include "prace_se_soubory.h"

using namespace std;

int main()
{
	FILE* vstup;
	FILE* vysledky;
	const char* soubor = "cvika/Cv10/prace_se_soubory/vstup.txt";
	const char* soubor2 = "cvika/Cv10/prace_se_soubory/vysledky.txt";

	if (fopen_s(&vstup, soubor, "r") != 0)
	{
		printf("Nelze otevrit soubor");
		return -1;
	}

	char veta[100];
	int pocet_pismen = 0;
	int pocet_cisel = 0;
	int delka_slov[50];
	for (int z = 0; z < 50; z++)
		delka_slov[z] = 0;

	while (!feof(vstup))
	{
		int j = 0;
		fgets(veta, 100, vstup);
		char ch = fgetc(vstup);
		for (int i = 0; i <= strlen(veta); i++)
		{
			if (isalpha(veta[i]))
				pocet_pismen += 1;
			if (isdigit(veta[i]))
				pocet_cisel += 1;
			if (ch != 32)
				delka_slov[j] += 1;
			else j++;
		}
	}

	if (fopen_s(&vysledky, soubor2, "w") != 0)
	{
		printf("Nelze otevrit soubor");
		return -1;
	}

	printf("pocet pismen je: %d\n", pocet_pismen);
	printf("pocet cisel je: %d\n", pocet_cisel);
	printf("delky jednotlivych slov jsou: \n");

	fprintf(vysledky, "pocet pismen je: %d\n", pocet_pismen);
	fprintf(vysledky, "pocet cisel je: %d\n", pocet_cisel);
	fprintf(vysledky, "delky jednotlivych slov jsou: \n");

	for (int i = 0; i < 50; i++)
		if (delka_slov[i] > 0)
		{
			printf("%d, ", delka_slov[i]);
			fprintf(vysledky, "%d, ", delka_slov[i]);
		}

	fclose(vstup);
	fclose(vysledky);

	return 0;
}
