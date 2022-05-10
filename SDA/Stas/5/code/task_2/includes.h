#pragma once
#define MAX_ARR_LEN 20
#define MAX_BUFFER_LEN 200

typedef struct Int_Node
{
    int data;
    struct Int_Node *prev;
    struct Int_Node *next;
} Int_Node;

typedef struct Str_Node
{
    char data[MAX_ARR_LEN];
    struct Str_Node *prev;
    struct Str_Node *next;
} Str_Node;

void int_create_list();
void int_show();
void int_free_list();
void replace();
