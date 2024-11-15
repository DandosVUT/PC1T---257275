#pragma once

#include <iostream>
#define VELIKOST_POLE 10

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

};

void hraci_pole(int (*okraj)[VELIKOST_POLE]);

void vykresleni(int (*okraj)[VELIKOST_POLE]);

void zmena_smeru(int WSAD, struct had H);

//void delka_hada(struct had H);

void pozice_hada(int (*pozice)[VELIKOST_POLE], struct had H);
