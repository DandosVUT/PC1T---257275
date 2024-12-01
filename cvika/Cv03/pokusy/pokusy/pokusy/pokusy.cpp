// pokusy.cpp : Defines the entry point for the application.
//

#include "pokusy.h"
#include <conio.h>
#include <windows.h>
#define VELIKOST_POLE 30

using namespace std;


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

void zmena_smeru(int WSAD) // smer reprezentovany jako 'S','J','V','Z' podle svet stran
{
	if (WSAD == (87 || 119))
		printf("uspesne 1\n");
	if (WSAD == (83 || 115))
		printf("uspesne 2\n");
	if (WSAD == (65 || 97))
		printf("uspesne 3\n");
	if (WSAD == (68 || 100))
		printf("uspesne 4\n");
	if (WSAD == 0)
		printf("blbost\n");
}

int main()
{

	printf("vitejte\n");
	int j = getchar();
	zmena_smeru(j);

	Sleep(2000);
	printf("cislo char: %d", j);
	return 0;
}
