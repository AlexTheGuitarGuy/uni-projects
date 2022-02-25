#pragma once
#define MAX_STRLEN 20

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
