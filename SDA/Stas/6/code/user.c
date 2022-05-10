#include <stdio.h>
#include <stdbool.h>
#include "includes.h"

void show_options()
{
    printf("\nMeniu\n");
    printf("1. Crearea nodurilor arborelui binar oarecare\n   in memoria dinamica si introducerea informatiei\n   despre nodurile arborelui de la tastatura in mod interactiv.\n");
    printf("2. Afisarea informatiei despre nodurile arborelui la ecran\n");
    printf("3. Cautarea nodului in arbore.\n");
    printf("4. Modificarea informatiei unui nod din arbore.\n");
    printf("5. Determinarea numarului de noduri.\n");
    printf("6. Determinarea inaltimii arborelui.\n");
    printf("7. Eliberarea memoriei alocate pentru lista.\n");
    printf("0. Iesire din program.\n");
}

int handle_options(int in)
{

    switch (in)
    {
    case 1:
        createTree();
        break;
    case 2:
        printTree();
        break;
    case 3:
        char find[MAX_STRLEN];
        printf("modelul elementului cautat: ");
        if (scanf("%s", find))
        {
            Node *res = findStruct(find);
            if (res == NULL)
                printf("elementul cautat nu se afla in arbore.\n");
            else
                printf("elementul este prezent la adresa %p.\n", res);
        }
        else
            printf("valoare invalida.");
        break;
    case 4:
        char choice[MAX_STRLEN];
        printf("adresa elementului schimbat: ");
        if (scanf("%s", choice))
            modify(choice);
        break;
    case 5:
        printf("arborele dat are %d noduri.\n", countNodes());
        break;
    case 6:
        printf("arborele dat are intaltimea de %d.\n", height());
        break;
    case 7:
        freeTree();
        break;
    case 0:
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
