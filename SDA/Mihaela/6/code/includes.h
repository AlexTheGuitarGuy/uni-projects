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
    Film value;
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
