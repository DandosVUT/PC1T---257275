#pragma once

int prunik(double zacatek1, double konec1, double zacatek2, double konec2, double* vysl_zacatek, double* vysl_konec)
{
	if (zacatek2 > konec1)
		int t = 1;
	else return 0;

	for (double i = 0.1; i < 10; i++)
	{
		if ((zacatek1 + i) == zacatek2)
			vysl_zacatek = &zacatek2;
		if ((konec1 + i) == konec2)
			vysl_konec = &konec2;
		if (konec1 == (konec2 + i))
			vysl_konec = &konec1;
	}
	return 1;
}
