#include <bits/stdc++.h>
#include <iostream>
#include <vector>

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
    void printDist(int dist[], vector<vector<int>> paths, int n);
    void bellmanFord(int from);
};

Graph::Graph(int e)
{
    E = e;
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
            cout << "Ce varfuri uneste muchia " << e << "?\n";
            cin >> from;
            cin >> to;
            if (from < 0 || to < 0)
            {
                cout << "Valoare invalida, introduceti din nou" << endl;
            }
            else
            {
                if (from > V)
                    V = from;
                if (to > V)
                    V = to;
                cout << "Ponderea: ";
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

void Graph::printDist(int dist[], vector<vector<int>> paths, int n)
{

    cout << endl
         << "Varful" << '\t' << "Distanta" << '\t' << "Drum";

    for (int i = 0; i < n; ++i)
    {
        cout << endl
             << i << "\t" << dist[i] << "\t\t";
        if (dist[i] != INT_MAX && dist[i] != INT_MIN)
        {
            for (int j : paths[i])
                cout << j << "->";
            cout << i;
        }
    }
}

void Graph::bellmanFord(int from)
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
                int cost = edge[j].cost;

                if (dist[u] != INT_MAX && dist[u] + cost < dist[v])
                {
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

        for (int i = 0; i < E && updated == true; i++)
        {
            int u = edge[i].from;
            int v = edge[i].to;
            int cost = edge[i].cost;

            if (dist[u] != INT_MAX && dist[u] + cost < dist[v])
            {
                dist[v] = INT_MIN;
            }
        }

        printDist(dist, paths, V);
        std::exit(0);
    }
    else
    {
        cout << "Valoare invalida, introduceti din nou" << endl;
        return;
    }
}

int main()
{
    int E;

    cout << "Cate muchii va avea graful?" << endl;
    while (true)
    {
        cin >> E;
        if (E > 0)
            break;
        else
            cout << "Valoare invalida, introduceti din nou." << endl;
    }

    Graph g(E);

    g.introduce();
    int root;
    cout << endl
         << "Care va fi elementul de la care se va incepe cautarea?" << endl;
    while (true)
    {
        cin >> root;
        g.bellmanFord(root);
    }

    return 0;
}