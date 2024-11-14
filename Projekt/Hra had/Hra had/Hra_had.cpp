
#include "Hra_had.h"

#define VELIKOST_POLE 10

using namespace std;

int main()
{
	int okraj[VELIKOST_POLE][VELIKOST_POLE];
	hraci_pole(okraj);
	vykresleni(okraj);

	return 0;
}