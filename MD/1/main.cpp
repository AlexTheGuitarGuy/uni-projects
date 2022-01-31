#include <iostream>
#include "includes/main_functions.h"
#include <string>

using namespace std;

int main()
{
    int type;
    bool done = false;

    cout << "Alegeti modul de reprezentare al grafului:\n";
    while (!done)
    {
        cout << "1 - Matrice de incidenta\n";
        cout << "2 - Matrice de adiacenta\n";
        cout << "3 - Lista de adiacenta\n";
        cin >> type;

        switch (type)
        {
        case 1:
            incidencyMatrixGraph();
            done = true;
            break;
        case 2:
            adjacencyMatrixGraph();
            done = true;
            break;
        case 3:
            adjacencyListGraph();
            done = true;
            break;
        default:
            cout << "\nValoare invalida, introduceti din nou.\n";
        }
    }

    return (0);
}