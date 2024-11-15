
#include "Hra_had.h"

#define VELIKOST_POLE 10

using namespace std;

int main()
{
	int mapa[VELIKOST_POLE][VELIKOST_POLE];
	int poziceH[VELIKOST_POLE][VELIKOST_POLE];

	struct had H;
	H.delka = 4;
	H.smer = 'E';
	/*for (int j = 3; j < 7; j++)
	{
		poziceH[5][j] = 3; // pocatecni parametry 
	}*/

	for (int j = 0; j < H.delka; j++)
	{
		H.telo.x[j] = 5;
		H.telo.y[j] = 3; // ulozena lokace dane casti hada, otazka co s prvni dilkem (hlavou)
	}

	// bude v opakujicim se cyklu, ktery se bude updatovat
	hraci_pole(mapa);
	pozice_hada(poziceH, H);

	vykresleni(mapa);

	return 0;
}