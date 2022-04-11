#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;

// Data structure to store graph edges
struct Edge
{
    int source, dest, weight;
};

bool isLong = false;

// Recursive function to print the path of (just) the first given vertex from source vertex.
void getPath(vector<vector<int>> const parent, vector<int> const vlist, int pathNum, vector<int> &resPath)
{
    if (vlist.empty())
        return;

    int v = vlist[pathNum];
    getPath(parent, parent[v], pathNum, resPath);
    resPath.push_back(v);
}

vector<vector<int>> parse(vector<vector<int>> const &parent, int dest, int N)
{
    vector<vector<int>> res(N);

    for (int i = 0; i < parent.size(); i++)
    {
        getPath(parent, parent[dest], i, res[i]);
    }
    return res;
}

bool isValid(int from, int to, vector<Edge> const &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        if (from == edges[i].source && to == edges[i].dest)
        {
            return true;
        }
    }
    return false;
}

void removeDuplicates(std::vector<vector<int>> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it)
    {
        end = std::remove(it + 1, end, *it);
    }

    v.erase(end, v.end());
}

void cleanPaths(vector<vector<int>> &resPath, vector<Edge> const &edges)
{
    removeDuplicates(resPath);

    for (int k = 0; k < resPath.size(); k++)
    {
        for (int i = 0, j = 1; j < resPath[k].size(); i++, j++)
        {
            if (!isValid(resPath[k][i], resPath[k][j], edges))
                resPath.erase(resPath.begin() + k);
        }
    }
}

void printPaths(vector<vector<int>> parent, int dest, vector<int> distance, vector<Edge> const &edges)
{
    if (!isLong)
    {
        cout << "Shortest distance of vertex " << dest << " from the source is "
             << distance[dest] << ". It's paths are:\n";
    }
    else
    {
        cout << "Longest distance of vertex " << dest << " from the source is "
             << -distance[dest] << ". It's paths are:\n";
    }
    vector<vector<int>> res = parse(parent, dest, parent.size());
    cleanPaths(res, edges);
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "]" << endl;
    }
}

// Function to run Bellman Ford Algorithm from given source
void BellmanFord(vector<Edge> const &edges, int source, int dest, int N)
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

            // if the distance to the dest v can be
            // shortened by taking the edge u-> v
            if (distance[u] != INT_MAX)
            {
                // if the distance to the dest v can be
                // shortened by taking the edge u-> v
                if (distance[u] + w < distance[v])
                {
                    // update distance to the new lower value
                    distance[v] = distance[u] + w;
                    // forget the previous parent list.
                    parent[v].clear();
                }
                // if u-> v is a way to get the shortest
                // distance to the dest v.
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

        // if the distance to the dest u can be
        // shortened by taking the edge u-> v
        if (distance[u] != INT_MAX && distance[u] + w < distance[v])
        {
            cout << "Negative Weight Cycle Found!!";
            return;
        }
    }

    printPaths(parent, dest, distance, edges);
}

void togglePathType(vector<Edge> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        edges[i].weight *= -1;
    }
    isLong = !isLong;
}

int introduceEdges(vector<Edge> &edges)
{
    int E, V = 0;
    cout << "Cate muchii va avea graful? ";
    cin >> E;
    for (int e = 0; e < E; e++)
    {
        int from = 0;
        int to = 0;
        int cost;
        while (true)
        {
            std::cout << "Ce varfuri uneste muchia " << e << "?\n";
            cin >> from;
            cin >> to;
            if (from < 0 || to < 0)
            {
                std::cout << "Valoare invalida, introduceti din nou" << endl;
            }
            else
            {
                if (from > V)
                    V = from;
                if (to > V)
                    V = to;
                std::cout << "Ponderea: ";
                cin >> cost;
                break;
            }
        }
        Edge newEdge;
        newEdge.source = from;
        newEdge.dest = to;
        newEdge.weight = cost;
        edges.push_back(newEdge);
    }
    V++;
    return V;
}

// main function
int main()
{
    // vector of graph edges as per above diagram
    /*vector<Edge> edges =
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
        };*/

    vector<Edge> edges;

    // Set maximum number of nodes in the graph
    int N = introduceEdges(edges);

    // let source be vertex 0
    cout << "Care varf este sursa? ";
    int source;
    cin >> source;
    cout << "Care varf este destinatia? ";
    int dest;
    cin >> dest;

    // run Bellman Ford Algorithm from given source
    BellmanFord(edges, source, dest, N);
    togglePathType(edges);
    BellmanFord(edges, source, dest, N);

    return 0;
}
