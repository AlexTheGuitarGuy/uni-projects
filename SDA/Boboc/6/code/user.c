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
        creareArbore();
        break;
    case 2:
        afisareArbore();
        break;
    case 3:
        char cautare[20];
        printf("denumirea elementului cautat: ");
        if (scanf("%s", cautare))
        {
            Nod *res = cautaStructura(cautare);
            if (res == NULL)
                printf("elementul cautat nu se afla in arbore.\n");
            else
                printf("elementul este prezent la adresa %p.\n", res);
        }
        else
            printf("valoare invalida.");
        break;
    case 4:
        char alegere[20];
        printf("denumirea elementului schimbat: ");
        if (scanf("%s", alegere))
            modifica(alegere);
        break;
    case 5:
        printf("arborele dat are %d noduri.\n", numaraNoduri());
        break;
    case 6:
        printf("arborele dat are intaltimea de %d.\n", inaltimea());
        break;
    case 7:
        eliberareMemorie();
        break;
    case 0:
        return 1;
    default:
        printf("Valoarea %d nu exista in meniul de optiuni, introduceti o alta valoare.\n", in);
    }

    return (1);
}

int main()
{

    int in;

    do
    {
        show_options();
        printf("\nCe operatiune doriti sa efectuati?\n");

        if (!scanf("%d", &in))
        {
            printf("\nvaloare invalida.\n");
            return (1);
        }
        else if (!handle_options(in))
        {
            return (1);
        }

    } while (in != 0);

    return (0);
}
