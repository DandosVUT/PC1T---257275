// prvocisla.cpp: Definuje vstupní bod pro aplikaci.
//

#include "prvocisla.h"

using namespace std;

int isPrime(int cislo)
{
	if (cislo < 0 || cislo > 100)
		return -1;
	int i;
	for (i = 2; i < cislo; i++)
	{
		if (cislo % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	printf("%d\n", isPrime(5));
	printf("%d\n", isPrime(9));
	printf("%d\n", isPrime(62));
	printf("%d\n", isPrime(97));
}
