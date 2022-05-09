#include <stdio.h>
#include <stdlib.h>
#include "algorithm.h"

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int getRand(int lower, int upper)
{
    return ((rand() % (upper - lower + 1)) + lower);
}

void getRandArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand();
}

void getAscArr(int *arr, int n)
{
    arr[0] = rand();
    for (int i = 1; i < n; i++)
        arr[i] = getRand(arr[i - 1], INT_MAX);
}

void getDescArr(int *arr, int n)
{
    arr[0] = rand();
    for (int i = 1; i < n; i++)
        arr[i] = getRand(0, arr[i - 1]);
}

void example(int *swaps, int *comps)
{
    int i = 5;
    while (i <= 20)
    {
        int *arr = (int *)malloc(i * sizeof(int));
        printf("size %d:\n", i);

        getRandArr(arr, i);
        printf("original: ");
        printArr(arr, i);

        heapSort(arr, i, swaps, comps);
        printf("sorted: ");
        printArr(arr, i);

        printf("\n");
        i++;
    }
}

void randArr(int n, int *swaps, int *comps)
{
    int *arr = (int *)malloc(n * sizeof(int));
    getRandArr(arr, n);
    heapSort(arr, n, swaps, comps);
}

void ascArr(int n, int *swaps, int *comps)
{
    int *arr = (int *)malloc(n * sizeof(int));
    getAscArr(arr, n);
    heapSort(arr, n, swaps, comps);
}

void descArr(int n, int *swaps, int *comps)
{
    int *arr = (int *)malloc(n * sizeof(int));
    getDescArr(arr, n);
    heapSort(arr, n, swaps, comps);
}