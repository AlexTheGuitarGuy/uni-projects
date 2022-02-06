#include "../classes/adjacencyListGraphClass.h"
#include "../classes/adjacencyMatrixGraphClass.h"

adjacencyMatrix ALtoAM(adjacencyList in)
{
    adjacencyMatrix res;
    res.v = in.v;
    res.arr = res.allocate();
    res.initialize(res.arr);
    int *tmp;
    for (int i = 0; i < res.v; i++)
    {
        tmp = in.list[i].to_array();
        for (int j = 0; tmp[j] != 0; j++)
        {
            res.arr[i][tmp[j] - 1] = 1;
        }
    }
    res.name = in.name;
    res.isMade = true;
    res.print(1);
    return (res);
}