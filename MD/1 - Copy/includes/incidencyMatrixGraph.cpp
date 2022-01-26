#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct
{
    int v;
    int m;
    int **arr;
} graph;
graph input;

int fail = 0;
int isOriented = 0;

int getGraphShape()
{

    try
    {

        cout << "Cate varfuri va avea graful? ";
        cin >> input.v;
        if (input.v < 1)
        {
            cout << "\nMarime invalida.\n";
            fail = 1;
            return 1;
        }

        cout << "\nCate muchii va avea graful? ";
        cin >> input.m;
        if (input.m < 1)
        {
            cout << "\nMarime invalida.\n";
            fail = 1;
            return 1;
        }
        cout << "\n";
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        fail = 1;
        return 1;
    }
    return 0;
}

int **graphAllocate()
{

    input.arr = (int **)malloc(input.m * input.v * sizeof(int *));

    if (input.arr == NULL)
    {
        cout << "A eșuat alocarea memoriei pentru întregul tablou.";
        fail = 1;
        return (NULL);
    }

    for (int i = 0; i < input.m; i++)
    {
        input.arr[i] = (int *)malloc(input.v * sizeof(int));
        if (input.arr[i] == NULL)
        {
            cout << "A eșuat alocarea memoriei pentru subtabloul " << i << " al tabloului bidimensional.";
            fail = 1;
            return (NULL);
        }
    }

    return (input.arr);
}

void graphIntroduce()
{
    int in, out;
    for (int i = 0; i < input.m; i++)
    {
        try
        {
            if (isOriented)
            {
                cout << "Din care varf iese muchia " << i + 1 << "? ";
            }
            else
                cout << "Ce varfuri uneste muchia " << i + 1 << "? ";

            cin >> out;
            out--;
            if (out >= input.v || out < 0)
            {
                cout << "\nNu exista varful dat.\n";
                fail = 1;
                return;
            }

            if (isOriented)
            {
                cout << "In care varf intra muchia " << i + 1 << "? ";
            }
            else
                cout << ' ';
            cin >> in;
            in--;
            if (in >= input.v || in < 0)
            {
                cout << "\nNu exista varful dat.\n";
                fail = 1;
                return;
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            fail = 1;
            return;
        }

        for (int j = 0; j < input.v; j++)
        {
            if (j == in)
            {
                input.arr[i][j] = 1;
            }
            else if (j == out && isOriented)
            {
                input.arr[i][j] = -1;
            }
            else if (j == out && !isOriented)
            {
                input.arr[i][j] = 1;
            }
            else
                input.arr[i][j] = 0;
        }
    }
}

void graphPrint()
{
    cout << "\t";
    for (int i = 0; i < input.v; i++)
    {
        cout << i + 1 << '\t';
    }
    cout << "\n";
    for (int i = 0; i < input.v; i++)
    {
        cout << "\t_";
    }
    cout << "\n";

    for (int i = 0; i < input.m; i++)
    {
        cout << i + 1 << "|\t";
        for (int j = 0; j < input.v; j++)
        {
            cout << input.arr[i][j] << '\t';
        }
        cout << "\n";
    }
    cout << "\n";
}

int incidencyMatrixGraph()
{
    cin.exceptions(std::ios_base::failbit);

    cout << "\nEste orientat graful dat? (1/0)\n";
    cin >> isOriented;

    getGraphShape();
    if (fail)
    {
        cout << "\nTerminare program.\n";
        return (0);
    }

    input.arr = graphAllocate();
    if (fail)
    {
        cout << "\nTerminare program.\n";
        return (0);
    }

    graphIntroduce();
    if (fail)
    {
        cout << "\nTerminare program.\n";
        return (0);
    }

    graphPrint();
    return (1);
}
