#include <stdio.h>
#include <stdlib.h>

typedef struct Coada
{
    int coada[100];
    int sfarsit;
    int inceput;
} Coada;

int de_la_array_la_int(int *array, int lungime)
{
    int rezultat = 0;
    for (int i = 0; i < lungime; i++)
    {
        rezultat += array[i];
        rezultat *= 10;
    }
    rezultat /= 10;
    return rezultat;
}

int reprezentare_binara(int n)
{
    int a[100], i;

    for (i = 0; n > 0; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }
    int *res = (int *)malloc(100 * sizeof(int));
    int j = 0;
    for (i = i - 1; i >= 0; i--, j++)
    {
        res[j] = a[i];
    }

    return de_la_array_la_int(res, j);
}

void adauga(Coada *in, int element)
{
    if (in->sfarsit == 100 - 1)
    {
        printf("Overflow \n");
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
        printf("Empty queue \n");
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

    adauga(&in, 6);
    adauga(&in, 5);
    adauga(&in, 10);

    for (int i = in.sfarsit; i >= 0; i--)
    {
        adauga(&out, reprezentare_binara(in.coada[i]));
    }

    afiseaza(out);

    return 0;
}
