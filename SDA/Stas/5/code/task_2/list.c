#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes.h"

Int_Node *int_root = NULL;

void int_insert_end(Int_Node **int_root, int value)
{
    Int_Node *new_node = malloc(sizeof(Int_Node));
    if (new_node == NULL)
    {
        exit(1);
    }
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = value;

    if (*int_root == NULL)
    {
        *int_root = new_node;
        return;
    }

    Int_Node *curr = *int_root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->prev = curr;
}

void int_create_list()
{
    int i;
    printf("lungimea listei: ");
    scanf("%d", &i);
    printf("insert %d values:\n", i);
    for (; i > 0; i--)
    {
        int value;
        scanf("%d", &value);
        int_insert_end(&int_root, value);
    }
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

int int_count(Int_Node **int_root)
{
    int c = 1;
    for (Int_Node *curr = *int_root; curr->next != NULL; curr = curr->next)
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

void insertStart(Int_Node **head, int data)
{

    Int_Node *newNode = (Int_Node *)malloc(sizeof(Int_Node));

    newNode->data = data;
    newNode->next = *head;

    *head = newNode;
}

void insertLast(Int_Node **head, int data)
{

    Int_Node *newNode = (Int_Node *)malloc(sizeof(Int_Node));

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Int_Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insert(int pos, int data, Int_Node **head)
{
    int size = int_count(head);

    if (pos == 0)
    {
        insertStart(head, data);
    }
    else if (size < pos)
    {
        insertLast(head, data);
    }
    else
    {
        Int_Node *temp = *head;
        Int_Node *newNode = (Int_Node *)
            malloc(sizeof(Int_Node));
        newNode->data = data;
        newNode->next = NULL;

        while (--pos)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;

        temp->next = newNode;
     }
}

void deleteNode(Int_Node *root, int index)
{
    Int_Node *temp = root;

    if (index == 0)
        root = root->next;
    else if (index >= int_count(&root))
    {

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
    else
    {
        for (int i = 2; i < index; i++)
        {
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
        }

        temp->next = temp->next->next;
    }
}

void replace_params(int from, Int_Node *to)
{
    int i = 0;
    for (Int_Node *curr = int_root; curr != NULL; curr = curr->next, i++)
    {
        if (from == curr->data)
        {
            Int_Node *tmp = to;
            for (int j = 0; j < int_count(&to); j++, i++, tmp = tmp->next)
                insert(i, tmp->data, &int_root);

            deleteNode(int_root, i + 1);
            i--;
        }
    }
}

void replace()
{
    int from;
    printf("valoarea inlocuita: ");
    scanf("%d", &from);

    Int_Node *to;
    int len;
    printf("lungimea listei cu care se va inlocui: ");
    scanf("%d", &len);

    printf("insert %d values:\n", len);
    for (int i = 0; i < len; i++)
    {
        int value;
        scanf("%d", &value);
        int_insert_end(&to, value);
    }

    replace_params(from, to);
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
