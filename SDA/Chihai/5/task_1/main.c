#include <stdio.h>
#include <stdlib.h>
#include "includes.h"

int main()
{
    int *list;
    create_int_list();
    list = toArr();
    int_to_str_list(list, count_int());
    show_str_list();
    return (0);
}
