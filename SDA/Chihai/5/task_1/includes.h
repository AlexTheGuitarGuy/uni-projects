#pragma once
#define MAX_STRLEN 20

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void create_list();
void show();
int count();
Node *get_node(int index);
void find_extremes();
void get_extremes_interval();
void free_list();
