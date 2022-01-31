#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "classes.h"

using namespace std;

graphList al_input;

int al_fail = 0;

void graphListAllocate()
{
    try
    {
        while (true)
        {
            cout << "\nCate varfuri va avea graful? ";
            cin >> al_input.v;
            if (al_input.v < 1)
            {
                cout << "\nMarime invalida, introduceti din nou.\n";
            }
            else
                break;
        }

        // graphList = (linked_list *)malloc(v * sizeof(linked_list));
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        al_fail = 1;
        return;
    }
}

void graphListIntroduce()
{

    for (int i = 0; i < al_input.v; i++)
    {
        int data = 1;
        try
        {
            cout << "\nCe varfuri se unesc cu varful " << i + 1 << "? (introduceti numere separate sau introduceti 0 pentru a trece la urmatorul)\n";
            while (data != 0)
            {
                while (true)
                {
                    cin >> data;
                    if (data < 0 || data > al_input.v)
                    {
                        cout << "\nValoare invalida, introduceti din nou\n";
                    }
                    else
                        break;
                }

                if (data != 0)
                {
                    if (!al_input.graphList[i].isPresent(data))
                        al_input.graphList[i].add_node(data);
                    if (!al_input.graphList[data - 1].isPresent(i + 1) && !al_input.isOriented)
                        al_input.graphList[data - 1].add_node(i + 1);
                }
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            al_fail = 1;
            return;
        }
    }

    for (int i = 0; i < al_input.v; i++)
    {
        al_input.graphList[i].add_node(0);
    }
}

void graphListPrint()
{
    cout << "\nGraful rezultant:\n";
    for (int i = 0; i < al_input.v; i++)
    {
        cout << i + 1 << " -> ";
        al_input.graphList[i].print_list();
        cout << '\n';
    }
}

void modifyList()
{

    int mod;
    cout << "\nCare varf doriti sa-l modificati? ";
    cin >> mod;
    mod--;
    al_input.graphList[mod].selectOperation(al_input, mod);
}

graphList adjacencyListGraph()
{
    cin.exceptions(std::ios_base::failbit);

    try
    {
        while (true)
        {
            cout << "\nEste orientat graful dat? (1/0)\n";
            cin >> al_input.isOriented;
            if (al_input.isOriented != 1 && al_input.isOriented != 0)
            {
                cout << "\nValoare diferita de 1 si 0, introduceti din nou.\n";
            }
            else
                break;
        }

        graphListAllocate();
        if (!al_fail)
        {
            graphListIntroduce();
            if (!al_fail)
            {

                graphListPrint();
            }
        }

        int change;
        while (true)
        {
            cout << "\nDoriti sa modificati vre-un element in graf? (1/0)\n";
            cin >> change;
            if (change != 1 && change != 0)
            {
                cout << "\nValoare diferita de 1 si 0, introduceti din nou.\n";
            }
            else
            {
                modifyList();
                graphListPrint();
                break;
            }
        }
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
    }

    return al_input;
}
