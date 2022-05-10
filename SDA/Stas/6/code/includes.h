#pragma once
#define MAX_STRLEN 20

typedef struct
{
    char adresa[MAX_STRLEN];
    char telefonul[MAX_STRLEN];
    float suprafata;
    int nr_odai;
    float costul;
} Casa;

typedef struct Node
{
    Casa value;
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
