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

namespace save
{
    adjacencyList tmp[100];

    void getSaves()
    {
        int i = 0;
        std::ifstream inf("graphs.txt", std::ios::out | std::ios::app);
        while (!(inf >> std::ws).eof())
        {
            tmp[i].deserialize(inf);
            if (inf.fail())
                break;
            i++;
        }
        inf.close();
        if (!inf.good())
        {
            return;
        }
        return;
    }

    bool isSaved(string name)
    {
        getSaves();
        for (int i = 0; tmp[i].isMade; i++)
        {
            if (tmp[i].name == name)
            {
                return true;
            }
        }
        return false;
    }
}

bool isPresent(string name)
{
    for (int i = 0; al_input[i].isMade; i++)
    {
        if (al_input[i].name == name)
        {
            return true;
        }
    }
    return false;
}

void listifyAll()
{
    if (im_input[0].isMade == true)
    {
        for (int i = 0; im_input[i].isMade; i++)
        {
            if (!isPresent(im_input[i].name))
            {
                al_input[al_i] = AMtoAL(IMtoAM(im_input[i]));
                al_i++;
            }
            else
            {
                cout << "\nLista de adiacenta cu numele " << im_input[i].name << " exista deja, nu se va converti matricea de incidenta respectiva.";
            }
        }
        cout << '\n';
    }

    if (am_input[0].isMade == true)
    {
        for (int i = 0; am_input[i].isMade; i++)
        {
            if (!isPresent(am_input[i].name))
            {
                al_input[al_i] = AMtoAL(am_input[i]);
                al_i++;
            }
            else
            {
                cout << "\nLista de adiacenta cu numele " << am_input[i].name << " exista deja, nu se va converti matricea de adiacenta respectiva.";
            }
        }
        cout << '\n';
    }
}

void saveGraphs()
{
    listifyAll();
    std::ofstream of("graphs.txt", std::ios::out | std::ios::app);
    for (int i = 0; i < al_i; i++)
    {
        if (!save::isSaved(al_input[i].name))
            al_input[i].serialize(of);
        else
            cout << "\nGraful cu numele " << al_input[i].name << " deja este salvat, schimati-i numele pentru a-l putea salva.";
    }
    of.close();
    if (!of.good())
    {
        cout << "S-a produs o eroare in lucrul cu fisierul de scriere!" << endl;
    }
    cout << '\n';
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
    if (im_i > 0)
    {
        for (int i = 0; i < im_i; i++)
        {
            im_input[i].freeGraph();
        }
        im_i = 0;
    }

    if (am_i > 0)
    {
        for (int i = 0; i < am_i; i++)
        {
            am_input[i].freeGraph();
        }
        am_i = 0;
    }

    if (al_i > 0)
    {
        for (int i = 0; i < al_i; i++)
        {
            al_input[i].freeGraph();
        }
        al_i = 0;
    }
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
        of.close();
        if (!of.good())
        {
            cout << "S-a produs o eroare in lucrul cu fisierul de scriere!" << endl;
        }
    }

    void getSaves(adjacencyList *tmp)
    {
        i = 0;
        std::ifstream inf("graphs.txt", std::ios::out | std::ios::app);
        while (!(inf >> std::ws).eof())
        {
            tmp[i].deserialize(inf);
            if (inf.fail())
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

    bool deleteGraph()
    {
        bool done = false;
        adjacencyList tmp[100];
        int choice;
        getSaves(tmp);
        try
        {
            cout << "\nAlegeti numarul grafului pe care doriti sa-l stergeti.\n";
            cin >> choice;
            if (choice == 0)
            {
                bool done = true;
                return done;
            }
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
        }
        return done;
    }

}

void deleteGraph()
{
    bool done;
    while (!done)
    {
        done = del::deleteGraph();
    }
}

void getSaves()
{
    adjacencyList tmp[100];
    int i = 0;
    std::ifstream inf("graphs.txt", std::ios::out | std::ios::app);
    while (!(inf >> std::ws).eof())
    {
        tmp[i].deserialize(inf);
        if (inf.fail())
            break;
        i++;
    }
    inf.close();
    printSavedGraphs(tmp);
    if (!inf.good())
    {
        return;
    }
    return;
}

void convertChoice(int from, int to, int nb)
{
    if (from == 1 && to == 2)
    {
        am_input[am_i] = IMtoAM(im_input[nb]);
        im_input[nb].print(1);
        cout << "\n->\n";
        am_input[am_i].print(1);
        am_i++;
    }
    else if (from == 1 && to == 3)
    {
        al_input[al_i] = AMtoAL(IMtoAM(im_input[nb]));
        im_input[nb].print(1);
        cout << "\n->\n";
        al_input[al_i].print(1);
        al_i++;
    }
    else if (from == 2 && to == 1)
    {
        im_input[im_i] = AMtoIM(am_input[nb]);
        am_input[nb].print(1);
        cout << "\n->\n";
        im_input[im_i].print(1);
        im_i++;
    }
    else if (from == 2 && to == 3)
    {
        al_input[al_i] = AMtoAL(am_input[nb]);
        am_input[nb].print(1);
        cout << "\n->\n";
        al_input[al_i].print(1);
        al_i++;
    }
    else if (from == 3 && to == 1)
    {
        im_input[im_i] = AMtoIM(ALtoAM(al_input[nb]));
        al_input[nb].print(1);
        cout << "\n->\n";
        im_input[im_i].print(1);
        im_i++;
    }
    else if (from == 3 && to == 2)
    {
        am_input[am_i] = ALtoAM(al_input[nb]);
        al_input[nb].print(1);
        cout << "\n->\n";
        am_input[am_i].print(1);
        am_i++;
    }
}

void convertGraph()
{
    try
    {
        int typeFrom, typeTo;
        bool done = false;

        while (!done)
        {
            string error = "\nValoare invalida, introduceti din nou.\n";
            string types = "1 - Matrice de incidenta\n2 - Matrice de adiacenta\n3 - Lista de adiacenta\n0 - Inapoi\n";
            cout << "\nAlegeti tipul reprezentarii grafului din care doriti sa convertiti:\n"
                 << types;
            cin >> typeFrom;
            if (typeFrom == 0)
                return;
            else if (typeFrom < 0 || typeFrom > 3)
            {
                cout << error;
                continue;
            }
            cout << "\nAlegeti tipul reprezentarii grafului in care doriti sa convertiti:\n";
            cin >> typeTo;
            if (typeTo == 0)
                return;
            else if (typeTo < 0 || typeTo > 3)
            {
                cout << error;
                continue;
            }
            int choice;
            string message = "\nCare graf doriti sa-l convertiti? ";

            switch (typeFrom)
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
                        convertChoice(typeFrom, typeTo, choice);
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
                        convertChoice(typeFrom, typeTo, choice);
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
                        convertChoice(typeFrom, typeTo, choice);
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
            cout << "7 - Afisarea listei grafurilor alocate\n";
            cout << "8 - Afisarea listei grafurilor salvate\n";
            cout << "9 - Eliberarea memoriei alocate\n";
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
            case 6:
                convertGraph();
                break;
            case 7:
                showGraphList(4);
                break;
            case 8:
                getSaves();
                break;
            case 9:
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