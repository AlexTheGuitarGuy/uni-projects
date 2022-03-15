#pragma once
#define MAX_STRLEN 20

typedef struct
{
    char modelul[MAX_STRLEN];
    char procesorul[MAX_STRLEN];
    float memoria;
    float viteza;
    float pretul;
} Computer;

typedef struct Node
{
    Computer data;
    struct Node *next;
} Node;

void create_list();
void introduce();
void show();
void search();
void modify();
Node *get_last_address();
int count();
void swap();
void sort();
void free_list();
