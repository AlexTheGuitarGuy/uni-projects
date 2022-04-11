#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;

// Data structure to store graph edges
struct Edge
{
    int source, dest, weight;
};

// Recursive function to print the path of (just) the first given vertex from source vertex.
void printPath(vector<vector<int>> const &parent, vector<int> const &vlist)
{
    if (vlist.empty())
        return;

    int v = vlist.front();
    printPath(parent, parent[v]);
    cout << v << " ";
}
// Function to run Bellman Ford Algorithm from given source
void BellmanFord(vector<Edge> const &edges, int source, int N)
{
    // count number of edges present in the graph
    int E = edges.size();

    // distance[] and parent[] stores shortest-path (least cost/path)
    // information. Initially all vertices except source vertex have
    // a weight of infinity and a no parent

    vector<int> distance(N, INT_MAX);
    distance[source] = 0;

    vector<vector<int>> parent(N);

    int u, v, w, k = N;

    // Relaxation step (run V-1 times)
    while (--k)
    {
        for (int j = 0; j < E; j++)
        {
            // edge from u to v having weight w
            u = edges[j].source, v = edges[j].dest;
            w = edges[j].weight;

            // if the distance to the destination v can be
            // shortened by taking the edge u-> v
            if (distance[u] != INT_MAX)
            {
                // if the distance to the destination v can be
                // shortened by taking the edge u-> v
                if (distance[u] + w < distance[v])
                {
                    // update distance to the new lower value
                    distance[v] = distance[u] + w;
                    // forget the previous parent list.
                    parent[v].clear();
                }
                // if u-> v is a way to get the shortest
                // distance to the destination v.
                if (distance[u] + w == distance[v])
                {
                    // add u as a possible parent for v
                    parent[v].push_back(u);
                }
            }
        }
    }

    // Run Relaxation step once more for Nth time to
    // check for negative-weight cycles
    for (int i = 0; i < E; i++)
    {
        // edge from u to v having weight w
        u = edges[i].source, v = edges[i].dest;
        w = edges[i].weight;

        // if the distance to the destination u can be
        // shortened by taking the edge u-> v
        if (distance[u] != INT_MAX && distance[u] + w < distance[v])
        {
            cout << "Negative Weight Cycle Found!!";
            return;
        }
    }

    for (int i = 0; i < N; i++)
    {

        cout << "Distance of vertex " << i << " from the source is "
             << setw(2) << distance[i] << ". It's path is [ ";

        printPath(parent, parent[i]);
        cout << "]" << '\n';
    }
}

// main function
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges =
        {
            // (x, y, w) -> edge from x to y having weight w
            {0, 1, 3},
            {0, 2, 6},
            {0, 4, 8},
            {1, 2, 2},
            {1, 3, 1},
            {2, 3, 1},
            {2, 4, 2},
            {2, 6, 4},
            {3, 4, 3},
            {3, 5, 3},
            {3, 7, 6},
            {4, 5, 1},
            {4, 6, 2},
            {4, 7, 3},
            {5, 7, 3},
            {6, 7, 2},
        };

    // Set maximum number of nodes in the graph
    int N = 8;

    // let source be vertex 0
    int source = 0;

    // run Bellman Ford Algorithm from given source
    BellmanFord(edges, source, N);

    return 0;
}
