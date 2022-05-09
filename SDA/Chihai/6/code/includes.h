#pragma once

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
    Disciplina value;
    struct Node *left;
    struct Node *right;
} Node;

void createTree();
void printTree();
Node *findStruct(char *value);
void modify(char *value);
int countNodes();
int height();
void freeTree();
