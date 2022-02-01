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
        int **arr;

        arr = new int *[v];
        for (int i = 0; i < v; i++)
            arr[i] = new int[v];

        return (arr);
    }

    int **reallocate()
    {
        int **tmp = new int *[v];
        for (int i = 0; i < v; i++)
            tmp[i] = new int[v];

        for (int i = 0; i < v - 1; i++)
        {
            for (int j = 0; j < v - 1; j++)
            {
                tmp[i][j] = arr[i][j];
            }
        }
        return (tmp);
    }

    int **reallocate(int del)
    {
        int **tmp = new int *[v];
        for (int i = 0; i < v; i++)
            tmp[i] = new int[v];

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (i >= del && j < del)
                    tmp[i][j] = arr[i + 1][j];
                if (i < del && j >= del)
                    tmp[i][j] = arr[i][j + 1];
                if (i < del && j < del)
                    tmp[i][j] = arr[i][j];
                if (i >= del && j >= del)
                    tmp[i][j] = arr[i + 1][j + 1];
            }
        }
        return (tmp);
    }

    void initialize(int **arr)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (arr[i][j] != 1)
                    arr[i][j] = 0;
            }
        }
    }

    void introduce()
    {
        initialize(arr);

        int i, j;
        try
        {
            cout << "Ce varfuri se unesc? (introduceti perechi separate sau introduceti 0 pentru a inceta)\n";
            while (true)
            {

                cin >> i >> j;
                if (i == 0 || j == 0)
                {
                    break;
                }
                i--;
                j--;
                cout << "_\n";

                if ((i < 0 || j < 0) || (i >= v || j >= v))
                {
                    cout << "\nValoare invalida, introduceti din nou.\n";
                    continue;
                }

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

    void add()
    {
        int add = 0;

        try
        {
            cout << "\nCate varfuri doriti sa adaugati? (0 pentru a iesi)\n";
            cin >> add;
            if (add == 0)
                return;
            else if (add >= 0)
            {
                for (; add > 0; add--)
                {
                    v++;
                    arr = reallocate();
                    initialize(arr);
                }
            }
            else
            {
                cout << "\nValoare invalida, introduceti din nou.\n";
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            return;
        }
    }

    void deleteElem()
    {
        int del,
            choice,
            **tmp,
            i, j;
        try
        {
            cout << "\nDoriti sa stergeti legaturi sau varfuri? (1/2/0) ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "\nCe legaturi doriti sa stergeti? (0 pentru a iesi) \n";
                while (true)
                {
                    cin >> i >> j;
                    if (i == 0 || j == 0)
                        return;
                    i--;
                    j--;

                    if (i < 0 || j < 0 || i >= v || j >= v)
                    {
                        cout << "\nValoare invalida, introduceti din nou.\n";
                    }
                    else
                    {
                        arr[i][j] = 0;
                    }
                    cout << "_\n";
                }
                break;
            case 2:
                cout << "\nCe varf doriti sa stergeti? (0 pentru a iesi)\n";
                cin >> del;
                if (del == 0)
                    return;
                del--;
                v--;
                arr = reallocate(del);
                initialize(arr);
                break;
            case 0:
                return;
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            return;
        }
    }

    void selectOperation()
    {
        int choice;
        try
        {
            bool done = false;
            while (!done)
            {
                cout << "\nAlegeti operatiunea:\n";

                cout << "1. Modificare\n";
                cout << "2. Adaugare\n";
                cout << "3. Stergere\n";
                cout << "0. iesire\n";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    introduce();
                    print();
                    break;
                case 2:
                    add();
                    print();
                    break;
                case 3:
                    deleteElem();
                    print();
                    break;
                case 0:
                    done = true;
                    break;
                default:
                    cout << "\nValoare diferita de diapazonul 1-4, introduceti din nou.\n";
                }
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            return;
        }
    }

    void shouldModify()
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
                    selectOperation();
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

    void freeGraph()
    {
        for (int i = 0; i < v; i++)
        {
            free(arr[i]);
        }
        free(arr);
    }
};
