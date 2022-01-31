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

    void reallocate(int **arr)
    {
        arr = (int **)realloc(arr, v * v * sizeof(int *));

        if (arr == NULL)
        {
            cout << "A eșuat alocarea memoriei pentru întregul tablou.";
            fail = true;
            return ;
        }

        for (int i = 0; i < v; i++)
        {
            arr[i] = (int *)realloc(arr[i], v * sizeof(int));
            if (arr[i] == NULL)
            {
                cout << "A eșuat alocarea memoriei pentru subtabloul " << i << " al tabloului bidimensional.";
                fail = true;
                return;
            }
        }

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
            cout << "\nCate varfuri doriti sa adaugati?\n";
            cin >> add;
            if (add >= 0)
            {
                v += add;
                reallocate(arr);
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

    void ignoreInit(int del, int **tmp)
    {
        int ignorei = 0;
        int ignorej = 0;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (i >= del)
                    ignorei = 1;
                else
                    ignorei = 0;
                if (j >= del)
                    ignorej = 1;
                else
                    ignorej = 0;
                if (arr[i][j] == 1)
                    tmp[i][j] == 1;
            }
        }
    }

    void deleteElem()
    {
        int del;
        int **tmp;
        try
        {
            //cout << "\nDoriti sa stergeti legaturi sau varfuri? (1/2)";
            cout << "\nCe varf doriti sa stergeti?\n";
            cin >> del;
            del--;
            v--;
            tmp = allocate();
            print();
            initialize(tmp);
            ignoreInit(del, tmp);
            arr = tmp;
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
