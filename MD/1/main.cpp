#include <iostream>
#include "includes/graphs.h"
#include <string>

using namespace std;

int main()
{
    /*int type;
    cout << "Alegeti modul de reprezentare a grafului:\n";
    cout << "1 - Matrice de incidenta\n";
    cout << "2 - Matrice de adiacenta\n";
    cin >> type;

    switch (type)
    {
    case 1:
        incidencyMatrixGraph();
        break;
    case 2:
        adjacencyMatrixGraph();
        break;
    default:
        cout << "Valoare invalida.";
    }*/
    adjacencyListGraph();
    return (0);
}