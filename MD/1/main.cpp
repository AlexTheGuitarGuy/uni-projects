#include <iostream>
#include "includes/main_functions.h"
#include <string>

using namespace std;

incidencyMatrix im_input[100];
adjacencyMatrix am_input[100];
adjacencyList al_input[100];

void makeGraph()
{
    try
    {
        int type;
        bool done = false;

        while (!done)
        {
            cout << "\nAlegeti modul de reprezentare al grafului nou:\n";
            cout << "1 - Matrice de incidenta\n";
            cout << "2 - Matrice de adiacenta\n";
            cout << "3 - Lista de adiacenta\n";
            cout << "0 - Inapoi\n";
            cin >> type;

            switch (type)
            {
            case 1:
                im_input[0].make();
                break;
            case 2:
                am_input[0].make();
                break;
            case 3:
                al_input[0].make();
                break;
            case 0:
                done = true;
                break;
            default:
                cout << "\nValoare invalida, introduceti din nou.\n";
            }
        }
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        return;
    }
}

void modifyGraph()
{
    try
    {
        int type;
        bool done = false;

        while (!done)
        {
            cout << "\nAlegeti tipul reprezentarii grafului pe care doriti sa-l modificati:\n";
            cout << "1 - Matrice de incidenta\n";
            cout << "2 - Matrice de adiacenta\n";
            cout << "3 - Lista de adiacenta\n";
            cout << "0 - Inapoi\n";
            cin >> type;

            switch (type)
            {
            case 1:
                im_input[0].shouldModify();
                break;
            case 2:
                am_input[0].shouldModify();
                break;
            case 3:
                al_input[0].shouldModify();
                break;
            case 0:
                done = true;
                break;
            default:
                cout << "\nValoare invalida, introduceti din nou.\n";
            }
        }
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        return;
    }
}

void showGraphList()
{
    for (int i = 0; im_input[i].isMade; i++)
        im_input[i].print(i + 1);
    for (int i = 0; am_input[i].isMade; i++)
        am_input[i].print(i + 1);
    for (int i = 0; al_input[i].isMade; i++)
        al_input[i].print(i + 1);
}

int main()
{
    try
    {
        int type;
        bool done = false;

        while (!done)
        {
            cout << "\nAlegeti tipul de operatie:\n";
            cout << "1 - Creare graf\n";
            cout << "2 - Modificare graf\n";
            cout << "3 - Salvare graf\n";
            cout << "4 - Stergere graf\n";
            cout << "5 - Convertire graf\n";
            cout << "6 - Afisarea listei grafurilor\n";
            cout << "0 - Iesire\n";
            cin >> type;

            switch (type)
            {
            case 1:
                makeGraph();
                break;
            case 2:
                modifyGraph();
                break;
            case 6:
                showGraphList();
                break;
            case 0:
                done = true;
                break;
            default:
                cout << "\nNu exista optiunea cu numarul dat, introduceti din nou.\n";
            }
        }
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        return 1;
    }

    return (0);
}