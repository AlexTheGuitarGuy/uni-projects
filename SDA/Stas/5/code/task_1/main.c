#include <stdio.h>
#include <stdlib.h>
#include "includes.h"

int main()
{
    create_list();
    printf("\nLista:\n");
    show();
    printf("\n%d de elemente\n", count());
    find_extremes();
    printf("\nIntervalul dintre numerele maxim si minim:");
    get_extremes_interval();
    return (0);
}
