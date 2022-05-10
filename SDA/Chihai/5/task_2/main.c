#include <stdio.h>
#include <stdlib.h>
#include "includes.h"

int main()
{
    int_create_list();

    replace();
    printf("new list:\n");
    int_show();

    int_free_list();
    return 0;
}