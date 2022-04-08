#pragma once
#define MAX_STRLEN 20

typedef struct Int_Node
{
    int data;
    struct Int_Node *next;
} Int_Node;

void create_int_list();
void show_int_list();
int count_int();
Int_Node *get_int_node(int index);
void free_int_list();
int *toArr();

typedef struct Str_Node
{
    char data[MAX_STRLEN];
    struct Str_Node *next;
} Str_Node;

void int_to_str_list();
void show_str_list();
Str_Node *get_str_node(int index);
void free_str_list();
