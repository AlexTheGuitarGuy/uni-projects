#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct
{
    int v;
    int **arr;
} adjacencyGraph;
adjacencyGraph ag_input;

int ag_fail = 0;
int ag_isOriented = 0;

int getAdjacencyGraphShape()
{

    try
    {
        while (true)
        {
            cout << "\nCate varfuri va avea graful? ";
            cin >> ag_input.v;
            if (ag_input.v < 1)
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
        ag_fail = 1;
        return 1;
    }
    return 0;
}

int **adjacencyGraphAllocate()
{

    ag_input.arr = (int **)malloc(ag_input.v * ag_input.v * sizeof(int *));

    if (ag_input.arr == NULL)
    {
        cout << "A eșuat alocarea memoriei pentru întregul tablou.";
        ag_fail = 1;
        return (NULL);
    }

    for (int i = 0; i < ag_input.v; i++)
    {
        ag_input.arr[i] = (int *)malloc(ag_input.v * sizeof(int));
        if (ag_input.arr[i] == NULL)
        {
            cout << "A eșuat alocarea memoriei pentru subtabloul " << i << " al tabloului bidimensional.";
            ag_fail = 1;
            return (NULL);
        }
    }

    return (ag_input.arr);
}

void adjacencyGraphIntroduce()
{
    for (int i = 0; i < ag_input.v; i++)
    {
        for (int j = 0; j < ag_input.v; j++)
        {
            ag_input.arr[i][j] = 0;
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
            if (i >= ag_input.v || j >= ag_input.v)
            {
                cout << "\nValoare invalida, introduceti din nou.\n";
                continue;
            }
            else if (i < 0 || j < 0)
                break;

            ag_input.arr[i][j] = 1;
            if (!ag_isOriented)
            {
                ag_input.arr[j][i] = 1;
            }
        }
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        ag_fail = 1;
        return;
    }
}

void adjacencyGraphPrint()
{
    cout << "Graful obtinut:\n";
    cout << "\t";
    for (int i = 0; i < ag_input.v; i++)
    {
        cout << i + 1 << '\t';
    }
    cout << "\n";
    for (int i = 0; i < ag_input.v; i++)
    {
        cout << "\t_";
    }
    cout << "\n";

    for (int i = 0; i < ag_input.v; i++)
    {
        cout << i + 1 << "|\t";
        for (int j = 0; j < ag_input.v; j++)
        {
            cout << ag_input.arr[i][j] << '\t';
        }
        cout << "\n";
    }
    cout << "\n";
}

int adjacencyMatrixGraph()
{
    cin.exceptions(std::ios_base::failbit);

    try
    {
        while (true)
        {
            cout << "\nEste orientat graful dat? (1/0)\n";
            cin >> ag_isOriented;
            if (ag_isOriented != 1 && ag_isOriented != 0)
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

    getAdjacencyGraphShape();
    if (ag_fail)
        return (0);

    ag_input.arr = adjacencyGraphAllocate();
    if (ag_fail)
        return (0);

    adjacencyGraphIntroduce();
    if (ag_fail)
        return (0);

    adjacencyGraphPrint();
    return (1);
}
