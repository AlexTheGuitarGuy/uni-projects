#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Graph
{
private:
    int V;
    list<int> *adj;

    bool isPresent(int n, int list_i)
    {
        return (std::find(adj[list_i].begin(), adj[list_i].end(), n) != adj[list_i].end());
    };

public:
    Graph(int v);

    bool isOverSize(int n)
    {
        return (n >= V ? true : false);
    };

    void addEdge(int v, int w);

    void introduce();

    void print();

    void BFS(int s);
};

Graph::Graph(int v)
{
    V = v;

    adj = new list<int>[v];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::introduce()
{
    for (auto i = 0; i < V; i++)
    {
        int data = 0;
        cout << "Ce varfuri se unesc cu varful " << i << "? (-1 pentru a continua)" << endl;
        while (data != -1)
        {
            while (true)
            {
                cin >> data;
                if (data < -1 || data > V - 1)
                {
                    cout << "Valoare invalida, introduceti din nou" << endl;
                }
                else
                    break;
            }
            if (data != -1 && !isPresent(data, i))
                addEdge(i, data);
            else if (isPresent(data, i))
            {
                cout << "Elementul dat este deja prezent, introduceti din nou." << endl;
            }
        }
    }
}

void Graph::print()
{
    cout << "Graful obtinut in forma de lista de adiacenta:" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";
        for (auto const &j : adj[i])
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}

void Graph::BFS(int s)
{
    cout << "Efectuarea cautarii in largime: " << endl;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    list<int> queue;
    visited[s] = true;

    cout << s << " ";
    queue.push_back(s);
    while (!queue.empty())
    {

        s = queue.front();
        queue.pop_front();

        for (auto i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if (!visited[*i])
            {
                cout << *i << " ";
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    int size;
    cout << "Cate varfuri va avea graful?" << endl;
    while (true)
    {
        cin >> size;
        if (size > 0)
            break;
        else
            cout << "Valoare invalida, introduceti din nou." << endl;
    }
    Graph g(size);
    g.introduce();
    g.print();

    int root;
    cout << "Care va fi elementul de la care se va incepe cautarea?" << endl;
    while (true)
    {
        cin >> root;
        if (!g.isOverSize(root) && root >= 0)
        {
            g.BFS(root);
            break;
        }
        else
            cout << "Valoare invalida, introduceti din nou" << endl;
    }

    return 0;
}