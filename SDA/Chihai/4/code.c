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

Disciplina introduce_struct()
{
    Disciplina in;
    printf("denumirea: ");
    scanf("%s", in.denumirea);
    printf("facultatea: ");
    scanf("%s", in.facultatea);
    printf("departamentul: ");
    scanf("%s", in.departamentul);
    printf("nr_ore: ");
    scanf("%d", &in.nr_ore);
    printf("anul: ");
    scanf("%d", &in.anul);
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

void show_struct(Disciplina in)
{
    printf("\ndenumirea: ");
    printf("%s", in.denumirea);
    printf("\nfacultatea: ");
    printf("%s", in.facultatea);
    printf("\ndepartamentul: ");
    printf("%s", in.departamentul);
    printf("\nnr_ore: ");
    printf("%d", in.nr_ore);
    printf("\nanul: ");
    printf("%d", in.anul);
    printf("\n");
}

void show()
{
    int i = 0;
    for (Node *tmp = root; tmp != NULL; tmp = tmp->next, i++)
    {
        printf("\nstructura %d", i);
        show_struct(tmp->data);
    }
}

void search()
{
    int choice;
    printf("\ncampuri disponibile:\n1.denumirea\n2.anul\n");
    printf("\ncampul cautat: ");
    if (!scanf("%d", &choice) || choice > 2 || choice < 1)
    {
        printf("\nvaloare invalida.\n");
        return;
    }
    show();

    char sName[MAX_STRLEN];
    int sYear;
    printf("\nvaloare cautata: ");
    switch (choice)
    {
    case 1:
        if (!scanf("%s", sName))
        {
            printf("\nvaloare invalida.\n");
            return;
        }
        break;
    case 2:
        if (!scanf("%d", &sYear))
        {
            printf("\nvaloare invalida.\n");
            return;
        }
        break;
    default:
        break;
    }

    int i = 0;
    for (Node *tmp = root; tmp != NULL; tmp = tmp->next, i++)
    {
        if ((choice == 1 && strcmp(tmp->data.denumirea, sName) == 0) ||
            (choice == 2 && tmp->data.anul == sYear))
        {
            printf("\nDisciplina %d", i);
            show_struct(tmp->data);
        }
    }
}

int count()
{
    int c = 0;
    for (Node *curr = root; curr != NULL; curr = curr->next)
    {
        c++;
    }
    return c;
}

void modify()
{
    show();
    printf("\nnumarul disciplinei care va fi modificat: ");
    int choice;
    if (!scanf("%d", &choice) || choice >= count() || choice < 0)
    {
        printf("\nvaloare invalida.");
        return;
    }

    int i = 0;
    for (Node *tmp = root; tmp != NULL; tmp = tmp->next, i++)
    {
        if (i == choice)
            tmp->data = introduce_struct();
    }
}

Node *get_last_address()
{
    Node *tmp = root;
    for (; tmp->next != NULL; tmp = tmp->next)
        ;
    return tmp;
}

Node *get_node(int index)
{
    int i = 0;
    for (Node *tmp = root; tmp != NULL; tmp = tmp->next, i++)
    {
        if (i == index)
            return tmp;
    }
}

void swap_struct(Node *first, Node *second)
{
    Disciplina tmp = first->data;
    first->data = second->data;
    second->data = tmp;
}

void swap()
{
    int a, b;
    show();
    printf("\nstructurile care vor interschimbate: ");
    if (!scanf("%d %d", &a, &b) || a >= count() || a < 0 || b >= count() || b < 0)
    {
        printf("\nvaloare invalida.\n");
        return;
    }

    Node *first = get_node(a);
    Node *second = get_node(b);
    swap_struct(first, second);
}

void sort()
{
    int choice;
    printf("\ncampuri disponibile:\n1.denumirea\n2.anul\n");
    printf("\ncampul sortat: ");
    if (!scanf("%d", &choice) || choice > 2 || choice < 1)
    {
        printf("\nvaloare invalida.\n");
        return;
    }

    Disciplina replace;
    for (int i = 0; i < count(); i++)
    {
        for (int j = i + 1; j < count(); j++)
        {

            if ((strcmp(get_node(i)->data.denumirea, get_node(j)->data.denumirea) > 0 && choice == 1) ||
                (get_node(i)->data.anul < get_node(j)->data.anul && choice == 2))
            {
                swap_struct(get_node(i), get_node(j));
            }
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
