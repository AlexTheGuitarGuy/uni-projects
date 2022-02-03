#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "incidencyMatrixGraphClass.h"

using namespace std;

incidencyMatrix im_input;

incidencyMatrix incidencyMatrixGraph()
{
    cin.exceptions(std::ios_base::failbit);

    try
    {
        while (true)
        {
            cout << "\nEste orientat graful dat? (1/0)\n";
            cin >> im_input.isOriented;
            if (im_input.isOriented != 1 && im_input.isOriented != 0)
            {
                cout << "\nValoare diferita de 1 si 0, introduceti din nou.\n";
            }
            else
                break;
        }
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        im_input.fail = 1;
    }

    im_input.getShape();
    if (!im_input.fail)
    {

        im_input.arr = im_input.allocate();
        if (!im_input.fail)
        {
            im_input.introduce();
            if (!im_input.fail)
            {
                im_input.print();
            }
        }
    }

    im_input.shouldModify();
    return (im_input);
}
