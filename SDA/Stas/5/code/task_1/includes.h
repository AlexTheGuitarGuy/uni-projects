#pragma once
#define MAX_ARR_LEN 20
#define MAX_BUFFER_LEN 200
#define MAX_LIST_LEN 20

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
int int_count();
int *to_arr();
void int_free_list();

void str_create_list();
void str_show();
int str_count();
void str_free_list();
