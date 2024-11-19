// prace_se_soubory.cpp: Definuje vstupní bod pro aplikaci.
//

#include "prace_se_soubory.h"

using namespace std;

int main()
{
	FILE* vstup;
	const char* soubor = "C:/Users/lewro/source/repos/DandosVUT/PC1T---257275/cvika/Cv10/prace_se_soubory/vstup.txt";

	if (fopen_s(&vstup, soubor, "r") != 0)
	{
		printf("Nelze otevrit soubor");
		return -1;
	}

	char veta[100];
	int pocet_pismen = 0;
	int pocet_cisel = 0;
	int slovo = 0;

	while (!feof(vstup))
	{
		fgets(veta, 100, vstup);
		for (int i = 0; i <= strlen(veta); i++)
		{
			if (isalpha(veta[i]))
				pocet_pismen += 1;
			if (isdigit(veta[i]))
				pocet_cisel += 1;
		}
	}


	printf("pocet pismen je: %d\n", pocet_pismen);
	printf("pocet cisel je: %d\n", pocet_cisel);
	printf("delky jednotlivych slov jsou: \n");

	fprintf(vstup, "pocet pismen je: %d\n", pocet_pismen);
	fprintf(vstup, "pocet cisel je: %d\n", pocet_cisel);
	fprintf(vstup, "delky jednotlivych slov jsou: \n");

	while (fgetc(vstup) != EOF)
	{
		if (fgetc(vstup) != 32)
			slovo += 1;
		printf(", %d", slovo);
		slovo = 0;
	}

	fclose(vstup);

	return 0;
}
