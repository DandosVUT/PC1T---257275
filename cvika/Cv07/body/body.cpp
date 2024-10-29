// body.cpp: Definuje vstupní bod pro aplikaci.
//

#include "body.h"
#include "body2d.h"

#define POCET_BODU 10

using namespace std;

int main()
{
	int body[POCET_BODU][2] = {
		5,10,
		-14,2,
		45,4,
		-9,8,
		58,-3,
		47,5,
		-18,-86,
		75,7,
		-25,51,
		17,98 };
	printf("Zadejte souradnice referencniho bodu: \n");
	int X, Y;
	scanf("%d\n", &X);
	scanf("%d\n", &Y);

	indexNejblizsi(10, body, X, Y);

	printf("nejblizsi bod je: %d\n", indexNejblizsi);
	printf("prumerna vzdalenost od referencniho bodu je: %d\n");

	return 0;
}
