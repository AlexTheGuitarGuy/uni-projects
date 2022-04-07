#include <stdio.h>
#include <stdlib.h>

typedef struct Coada
{
    int coada[100];
    int sfarsit;
    int inceput;
} Coada;

void adauga(Coada *in, int element)
{
    if (in->sfarsit == 100 - 1)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        if (in->inceput == -1)
            in->inceput = 0;

        in->sfarsit++;
        in->coada[in->sfarsit] = element;
    }
}

void construieste_coada(Coada *in)
{
    in->inceput = -1;
    in->sfarsit = -1;
}

void afiseaza(Coada in)
{
    if (in.inceput == -1)
        printf("Empty queue\n");
    else
    {
        printf("Coada: \n");
        for (int i = in.inceput; i <= in.sfarsit; i++)
            printf("%d ", in.coada[i]);
        printf("\n");
    }
}

int main()
{
    Coada in;
    construieste_coada(&in);

    Coada out;
    construieste_coada(&out);

    adauga(&in, 1);
    adauga(&in, 2);
    adauga(&in, 3);
    adauga(&in, 4);
    adauga(&in, 5);
    adauga(&in, 6);
    adauga(&in, 7);
    adauga(&in, 8);
    adauga(&in, 9);
    adauga(&in, 10);

    int n;
    printf("Numarul n: ");
    if (!scanf("%d", &n) || n <= 0)
    {
        printf("valoare invalida.");
        return 1;
    }
    for (int i = 0; i <= in.sfarsit; i++)
    {
        if ((i + 1) % n != 0)
            adauga(&out, in.coada[i]);
    }

    afiseaza(out);

    return 0;
}
