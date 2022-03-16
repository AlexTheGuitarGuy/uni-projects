#include <stdio.h>

int arr_ncmp(int *arr1, int *arr2, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (arr1[i] != arr2[i])
            return (arr1[i] - arr2[i]);
    }
    return 0;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 6, 4, 5};
    printf("%d", arr_ncmp(arr1, arr2, 5));
    return (0);
}