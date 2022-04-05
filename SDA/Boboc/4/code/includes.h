#pragma once

typedef struct Film
{
    char denumirea[20];
    char tara[20];
    char regizorul[20];
    char genul[20];
    int anul;
} Film;

typedef struct Node
{
    Film data;
    struct Node *next;
} Node;

void creare_lista();
void introduce();
void afisare();
void cautare();
void modifica();
Node *ultima_adresa();
int numara();
void interschimbare();
void sortare();
void eliberare();
