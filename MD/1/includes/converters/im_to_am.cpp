#include "../classes/incidencyMatrixGraphClass.h"
#include "../classes/adjacencyMatrixGraphClass.h"

adjacencyMatrix IMtoAM(incidencyMatrix in)
{
    adjacencyMatrix res;
    res.v = in.v;
    res.arr = res.allocate();
    res.initialize(res.arr);
    for (int i = 0; i < in.v; i++)
    {
        for (int j = 0; j < in.m; j++)
        {
            if (in.isOriented)
            {
                if (in.arr[j][i] == -1)
                {
                    for (int k = 0; k < in.v; k++)
                    {
                        if (in.arr[j][k] == 1)
                        {
                            res.arr[i][k] = 1;
                        }
                    }
                }
                else if (in.arr[j][i] == 2)
                {
                    res.arr[i][i] = 1;
                }
            }
            else
            {
                if (in.arr[j][i] == 1)
                {
                    for (int k = 0; k < in.v; k++)
                    {
                        if (in.arr[j][k] == 1 && k != i)
                        {
                            res.arr[i][k] = 1;
                        }
                    }
                }
                else if (in.arr[j][i] == 2)
                {
                    res.arr[i][i] = 1;
                }
            }
        }
    }
    res.name = in.name;
    res.isMade = true;
    return (res);
}