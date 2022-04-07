#pragma once
#define MAX_STRLEN 20

typedef struct Disciplina
{
    char denumirea[20];
    char facultatea[20];
    char departamentul[20];
    int nr_ore;
    int anul;
} Disciplina;

typedef struct Node
{
    Disciplina data;
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
