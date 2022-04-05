#include <boost/graph/bellman_ford_shortest_paths.hpp>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

typedef struct Edge
{
    int from, to, cost;
} Edge;

class Graph
{
private:
    int V, E;
    vector<Edge> edge;

public:
    Graph(int E);
    void introduce();
    void printDist(int dist[], vector<vector<int>> paths, int n, bool isLong);
    void bellmanFord(int from, bool isLong);
    bool isValid(int root);
};

Graph::Graph(int e)
{
    E = e;
    introduce();
}

void Graph::introduce()
{
    V = 0;
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
        newEdge.from = from;
        newEdge.to = to;
        newEdge.cost = cost;
        edge.push_back(newEdge);
    }
    V++;
}

void Graph::printDist(int dist[], vector<vector<int>> paths, int n, bool isLong = false)
{

    std::cout << endl
              << "Varful" << '\t' << "Distanta" << '\t' << "Drum";

    for (int i = 0; i < n; ++i)
    {
        if (isLong && dist[i] != INT_MAX)
            std::cout << endl
                      << i << "\t" << -dist[i] << "\t\t";
        else
            std::cout << endl
                      << i << "\t" << dist[i] << "\t\t";
        if (dist[i] != INT_MAX && dist[i] != INT_MIN)
        {
            for (int j : paths[i])
                std::cout << j << "->";
            std::cout << i;
        }
        else
            break;
    }
}

void Graph::bellmanFord(int from, bool isLong = false)
{
    if (from < V && from >= 0)
    {

        int dist[V];
        vector<vector<int>> paths;
        paths.resize(V);

        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX;
        dist[from] = 0;

        bool updated;
        for (int i = 1; i <= V - 1; i++)
        {
            updated = false;

            for (int j = 0; j < E; j++)
            {
                int u = edge[j].from;
                int v = edge[j].to;
                int cost;
                if (isLong)
                    cost = -abs(edge[j].cost);
                else
                    cost = edge[j].cost;

                if (dist[u] != INT_MAX && dist[u] + cost < dist[v])
                {
                    if ((!paths[v].empty() && u != paths[v].back()) || paths[v].empty())
                        paths[v].push_back(u);

                    dist[v] = dist[u] + cost;
                    if (paths[v][0] != 0)
                    {
                        paths[v].insert(paths[v].begin(), paths[paths[v][0]].begin(), paths[paths[v][0]].end());
                    }
                    updated = true;
                }
            }
            if (updated == false)
                break;
        }

        bool isCycle = false;
        for (int i = 0; i < E && updated == true; i++)
        {
            int u = edge[i].from;
            int v = edge[i].to;
            int cost = edge[i].cost;

            if (dist[u] != INT_MAX && dist[u] + cost < dist[v])
            {
                if (!isLong)
                    dist[v] = INT_MIN;
                else
                    dist[v] = INT_MAX;
                isCycle = true;
            }
        }
        if (isCycle)
            std::cout << endl
                      << "A fost depistat un ciclu infinit.";
        else
            printDist(dist, paths, V, isLong);
        return;
    }
    else
    {
        std::cout << "Valoare invalida, introduceti din nou" << endl;
        return;
    }
}

bool Graph::isValid(int root)
{
    if (root >= 0 && root < V)
        return true;
    return false;
}

int main()
{
    int E;

    std::cout << "Cate muchii va avea graful?" << endl;
    while (true)
    {
        cin >> E;
        if (E > 0)
            break;
        else
            std::cout << "Valoare invalida, introduceti din nou." << endl;
    }
    Graph g(E);

    int root;
    std::cout << endl
              << "Care va fi elementul de la care se va incepe cautarea?" << endl;
    while (true)
    {
        cin >> root;
        if (g.isValid(root))
        {
            std::cout << endl
                      << "Cel mai scrut drum:";
            g.bellmanFord(root);
            std::cout << endl
                      << endl
                      << "Cel mai lung drum:";
            g.bellmanFord(root, true);
            break;
        }
        else
            std::cout << "Valoare invalida, introduceti din nou." << endl;
    }

    return 0;
}