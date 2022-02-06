#include "../classes/adjacencyListGraphClass.h"
#include "../classes/adjacencyMatrixGraphClass.h"

adjacencyList AMtoAL(adjacencyMatrix in)
{
    adjacencyList res;
    res.v = in.v;
    for (int i = 0; i < res.v; i++)
    {
        for (int j = 0; j < res.v; j++)
        {
            if (in.arr[i][j] != 0)
            {
                res.list[i].push(j + 1);
            }
        }
    }
    res.addEnding();
    res.name = in.name;
    res.isMade = true;
    res.print(1);
    return (res);
}