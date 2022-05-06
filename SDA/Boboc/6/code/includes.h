#pragma once

typedef struct Film
{
    char denumirea[20];
    char tara[20];
    char regizorul[20];
    char genul[20];
    int anul;
} Film;

typedef struct Nod
{
    Film valoare;
    struct Nod *stanga;
    struct Nod *dreapta;
} Nod;

void creareArbore();
void afisareArbore();
Nod *cautaStructura(char *valoare);
void modifica(char *valoare);
int numaraNoduri();
int inaltimea();
void eliberareMemorie();
