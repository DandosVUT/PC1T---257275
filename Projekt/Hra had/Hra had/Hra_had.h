#pragma once

#include <iostream>
#define VELIKOST_POLE 10

struct had
{
	int delka;
	char smer;

};


void hraci_pole(int (*okraj)[VELIKOST_POLE]);

void vykresleni(int(*okraj)[VELIKOST_POLE]);

void pohyb(int WSAD, struct had H);
