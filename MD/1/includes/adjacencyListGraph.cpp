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

    bool isPresent(int data)
    {
        node *tmp = new node;
        tmp = head;
        while (tmp != NULL)
        {
            if (tmp->data == data)
                return true;
            tmp = tmp->next;
        }
        return false;
    }
};

int v;
int listFail = 0;
int listIsOriented = 0;
linked_list graphList[100];

void graphListAllocate()
{
    try
    {
        while (true)
        {
            cout << "\nCate varfuri va avea graful? ";
            cin >> v;
            if (v < 1)
            {
                cout << "\nMarime invalida, introduceti din nou.\n";
            }
            else
                break;
        }

        // graphList = (linked_list *)malloc(v * sizeof(linked_list));
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        listFail = 1;
        return;
    }
}

void graphListIntroduce()
{

    for (int i = 0; i < v; i++)
    {
        int data = 1;
        try
        {
            cout << "\nCe varfuri se unesc cu varful " << i + 1 << "? (introduceti numere separate sau introduceti 0 pentru a trece la urmatorul)\n";
            while (data != 0)
            {
                while (true)
                {
                    cin >> data;
                    if (data < 0 || data > v)
                    {
                        cout << "\nValoare invalida, introduceti din nou\n";
                    }
                    else
                        break;
                }

                if (data != 0)
                {
                    if (!graphList[i].isPresent(data))
                        graphList[i].add_node(data);
                    if (!graphList[data - 1].isPresent(i + 1) && !listIsOriented)
                        graphList[data - 1].add_node(i + 1);
                }
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            listFail = 1;
            return;
        }
    }

    for (int i = 0; i < v; i++)
    {
        graphList[i].add_node(0);
    }
}

void graphListPrint()
{
    cout << "\nGraful rezultant:\n";
    for (int i = 0; i < v; i++)
    {
        cout << i + 1 << " -> ";
        graphList[i].print_list();
        cout << '\n';
    }
}

int adjacencyListGraph()
{
    cin.exceptions(std::ios_base::failbit);

    try
    {
        while (true)
        {
            cout << "\nEste orientat graful dat? (1/0)\n";
            cin >> listIsOriented;
            if (listIsOriented != 1 && listIsOriented != 0)
            {
                cout << "\nValoare diferita de 1 si 0, introduceti din nou.\n";
            }
            else
                break;
        }
    }
    catch (std::ios_base::failure const &ex)
    {
        cout << "\nValoare diferita de int.\n";
        return 0;
    }

    graphListAllocate();
    if (listFail)
        return (0);
    graphListIntroduce();

    if (listFail)
        return (0);

    graphListPrint();
    if (listFail)
        return (0);

    return (1);
}
