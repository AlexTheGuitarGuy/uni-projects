#pragma once
#include <iostream>

using namespace std;

class adjacencyMatrix
{
private:
    int v;

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

    void add()
    {
        int add = 0;

        try
        {
            std::cout << "\nCate varfuri doriti sa adaugati? (0 pentru a iesi)\n";
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
                std::cout << "\nValoare invalida, introduceti din nou.\n";
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            std::cout << "\nValoare diferita de int.\n";
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
            std::cout << "\nDoriti sa stergeti legaturi sau varfuri? (1/2/0) ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                std::cout << "\nCe legaturi doriti sa stergeti? (0 pentru a iesi) \n";
                while (true)
                {
                    cin >> i >> j;
                    if (i == 0 || j == 0)
                        return;
                    i--;
                    j--;

                    if (i < 0 || j < 0 || i >= v || j >= v)
                    {
                        std::cout << "\nValoare invalida, introduceti din nou.\n";
                    }
                    else
                    {
                        arr[i][j] = 0;
                    }
                    std::cout << "_\n";
                }
                break;
            case 2:
                std::cout << "\nCe varf doriti sa stergeti? (0 pentru a iesi)\n";
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
            std::cout << "\nValoare diferita de int.\n";
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
                std::cout << "\nAlegeti operatiunea:\n";

                std::cout << "1. Modificare\n";
                std::cout << "2. Adaugare\n";
                std::cout << "3. Stergere\n";
                std::cout << "0. Iesire\n";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    introduce();
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
                    std::cout << "\nValoare diferita de diapazonul oferit, introduceti din nou.\n";
                }
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            std::cout << "\nValoare diferita de int.\n";
            return;
        }
    }

    void freeGraph()
    {
        for (int i = 0; i < v; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }

public:
    bool fail = false;
    int **arr;
    int isMade = 0;
    string name;

    void getShape()
    {

        try
        {
            while (true)
            {
                std::cout << "\nCate varfuri va avea graful? ";
                cin >> v;
                if (v < 1)
                {
                    std::cout << "\nMarime invalida, introduceti din nou.\n";
                }
                else
                    break;
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            std::cout << "\nValoare diferita de int.\n";
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

    void introduce()
    {
        initialize(arr);

        int i, j;
        try
        {
            std::cout << "Ce varfuri se unesc? (introduceti perechi separate sau introduceti 0 pentru a inceta)\n";
            while (true)
            {

                cin >> i >> j;
                if (i == 0 || j == 0)
                {
                    break;
                }
                i--;
                j--;
                std::cout << "_\n";

                if ((i < 0 || j < 0) || (i >= v || j >= v))
                {
                    std::cout << "\nValoare invalida, introduceti din nou.\n";
                    continue;
                }

                arr[i][j] = 1;
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            std::cout << "\nValoare diferita de int.\n";
            fail = true;
            return;
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
            std::cout << "\nMatricea de adiacenta pentru graful \"" << name << "\":\n";
        }
        std::cout << "\t";
        for (int i = 0; i < v; i++)
        {
            std::cout << i + 1 << '\t';
        }
        std::cout << "\n";
        for (int i = 0; i < v; i++)
        {
            std::cout << "\t_";
        }
        std::cout << "\n";

        for (int i = 0; i < v; i++)
        {
            std::cout << i + 1 << "|\t";
            for (int j = 0; j < v; j++)
            {
                std::cout << arr[i][j] << '\t';
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void shouldModify()
    {
        int change;
        print(1);

        try
        {
            while (true)
            {
                std::cout << "\nDoriti sa modificati graful dat? (1/0)\n";
                cin >> change;
                if (change != 1 && change != 0)
                {
                    std::cout << "\nValoare diferita de 1 si 0, introduceti din nou.\n";
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
            std::cout << "\nValoare diferita de int.\n";
        }
    }

    void make()
    {
        cin.exceptions(std::ios_base::failbit);

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
};
