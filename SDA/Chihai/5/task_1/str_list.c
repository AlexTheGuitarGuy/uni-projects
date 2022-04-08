#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes.h"

Str_Node *root_str = NULL;

int arr_to_int(int *array, int len)
{
    int i, k = 0;
    for (i = 0; i < len; i++)
        k = 10 * k + array[i];
    return k;
}

char *toBinStr(int n)
{
    int a[100], i;

    for (i = 0; n > 0; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }
    int *binArr = (int *)malloc(100 * sizeof(int));
    int j = 0;
    for (i = i - 1; i >= 0; i--, j++)
    {
        binArr[j] = a[i];
    }
    /*for (int i = 0; i < j; i++)
    {
        printf("%d", binArr[i]);
    }
    printf("\n");*/
    int binInt = arr_to_int(binArr, j);
    // printf("%d\n", binInt);
    char *res = (char *)malloc(100 * sizeof(char));
    itoa(binInt, res, 10);
    return res;
}

void insert_end_str(char *data)
{
    Str_Node *new_str_node = malloc(sizeof(Str_Node));
    if (new_str_node == NULL)
    {
        exit(1);
    }
    new_str_node->next = NULL;
    strcpy(new_str_node->data, data);

    if (root_str == NULL)
    {
        root_str = new_str_node;
        return;
    }

    Str_Node *curr = root_str;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_str_node;
}

void make_cycle_str()
{
    if (root_str == NULL)
    {
        return;
    }

    Str_Node *curr = root_str;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = root_str;
}

void int_to_str_list(int *in, int len)
{
    for (int j = 0; j < len; j++)
    {
        // printf("%d: %s\n", in[j], toBinStr(in[j]));
        insert_end_str(toBinStr(in[j]));
    }
    make_cycle_str();
}

void show_str_list()
{
    Str_Node *tmp = root_str;
    for (; tmp->next != root_str; tmp = tmp->next)
    {
        printf("%s ", tmp->data);
    }
    printf("%s ", tmp->data);
}

int count_str()
{
    int c = 1;
    for (Str_Node *curr = root_str; curr->next != root_str; curr = curr->next)
    {
        c++;
    }
    return c;
}

Str_Node *get_str_node(int index)
{
    int i = 0;
    for (Str_Node *tmp = root_str; tmp->next != root_str; tmp = tmp->next, i++)
    {
        if (i == index)
            return tmp;
    }
}

void free_str_list()
{
    Str_Node *curr = root_str;
    while (curr != NULL)
    {
        Str_Node *aux = curr;
        curr = curr->next;
        free(aux);
    }
    root_str = NULL;
}
