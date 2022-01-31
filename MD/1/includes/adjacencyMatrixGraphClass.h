#pragma once
#include <iostream>

using namespace std;


class adjacencyMatrix
{
public:
    int v;
    int **arr;
    bool fail = false;

    void getShape()
    {

        try
        {
            while (true)
            {
                cout << "\nCate varfuri va avea graful? ";
                cin >> v;
                if (v < 1)
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
            fail = true;
        }
    }

    int **allocate()
    {

        arr = (int **)malloc(v * v * sizeof(int *));

        if (arr == NULL)
        {
            cout << "A eșuat alocarea memoriei pentru întregul tablou.";
            fail = true;
            return (NULL);
        }

        for (int i = 0; i < v; i++)
        {
            arr[i] = (int *)malloc(v * sizeof(int));
            if (arr[i] == NULL)
            {
                cout << "A eșuat alocarea memoriei pentru subtabloul " << i << " al tabloului bidimensional.";
                fail = true;
                return (NULL);
            }
        }

        return (arr);
    }

    void introduce()
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                arr[i][j] = 0;
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
                if (i >= v || j >= v)
                {
                    cout << "\nValoare invalida, introduceti din nou.\n";
                    continue;
                }
                else if (i < 0 || j < 0)
                    break;

                arr[i][j] = 1;
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            fail = true;
            return;
        }
    }

    void print()
    {
        cout << "Graful obtinut:\n";
        cout << "\t";
        for (int i = 0; i < v; i++)
        {
            cout << i + 1 << '\t';
        }
        cout << "\n";
        for (int i = 0; i < v; i++)
        {
            cout << "\t_";
        }
        cout << "\n";

        for (int i = 0; i < v; i++)
        {
            cout << i + 1 << "|\t";
            for (int j = 0; j < v; j++)
            {
                cout << arr[i][j] << '\t';
            }
            cout << "\n";
        }
        cout << "\n";
    }

    void selectOperation(int v)
    {
        int choice;
        try
        {

            cout << "\nAlegeti operatiunea:\n";

            cout << "1. Modificare\n";
            cout << "2. Adaugare\n";
            cout << "3. Stergere\n";
            cout << "4. Alegere varf\n";
            cin >> choice;
            switch (choice)
            {
            case 1:

                break;
            case 2:

                break;
            case 3:
                break;
            case 4:
                break;
            default:
                cout << "\nValoare diferita de diapazonul 1-4, introduceti din nou.\n";
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            return;
        }
    }
};
