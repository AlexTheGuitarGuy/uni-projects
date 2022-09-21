// C++ program for Kruskal's algorithm to find Minimum
// Spanning Tree of a given connected, undirected and
// weighted graph
#include <bits/stdc++.h>
using namespace std;

// Creating shortcut for an integer pair
typedef pair<int, int> iPair;

// Structure to represent a graph
struct Graph
{
    int V, E;
    vector<pair<int, iPair>> edges;

    // Constructor
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    // Utility function to add an edge
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    // Function to find MST using Kruskal's
    // MST algorithm
    int kruskalMST();
};

// To represent Disjoint Sets
struct DisjointSets
{
    int *parent, *rnk;
    int n;

    // Constructor.
    DisjointSets(int n)
    {
        // Allocate memory
        this->n = n;
        parent = new int[n + 1];
        rnk = new int[n + 1];

        // Initially, all vertices are in
        // different sets and have rank 0.
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;

            // every element is parent of itself
            parent[i] = i;
        }
    }

    // Find the parent of a node 'u'
    // Path Compression
    int find(int u)
    {
        /* Make the parent of the nodes in the path
           from u--> parent[u] point to parent[u] */
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // Union by rank
    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        /* Make tree with smaller height
           a subtree of the other tree  */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

/* Functions returns weight of the MST*/

int Graph::kruskalMST()
{
    int mst_wt = 0; // Initialize result

    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());

    // Create disjoint sets
    DisjointSets ds(V);

    // Iterate through all sorted edges
    vector<pair<int, iPair>>::iterator it;
    for (it = edges.begin(); it != edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v)
        {
            // Current edge will be in the MST
            // so print it
            cout << u << " - " << v << endl;

            // Update MST weight
            mst_wt += it->first;

            // Merge two sets
            ds.merge(set_u, set_v);
        }
    }

    return mst_wt;
}

void printAdjMatrix(Graph g)
{
    cout << endl
         << endl
         << "Reprezentarea grafului ca matrice de adiacenta:";
    vector<vector<int>> m(
        g.V,
        vector<int>(g.V));

    for (int i = 0; i < g.E; i++)
    {
        std::pair<int, iPair> coords;
        coords = g.edges[i];
        int x = coords.second.first;
        int y = coords.second.second;
        int w = coords.first;

        m[x - 1][y - 1] = w;
        m[y - 1][x - 1] = w;
    }

    for (int i = 0; i < g.V; i++)
    {
        cout << endl;
        for (int j = 0; j < g.V; j++)
            cout << m[i][j] << ' ';
    }
}

void printAdjList(Graph g)
{
    cout << endl
         << endl
         << "Reprezentarea grafului ca lista de adiacenta:";
    vector<vector<int>> m;

    for (int i = 0; i < g.E; i++)
    {
        vector<int> tmp;
        tmp.push_back(i + 1);
        m.push_back(tmp);
    }

    for (int i = 0; i < g.E; i++)
    {
        for (int i = 0; i < g.E; i++)
        {
            std::pair<int, iPair> coords;
            coords = g.edges[i];
            int x = coords.second.first;
            int y = coords.second.second;
            int w = coords.first;

            if (!std::count(m[x - 1].begin(), m[x - 1].end(), y))
                m[x - 1].push_back(y);
            if (!std::count(m[y - 1].begin(), m[y - 1].end(), x))
                m[y - 1].push_back(x);
        }
    }

    for (int i = 0; i < g.V; i++)
    {
        cout << endl;
        cout << m[i][0] << " -> ";
        for (int j = 1; j < m[i].size(); j++)
            cout << m[i][j] << ' ';
    }
}

void printIncMatrix(Graph g)
{
    cout << endl
         << endl
         << "Reprezentarea grafului ca matrice de incidenta:";
    vector<vector<int>> m(
        g.E,
        vector<int>(g.V));

    for (int i = 0; i < g.E; i++)
    {
        std::pair<int, iPair> coords;
        coords = g.edges[i];
        int x = coords.second.first;
        int y = coords.second.second;
        int w = coords.first;

        m[i][x - 1] = 1;
        m[i][y - 1] = 1;
    }

    for (int i = 0; i < g.V; i++)
    {
        cout << endl;
        for (int j = 0; j < g.V; j++)
            cout << m[i][j] << ' ';
    }
}

// Driver program to test above functions
int main()
{
    /* Let us create above shown weighted
       and undirected graph */
    // cout << "Cate varfuri si muchii are graful?" << endl;
    int V = 9, E = 11;
    // cin >> V >> E;
    Graph g(V, E);

    /*int u, v, w;
    cout << "introduceti muchiile" << endl;
    int i = 0;
    while (i < g.E)
    {
        cout << "varful " << i + 1 << endl;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
        i++;
    }*/

    //  making above shown graph
    g.addEdge(1, 2, 4);
    g.addEdge(1, 7, 8);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 7, 11);
    g.addEdge(3, 4, 7);
    g.addEdge(3, 9, 2);
    g.addEdge(3, 6, 4);
    g.addEdge(9, 7, 6);
    g.addEdge(7, 6, 2);
    g.addEdge(4, 5, 9);
    g.addEdge(6, 4, 10);

    cout << "Edges of MST are \n";
    int mst_wt = g.kruskalMST();

    cout << "\nWeight of MST is " << mst_wt;

    printAdjMatrix(g);
    printAdjList(g);
    printIncMatrix(g);

    return 0;
}
