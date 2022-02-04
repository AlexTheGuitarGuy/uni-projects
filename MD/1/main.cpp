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

        cout << "\nAlegeti modul de reprezentare al grafului:\n";
        while (!done)
        {
            cout << "1 - Matrice de incidenta\n";
            cout << "2 - Matrice de adiacenta\n";
            cout << "3 - Lista de adiacenta\n";
            cout << "0 - Iesire\n";
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

int main()
{
    try
    {
        int type;
        bool done = false;

        cout << "\nAlegeti tipul de operatie:\n";
        while (!done)
        {
            cout << "1 - Crearea unui graf\n";
            cout << "2 - Convertirea unui graf\n";
            cout << "3 - Salvarea unui graf\n";
            cout << "4 - Stergerea unui graf\n";
            cout << "5 - Modificarea unui graf\n";
            cout << "6 - Afisarea listei grafurilor\n";
            cout << "0 - Iesire\n";
            cin >> type;

            switch (type)
            {
            case 1:
                makeGraph();
                break;
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