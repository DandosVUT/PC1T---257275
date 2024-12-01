#pragma once

#include <iostream>
#define VELIKOST_POLE 30
#define MAX_JMENO 50

struct Skore
{
	char jmeno[MAX_JMENO];
	int skore;
};


//void uvodni_menu();

//void konec_hry();

struct souradnice
{
	int x[VELIKOST_POLE];
	int y[VELIKOST_POLE];
};

struct had
{
	int delka;
	char smer;
	struct souradnice telo;
	int skore;

};

void hraci_pole(int (*okraj)[VELIKOST_POLE], struct had* H);

void vykresleni(int(*okraj)[VELIKOST_POLE]);

void aktualizuj_ovoce(int(*okraj)[VELIKOST_POLE]);

int WSAD();

void zmena_smeru(int WSAD, struct had *H);

int kontrola_prekazky(int(*okraj)[VELIKOST_POLE], struct had* H);

void pohyb_hada(struct had* H, int(*okraj)[VELIKOST_POLE]);

void nacti_vysledky(Skore vysledky[], int* pocet);

void uloz_vysledky(Skore vysledky[], int pocet);

void zobraz_vysledky(Skore vysledky[], int pocet);

void serad_vysledky(Skore vysledky[], int* pocet);

