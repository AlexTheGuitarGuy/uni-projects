#include <iostream>
#include "includes/main_functions.h"
#include <string>
#include <fstream>

using namespace std;

incidencyMatrix im_input[100];
int im_i = 0;
adjacencyMatrix am_input[100];
int am_i = 0;
adjacencyList al_input[100];
int al_i = 0;

void showGraphList(int show)
{

    switch (show)
    {
    case 1:
        cout << "\nMatrici de incidenta disponibile: \n";
        for (int i = 0; im_input[i].isMade; i++)
        {
            cout << i + 1 << ": ";
            im_input[i].print(1);
        }
        break;
    case 2:
        cout << "\nMatrici de adiacenta disponibile: \n";
        for (int i = 0; am_input[i].isMade; i++)
        {
            cout << i + 1 << ": ";
            am_input[i].print(1);
        }
        break;
    case 3:
        cout << "\nListe de adiacenta disponibile: \n";
        for (int i = 0; al_input[i].isMade; i++)
        {
            cout << i + 1 << ": ";
            al_input[i].print(1);
        }
        break;
    case 4:
        if (im_input[0].isMade == true)
        {
            cout << "\nMatrici de incidenta disponibile: \n";
            for (int i = 0; im_input[i].isMade; i++)
            {
                cout << i + 1 << ": ";
                im_input[i].print(1);
            }
        }

        if (am_input[0].isMade == true)
        {
            cout << "\nMatrici de adiacenta disponibile: \n";
            for (int i = 0; am_input[i].isMade; i++)
            {
                cout << i + 1 << ": ";
                am_input[i].print(1);
            }
        }

        if (al_input[0].isMade == true)
        {
            cout << "\nListe de adiacenta disponibile: \n";
            for (int i = 0; al_input[i].isMade; i++)
            {
                cout << i + 1 << ": ";
                al_input[i].print(1);
            }
        }
        break;
    default:
        cout << "\nNu exista asa optiune\n";
        break;
    }
}

void printSavedGraphs(adjacencyList *in)
{

    if (in[0].isMade == true)
    {
        cout << "\nListe de adiacenta salvate: \n";
        for (int i = 0; in[i].isMade; i++)
        {
            cout << i + 1 << ": ";
            in[i].print(1);
        }
    }
}

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
                im_input[im_i].make();
                im_i++;
                break;
            case 2:
                am_input[am_i].make();
                am_i++;
                break;
            case 3:
                al_input[al_i].make();
                al_i++;
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

            int choice;
            string message = "\nCare graf doriti sa-l modificati? ";
            string error = "\nValoare invalida, introduceti din nou.\n";
            switch (type)
            {
            case 1:
                while (true)
                {
                    showGraphList(1);
                    cout << message;
                    cin >> choice;
                    if (choice == 0)
                        break;
                    choice--;
                    if (choice >= 0 && choice < im_i)
                    {
                        im_input[choice].shouldModify();
                        break;
                    }
                    else
                        cout << error;
                }
                break;
            case 2:
                while (true)
                {
                    showGraphList(2);
                    cout << message;
                    cin >> choice;
                    if (choice == 0)
                        break;
                    choice--;
                    if (choice >= 0 && choice < am_i)
                    {
                        am_input[choice].shouldModify();
                        break;
                    }
                    else
                        cout << error;
                }
                break;

            case 3:
                while (true)
                {
                    showGraphList(3);
                    cout << message;
                    cin >> choice;
                    if (choice == 0)
                        break;
                    choice--;
                    if (choice >= 0 && choice < al_i)
                    {
                        al_input[choice].shouldModify();
                        break;
                    }
                    else
                        cout << error;
                }
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

void saveGraphs()
{
    std::ofstream of("graphs.txt", std::ios::out | std::ios::app);
    for (int i = 0; i < al_i; i++)
    {
        al_input[i].serialize(of);
    }
    of.close();
    if (!of.good())
    {
        cout << "S-a produs o eroare in lucrul cu fisierul de scriere!" << endl;
    }
}

void loadGraphs()
{
    std::ifstream inf("graphs.txt", std::ios::out | std::ios::app);

    while (!(inf >> std::ws).eof())
    {

        al_input[al_i].deserialize(inf);
        if (inf.fail()) /* handle with break or throw */
            break;
        al_i++;
    }
    inf.close();
    if (!inf.good())
    {
        return;
    }
}

void freeGraphs()
{
    for (int i = 0; i < im_i; i++)
    {
        im_input[i].freeGraph();
    }
    im_i = 0;

    for (int i = 0; i < am_i; i++)
    {
        am_input[i].freeGraph();
    }
    am_i = 0;

    for (int i = 0; i < al_i; i++)
    {
        al_input[i].freeGraph();
    }
    al_i = 0;
}

namespace del
{
    int i;

    void removeGraph(int del, adjacencyList *tmp)
    {
        std::ofstream of("graphs.txt", std::ios::out | std::ios::trunc);
        for (int j = 0; j < i; j++)
        {
            if (j != del)
            {
                tmp[j].shouldSave = true;
            }
        }

        for (int j = 0; j < i; j++)
        {
            if (j != del)
            {
                tmp[j].serialize(of);
            }
        }
        // tmp[del].freeGraph();
        of.close();
        if (!of.good())
        {
            cout << "S-a produs o eroare in lucrul cu fisierul de scriere!" << endl;
        }
    }

    void getSaves(adjacencyList *tmp)
    {
        std::ifstream inf("graphs.txt", std::ios::out | std::ios::app);
        while (!(inf >> std::ws).eof())
        {
            tmp[i].deserialize(inf);
            if (inf.fail()) /* handle with break or throw */
                break;
            i++;
        }
        printSavedGraphs(tmp);
        inf.close();
        if (!inf.good())
        {
            return;
        }
    }

    void deleteGraph()
    {
        adjacencyList tmp[100];
        i = 0;
        int choice;
        getSaves(tmp);
        try
        {
            cout << "\nAlegeti numarul grafului pe care doriti sa-l stergeti.\n";
            cin >> choice;
            if (choice == 0)
                return;
            choice--;
            if (choice >= 0 && choice < i)
            {
                removeGraph(choice, tmp);
            }
            else
                cout << "\nValoare invalida.\n";
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            return;
        }
    }

}

void deleteGraph()
{
    del::deleteGraph();
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
            cout << "3 - Salvare grafuri\n";
            cout << "4 - Incarcare grafuri\n";
            cout << "5 - Stergere graf\n";
            cout << "6 - Convertire graf\n";
            cout << "7 - Afisarea listei grafurilor\n";
            cout << "8 - Eliberarea memoriei alocate\n";
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
            case 3:
                saveGraphs();
                break;
            case 4:
                loadGraphs();
                break;
            case 5:
                deleteGraph();
                break;
            case 7:
                showGraphList(4);
                break;
            case 8:
                freeGraphs();
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

    freeGraphs();
    return (0);
}