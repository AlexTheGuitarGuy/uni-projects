#include <stdio.h>
#include <time.h>
#include "tests.h"

void show_options()
{
    printf("\nMeniu\n");
    printf("1. Tabloul demonstrativ de n elemente (5 <= n <= 20)\n");
    printf("2. Tabloul cu valori aleatorii (n = 10000, n = 100000, n = 1000000)\n");
    printf("3. Tabloul sortat crescator (n = 10000, n = 100000, n = 1000000)\n");
    printf("4. Tabloul sortat descrescator (n = 10000, n = 100000, n = 1000000)\n");
    printf("0. Iesire din program.\n");
}

int handle_options(int in)
{
    int n = 10000;
    int next = 0;

    switch (in)
    {
    case 1:
        int t = clock();
        int swaps = 0;
        int comps = 0;

        example(&swaps, &comps);

        t = clock() - t;
        printf("time: %f", ((double)t) / CLOCKS_PER_SEC);
        printf("\nswaps: %d", swaps);
        printf("\ncomparisons: %d\n", comps);
        break;

    case 2:
        printf("continue to n = %d test? (1/0) ", n);
        if (scanf("%d", &next) && next == 1)
        {
            int t = clock();
            int swaps = 0;
            int comps = 0;

            randArr(n, &swaps, &comps);

            t = clock() - t;
            printf("\ntime: %f", ((double)t) / CLOCKS_PER_SEC);
            printf("\nswaps: %d", swaps);
            printf("\ncomparisons: %d\n\n", comps);
        }

        printf("continue to n = %d test? (1/0) ", n * 10);
        if (scanf("%d", &next) && next == 1)
        {
            int t = clock();
            int swaps = 0;
            int comps = 0;

            randArr(n * 10, &swaps, &comps);

            t = clock() - t;
            printf("\ntime: %f", ((double)t) / CLOCKS_PER_SEC);
            printf("\nswaps: %d", swaps);
            printf("\ncomparisons: %d\n\n", comps);
        }

        printf("continue to n = %d test? (1/0) ", n * 100);
        if (scanf("%d", &next) && next == 1)
        {
            int t = clock();
            int swaps = 0;
            int comps = 0;

            randArr(n * 100, &swaps, &comps);

            t = clock() - t;
            printf("\ntime: %f", ((double)t) / CLOCKS_PER_SEC);
            printf("\nswaps: %d", swaps);
            printf("\ncomparisons: %d\n", comps);
        }
        break;

    case 3:
        printf("continue to n = %d test? (1/0) ", n);
        if (scanf("%d", &next) && next == 1)
        {
            int t = clock();
            int swaps = 0;
            int comps = 0;

            ascArr(n, &swaps, &comps);

            t = clock() - t;
            printf("\ntime: %f", ((double)t) / CLOCKS_PER_SEC);
            printf("\nswaps: %d", swaps);
            printf("\ncomparisons: %d\n\n", comps);
        }

        printf("continue to n = %d test? (1/0) ", n * 10);
        if (scanf("%d", &next) && next == 1)
        {
            int t = clock();
            int swaps = 0;
            int comps = 0;

            ascArr(n * 10, &swaps, &comps);

            t = clock() - t;
            printf("\ntime: %f", ((double)t) / CLOCKS_PER_SEC);
            printf("\nswaps: %d", swaps);
            printf("\ncomparisons: %d\n\n", comps);
        }

        printf("continue to n = %d test? (1/0) ", n * 100);
        if (scanf("%d", &next) && next == 1)
        {
            int t = clock();
            int swaps = 0;
            int comps = 0;

            ascArr(n * 100, &swaps, &comps);

            t = clock() - t;
            printf("\ntime: %f", ((double)t) / CLOCKS_PER_SEC);
            printf("\nswaps: %d", swaps);
            printf("\ncomparisons: %d\n", comps);
        }
        break;

    case 4:
        printf("continue to n = %d test? (1/0) ", n);
        if (scanf("%d", &next) && next == 1)
        {
            int t = clock();
            int swaps = 0;
            int comps = 0;

            descArr(n, &swaps, &comps);

            t = clock() - t;
            printf("\ntime: %f", ((double)t) / CLOCKS_PER_SEC);
            printf("\nswaps: %d", swaps);
            printf("\ncomparisons: %d\n\n", comps);
        }

        printf("continue to n = %d test? (1/0) ", n * 10);
        if (scanf("%d", &next) && next == 1)
        {
            int t = clock();
            int swaps = 0;
            int comps = 0;

            descArr(n * 10, &swaps, &comps);

            t = clock() - t;
            printf("\ntime: %f", ((double)t) / CLOCKS_PER_SEC);
            printf("\nswaps: %d", swaps);
            printf("\ncomparisons: %d\n\n", comps);
        }

        printf("continue to n = %d test? (1/0) ", n * 100);
        if (scanf("%d", &next) && next == 1)
        {
            int t = clock();
            int swaps = 0;
            int comps = 0;

            descArr(n * 100, &swaps, &comps);

            t = clock() - t;
            printf("\ntime: %f", ((double)t) / CLOCKS_PER_SEC);
            printf("\nswaps: %d", swaps);
            printf("\ncomparisons: %d\n", comps);
        }
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
