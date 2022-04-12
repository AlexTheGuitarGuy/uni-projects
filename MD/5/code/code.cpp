// C++ program for implementation of Ford Fulkerson
// algorithm
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

// Number of vertices in given graph
int V;

/* Returns true if there is a path from source 'from' to sink
  'to' in residual graph. Also fills parent[] to store the
  path */
bool bfs(int **rGraph, int from, int to, int parent[])
{
    // Create a visited array and mark all vertices as not
    // visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    // Create a queue, enqueue source vertex and mark source
    // vertex as visited
    queue<int> queue;
    queue.push(from);
    visited[from] = true;
    parent[from] = -1;

    // Standard BFS Loop
    while (!queue.empty())
    {
        int j = queue.front();
        queue.pop();

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false && rGraph[j][i] > 0)
            {
                // If we find a connection to the sink node,
                // then there is no point in BFS anymore We
                // just have to set its parent and can return
                // true
                if (i == to)
                {
                    parent[i] = j;
                    return true;
                }
                queue.push(i);
                parent[i] = j;
                visited[i] = true;
            }
        }
    }

    // We didn't reach sink in BFS starting from source, so
    // return false
    return false;
}

// Returns the maximum flow in the given graph
int fordFulkerson(int **graph, int from, int to)
{
    int i, j;

    // Create a residual graph and fill the residual graph
    // with given capacities in the original graph as
    // residual capacities in residual graph
    int **rGraph = new int *[V];
    for (int i = 0; i < V; i++)
        rGraph[i] = new int[V]; // Residual graph where rGraph[j][i]
                                // indicates residual capacity of edge
                                // from j to i (if there is an edge. If
                                // rGraph[j][i] is 0, then there is not)
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            rGraph[i][j] = graph[i][j];

    int parent[V]; // This array is filled by BFS and to
                   // store path

    int max_flow = 0; // There is no flow initially

    // Augment the flow while there is path from source to
    // sink
    while (bfs(rGraph, from, to, parent))
    {
        // Find minimum residual capacity of the edges along
        // the path filled by BFS. Or we can say find the
        // maximum flow through the path found.
        int path_flow = INT_MAX;
        for (j = to; j != from; j = parent[j])
        {
            i = parent[j];
            path_flow = min(path_flow, rGraph[i][j]);
        }

        // update residual capacities of the edges and
        // reverse edges along the path
        for (j = to; j != from; j = parent[j])
        {
            i = parent[j];
            rGraph[i][j] -= path_flow;
            rGraph[j][i] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // Return the overall flow
    return max_flow;
}

void introduceEdges(int **graph)
{
    for (int i = 0; i < V; i++)
    {
        int j;
        while (true)
        {
            std::cout << "Ce varf se uneste cu varful " << i << "? (introduceti -1 pentru a continua)\n";
            cin >> j;
            if (j < -1 || j > V)
            {
                std::cout << "Valoare invalida, introduceti din nou" << endl;
            }
            else if (j == -1)
                break;
            else
            {
                std::cout << "Ponderea: ";
                cin >> graph[i][j];
            }
        }
    }
}

// Driver program to test above functions
int main()
{
    cout << "numarul de varfuri in graf: ";
    cin >> V;

    // Let us create a graph shown in the above example
    int **graph = new int *[V];
    for (int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    introduceEdges(graph);

    /*graph[0][1] = 27;
    graph[0][2] = 23;
    graph[0][3] = 30;
    graph[1][6] = 13;
    graph[1][4] = 23;
    graph[2][4] = 15;
    graph[2][6] = 9;
    graph[3][5] = 25;
    graph[3][6] = 6;
    graph[4][7] = 32;
    graph[5][4] = 8;
    graph[5][7] = 19;
    graph[6][7] = 29;*/

    cout << "Care varf este sursa? ";
    int source = 1;
    cin >> source;
    cout << "Care varf este destinatia? ";
    int dest = 7;
    cin >> dest;

    cout << "The maximum possible flow is "
         << fordFulkerson(graph, source, dest);

    return 0;
}