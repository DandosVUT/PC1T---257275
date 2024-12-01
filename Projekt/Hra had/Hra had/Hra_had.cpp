#include "Hra_had.h"
#include <cstdlib>
#include <ctime>
#include <fcntl.h>
#include <conio.h>
#include <windows.h>

#define VELIKOST_POLE 30
#define MAX_HRACU 10
#define MAX_JMENO 50

using namespace std;

int main()
{
    int hra;
    do
    {
        system("cls");
        int volba;
        printf("Vitejte ve hre HAD \n\n");
        printf("1. Zacit hrat \n");
        printf("2. Tabulka vysledku \n");

        printf("Vyberte si cislo: ");
        scanf_s("%d", &volba);

        struct Skore vysledky[MAX_HRACU];
        int pocet_vysledku = 0;
        nacti_vysledky(vysledky, &pocet_vysledku);

        if (volba == 2)
        {
            zobraz_vysledky(vysledky, pocet_vysledku);
        }
        else if (volba != 1)
        {
            printf("Neplatna volba, konec programu.\n");
            return 0;
        }
        else
        {
            char jmeno[MAX_JMENO];
            printf("Zadejte sve jmeno: ");
            scanf_s("%49s", jmeno, MAX_JMENO);

            int mapa[VELIKOST_POLE][VELIKOST_POLE];

            // Inicializácia hada
            struct had H;

            // Inicializácia hada do stredu hracieho poľa
            H.delka = 4;
            H.smer = 'V';
            H.skore = 0;
            int stred_x = VELIKOST_POLE / 2;
            int stred_y = VELIKOST_POLE / 2;

            for (int i = 0; i < H.delka; i++)
            {
                H.telo.x[i] = stred_x;
                H.telo.y[i] = stred_y - i;
                mapa[stred_x][stred_y - i] = 3; // 3 znamená telo hada
            }

            //inicializace ovoce
            aktualizuj_ovoce(mapa);

            // Hlavný herný cyklus
            while (true)
            {
                system("cls");
                hraci_pole(mapa, &H);
                vykresleni(mapa);

                // Správa vstupu hráča (zmena smeru pomocou WSAD)
                int vstup = getch(); // Načítanie klávesy zo vstupu (WSAD)
                if (vstup != 0)
                {
                    zmena_smeru(vstup, &H); // Zmena smeru hada podľa stlačenej klávesy
                }

                // Pohyb hada
                pohyb_hada(&H, mapa);

                // Kontrola prekazek a ukončenie hry, ak došlo ku kolízii
                if (kontrola_prekazky(mapa, &H) == 0)
                    break;

                Sleep(200); // Pauza medzi cyklami (200 ms)
            }

            printf("Game Over! Skore: %d\n", H.skore); // zaznamenava puvodni inicializai H.skore (respketive 0)

            const char* inputFilePath = "C:/Users/lewro/source/repos/DandosVUT/PC1T---257275/Projekt/Hra had/Hra had/vysledky.txt";

            if (pocet_vysledku < MAX_HRACU) {
                strcpy(vysledky[pocet_vysledku].jmeno, jmeno);
                vysledky[pocet_vysledku].skore = H.skore;
                pocet_vysledku++;
            }
            else if (H.skore > vysledky[MAX_HRACU - 1].skore) {
                strcpy(vysledky[MAX_HRACU - 1].jmeno, jmeno);
                vysledky[MAX_HRACU - 1].skore = H.skore;
            }

            serad_vysledky(vysledky, &pocet_vysledku);
            uloz_vysledky(vysledky, pocet_vysledku);
        }
        printf("\nchcete program spustit znovu?\n 1. Ano\n 2. Ne\n ");
        scanf_s("%d", &hra);

    } while (hra == 1);

    return 0;
}