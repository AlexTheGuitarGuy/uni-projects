#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "adjacencyListGraphClass.h"

using namespace std;

adjacencyList al_input;

adjacencyList adjacencyListGraph()
{
    cin.exceptions(std::ios_base::failbit);

    al_input.allocate();
    if (!al_input.fail)
    {
        al_input.introduce();
        if (!al_input.fail)
        {
            al_input.print();
        }
    }

    al_input.shouldModify();
    return al_input;
}
