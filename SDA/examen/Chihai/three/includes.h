#pragma once
#define MAX_STRLEN 20

typedef struct
{
    char marca[MAX_STRLEN];
    char tara[MAX_STRLEN];
    float pretul;
} Mobil;

typedef struct Node
{
    Mobil data;
    struct Node *next;
} Node;
