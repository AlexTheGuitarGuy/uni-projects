#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes.h"

Int_Node *root_int = NULL;

void insert_end_int(int data)
{
    Int_Node *new_Int_Node = malloc(sizeof(Int_Node));
    if (new_Int_Node == NULL)
    {
        exit(1);
    }
    new_Int_Node->next = NULL;
    new_Int_Node->data = data;

    if (root_int == NULL)
    {
        root_int = new_Int_Node;
        return;
    }

    Int_Node *curr = root_int;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_Int_Node;
}

void make_cycle_int()
{
    if (root_int == NULL)
    {
        return;
    }

    Int_Node *curr = root_int;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = root_int;
}

void create_int_list()
{

    int i;
    printf("marimea listei: ");
    scanf("%d", &i);
    int data;
    for (int j = 0; j < i; j++)
    {
        printf("datele elementului %d: ", j);
        scanf("%d", &data);
        insert_end_int(data);
    }
    make_cycle_int();
}

void show_int_list()
{
    Int_Node *tmp = root_int;
    for (; tmp->next != root_int; tmp = tmp->next)
    {
        printf("%d ", tmp->data);
    }
    printf("%d ", tmp->data);
}

int count_int()
{
    int c = 1;
    for (Int_Node *curr = root_int; curr->next != root_int; curr = curr->next)
    {
        c++;
    }
    return c;
}

Int_Node *get_int_node(int index)
{
    int i = 0;
    for (Int_Node *tmp = root_int; tmp->next != root_int; tmp = tmp->next, i++)
    {
        if (i == index)
            return tmp;
    }
}

int *toArr()
{
    int *res;
    res = (int *)malloc(count_int() * sizeof(int));
    int i = 0;
    Int_Node *curr;
    for (curr = root_int; curr->next != root_int; curr = curr->next, i++)
    {
        res[i] = curr->data;
    }
    res[i] = curr->data;
    return res;
}

void free_int_list()
{
    Int_Node *curr = root_int;
    while (curr != NULL)
    {
        Int_Node *aux = curr;
        curr = curr->next;
        free(aux);
    }
    root_int = NULL;
}
