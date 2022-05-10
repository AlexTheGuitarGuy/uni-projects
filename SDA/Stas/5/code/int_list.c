#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes.h"

Int_Node *int_root = NULL;

void int_insert_end()
{
    Int_Node *new_node = malloc(sizeof(Int_Node));
    if (new_node == NULL)
    {
        exit(1);
    }
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = rand();

    if (int_root == NULL)
    {
        int_root = new_node;
        return;
    }

    Int_Node *curr = int_root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->prev = curr;
}

void int_create_list()
{
    int i = MAX_LIST_LEN;
    for (; i > 0; i--)
        int_insert_end();
}

void int_show()
{
    Int_Node *tmp = int_root;
    for (; tmp->next != NULL; tmp = tmp->next)
    {
        printf("%d ", tmp->data);
    }
    printf("%d ", tmp->data);
}

int int_count()
{
    int c = 1;
    for (Int_Node *curr = int_root; curr->next != NULL; curr = curr->next)
    {
        c++;
    }
    return c;
}

Int_Node *int_get_node(int index)
{
    int i = 0;
    for (Int_Node *tmp = int_root; tmp->next != NULL; tmp = tmp->next, i++)
    {
        if (i == index)
            return tmp;
    }
}

int *to_arr()
{
    int *res;
    res = (int *)malloc(int_count() * sizeof(int));
    int i = 0;
    Int_Node *curr;
    for (curr = int_root; curr->next != NULL; curr = curr->next, i++)
        res[i] = curr->data;
    res[i] = curr->data;
    return res;
}

void int_free_list()
{
    Int_Node *curr = int_root;
    while (curr != NULL)
    {
        Int_Node *aux = curr;
        curr = curr->next;
        free(aux);
    }
    int_root = NULL;
}
