// pocitani.cpp: Definuje vstupní bod pro aplikaci.
//

#include "pocitani.h"
#include "math.h"

using namespace std;

void soucet(double a[3], double b[3], double c[3])
{
	printf("Vektor A - zadejte 3 hodnoty oddelene carkou: \n");
	int i;
	for (i = 1; i <= 2; i++)
		scanf("%lf", &a[i]);
	printf("Vektor B - zadejte 3 hodnoty oddelene carkou: \n");
	for (i = 1; i <= 2; i++)
		scanf("%lf", &b[i]);
	for (i = 0; i <= 2; i++)
		c[i] = a[i] + b[i];
	printf("Soucet A+B: ");
	for (i = 1; i <= 2; i++)
		printf("%lf", c[i]);
}

 double velikost(double a[3])
{
	 int i;
	 double soucet = 0;
	 for (i = 0; i <= 2; i++)
		 soucet = soucet + (a[i] * a[i]);
	 soucet = sqrt(soucet);
	 printf("velikost vektoru A je: %lf\n", soucet);
	 
	 return soucet;
}

 double skalarniSoucin(double a[3], double b[3])
 {
	 int i;
	 double soucin = 0;
	 for (i = 0; i <= 2; i++)
		 soucin = soucin + (a[i] * b[i]);
	 printf("soucin vektoru A a B je: %lf\n", soucin);

	 return soucin;
 }

int main()
{
	double pokus[] = { 1,2,3 };
	double pokus2[] = { 2,5,8 };
	soucet;
	velikost(pokus);
	skalarniSoucin(pokus, pokus2);
	return 0;
}
