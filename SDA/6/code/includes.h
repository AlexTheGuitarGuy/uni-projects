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
    Computer value;
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
