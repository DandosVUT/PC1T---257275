
#include "Hra_had.h"
#include "struktury.cpp"

#define VELIKOST_POLE 30

using namespace std;

int main()
{
	int mapa[VELIKOST_POLE][VELIKOST_POLE];

	//zadani pocatecnich podminek
	struct had H;
	H.delka = 4;
	H.smer = 'E';
	H.skore = 0;
	for (int i = 0; i < H.delka; i++)
	{
		H.telo.x[i] = 5;
		H.telo.y[i] = 5 - i;
	}

	uvodni_menu(); // je treba dodelat rozdeleni, kdy se zapne hra a kdy napr. jen tabulka vysledku apod.

	// bude v opakujicim se cyklu, ktery se bude updatovat
	int k = 0;
	while (k == 0)
	{
		hraci_pole(mapa, H);
		vykresleni(mapa);
		WSAD();
		zmena_smeru(WSAD(), H);
		pohyb_hada(H);
		if (kontrola_prekazky(mapa, H) == 1)// z duvodu aby probehla i kontrola prekazky v pripade, kdy had narazi na ovoce
		{
			k = 1;
			konec_hry();
			break;
		}
	}


	return 0;
}