#pragma once
#include <iostream>

using namespace std;

class incidencyMatrix
{
public:
    int v;
    int m;
    int **arr;
    int isOriented;
    bool fail = false;

    int getShape()
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

            while (true)
            {
                cout << "\nCate muchii va avea graful? ";
                cin >> m;
                if (m < 1)
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
            return 1;
        }
        return 0;
    }

    int **allocate()
    {

        int **arr;

        arr = new int *[m];
        for (int i = 0; i < m; i++)
            arr[i] = new int[v];

        return (arr);
    }

    int **vreallocate()
    {
        int **tmp = new int *[m];
        for (int i = 0; i < m; i++)
        {
            tmp[i] = new int[v];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < v; j++)
            {
                tmp[i][j] = arr[i][j];
            }
        }
        return (tmp);
    }

    int **mreallocate()
    {
        int **tmp = new int *[m];
        for (int i = 0; i < m; i++)
        {
            tmp[i] = new int[v];
        }
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < v; j++)
            {
                tmp[i][j] = arr[i][j];
            }
        }
        return (tmp);
    }

    void initialize()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (arr[i][j] != 1 && arr[i][j] != -1)
                    arr[i][j] = 0;
            }
        }
    }

    void introduce()
    {
        initialize();
        int in, out;
        for (int i = 0; i < m; i++)
        {
            cout << "\nCe varfuri uneste muchia " << i + 1 << "? (introduceti perechi)\n";
            try
            {
                while (true)
                {

                    cin >> out >> in;
                    in--;
                    out--;
                    if (in >= v || in < 0 || out >= v || out < 0)
                    {
                        cout << "\nNu exista varful dat, introduceti din nou.\n";
                    }
                    else
                        break;
                }
            }
            catch (std::ios_base::failure const &ex)
            {
                cout << "\nValoare diferita de int.\n";
                fail = true;
                return;
            }

            if (isOriented)
            {
                arr[i][out] = -1;
            }
            else if (!isOriented)
            {
                arr[i][out] = 1;
            }
            arr[i][in] = 1;
        }
    }

    void initialize(int i)
    {

        for (int j = 0; j < v; j++)
        {
            arr[i][j] = 0;
        }
    }

    void introduce(int i)
    {
        initialize(i);
        int in, out;

        cout << "\nCe varfuri uneste muchia " << i + 1 << "? (introduceti perechi)\n";
        try
        {
            while (true)
            {

                cin >> out >> in;
                in--;
                out--;
                if (in >= v || in < 0 || out >= v || out < 0)
                {
                    cout << "\nNu exista varful dat, introduceti din nou.\n";
                }
                else
                    break;
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            fail = true;
            return;
        }
        if (isOriented)
        {

            arr[i][out] = -1;
        }
        else if (!isOriented)
        {

            arr[i][out] = 1;
        }

        arr[i][in] = 1;
    }

    void introduce(int i, int del)
    {
        v++;
        initialize(i);
        v--;
        int in, out;

        cout << "\nCe varfuri uneste muchia " << i + 1 << "? (introduceti perechi)\n";
        try
        {
            while (true)
            {

                cin >> out >> in;
                in--;
                out--;
                if (in >= v || in < 0 || out >= v || out < 0)
                {
                    cout << "\nNu exista varful dat, introduceti din nou.\n";
                }
                else
                    break;
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            fail = true;
            return;
        }
        if (isOriented)
        {
            if (out >= del)
                arr[i][out + 1] = -1;
            else
                arr[i][out] = -1;
        }
        else if (!isOriented)
        {
            if (out >= del)
                arr[i][out + 1] = 1;
            else
                arr[i][out] = 1;
        }
        if (in == del)
            arr[i][in + 1] = 1;
        else
            arr[i][in] = 1;
    }

    void print()
    {
        cout << "\nGraful obtinut:\n";
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

        for (int i = 0; i < m; i++)
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

    void modify()
    {
        while (true)
        {
            int i;
            cout << "\nCe muchie doriti sa modificati?\n";
            cin >> i;
            i--;
            if (i >= 0 && i < m)
            {
                initialize(i);
                introduce(i);
                break;
            }
            else
                cout << "\nValoare invalida, introduceti din nou.\n";
        }
    }

    void add()
    {
        int add;
        int choice;

        try
        {
            cout << "\nDoriti sa adaugati varfuri sau muchii? (1/2/0)\n";
            cin >> choice;
            if (choice == 0)
                return;
            else if (choice == 1)
            {
                cout << "\nCate varfuri doriti sa adaugati?\n";
                cin >> add;
                while (add > 0)
                {
                    v++;
                    arr = vreallocate();
                    initialize();
                    add--;
                }
            }
            else if (choice == 2)
            {
                cout << "\nCate muchii doriti sa adaugati?\n";
                cin >> add;
                while (add > 0)
                {
                    m++;
                    arr = mreallocate();
                    introduce(m - 1);
                    add--;
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

    int **vreallocate(int del)
    {
        int **tmp = new int *[m];
        for (int i = 0; i < m; i++)
        {
            tmp[i] = new int[v];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (j >= del)
                    tmp[i][j] = arr[i][j + 1];
                else
                    tmp[i][j] = arr[i][j];
            }
        }
        return (tmp);
    }

    int **mreallocate(int del)
    {
        int **tmp = new int *[m];
        for (int i = 0; i < m; i++)
        {
            tmp[i] = new int[v];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < v + 1; j++)
            {
                if (i >= del)
                    tmp[i][j] = arr[i + 1][j];
                else
                    tmp[i][j] = arr[i][j];
            }
        }
        return (tmp);
    }

    void reconnect(int j)
    {
        cout << "\nRescrieti legaturile muchiilor sterse ca rezultat al stergerii varfului:\n";
        for (int i = 0; i < m; i++)
        {
            if (arr[i][j] == 1 || arr[i][j] == -1)
                introduce(i, j);
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
            cout << "\nDoriti sa stergeti un varf sau o muchie? (1/2/0) ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "\nCe varf doriti sa stergeti? (0 pentru a iesi)\n";
                cin >> del;
                if (del == 0)
                    return;
                del--;
                v--;
                reconnect(del);
                arr = vreallocate(del);
                break;
            case 2:

                cout << "\nCe muchie doriti sa stergeti? (0 pentru a iesi)\n";
                cin >> del;
                if (del == 0)
                    return;
                del--;
                m--;
                arr = mreallocate(del);
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
                cout << "0. Iesire\n";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    modify();
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
                    cout << "\nValoare diferita de diapazonul oferit, introduceti din nou.\n";
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

    void freeGraph(int **arr)
    {
        for (int i = 0; i < v; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};
