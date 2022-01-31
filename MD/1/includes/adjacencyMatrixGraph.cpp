#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "adjacencyMatrixGraphClass.h"

using namespace std;

adjacencyMatrix am_input;

void am_modify()
{
    return;
}

void am_shouldModify()
{
    int change;

    try
    {
        while (true)
        {
            cout << "\nDoriti sa modificati vre-un element in graf? (1/0)\n";
            cin >> change;
            if (change != 1 && change != 0)
            {
                cout << "\nValoare diferita de 1 si 0, introduceti din nou.\n";
            }
            else if (change == 1)
            {
                am_modify();
                break;
            }
            else
                break;
        }
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
    }
}

adjacencyMatrix adjacencyMatrixGraph()
{
    cin.exceptions(std::ios_base::failbit);

    am_input.getShape();
    if (!am_input.fail)
    {
        am_input.allocate();
        if (!am_input.fail)
        {
            am_input.introduce();
            if(!am_input.fail)
                am_input.print();
        }
    }
    return am_input;
}
