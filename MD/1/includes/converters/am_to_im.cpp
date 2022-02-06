#include "../classes/incidencyMatrixGraphClass.h"
#include "../classes/adjacencyMatrixGraphClass.h"

bool orientationCheck(adjacencyMatrix in)
{
    for (int i = 0; i < in.v; i++)
    {
        for (int j = 0; j < in.v; j++)
        {
            if (in.arr[i][j] != in.arr[j][i])
            {
                return (true);
            }
        }
    }

    return (false);
}

int calculateM(adjacencyMatrix in, bool isOriented)
{
    int m = 0;
    for (int i = 0; i < in.v; i++)
    {
        for (int j = 0; j < in.v; j++)
        {
            if (in.arr[i][j] == 1 && i >= j && !isOriented)
            {
                m++;
            }
            else if (in.arr[i][j] == 1)
            {
                m++;
            }
        }
    }
    return (m);
}

incidencyMatrix AMtoIM(adjacencyMatrix in)
{
    incidencyMatrix res;
    res.v = in.v;

    res.isOriented = orientationCheck(in);
    res.m = calculateM(in, res.isOriented);
    res.arr = res.allocate();
    res.initialize();
    int m = 0;
    for (int i = 0; i < in.v && m < res.m; i++)
    {
        for (int j = 0; j < in.v; j++)
        {
            if (i == j && in.arr[i][j] == 1)
            {
                res.arr[m][i] = 2;
                m++;
                continue;
            }
            if (!res.isOriented)
            {
                if (in.arr[i][j] == 1 && i >= j)
                {
                    res.arr[m][i] = 1;
                    res.arr[m][j] = 1;
                    m++;
                }
            }
            else
            {
                if (in.arr[i][j] == 1)
                {
                    res.arr[m][i] = -1;
                    res.arr[m][j] = 1;
                    m++;
                }
            }
        }
    }
    res.name = in.name;
    res.isMade = true;
    res.print(1);
    return (res);
}