// FunExt.cpp : Defines the entry point for the application.
//

#include "FunExt.h"

using namespace std;

int main()
{
    double maxY = DBL_MAX;
    int maxX = INT_MAX;
    for (int x = 1; x <= 10; ++x)
    {
        double y = 5 - 3 * x + 2 * (x - 5) * (x - 5) - (x - 10) * (x - 10) * (x - 10);

        if (y > maxY)
        {
            maxY = y;
            maxX = x;
        }
    }
    printf("Minimum value: %lf at x=%d\n", maxY, maxX);
    return 0;
}
