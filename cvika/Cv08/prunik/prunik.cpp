// prunik.cpp: Definuje vstupní bod pro aplikaci.
//

#include "prunik.h"
#include "zeman.cpp"

using namespace std;

int main()
{
	double x1, y1, x2, y2, vysl_x, vysl_y;
	printf("Zadejte 1. interval: \n");
	scanf_s("%lf", &x1);
	scanf_s("%lf", &y1);
	printf("Zadejte 2. interval: \n");
	scanf_s("%lf", &x2);
	scanf_s("%lf", &y2);
	int p = prunik(x1, y1, x2, y2, &vysl_x, &vysl_y);
	if (p == 0)
		printf("Nema prunik");
	else printf("%lf, %lf", vysl_x, vysl_y);
	return 0;
}
