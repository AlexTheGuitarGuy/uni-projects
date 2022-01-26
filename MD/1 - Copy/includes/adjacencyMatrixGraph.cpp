#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct
{
    int v;
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

    input.arr = (int **)malloc(input.v * input.v * sizeof(int *));

    if (input.arr == NULL)
    {
        cout << "A eșuat alocarea memoriei pentru întregul tablou.";
        fail = 1;
        return (NULL);
    }

    for (int i = 0; i < input.v; i++)
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
    for (int i = 0; i < input.v; i++)
    {
        for (int j = 0; j < input.v; j++)
        {
            input.arr[i][j] = 0;
        }
    }

    int i, j;
    try
    {
        while (true)
        {
            cout << "Ce varfuri se unesc? (separati prin spatiu, introduceti o valoare negativa pentru a inceta\n";
            cin >> i >> j;
            i--;
            j--;
            if (i >= input.v || j >= input.v)
            {
                cout << "\nValoare invalida.\n";
                fail = 1;
                return;
            }
            else if (i < 0 || j < 0)
                break;

            input.arr[i][j] = 1;
            if (!isOriented)
            {
                input.arr[j][i] = 1;
            }
        }
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        fail = 1;
        return;
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

    for (int i = 0; i < input.v; i++)
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

int adjacencyMatrixGraph()
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
