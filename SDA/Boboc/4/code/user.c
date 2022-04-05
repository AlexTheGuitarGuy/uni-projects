#include <stdio.h>
#include "includes.h"

void afisare_options()
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
    printf("9. Sortarearea listei.\n");
    printf("10. Eliberarea memoriei alocate pentru lista.\n");
    printf("0. Iesire din program.\n");
}

int handle_options(int in)
{
    int alegere;
    switch (in)
    {
    case 1:
        creare_lista();
        break;
    case 2:
        introduce();
        break;
    case 3:
        afisare();
        break;
    case 4:
        cautare();
        break;
    case 5:
        modifica();
        break;
    case 6:
        printf("\nadresa ultimului element: %p\n", ultima_adresa());
        break;
    case 7:
        printf("\n%d elemente se afla in lista.\n", numara());
        break;
    case 8:
        interschimbare();
        break;
    case 9:
        sortare();
        break;
    case 10:
        eliberare();
        break;
    case 0:
        eliberare();
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
        afisare_options();
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
