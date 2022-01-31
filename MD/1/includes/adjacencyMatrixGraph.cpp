#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "adjacencyMatrixGraphClass.h"

using namespace std;

adjacencyMatrix am_input;

adjacencyMatrix adjacencyMatrixGraph()
{
    cin.exceptions(std::ios_base::failbit);

    am_input.getShape();
    if (!am_input.fail)
    {
        am_input.arr = am_input.allocate();
        if (!am_input.fail)
        {
            am_input.introduce();
            if(!am_input.fail)
                am_input.print();
        }
    }

    am_input.shouldModify();
    return am_input;
}
