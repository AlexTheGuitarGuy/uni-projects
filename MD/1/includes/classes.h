#pragma once
#include <iostream>

using namespace std;

// adjacency list classes

class gl;

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

    node *goToIndex(int n)
    {
        node *tmp = new node;
        tmp = head;

        int i;
        for (i = 0; tmp != NULL; i++)
        {
            if (i == n)
                return tmp;
            tmp = tmp->next;
        }
        if (i < n)
        {
            return NULL;
        }
        else
            return tmp;
    }

    node *goToData(int data)
    {
        node *tmp = new node;
        tmp = head;
        while (tmp != NULL)
        {
            if (tmp->data == data)
                return tmp;
            tmp = tmp->next;
        }
        return NULL;
    }

    void selectOperation(graphList input, int location)
    {
        int choice, n, data;
        node *tmp = new node;
        tmp = head;

        bool done = false;
        try
        {

            cout << "\nAlegeti operatiunea:\n";
            while (!done)
            {
                cout << "1. Modificare\n";
                cout << "2. Adaugare\n";
                cout << "3. Stergere\n";
                cout << "0. Iesire\n";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    while (true)
                    {
                        cout << "\nCare element legate de varf doriti sa-l modificati?\n";
                        cin >> n;
                        n--;
                        if (n > input.v)
                        {
                            cout << "Nu exista elemente la pozitia data, introduceti din nou.";
                            continue;
                        }
                        tmp = goToIndex(n);
                        break;
                    }
                    while (true)
                    {
                        cout << "\nCe varf se va afla la pozitia data?\n";
                        cin >> data;
                        if (isPresent(data))
                        {
                            cout << "\nElementul dat deja exista.";
                        }
                        else if (data != input.v)
                        {
                            tmp->data = data;
                            break;
                        }

                        if (!input.isOriented)
                        {
                            tmp = input.graphList[data].goToData(location);
                            tmp->data = data;
                        }
                    }
                    cout << "\nDoriti sa mai efectuati vre-o operatiune?";
                    break;
                case 2:

                    break;
                case 0:
                    done = true;
                    break;
                default:
                    cout << "\nValoare diferita de 1 si 2, introduceti din nou.\n";
                }
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            cout << "\nValoare diferita de int.\n";
            return;
        }
    }
};

class graphList
{
    class gl fuck;
};

// adjacency matrix classes

class adjacencyMatrix
{
public:
    int v;
    int isOriented;
    int **arr;
};

// incidency matrix classes

class incidencyMatrix
{
public:
    int v;
    int m;
    int isOriented;
    int **arr;
};
