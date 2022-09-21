#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes.h"

Node *root = NULL;

void insert_end()
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
    }
    new_node->next = NULL;

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

void create_list()
{
    int i;
    printf("\nmarimea listei: ");
    if (!scanf("%d", &i))
    {
        printf("\nvaloare invalida.\n");
        return;
    }

    for (; i > 0; i--)
        insert_end();
}

Mobil introduce_struct()
{
    Mobil in;
    printf("marca: ");
    scanf("%s", in.marca);
    printf("tara: ");
    scanf("%s", in.tara);
    printf("pretul: ");
    scanf("%f", &in.pretul);
    return in;
}

void introduce()
{
    int i = 0;
    for (Node *tmp = root; tmp != NULL; tmp = tmp->next, i++)
    {
        printf("\nstructura %d\n", i);
        tmp->data = introduce_struct();
    }
}

void show_struct(Mobil in)
{
    printf("\nmarca: ");
    printf("%s", in.marca);
    printf("\ntara: ");
    printf("%s", in.tara);
    printf("\npretul: ");
    printf("%f", in.pretul);
    printf("\n");
}

void show()
{
    int i = 0;
    for (Node *tmp = root; tmp != NULL; tmp = tmp->next, i++)
    {
        if (strcmp(tmp->data.tara, "China") == 0)
        {
            printf("\nstructura %d", i);
            show_struct(tmp->data);
        }
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

void show_options()
{
    printf("\nMeniu\n");
    printf("1. Crearea listei in memoria dinamica.\n");
    printf("2. Introducerea informatiei despre elementele listei de la tastatura.\n");
    printf("3. Afisarea informatiei despre elementele create in China la ecran.\n");
    printf("0. Iesire din program.\n");
}

int handle_options(int in)
{
    int choice;
    switch (in)
    {
    case 1:
        create_list();
        break;
    case 2:
        introduce();
        break;
    case 3:
        show();
        break;
    case 0:
        free_list();
        return 1;
    default:
        printf("Valoarea %d nu exista in meniul de optiuni, introduceti o alta valoare.\n", in);
    }

    return (1);
}

int handle_input()
{
    int in;

    do
    {
        show_options();
        printf("\nCe operatiune doriti sa efectuati?\n");

        if (!scanf("%d", &in))
        {
            printf("\nvaloare invalida.\n");
            return (0);
        }
        else if (!handle_options(in))
        {
            return (0);
        }

    } while (in != 0);

    return (1);
}

int main()
{

    if (!handle_input())
    {
        return (1);
    }

    return (0);
}
