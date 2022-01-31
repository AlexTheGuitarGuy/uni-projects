#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "classes.h"

using namespace std;

graphList al_input;

int al_fail = 0;

void listAllocate()
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

        // list = (linked_list *)malloc(v * sizeof(linked_list));
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        al_fail = 1;
        return;
    }
}

void addEnding()
{
    for (int i = 0; i < al_input.v; i++)
    {
        if (al_input.list[i].getTail()->data != 0)
            al_input.list[i].push(0);
    }
}

void listIntroduce()
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
                    if (!al_input.list[i].isPresent(data))
                        al_input.list[i].push(data);
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

    addEnding();
}

void listPrint()
{
    cout << "\nGraful rezultant:\n";
    for (int i = 0; i < al_input.v; i++)
    {
        cout << i + 1 << " -> ";
        al_input.list[i].print_list();

        cout << '\n';
    }
}

void list_modify()
{

    int mod;

    while (true)
    {
        cout << "\nCare varf doriti sa-l modificati? (0 pentru a iesi) ";
        cin >> mod;

        if (mod == 0)
            return;
        else if (mod > al_input.v)
        {
            cout << "\nValoare invalida.\n";
            continue;
        }
        mod--;
        al_input.list[mod].selectOperation(al_input.v);
        addEnding();
        listPrint();
    }
}

void list_shouldModify()
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
                list_modify();
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

graphList adjacencyListGraph()
{
    cin.exceptions(std::ios_base::failbit);

    listAllocate();
    if (!al_fail)
    {
        listIntroduce();
        if (!al_fail)
        {
            listPrint();
        }
    }

    list_shouldModify();
    return al_input;
}
