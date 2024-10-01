// bourka.cpp: Definuje vstupní bod pro aplikaci.
//

#include "bourka.h"

using namespace std;

int main()
{
	printf("zadejte cas hromu od blesku (v sekundach): \n");
	int cas;
	scanf_s("%d", &cas);
	int vzdalenost = cas * 340;
	printf("vzdalenost bourky je: %d metru", vzdalenost);

	return 0;

}
