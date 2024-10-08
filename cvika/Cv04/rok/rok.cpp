// rok.cpp: Definuje vstupní bod pro aplikaci.
//

#include "rok.h"

using namespace std;

int jePrestupny(int rok)
{
	if (rok % 400 == 0)
		return 1;
	if ((rok % 4 == 0) && (rok % 100 != 0))
		return 1;
	else return 0;
}

int main()
{
	printf("%d\n", jePrestupny(1000));
	printf("%d\n", jePrestupny(2000));
	printf("%d\n", jePrestupny(2002));
	printf("%d\n", jePrestupny(2012));
	printf("%d\n", jePrestupny(2022));
	printf("%d\n", jePrestupny(2200));
	return 0;
}
