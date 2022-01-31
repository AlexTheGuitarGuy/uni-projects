#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "classes.h"

using namespace std;

incidencyMatrix im_input;

int im_fail = 0;

int getIncidencyMatrixShape()
{

    try
    {
        while (true)
        {

            cout << "\nCate varfuri va avea graful? ";
            cin >> im_input.v;
            if (im_input.v < 1)
            {
                cout << "\nMarime invalida, introduceti din nou.\n";
            }
            else
                break;
        }

        while (true)
        {
            cout << "\nCate muchii va avea graful? ";
            cin >> im_input.m;
            if (im_input.m < 1)
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
        im_fail = 1;
        return 1;
    }
    return 0;
}

int **incidencyMatrixAllocate()
{

    im_input.arr = (int **)malloc(im_input.m * im_input.v * sizeof(int *));

    if (im_input.arr == NULL)
    {
        cout << "A eșuat alocarea memoriei pentru întregul tablou.";
        im_fail = 1;
        return (NULL);
    }

    for (int i = 0; i < im_input.m; i++)
    {
        im_input.arr[i] = (int *)malloc(im_input.v * sizeof(int));
        if (im_input.arr[i] == NULL)
        {
            cout << "A eșuat alocarea memoriei pentru subtabloul " << i << " al tabloului bidimensional.";
            im_fail = 1;
            return (NULL);
        }
    }

    return (im_input.arr);
}

void incidencyMatrixIntroduce()
{
    int in, out;
    for (int i = 0; i < im_input.m; i++)
    {
        try
        {
            while (true)
            {
                if (im_input.isOriented)
                {
                    cout << "\nDin care varf iese muchia " << i + 1 << "? ";
                }
                else
                    cout << "\nCe varfuri uneste muchia " << i + 1 << "? ";

                cin >> out;
                out--;
                if (out >= im_input.v || out < 0)
                {
                    cout << "\nNu exista varful dat, introduceti din nou.\n";
                }
                else
                    break;
            }
            while (true)
            {
                if (im_input.isOriented)
                {
                    cout << "\nIn care varf intra muchia " << i + 1 << "? ";
                }
                else
                    cout << ' ';
                cin >> in;
                in--;
                if (in >= im_input.v || in < 0)
                {
                    cout << "\nNu exista varful dat, introduceti din nou\n";
                }
                else
                    break;
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            im_fail = 1;
            return;
        }

        for (int j = 0; j < im_input.v; j++)
        {
            if (j == in)
            {
                im_input.arr[i][j] = 1;
            }
            else if (j == out && im_input.isOriented)
            {
                im_input.arr[i][j] = -1;
            }
            else if (j == out && !im_input.isOriented)
            {
                im_input.arr[i][j] = 1;
            }
            else
                im_input.arr[i][j] = 0;
        }
    }
}

void incidencyMatrixPrint()
{
    cout << "\nGraful obtinut:\n";
    cout << "\t";
    for (int i = 0; i < im_input.v; i++)
    {
        cout << i + 1 << '\t';
    }
    cout << "\n";
    for (int i = 0; i < im_input.v; i++)
    {
        cout << "\t_";
    }
    cout << "\n";

    for (int i = 0; i < im_input.m; i++)
    {
        cout << i + 1 << "|\t";
        for (int j = 0; j < im_input.v; j++)
        {
            cout << im_input.arr[i][j] << '\t';
        }
        cout << "\n";
    }
    cout << "\n";
}

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
        im_fail = 1;
    }

    getIncidencyMatrixShape();
    if (!im_fail)
    {

        im_input.arr = incidencyMatrixAllocate();
        if (!im_fail)
        {
            incidencyMatrixIntroduce();
        }
    }
    incidencyMatrixPrint();
    return im_input;
}
