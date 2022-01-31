#pragma once
#include <iostream>

using namespace std;

// adjacency list classes and functions
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

    node *getTail()
    {
        return tail;
    }

    void push(int n)
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

    void pop()
    {
        node *tmp = new node;
        tmp = head;
        while (tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = NULL;
        tail = tmp;
    }

    void print_list()
    {
        node *tmp = new node;
        tmp = head;
        if (tmp != NULL)
        {
            while (tmp != NULL)
            {
                cout << tmp->data << ' ';
                tmp = tmp->next;
            }
        }
        else
            cout << 0;
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

    int getLastIndex()
    {
        node *tmp = new node;
        tmp = head;

        int i;
        for (i = 0; tmp != NULL; i++, tmp = tmp->next);

        return (i);
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

    void modifyElem()
    {
        node *tmp = new node;
        tmp = head;
        int data, n;
        bool done = false;
        while (!done)
        {
            cout << "\nCare element legat de varf doriti sa-l modificati? (0 pentru a iesi)\n";
            cin >> n;
            if (n == 0)
                return;
            n--;
            if (n >= getLastIndex() - 1 || n < 0)
            {
                cout << "\nNu exista elemente la pozitia data, introduceti din nou.\n";
                continue;
            }
            tmp = goToIndex(n);
                done = true;
        }

        done = false;
        while (!done)
        {
            cout << "\nCe varf se va afla la pozitia data? (0 pentru a iesi)\n";
            cin >> data;
            if (data == 0)
                return;
            if (isPresent(data))
            {
                cout << "\nElementul dat deja exista.";
            }
            else if (data < 0)
                cout << "\nValoare invalida.\n";
            else
            {
                tmp->data = data;
                done = true;
                continue;
            }
        }
    }

    void addElem(int v)
    {
        node *tmp = new node;
        tmp = head;
        int data = 1, n;
        cout << "\nCe varfuri se unesc cu varful dat? (introduceti numere separate sau introduceti 0 pentru a termina)\n";
        while (data != 0)
        {
            while (true)
            {
                cin >> data;
                if (data < 0 || data > v)
                {
                    cout << "\nValoare invalida, introduceti din nou\n";
                }
                else if (data == 0)
                    break;

                if (data != 0)
                {
                    if (!isPresent(data))
                    {
                        tail->data = data;
                    }
                    else
                    {
                        cout << "\nElementul dat deja este prezent, introduceti din nou.\n";
                        break;
                    }
                    push(0);
                }
            }
        }
    }

    void deleteElem()
    {
        node *tmp = new node;
        tmp = head;
        bool done = false;
        int n, data;
        while (!done)
        {
            cout << "\nCare e pozitia elementului pe care oriti sa-l stergeti? (0 pentru a iesi)\n";
            cin >> n;
            if (n == 0)
                return;
            n--;
            if (n >= getLastIndex() - 1 || n < 0)
            {
                cout << "Nu exista elemente la pozitia data, introduceti din nou.";
                continue;
            }
            if (n > 0)
            {
                tmp = goToIndex(n - 1);
                tmp->next = tmp->next->next;
            }
            else if (n == 0)
            {
                head = head->next;
            }
            done = true;
        }
    }

    void selectOperation(int v)
    {
        int choice;
        try
        {

            cout << "\nAlegeti operatiunea:\n";

            cout << "1. Modificare\n";
            cout << "2. Adaugare\n";
            cout << "3. Stergere\n";
            cout << "4. Alegere varf\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                modifyElem();
                break;
            case 2:
                addElem(v);
                break;
            case 3:
                deleteElem();
                break;
            case 4:
                break;
            default:
                cout << "\nValoare diferita de diapazonul 1-4, introduceti din nou.\n";
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
public:
    int v;
    linked_list list[100];
};

// adjacency matrix classes

class adjacencyMatrix
{
public:
    int v;
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
