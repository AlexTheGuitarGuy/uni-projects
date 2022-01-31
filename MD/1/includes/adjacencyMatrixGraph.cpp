#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "classes.h"

using namespace std;

adjacencyMatrix am_input;

int am_fail = 0;

int getAdjacencyMatrixShape()
{

    try
    {
        while (true)
        {
            cout << "\nCate varfuri va avea graful? ";
            cin >> am_input.v;
            if (am_input.v < 1)
            {
                cout << "\nMarime invalida, introduceti din nou.\n";
            }
            else
                break;
        }
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        am_fail = 1;
        return 1;
    }
    return 0;
}

int **adjacencyMatrixAllocate()
{

    am_input.arr = (int **)malloc(am_input.v * am_input.v * sizeof(int *));

    if (am_input.arr == NULL)
    {
        cout << "A eșuat alocarea memoriei pentru întregul tablou.";
        am_fail = 1;
        return (NULL);
    }

    for (int i = 0; i < am_input.v; i++)
    {
        am_input.arr[i] = (int *)malloc(am_input.v * sizeof(int));
        if (am_input.arr[i] == NULL)
        {
            cout << "A eșuat alocarea memoriei pentru subtabloul " << i << " al tabloului bidimensional.";
            am_fail = 1;
            return (NULL);
        }
    }

    return (am_input.arr);
}

void adjacencyMatrixIntroduce()
{
    for (int i = 0; i < am_input.v; i++)
    {
        for (int j = 0; j < am_input.v; j++)
        {
            am_input.arr[i][j] = 0;
        }
    }

    int i, j;
    try
    {
        cout << "Ce varfuri se unesc? (introduceti perechi separate sau introduceti o valoare negativa pentru a inceta)\n";
        while (true)
        {

            cin >> i >> j;
            i--;
            j--;
            cout << "_\n";
            if (i >= am_input.v || j >= am_input.v)
            {
                cout << "\nValoare invalida, introduceti din nou.\n";
                continue;
            }
            else if (i < 0 || j < 0)
                break;

            am_input.arr[i][j] = 1;
        }
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        am_fail = 1;
        return;
    }
}

void adjacencyMatrixPrint()
{
    cout << "Graful obtinut:\n";
    cout << "\t";
    for (int i = 0; i < am_input.v; i++)
    {
        cout << i + 1 << '\t';
    }
    cout << "\n";
    for (int i = 0; i < am_input.v; i++)
    {
        cout << "\t_";
    }
    cout << "\n";

    for (int i = 0; i < am_input.v; i++)
    {
        cout << i + 1 << "|\t";
        for (int j = 0; j < am_input.v; j++)
        {
            cout << am_input.arr[i][j] << '\t';
        }
        cout << "\n";
    }
    cout << "\n";
}

void am_modify()
{
    
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

    getAdjacencyMatrixShape();
    if (!am_fail)
    {
        am_input.arr = adjacencyMatrixAllocate();
        if (!am_fail)
        {
            adjacencyMatrixIntroduce();
        }
    }

    adjacencyMatrixPrint();
    return am_input;
}
