#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes.h"

Node *root = NULL;
int greatest = INT_MIN, lowest = INT_MAX;

void insert_end()
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
    }
    new_node->next = NULL;
    new_node->data = rand();

    if (root == NULL)
    {
        root = new_node;
        return;
    }

    Node *curr = root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

void make_cycle()
{
    if (root == NULL)
    {
        return;
    }

    Node *curr = root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = root;
}

void create_list()
{
    int i = 100;
    for (; i > 0; i--)
        insert_end();
    make_cycle();
}

void show()
{
    Node *tmp = root;
    for (; tmp->next != root; tmp = tmp->next)
    {
        printf("%d ", tmp->data);
    }
    printf("%d ", tmp->data);
}

int count()
{
    int c = 1;
    for (Node *curr = root; curr->next != root; curr = curr->next)
    {
        c++;
    }
    return c;
}

Node *get_node(int index)
{
    int i = 0;
    for (Node *tmp = root; tmp->next != root; tmp = tmp->next, i++)
    {
        if (i == index)
            return tmp;
    }
}

void find_extremes()
{
    Node *tmp = root;
    for (; tmp->next != root; tmp = tmp->next)
    {
        if (tmp->data > greatest)
            greatest = tmp->data;
        if (tmp->data < lowest)
            lowest = tmp->data;
    }

    printf("\nmaxim: %d \nminim: %d", greatest, lowest);
}

void get_extremes_interval()
{
    Node *tmp = root;
    for (; tmp->data != greatest; tmp = tmp->next)
        ;
    tmp = tmp->next;
    printf("\n");
    for (; tmp->data != lowest; tmp = tmp->next)
    {
        printf("%d ", tmp->data);
    }
}

void free_list()
{
    Node *curr = root;
    while (curr != NULL)
    {
        Node *aux = curr;
        curr = curr->next;
        free(aux);
    }
    root = NULL;
}
