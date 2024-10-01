
#include "FunExt.h"

using namespace std;

int main()
{
	int a;
	int b;
	scanf("%d", &a);
	scanf("%d", &b);
	int obvodA = 4 * a;
	int obsahA = a ^ 2;
	int obvodB = 4 * b;
	int obsahB = b ^ 2;
	printf("obvod ctverce A: %d\n", obvodA);
	printf("obsah ctverce A: %d\n", obsahA);
	printf("obvod ctverce B: %d\n", obvodB);
	printf("obsah ctverce B: %d\n", obsahB);

	return 0;

}