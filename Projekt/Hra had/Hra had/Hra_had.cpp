
#include "Hra_had.h"

#define VELIKOST_POLE 10

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
	int WSAD;

	uvodni_menu(); // je treba dodelat rozdeleni, kdy se zapne hra a kdy napr. jen tabulka vysledku apod.

	// bude v opakujicim se cyklu, ktery se bude updatovat
	hraci_pole(mapa, H);
	vykresleni(mapa);
	pohyb_hada(H);
	int k = kontrola_prekazky(mapa, H); // z duvodu aby probehla i kontrola prekazky v pripade, kdy had narazi na ovoce
	if (k == 1)
		konec_hry();
	WSAD = getchar(); // bude to fungovat?? kazdopadne potreba moznosti zmeny smeru
	zmena_smeru(WSAD, H);


	return 0;
}