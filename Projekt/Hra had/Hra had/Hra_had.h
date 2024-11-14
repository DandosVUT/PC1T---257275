#pragma once

#include <iostream>
#define VELIKOST_POLE 10

struct had
{
	int delka;
	int x;
	int y;
};

struct mapa
{
	int vyska;
	int sirka;
};

void hraci_pole(int (*okraj)[VELIKOST_POLE]);

void vykresleni(int(*okraj)[VELIKOST_POLE]);
