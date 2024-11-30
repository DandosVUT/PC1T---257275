#include "struktury.cpp"
#include <cstdlib>
#include <ctime>
#include <termios.h>

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

    printf("Vyberte si číslo: ");
    scanf("%d", &volba);
    getchar(); // Remove newline from input buffer

    Skore vysledky[MAX_HRACU];
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
    H.delka = 4;
    H.smer = 'V'; // Východ
    H.skore = 0;
    for (int i = 0; i < H.delka; i++)
    {
        H.telo.x[i] = VELIKOST_POLE / 2;
        H.telo.y[i] = (VELIKOST_POLE / 2) - i;
    }

    // Inicializácia hry
    srand(static_cast<unsigned>(time(0))); // Inicializácia generátora náhodných čísel

    // Hlavný herný cyklus
    while (true)
    {
        // system("cls"); // Vyčistenie obrazovky (pre Windows)
        hraci_pole(mapa, &H);
        vykresleni(mapa);

        // Správa vstupu hráča (zmena smeru pomocou WSAD)
        char vstup = getchar(); // Načítanie znaku zo vstupu
        switch (vstup)
        {
        case 'w':
            zmena_smeru(0, H);
            break; // Sever
        case 's':
            zmena_smeru(1, H);
            break; // Juh
        case 'a':
            zmena_smeru(2, H);
            break; // Západ
        case 'd':
            zmena_smeru(3, H);
            break; // Východ
        }

        // Pohyb hada a kontrola prekážok
        pohyb_hada(&H, mapa);

        // Ukončenie hry, ak došlo ku kolízii
        if (kontrola_prekazky(mapa, &H)) 
        {
            printf("Game Over! Skore: %d\n", H.skore);

            char jmeno[MAX_JMENO];
            printf("Zadejte sve jmeno: ");
            scanf("%49s", jmeno);

            if (pocet_vysledku < MAX_HRACU) {
                strcpy(vysledky[pocet_vysledku].jmeno, jmeno);
                vysledky[pocet_vysledku].skore = H.skore;
                pocet_vysledku++;
            } else if (H.skore > vysledky[MAX_HRACU - 1].skore) {
                strcpy(vysledky[MAX_HRACU - 1].jmeno, jmeno);
                vysledky[MAX_HRACU - 1].skore = H.skore;
            }

            serad_vysledky(vysledky, &pocet_vysledku);
            uloz_vysledky(vysledky, pocet_vysledku);

            break;
        }
        // Zrýchlenie alebo oneskorenie (riadenie času)
        // sleep(200); // Pauza medzi cyklami (200 ms)
    }

    return 0;
}