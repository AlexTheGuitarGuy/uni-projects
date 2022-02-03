#pragma once
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
                std::cout << tmp->data << ' ';
                tmp = tmp->next;
            }
        }
        else
            std::cout << 0;
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
        for (i = 0; tmp != NULL; i++, tmp = tmp->next)
            ;

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
            std::cout << "\nCare element legat de varf doriti sa-l modificati? (0 pentru a iesi)\n";
            cin >> n;
            if (n == 0)
                return;
            n--;
            if (n >= getLastIndex() - 1 || n < 0)
            {
                std::cout << "\nNu exista elemente la pozitia data, introduceti din nou.\n";
                continue;
            }
            tmp = goToIndex(n);
            done = true;
        }

        done = false;
        while (!done)
        {
            std::cout << "\nCe varf se va afla la pozitia data? (0 pentru a iesi)\n";
            cin >> data;
            if (data == 0)
                return;
            if (isPresent(data))
            {
                std::cout << "\nElementul dat deja exista.";
            }
            else if (data < 0)
                std::cout << "\nValoare invalida.\n";
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
        std::cout << "\nCe varfuri se unesc cu varful dat? (introduceti numere separate sau introduceti 0 pentru a termina)\n";
        while (data != 0)
        {
            while (true)
            {
                cin >> data;
                if (data < 0 || data > v)
                {
                    std::cout << "\nValoare invalida, introduceti din nou\n";
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
                        std::cout << "\nElementul dat deja este prezent, introduceti din nou.\n";
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
            std::cout << "\nCare e pozitia elementului pe care oriti sa-l stergeti? (0 pentru a iesi)\n";
            cin >> n;
            if (n == 0)
                return;
            n--;
            if (n >= getLastIndex() - 1 || n < 0)
            {
                std::cout << "Nu exista elemente la pozitia data, introduceti din nou.";
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

            std::cout << "\nAlegeti operatiunea:\n";

            std::cout << "1. Modificare\n";
            std::cout << "2. Adaugare\n";
            std::cout << "3. Stergere\n";
            std::cout << "4. Alegere varf\n";
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
                std::cout << "\nValoare diferita de diapazonul 1-4, introduceti din nou.\n";
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            std::cout << "\nValoare diferita de int.\n";
            return;
        }
    }
};

class adjacencyList
{
private:
    linked_list list[100];
    int v;

    void modify()
    {

        int mod;

        while (true)
        {
            std::cout << "\nCare varf doriti sa-l modificati? (0 pentru a iesi) ";
            cin >> mod;

            if (mod == 0)
                return;
            else if (mod > v)
            {
                std::cout << "\nValoare invalida.\n";
                continue;
            }
            mod--;
            list[mod].selectOperation(v);
            addEnding();
            print();
        }
    }
    void addEnding()
    {
        for (int i = 0; i < v; i++)
        {
            if (list[i].getTail()->data != 0)
                list[i].push(0);
        }
    }

public:
    bool fail;

    void allocate()
    {
        try
        {
            while (true)
            {
                std::cout << "\nCate varfuri va avea graful? ";
                cin >> v;
                if (v < 1)
                {
                    std::cout << "\nMarime invalida, introduceti din nou.\n";
                }
                else
                    break;
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            std::cout << "\nValoare diferita de int.\n";
            fail = true;
            return;
        }
    }

    void introduce()
    {

        for (int i = 0; i < v; i++)
        {
            int data = 1;
            try
            {
                std::cout << "\nCe varfuri se unesc cu varful " << i + 1 << "? (introduceti numere separate sau introduceti 0 pentru a trece la urmatorul)\n";
                while (data != 0)
                {
                    while (true)
                    {
                        cin >> data;
                        if (data < 0 || data > v)
                        {
                            std::cout << "\nValoare invalida, introduceti din nou\n";
                        }
                        else
                            break;
                    }

                    if (data != 0)
                    {
                        if (!list[i].isPresent(data))
                            list[i].push(data);
                    }
                }
            }
            catch (std::ios_base::failure const &ex)
            {
                std::cout << "\nValoare diferita de int.\n";
                fail = true;
                return;
            }
        }

        addEnding();
    }

    void print()
    {
        std::cout << "\nGraful rezultant:\n";
        for (int i = 0; i < v; i++)
        {
            std::cout << i + 1 << " -> ";
            list[i].print_list();

            std::cout << '\n';
        }
    }

    void shouldModify()
    {
        int change;

        try
        {
            while (true)
            {
                std::cout << "\nDoriti sa modificati vre-un element in graf? (1/0)\n";
                cin >> change;
                if (change != 1 && change != 0)
                {
                    std::cout << "\nValoare diferita de diapazonul oferit, introduceti din nou.\n";
                }
                else if (change == 1)
                {
                    modify();
                    break;
                }
                else
                    break;
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            std::cout << "\nValoare diferita de int.\n";
        }
    }
};
