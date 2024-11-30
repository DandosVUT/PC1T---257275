#include "Hra_had.h"
#include <cstdlib>
#include <ctime>
#include <fcntl.h>
#include <conio.h>

#define VELIKOST_POLE 30
#define MAX_HRACU 10
#define MAX_JMENO 50

using namespace std;

int main()
{
    int volba;
    printf("Vitejte ve hre HAD \n\n");
    printf("1. Zacit hrat \n");
    printf("2. Tabulka vysledku \n");

    printf("Vyberte si cislo: ");
    scanf_s("%d", &volba);
    //getchar(); // Remove newline from input buffer

    struct Skore vysledky[MAX_HRACU];
    int pocet_vysledku = 0;
    nacti_vysledky(vysledky, &pocet_vysledku);

    if (volba == 2)
    {
        zobraz_vysledky(vysledky, pocet_vysledku);
        return 0;
    }
    else if (volba != 1)
    {
        printf("Neplatna volba, konec programu.\n");
        return 0;
    }

    int mapa[VELIKOST_POLE][VELIKOST_POLE];

    // Inicializácia hada
    struct had H;

    // Inicializácia hada do stredu hracieho poľa
    H.delka = 3;
    H.smer = 'V';
    int stred_x = VELIKOST_POLE / 2;
    int stred_y = VELIKOST_POLE / 2;

    for (int i = 0; i < H.delka; i++)
    {
        H.telo.x[i] = stred_x;
        H.telo.y[i] = stred_y - i;
        mapa[stred_x][stred_y - i] = 3; // 3 znamená telo hada
    }

    // Hlavný herný cyklus
    while (true)
    {
        system("cls"); // Vyčistenie obrazovky (pre Windows)
        hraci_pole(mapa, &H);
        vykresleni(mapa);

        // Správa vstupu hráča (zmena smeru pomocou WSAD)
        //char vstup = getchar(); // Načítanie znaku zo vstupu

        zmena_smeru(WSAD(), &H);

        // Pohyb hada a kontrola prekážok
        pohyb_hada(&H, mapa);

        // Ukončenie hry, ak došlo ku kolízii
        if (kontrola_prekazky(mapa, &H)) 
        {
            printf("Game Over! Skore: %d\n", H.skore);

            char jmeno[MAX_JMENO];
            printf("Zadejte sve jmeno: ");
            scanf_s("%49s", jmeno, MAX_JMENO);

            if (pocet_vysledku < MAX_HRACU) {
                strcpy_s(vysledky[pocet_vysledku].jmeno, jmeno);
                vysledky[pocet_vysledku].skore = H.skore;
                pocet_vysledku++;
            } else if (H.skore > vysledky[MAX_HRACU - 1].skore) {
                strcpy_s(vysledky[MAX_HRACU - 1].jmeno, jmeno);
                vysledky[MAX_HRACU - 1].skore = H.skore;
            }

            serad_vysledky(vysledky, &pocet_vysledku);
            uloz_vysledky(vysledky, pocet_vysledku);

            exit(0);
            break;
        }
        // Zrýchlenie alebo oneskorenie (riadenie času)
        // sleep(200); // Pauza medzi cyklami (200 ms)
    }

    return 0;
}