#include <stdio.h>

void swap(int *p, int *q)
{
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}

void heapify(int arr[], int n, int i, int *swaps, int *comps)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    *comps = *comps + 1;
    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    *comps = *comps + 1;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    *comps = *comps + 1;
    if (smallest != i)
    {
        *swaps = *swaps + 1;
        swap(&arr[i], &arr[smallest]);

        heapify(arr, n, smallest, swaps, comps);
    }
}

void heapSort(int arr[], int n, int *swaps, int *comps)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, swaps, comps);

    for (int i = n - 1; i >= 0; i--)
    {
        *swaps = *swaps + 1;
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0, swaps, comps);
    }
}
