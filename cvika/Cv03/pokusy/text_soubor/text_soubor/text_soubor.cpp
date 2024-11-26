// text_soubor.cpp : Defines the entry point for the application.
//

#include "text_soubor.h"

using namespace std;


int main()
{
	FILE* soubor;
	const char* idk;
	int pocet_pismen = 0;
	int pocet_cisel = 0;
	fopen_s(&soubor, "D:\\vstup.txt", "r");
	while (!feof(soubor))
	{
		printf("idk");
	}
	printf("pocet pismen je: %d\n", pocet_pismen); 
	printf("pocet cisel je: %d", pocet_cisel);
	return 0;
}
