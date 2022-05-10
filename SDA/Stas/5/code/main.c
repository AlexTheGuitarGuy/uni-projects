#include <stdio.h>
#include <stdlib.h>
#include "includes.h"

int main()
{
    int_create_list();
    printf("\nExemplu de lista:\n");
    int_show();

    int *arr = to_arr();

    str_create_list(arr);
    printf("\nAceeasi lista in forma hexadecimala:\n");
    str_show();

    int_free_list();
    str_free_list();
    return (0);
}
