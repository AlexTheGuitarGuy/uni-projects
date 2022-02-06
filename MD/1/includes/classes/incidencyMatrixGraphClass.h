#pragma once
#include <iostream>

using namespace std;

class incidencyMatrix
{
private:
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
        if (in == out)
            arr[i][in] = 2;
        else
        {
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

    void reconnect()
    {
        cout << "\nRescrieti legaturile muchiilor sterse ca rezultat al stergerii varfului:\n";
        int connections;
        int j;

        for (int i = 0; i < m; i++)
        {
            connections = 0;
            int j;
            for (j = 0; j < v; j++)
            {
                if (arr[i][j] == 1 || arr[i][j] == -1)
                    connections++;
                else if (arr[i][j] == 2)
                    connections = 2;
            }
            if (connections != 2)
                introduce(i);
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
                arr = vreallocate(del);
                reconnect();
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
                    print(-1);
                    break;
                case 2:
                    add();
                    print(-1);
                    break;
                case 3:
                    deleteElem();
                    print(-1);
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

public:
    int v;
    int m;
    int **arr;
    int isOriented;
    bool fail = false;
    int isMade = 0;
    string name;

    void initialize()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (arr[i][j] != 1 && arr[i][j] != -1 && arr[i][j] != 2)
                    arr[i][j] = 0;
            }
        }
    }

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
            if (in == out)
                arr[i][in] = 2;
            else
            {
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
    }

    void print(int i)
    {
        switch (i)
        {
        case -1:
            std::cout << "\nGraful rezultant:\n";
            break;
        default:
            std::cout << "\nMatricea de incidenta pentru graful \"" << name << "\":\n";
        }
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

    void shouldModify()
    {
        int change;

        print(1);
        try
        {
            while (true)
            {
                cout << "\nDoriti sa modificati graful dat? (1/0)\n";
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

    void make()
    {
        cin.exceptions(std::ios_base::failbit);

        try
        {
            while (true)
            {
                cout << "\nEste orientat graful dat? (1/0)\n";
                cin >> isOriented;
                if (isOriented != 1 && isOriented != 0)
                {
                    cout << "\nValoare diferita de 1 si 0, introduceti din nou.\n";
                }
                else
                    break;
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            fail = 1;
        }

        getShape();
        if (!fail)
        {

            arr = allocate();
            if (!fail)
            {
                introduce();
                if (!fail)
                {
                    cout << "\nCum se va numi graful dat? (fara spatii)\n";
                    cin >> name;
                    print(1);
                    isMade = 1;
                }
            }
        }
    }

    void freeGraph()
    {
        for (int i = 0; i < v; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        isMade = false;
    }
};
