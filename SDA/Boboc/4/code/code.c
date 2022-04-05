#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes.h"

Node *inceput = NULL;

void introduce_sfarsit()
{
    Node *elem_nou = malloc(sizeof(Node));
    if (elem_nou == NULL)
    {
        exit(1);
    }
    elem_nou->next = NULL;

    if (inceput == NULL)
    {
        inceput = elem_nou;
        return;
    }

    Node *elem_curent = inceput;
    while (elem_curent->next != NULL)
    {
        elem_curent = elem_curent->next;
    }
    elem_curent->next = elem_nou;
}

void creare_lista()
{
    int i;
    printf("\nmarimea listei: ");
    if (!scanf("%d", &i))
    {
        printf("\nvaloare invalida.\n");
        return;
    }

    for (; i > 0; i--)
        introduce_sfarsit();
}

Film introduce_struct()
{
    Film in;
    printf("denumirea: ");
    scanf("%s", in.denumirea);
    printf("tara: ");
    scanf("%s", in.tara);
    printf("regizorul: ");
    scanf("%s", in.regizorul);
    printf("genul: ");
    scanf("%s", in.genul);
    printf("anul: ");
    scanf("%d", &in.anul);
    return in;
}

void introduce()
{
    int i = 0;
    for (Node *tmp = inceput; tmp != NULL; tmp = tmp->next, i++)
    {
        printf("\nstructura %d\n", i);
        tmp->data = introduce_struct();
    }
}

void afisare_struct(Film in)
{
    printf("\ndenumirea: ");
    printf("%s", in.denumirea);
    printf("\ntara: ");
    printf("%s", in.tara);
    printf("\nregizorul: ");
    printf("%s", in.regizorul);
    printf("\ngenul: ");
    printf("%s", in.genul);
    printf("\nanul: ");
    printf("%d", in.anul);
    printf("\n");
}

void afisare()
{
    int i = 0;
    for (Node *tmp = inceput; tmp != NULL; tmp = tmp->next, i++)
    {
        printf("\nstructura %d", i);
        afisare_struct(tmp->data);
    }
}

void cautare()
{
    int alegere;
    printf("\ncampuri disponibile:\n1.denumirea\n2.anul\n");
    printf("\ncampul cautat: ");
    if (!scanf("%d", &alegere) || alegere > 2 || alegere < 1)
    {
        printf("\nvaloare invalida.\n");
        return;
    }
    afisare();

    char cNume[20];
    int cAn;
    printf("\nvaloare cautata: ");
    switch (alegere)
    {
    case 1:
        if (!scanf("%s", cNume))
        {
            printf("\nvaloare invalida.\n");
            return;
        }
        break;
    case 2:
        if (!scanf("%d", &cAn))
        {
            printf("\nvaloare invalida.\n");
            return;
        }
        break;
    default:
        break;
    }

    int i = 0;
    for (Node *tmp = inceput; tmp != NULL; tmp = tmp->next, i++)
    {
        if ((alegere == 1 && strcmp(tmp->data.denumirea, cNume) == 0) ||
            (alegere == 2 && tmp->data.anul == cAn))
        {
            printf("\nfilmul %d", i);
            afisare_struct(tmp->data);
        }
    }
}

int numara()
{
    int n = 0;
    for (Node *elem_curent = inceput; elem_curent != NULL; elem_curent = elem_curent->next)
    {
        n++;
    }
    return n;
}

void modifica()
{
    afisare();
    printf("\nnumarul filmului care va fi modificat: ");
    int alegere;
    if (!scanf("%d", &alegere) || alegere >= numara() || alegere < 0)
    {
        printf("\nvaloare invalida.");
        return;
    }

    int i = 0;
    for (Node *tmp = inceput; tmp != NULL; tmp = tmp->next, i++)
    {
        if (i == alegere)
            tmp->data = introduce_struct();
    }
}

Node *ultima_adresa()
{
    Node *tmp = inceput;
    for (; tmp->next != NULL; tmp = tmp->next)
        ;
    return tmp;
}

Node *nod_la(int index)
{
    int i = 0;
    for (Node *tmp = inceput; tmp != NULL; tmp = tmp->next, i++)
    {
        if (i == index)
            return tmp;
    }
}

void interschimbare_struct(Node *primul, Node *al_doilea)
{
    Film tmp = primul->data;
    primul->data = al_doilea->data;
    al_doilea->data = tmp;
}

void interschimbare()
{
    int a, b;
    afisare();
    printf("\nstructurile care vor interschimbate: ");
    if (!scanf("%d %d", &a, &b) || a >= numara() || a < 0 || b >= numara() || b < 0)
    {
        printf("\nvaloare invalida.\n");
        return;
    }

    Node *primul = nod_la(a);
    Node *al_doilea = nod_la(b);
    interschimbare_struct(primul, al_doilea);
}

void sortare()
{
    int alegere;
    printf("\ncampuri disponibile:\n1.denumirea\n2.anul\n");
    printf("\ncampul sortat: ");
    if (!scanf("%d", &alegere) || alegere > 2 || alegere < 1)
    {
        printf("\nvaloare invalida.\n");
        return;
    }

    for (int i = 0; i < numara(); i++)
    {
        for (int j = i + 1; j < numara(); j++)
        {
            if ((strcmp(nod_la(i)->data.denumirea, nod_la(j)->data.denumirea) > 0 && alegere == 1) ||
                (nod_la(i)->data.anul < nod_la(j)->data.anul && alegere == 2))
            {
                interschimbare_struct(nod_la(i), nod_la(j));
            }
        }
    }
}

void eliberare()
{
    Node *elem_curent = inceput;
    while (elem_curent != NULL)
    {
        Node *tmp = elem_curent;
        elem_curent = elem_curent->next;
        free(tmp);
    }
    inceput = NULL;
}
