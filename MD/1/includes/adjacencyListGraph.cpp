#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head, *tail;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void print_list()
    {
        node *tmp = new node;
        tmp = head;
        while (tmp->next != NULL)
        {
            cout << tmp->data << ' ';
            tmp = tmp->next;
        }
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }

};

int v;
int fail = 0;
int isOriented = 0;
linked_list graph[100];


void graphAllocate()
{
    try
    {

        cout << "Cate varfuri va avea graful? ";
        cin >> v;
        if (v < 1)
        {
            cout << "\nMarime invalida.\n";
            fail = 1;
            return;
        }
        cout << "\n";

        //graph = (linked_list *)malloc(v * sizeof(linked_list));
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        fail = 1;
        return;
    }
}

void graphIntroduce()
{

    for (int i = 0; i < v; i++)
    {
        int data = 1;
        try
        {
            cout << "\nCe varfuri se unesc cu varful " << i + 1 << "? (introduceti numere separate sau introduceti 0 pentru a inceta)\n";
            while (data != 0)
            {
                cin >> data;
                if (data < 0 || data > v)
                {
                    cout << "\nValoare invalida\n";
                    fail = 1;
                    return;
                }
                graph[i].add_node(data);
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            fail = 1;
            return;
        }
    }
}

void graphPrint()
{
    cout << "\nGraful rezultant:\n";
    for (int i = 0; i < v; i++)
    {
        cout << i + 1 << " -> ";

        graph[i].print_list();
        cout << '\n';
    }
}

int adjacencyListGraph()
{
    cin.exceptions(std::ios_base::failbit);

    // cout << "\nEste orientat graful dat? (1/0)\n";
    // cin >> isOriented;

    graphAllocate();
    if (fail)
        return (0);
    graphIntroduce();

    if (fail)
        return (0);

    graphPrint();
    if (fail)
        return (0);

    return (1);
}
