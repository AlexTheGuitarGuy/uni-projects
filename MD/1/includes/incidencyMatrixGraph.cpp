#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
typedef struct
{
    int v;
    int m;
    int **arr;
} incidencyGraph;
incidencyGraph ig_input;

int ig_fail = 0;
int ig_isOriented = 0;

int getIncidencyGraphShape()
{

    try
    {
        while (true)
        {

            cout << "\nCate varfuri va avea graful? ";
            cin >> ig_input.v;
            if (ig_input.v < 1)
            {
                cout << "\nMarime invalida, introduceti din nou.\n";
            }
            else
                break;
        }

        while (true)
        {
            cout << "\nCate muchii va avea graful? ";
            cin >> ig_input.m;
            if (ig_input.m < 1)
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
        ig_fail = 1;
        return 1;
    }
    return 0;
}

int **incidencyGraphAllocate()
{

    ig_input.arr = (int **)malloc(ig_input.m * ig_input.v * sizeof(int *));

    if (ig_input.arr == NULL)
    {
        cout << "A eșuat alocarea memoriei pentru întregul tablou.";
        ig_fail = 1;
        return (NULL);
    }

    for (int i = 0; i < ig_input.m; i++)
    {
        ig_input.arr[i] = (int *)malloc(ig_input.v * sizeof(int));
        if (ig_input.arr[i] == NULL)
        {
            cout << "A eșuat alocarea memoriei pentru subtabloul " << i << " al tabloului bidimensional.";
            ig_fail = 1;
            return (NULL);
        }
    }

    return (ig_input.arr);
}

void incidencyGraphIntroduce()
{
    int in, out;
    for (int i = 0; i < ig_input.m; i++)
    {
        try
        {
            while (true)
            {
                if (ig_isOriented)
                {
                    cout << "\nDin care varf iese muchia " << i + 1 << "? ";
                }
                else
                    cout << "\nCe varfuri uneste muchia " << i + 1 << "? ";

                cin >> out;
                out--;
                if (out >= ig_input.v || out < 0)
                {
                    cout << "\nNu exista varful dat, introduceti din nou.\n";
                }
                else
                    break;
            }
            while (true)
            {
                if (ig_isOriented)
                {
                    cout << "\nIn care varf intra muchia " << i + 1 << "? ";
                }
                else
                    cout << ' ';
                cin >> in;
                in--;
                if (in >= ig_input.v || in < 0)
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
            ig_fail = 1;
            return;
        }

        for (int j = 0; j < ig_input.v; j++)
        {
            if (j == in)
            {
                ig_input.arr[i][j] = 1;
            }
            else if (j == out && ig_isOriented)
            {
                ig_input.arr[i][j] = -1;
            }
            else if (j == out && !ig_isOriented)
            {
                ig_input.arr[i][j] = 1;
            }
            else
                ig_input.arr[i][j] = 0;
        }
    }
}

void incidencyGraphPrint()
{
    cout << "\nGraful obtinut:\n";
    cout << "\t";
    for (int i = 0; i < ig_input.v; i++)
    {
        cout << i + 1 << '\t';
    }
    cout << "\n";
    for (int i = 0; i < ig_input.v; i++)
    {
        cout << "\t_";
    }
    cout << "\n";

    for (int i = 0; i < ig_input.m; i++)
    {
        cout << i + 1 << "|\t";
        for (int j = 0; j < ig_input.v; j++)
        {
            cout << ig_input.arr[i][j] << '\t';
        }
        cout << "\n";
    }
    cout << "\n";
}

int incidencyMatrixGraph()
{
    cin.exceptions(std::ios_base::failbit);

    try
    {
        while (true)
        {
            cout << "\nEste orientat graful dat? (1/0)\n";
            cin >> ig_isOriented;
            if (ig_isOriented != 1 && ig_isOriented != 0)
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
        return 0;
    }

    getIncidencyGraphShape();
    if (ig_fail)
        return (0);

    ig_input.arr = incidencyGraphAllocate();
    if (ig_fail)
        return (0);

    incidencyGraphIntroduce();
    if (ig_fail)
        return (0);

    incidencyGraphPrint();
    return (1);
}
