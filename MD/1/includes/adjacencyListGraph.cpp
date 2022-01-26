#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct graphList
{
    int entry;
    graphList *next;
};

typedef struct
{
    int v;
    graphList **head;
} graph;
graph input;

int fail = 0;
int isOriented = 0;

graphList **graphAllocate()
{
    try
    {

        cout << "Cate varfuri va avea graful? ";
        cin >> input.v;
        if (input.v < 1)
        {
            cout << "\nMarime invalida.\n";
            fail = 1;
            return NULL;
        }
        cout << "\n";

        input.head = (graphList **)malloc(input.v * sizeof(graphList *));
        for (int i = 0; i < input.v; i++)
        {
            input[i]->head = (graphList *)malloc(sizeof(graphList));
        }
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        fail = 1;
        return NULL;
    }

    return (input.head);
}

void graphIntroduce()
{
    graphList **tmp = input.head;

    for (int i = 0, size; i < input.v; i++)
    {
        try
        {
            cout << "Ce varfuri se unesc cu varful " << i + 1 << "? (introduceti numere separate sau introduceti o valoare negativa pentru a inceta)\n";
            while (true)
            {
                cin >> tmp[i]->entry;
                /*if(i < 0)
                    break;
                tmp[i]->next = (graphList *)malloc(sizeof(graphList) * 3);
                tmp[i] = tmp[i]->next;

            }
            tmp[i]->entry = '\0';
            tmp[i]->next = NULL;*/
                break;
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            fail = 1;
            return;
        }
    }
}

void graphPrint()
{
    graphList **tmp = input.head;

    for (int i = 0, size; i < input.v; i++)
    {
        while (tmp[i]->next != NULL)
        {
            cout << tmp[i]->entry << ' ';
            tmp[i] = tmp[i]->next;
        }
        cout << '\n';
    }
}

int adjacencyListGraph()
{
    cin.exceptions(std::ios_base::failbit);

    cout << "\nEste orientat graful dat? (1/0)\n";
    cin >> isOriented;

    input.head = graphAllocate();
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
