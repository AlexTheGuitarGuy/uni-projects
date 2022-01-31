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

        arr = (int **)malloc(m * v * sizeof(int *));

        if (arr == NULL)
        {
            cout << "A eșuat alocarea memoriei pentru întregul tablou.";
            fail = true;
            return (NULL);
        }

        for (int i = 0; i < m; i++)
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
        int in, out;
        for (int i = 0; i < m; i++)
        {
            try
            {
                while (true)
                {
                    if (isOriented)
                    {
                        cout << "\nDin care varf iese muchia " << i + 1 << "? ";
                    }
                    else
                        cout << "\nCe varfuri uneste muchia " << i + 1 << "? ";

                    cin >> out;
                    out--;
                    if (out >= v || out < 0)
                    {
                        cout << "\nNu exista varful dat, introduceti din nou.\n";
                    }
                    else
                        break;
                }
                while (true)
                {
                    if (isOriented)
                    {
                        cout << "\nIn care varf intra muchia " << i + 1 << "? ";
                    }
                    else
                        cout << ' ';
                    cin >> in;
                    in--;
                    if (in >= v || in < 0)
                    {
                        cout << "\nNu exista varful dat, introduceti din nou\n";
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

            for (int j = 0; j < v; j++)
            {
                if (j == in)
                {
                    arr[i][j] = 1;
                }
                else if (j == out && isOriented)
                {
                    arr[i][j] = -1;
                }
                else if (j == out && !isOriented)
                {
                    arr[i][j] = 1;
                }
                else
                    arr[i][j] = 0;
            }
        }
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
};
