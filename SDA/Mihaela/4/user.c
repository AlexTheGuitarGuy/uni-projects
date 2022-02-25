#include <stdio.h>
#include "includes.h"

void show_options()
{
    printf("\nMeniu\n");
    printf("1. Crearea listei in memoria dinamica.\n");
    printf("2. Introducerea informatiei despre elementele listei de la tastatura.\n");
    printf("3. Afisarea informatiei despre elementele listei la ecran.\n");
    printf("4. Cautarea elementului in lista.\n");
    printf("5. Modificarea campurilor unui element din lista.\n");
    printf("6. Determinarea adresei ultimului element din lista.\n");
    printf("7. Determinarea lungimii listei (numarul de elemente).\n");
    printf("8. Interschimbarea a doua elemente indicate in lista.\n");
    printf("9. Sortarea listei.\n");
    printf("10. Eliberarea memoriei alocate pentru lista.\n");
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
    case 4:
        search();
        break;
    case 5:
        modify();
        break;
    case 6:
        printf("\nadresa ultimului element: %p\n", get_last_address());
        break;
    case 7:
        printf("\n%d elemente se afla in lista.\n", count());
        break;
    case 8:
        swap();
        break;
    case 9:
        sort();
        break;
    case 10:
        free_list();
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
