#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "includes.h"

Nod *radacina = NULL;

Film introduce_struct()
{
    Film in;
    printf("denumirea: ");
    scanf("%s", in.denumirea);
    printf("tara: ");
    scanf("%s", in.tara);
    printf("regizorul: ");
    scanf("%s", in.regizorul);
    printf("genul: ");
    scanf("%s", in.genul);
    printf("anul: ");
    scanf("%d", &in.anul);
    printf("\n");
    return in;
}

Nod *creareNod(Film valoare)
{
    Nod *rezultat = malloc(sizeof(Nod));
    if (rezultat != NULL)
    {
        rezultat->stanga = NULL;
        rezultat->dreapta = NULL;
        rezultat->valoare = valoare;
    }
    return rezultat;
}

bool introduceStruct(Nod **radacinaptr, Film valoare)
{
    Nod *radacina = *radacinaptr;

    if (radacina == NULL)
    {
        (*radacinaptr) = creareNod(valoare);
        return true;
    }

    if (strcmp(valoare.denumirea, radacina->valoare.denumirea) == 0)
        return false;

    if (strcmp(valoare.denumirea, radacina->valoare.denumirea) < 0)
        return introduceStruct(&(radacina->stanga), valoare);
    else
        return introduceStruct(&(radacina->dreapta), valoare);
}

int numarNoduri = 0;
void creareArbore()
{

    while (true)
    {
        Film in;
        printf("valoarea nodului %d:\n", numarNoduri);
        in = introduce_struct();

        if (!introduceStruct(&radacina, in))
            printf("valoarea data deja exista.\n");
        numarNoduri++;

        int alegere;
        printf("doriti sa mai introduceti o structura? (1/0) ");
        if (scanf("%d", &alegere) && alegere == 0)
            return;
        else if (alegere != 1)
            break;
    }
}

void afiseazaInserarea(int nivel)
{
    for (int i = 0; i < nivel; i++)
    {
        printf("\t");
    }
}

void show_struct(Film in, int nivel)
{
    afiseazaInserarea(nivel);
    printf("denumirea: ");
    printf("%s\n", in.denumirea);

    afiseazaInserarea(nivel);
    printf("tara: ");
    printf("%s\n", in.tara);

    afiseazaInserarea(nivel);
    printf("regizorul: ");
    printf("%s\n", in.regizorul);

    afiseazaInserarea(nivel);
    printf("genul: ");
    printf("%s\n", in.genul);

    afiseazaInserarea(nivel);
    printf("anul: ");
    printf("%d\n", in.anul);
}

void afisareArboreRec(Nod *radacina, int nivel)
{
    if (radacina == NULL)
    {
        afiseazaInserarea(nivel);
        printf("<empty>\n");
        return;
    }

    show_struct(radacina->valoare, nivel);

    afiseazaInserarea(nivel);
    printf("stanga\n");

    afisareArboreRec(radacina->stanga, nivel + 1);

    afiseazaInserarea(nivel);
    printf("dreapta\n");

    afisareArboreRec(radacina->dreapta, nivel + 1);

    afiseazaInserarea(nivel);
    printf("done\n");
}

void afisareArbore()
{
    afisareArboreRec(radacina, 0);
}

Nod *cautaStructuraRec(Nod *radacina, char *valoare)
{
    if (radacina == NULL)
        return NULL;
    if (strcmp(radacina->valoare.denumirea, valoare) == 0)
        return radacina;

    if (strcmp(valoare, radacina->valoare.denumirea) < 0)
        return cautaStructuraRec(radacina->stanga, valoare);
    else
        return cautaStructuraRec(radacina->dreapta, valoare);
}

Nod *cautaStructura(char *valoare)
{
    return cautaStructuraRec(radacina, valoare);
}

void modifica(char *valoare)
{
    Nod *modificare;

    modificare = cautaStructura(valoare);

    modificare->valoare = introduce_struct();
}

int numaraNoduriRec(Nod *radacina)
{
    int rezultat = 0;
    if (radacina->dreapta != NULL)
        rezultat += numaraNoduriRec(radacina->dreapta) + 1;
    if (radacina->stanga != NULL)
        rezultat += numaraNoduriRec(radacina->stanga) + 1;

    return rezultat;
}

int numaraNoduri()
{
    if (radacina != NULL)
        return numaraNoduriRec(radacina) + 1;
    else
        return 0;
}

int inaltimeaRec(Nod *radacina)
{
    int dreapta = 0, stanga = 0;
    if (radacina->dreapta != NULL)
        dreapta += inaltimeaRec(radacina->dreapta) + 1;
    if (radacina->stanga != NULL)
        stanga += inaltimeaRec(radacina->stanga) + 1;

    if (dreapta > stanga)
        return dreapta;
    else
        return stanga;
}

int inaltimea()
{
    if (radacina != NULL)
        return inaltimeaRec(radacina) + 1;
    else
        return 0;
}

void eliberareMemorieRec(Nod *radacina)
{
    if (!radacina)
        return;
    eliberareMemorieRec(radacina->dreapta);
    eliberareMemorieRec(radacina->stanga);

    free(radacina);
}

void eliberareMemorie()
{
    eliberareMemorieRec(radacina);
}