// Vektory.cpp : Defines the entry point for the application.
//

#include "Vektory.h"

using namespace std;

int main()
{
	struct vektor3d u, v;
	enum typOperace typOp;
	printf("zadejte vektor u: ");
	scanf_s("%lf,%lf,%lf", &u.x, &u.y, &u.z);
	printf("zadejte vektor v: ");
	scanf_s("%lf,%lf,%lf", &v.x, &v.y, &v.z);
	printf("zadejte typ operace: 1 - soucet, 2 - skalarniSoucin, 3 - vektorovySoucin\n");
	scanf_s("%d", &typOp);
	if (typOp == 2)
		printf("skalarni soucin je: %lf", skSoucin(u, v));
	else {
		tisk(operace(u, v, typOp));
	}

	return 0;
}
