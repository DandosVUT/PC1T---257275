#pragma once

#include <iostream>
#define VELIKOST_POLE 30


void uvodni_menu();

void konec_hry();

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

void hraci_pole(int (*okraj)[VELIKOST_POLE], struct had H);

void vykresleni(int(*okraj)[VELIKOST_POLE]);

void zmena_smeru(int WSAD, struct had H);

int kontrola_prekazky(int(*okraj)[VELIKOST_POLE], struct had *H);

void pohyb_hada(struct had H);