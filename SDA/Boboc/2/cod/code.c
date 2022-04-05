#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char denumirea[20];
    char tara[20];
    char regizorul[20];
    float genul[20];
    int anul;
} Film;

void afisareOptiuni()
{
    printf("\nMeniu:\n");
    printf("1. Crearea unui fisier binar nou, introducerea campurilor structurilor de la tastatura si inscrierea lor in acest fisier.\n");
    printf("2. Afisarea elementelor fisierului binar la ecran.\n");
    printf("3. Adaugarea unei structuri noi la sfarsit de fisier.\n");
    printf("4. Modificarea unei structuri a fisierului.\n");
    printf("5. Cautarea dupa un camp al structurii in fisier.\n");
    printf("6. Sortarea structurilor fisierului dupa un careva camp.\n");
    printf("7. Emaximinarea unei structuri din fisier.\n");
    printf("8. Stergerea fisierului de pe disc (la dorinta)\n");
    printf("0. Iesire din program.\n");
}

void afisareStructura(Film in)
{
    printf("\ndenumirea: ");
    printf("%s", in.denumirea);
    printf("\ntara: ");
    printf("%s", in.tara);
    printf("\nregizorul: ");
    printf("%s", in.regizorul);
    printf("\ngenul: ");
    printf("%s", in.genul);
    printf("\nanul: ");
    printf("%d", in.anul);
    printf("\n");
}

void introducereStructura(Film *in)
{
    printf("denumirea: ");
    scanf("%s", in->denumirea);
    printf("tara: ");
    scanf("%s", in->tara);
    printf("regizorul: ");
    scanf("%s", in->regizorul);
    printf("genul: ");
    scanf("%s", in->genul);
    printf("anul: ");
    scanf("%d", &in->anul);
}

void creare()
{
    Film tmp;

    FILE *rezultat;
    int maxim;
    printf("Numarul de filme: ");
    if (!scanf("%d", &maxim))
    {
        printf("\nvaloare invalida.\n");
        fclose(rezultat);
        return;
    }

    fopen_s(&rezultat, "filme.bin", "wb");
    if (rezultat == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru scriere.");
        fclose(rezultat);
        return;
    }

    size_t elemente_scrise = 0;
    elemente_scrise += fwrite(&maxim, sizeof(int), 1, rezultat);
    for (int i = 0; i < maxim; i++)
    {
        printf("\nFilmul %d\n", i);
        introducereStructura(&tmp);
        elemente_scrise += fwrite(&tmp, sizeof(Film), 1, rezultat);
    }
    fclose(rezultat);
    if (elemente_scrise == 0)
    {
        printf("s-a produs o eroare in procesul de scriere a datelor.");
        return;
    }
}

void afisare()
{
    Film tmp;
    FILE *intrare;
    fopen_s(&intrare, "filme.bin", "rb");
    if (intrare == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire.");
        fclose(intrare);
        return;
    }

    int maxim;
    size_t elemente_citite = 0;
    elemente_citite += fread(&maxim, sizeof(int), 1, intrare);
    elemente_citite += fread(&tmp, sizeof(Film), 1, intrare);
    for (int i = 0; !feof(intrare); i++)
    {
        printf("\nFilmul %d", i);
        afisareStructura(tmp);
        elemente_citite += fread(&tmp, sizeof(Film), 1, intrare);
    }
    fclose(intrare);
    if (elemente_citite == 0)
    {
        printf("s-a produs o eroare in procesul de citire a datelor.");
        return;
    }
}

void adaugare()
{
    FILE *f;
    fopen_s(&f, "filme.bin", "rb+");
    if (f == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire si scriere.");
        fclose(f);
        return;
    }

    int maxim;
    size_t elemente_citite = 0;
    size_t elemente_scrise = 0;
    fseek(f, 0, SEEK_SET);
    elemente_citite += fread(&maxim, sizeof(int), 1, f);
    if (elemente_citite == 0)
    {
        printf("s-a produs o eroare in procesul de citire a datelor.");
        fclose(f);
        return;
    }
    maxim++;
    fseek(f, 0, SEEK_SET);
    elemente_scrise += fwrite(&maxim, sizeof(int), 1, f);

    Film tmp;
    introducereStructura(&tmp);
    fseek(f, 0, SEEK_END);
    elemente_scrise += fwrite(&tmp, sizeof(Film), 1, f);

    fclose(f);
    if (elemente_scrise == 0)
    {
        printf("s-a produs o eroare in procesul de scriere a datelor.");
        return;
    }
}

void modificare()
{
    afisare();
    FILE *f;
    fopen_s(&f, "filme.bin", "rb+");
    if (f == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire si scriere.");
        fclose(f);
        return;
    }
    int maxim;
    fread(&maxim, sizeof(int), 1, f);
    printf("\nnumarul filmului care va fi modificat: ");
    int alegere;
    if (!scanf("%d", &alegere) || alegere >= maxim)
    {
        printf("\bvaloare invalida.");
        fclose(f);
        return;
    }

    size_t elemente_scrise = 0;
    Film tmp;
    introducereStructura(&tmp);
    fseek(f, (sizeof(Film) * alegere + sizeof(int)), SEEK_SET);
    elemente_scrise += fwrite(&tmp, sizeof(Film), 1, f);

    fclose(f);
    if (elemente_scrise == 0)
    {
        printf("s-a produs o eroare in procesul de scriere a datelor.");
        return;
    }
}

void cautare()
{
    Film tmp;
    FILE *intrare;
    fopen_s(&intrare, "filme.bin", "rb");
    if (intrare == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire.");
        fclose(intrare);
        return;
    }

    int alegere;
    printf("\ncampuri disponibile:\n1.denumirea\n2.anul\n");
    printf("\ncampul cautat: ");
    if (!scanf("%d", &alegere) || alegere > 2 || alegere < 1)
    {
        printf("\nvaloare invalida.\n");
        fclose(intrare);
        return;
    }
    afisare();

    char cNume[20];
    int cAn;
    printf("\nvaloare cautata: ");
    switch (alegere)
    {
    case 1:
        if (!scanf("%s", cNume))
        {
            printf("\nvaloare invalida.\n");
            fclose(intrare);
            return;
        }
        break;
    case 2:
        if (!scanf("%d", &cAn))
        {
            printf("\nvaloare invalida.\n");
            fclose(intrare);
            return;
        }
        break;
    default:
        break;
    }

    int maxim;
    size_t elemente_citite = 0;
    elemente_citite += fread(&maxim, sizeof(int), 1, intrare);
    elemente_citite += fread(&tmp, sizeof(Film), 1, intrare);
    for (int i = 0; !feof(intrare); i++)
    {
        if (alegere == 1 && strcmp(tmp.denumirea, cNume) == 0)
        {
            printf("\nFilmul %d", i);
            afisareStructura(tmp);
        }
        else if (alegere == 2 && tmp.anul == cAn)
        {
            printf("\nFilmul %d", i);
            afisareStructura(tmp);
        }
        elemente_citite += fread(&tmp, sizeof(Film), 1, intrare);
    }
    fclose(intrare);
    if (elemente_citite == 0)
    {
        printf("s-a produs o eroare in procesul de citire a datelor.");
        return;
    }
}

void scrieLaIndex(Film in, int i)
{
    FILE *f;
    fopen_s(&f, "filme.bin", "rb+");
    if (f == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire si scriere.");
        fclose(f);
        return;
    }

    size_t elemente_scrise = 0;
    fseek(f, (sizeof(Film) * i + sizeof(int)), SEEK_SET);
    elemente_scrise += fwrite(&in, sizeof(Film), 1, f);

    fclose(f);
    if (elemente_scrise == 0)
    {
        printf("s-a produs o eroare in procesul de scriere a datelor.");
        return;
    }
}

void sortare()
{
    FILE *in;
    fopen_s(&in, "filme.bin", "rb");
    if (in == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire.");
        fclose(in);
        return;
    }

    int alegere;
    printf("\ncampuri disponibile:\n1.denumirea\n2.anul\n");
    printf("\ncampul sortat: ");
    if (!scanf("%d", &alegere) || alegere > 2 || alegere < 0)
    {
        printf("\nvaloare invalida.\n");
        fclose(in);
        return;
    }

    int maxim;
    size_t elemente_citite = 0;
    elemente_citite += fread(&maxim, sizeof(int), 1, in);
    Film tmp[maxim];
    for (int i = 0; !feof(in); i++)
    {
        elemente_citite += fread(&tmp[i], sizeof(Film), 1, in);
    }
    fclose(in);
    if (elemente_citite == 0)
    {
        printf("s-a produs o eroare in procesul de citire a datelor.");
        return;
    }

    Film inlocuieste;
    for (int i = 0; i < maxim; i++)
    {
        for (int j = i + 1; j < maxim; j++)
        {

            if ((strcmp(tmp[i].denumirea, tmp[j].denumirea) > 0 && alegere == 1) ||
                (tmp[i].anul < tmp[j].anul && alegere == 2))
            {
                inlocuieste = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = inlocuieste;
                scrieLaIndex(tmp[i], i);
                scrieLaIndex(tmp[j], j);
            }
        }
    }
}

void stergere()
{
    FILE *de_la;
    fopen_s(&de_la, "filme.bin", "rb");
    if (de_la == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire si scriere.");
        fclose(de_la);
        return;
    }

    int maxim;
    size_t elemente_citite = 0;
    fseek(de_la, 0, SEEK_SET);
    elemente_citite += fread(&maxim, sizeof(int), 1, de_la);

    Film tmp[maxim];
    for (int i = 0; !feof(de_la); i++)
    {
        elemente_citite += fread(&tmp[i], sizeof(Film), 1, de_la);
    }

    fclose(de_la);
    if (elemente_citite == 0)
    {
        printf("s-a produs o eroare in procesul de citire a datelor.");
        return;
    }

    afisare();
    printf("\nnumarul filmului care va fi sters: ");
    int alegere;
    if (!scanf("%d", &alegere) || alegere >= maxim)
    {
        printf("\bvaloare invalida.");
        return;
    }

    FILE *pana_la;
    fopen_s(&pana_la, "tmp.bin", "wb");
    if (pana_la == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire si scriere.");
        fclose(pana_la);
        return;
    }

    maxim--;
    size_t elemente_scrise = 0;
    elemente_scrise += fwrite(&maxim, sizeof(int), 1, pana_la);
    for (int i = 0; i < maxim + 1; i++)
    {
        if (i != alegere)
            elemente_scrise += fwrite(&tmp[i], sizeof(Film), 1, pana_la);
    }

    fclose(pana_la);
    if (elemente_scrise == 0)
    {
        printf("s-a produs o eroare in procesul de scriere a datelor.");
        return;
    }

    remove("filme.bin");
    rename("tmp.bin", "filme.bin");
}

int alegereOptiune(int in)
{
    int alegere;
    switch (in)
    {
    case 1:
        printf("\ntoate datele aflate acum pe fisier vor fi sterse. sunteti sigur? (1/0) ");

        if (!scanf("%d", &alegere) || (alegere != 0 && alegere != 1))
        {
            printf("\nvaloare invalida.\n");
        }
        else if (alegere == 1)
            creare();
        break;
    case 2:
        afisare();
        break;
    case 3:
        adaugare();
        break;
    case 4:
        modificare();
        break;
    case 5:
        cautare();
        break;
    case 6:
        sortare();
        break;
    case 7:
        stergere();
        break;
    case 8:
        printf("\ntoate datele aflate acum pe fisier vor fi sterse. sunteti sigur? (1/0) ");
        if (!scanf("%d", &alegere) || (alegere != 0 && alegere != 1))
        {
            printf("\nvaloare invalida.\n");
        }
        else if (alegere == 1)
            remove("filme.bin");
        break;
    case 0:
        return 1;
    default:
        printf("Valoarea %d nu exista in meniul de optiuni, introduceti o alta valoare.\n", in);
    }

    return (1);
}

int main()
{
    int alegere;

    do
    {
        afisareOptiuni();
        printf("\nCe operatiune doriti sa efectuati?\n");

        if (!scanf("%d", &alegere))
        {
            printf("\nvaloare invalida.\n");
            return (1);
        }
        else if (!alegereOptiune(alegere))
        {
            return (1);
        }

    } while (alegere != 0);

    return (0);
}
