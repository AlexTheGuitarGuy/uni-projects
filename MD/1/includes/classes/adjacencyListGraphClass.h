#pragma once
#include <iostream>
#include <fstream>

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

    int *to_array()
    {
        node *tmp = new node;
        tmp = head;
        int *res = new int[size()];
        int i = 0;
        if (tmp != NULL)
        {
            while (tmp != NULL)
            {
                res[i] = tmp->data;
                tmp = tmp->next;
                i++;
            }
        }

        return (res);
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

    void deleteData(int data)
    {
        node *tmp = new node;
        tmp = head;
        for (int i = 0; i < getLastIndex(); i++)
        {
            if (tmp->data == data)
                deleteElem(i);
            tmp = tmp->next;
        }
    }

    void deleteV()
    {
        node *tmp = new node;
        tmp = head;
        if (size() > 2)
        {
            for (int i = 0; size() > 2; i++)
            {
                deleteElem(i);
                tmp = tmp->next;
            }
            deleteElem(0);
        }
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

            cin >> data;
            if (data < 0 || data > v)
            {
                std::cout << "\nValoare invalida, introduceti din nou\n";
                continue;
            }
            else if (data == 0)
                break;
            else if (data != 0)
            {
                if (!isPresent(data))
                {
                    if (size() > 1 && goToIndex(getLastIndex() - 1)->data == 0)
                        pop();
                    push(data);
                }
                else
                {
                    std::cout << "\nElementul dat deja este prezent, introduceti din nou.\n";
                    continue;
                }
            }
        }
        push(0);
    }

    void deleteElem(int pos)
    {
        node *tmp = new node;
        tmp = head;
        bool done = false;
        while (!done)
        {
            if (pos > 0)
            {
                tmp = goToIndex(pos - 1);
                tmp->next = tmp->next->next;
            }
            else if (pos == 0)
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

            std::cout << "\nAlegeti operatiunea pentru varf:\n";

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
                if (size() < 1)
                {
                    cout << "\nNu exista elemente legate de varful dat.\n";
                    break;
                }
                std::cout << "\nCare e pozitia elementului pe care oriti sa-l stergeti? (0 pentru a iesi)\n";
                int pos;
                cin >> pos;
                if (pos == 0)
                    break;
                pos--;
                while (pos >= getLastIndex() - 1 || pos < 0)
                {
                    std::cout << "\nNu exista elemente de sters la pozitia data, introduceti din nou. \n";
                    cin >> pos;
                    if (pos == 0)
                        break;
                    pos--;
                }
                deleteElem(pos);
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

    int size()
    {
        node *tmp = new node;
        tmp = head;
        int i = 0;
        if (tmp != NULL)
        {
            while (tmp != NULL)
            {
                i++;
                tmp = tmp->next;
            }
        }
        return (i);
    }

    void freeList()
    {
        node *tmp = new node;

        while ((tmp = head) != NULL)
        {
            head = head->next;
            delete tmp;
        }
    }
};

class adjacencyList
{
private:
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
            print(-1);
        }
    }

    void add()
    {
        int add;
        try
        {
            while (true)
            {
                cout << "\nCate varfuri doriti sa adaugati?\n";
                cin >> add;
                if (add < 0)
                {
                    cout << "\nValoare invalida, introduceti din nou.\n";
                    continue;
                }
                v += add;
                break;
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            std::cout << "\nValoare diferita de int.\n";
            return;
        }
    }

    void deleteVs()
    {
        int del;

        while (true)
        {
            std::cout << "\nCare varf doriti sa-l stergeti? (0 pentru a iesi) ";
            cin >> del;

            if (del == 0)
                return;
            else if (del > v)
            {
                std::cout << "\nValoare invalida.\n";
                continue;
            }
            del--;
            list[del].deleteV();
            linked_list tmp;
            for (int i = del; del < v; del++)
            {
                tmp = list[del];
                list[del] = list[del + 1];
                list[del + 1] = tmp;
            }
            v--;
            print(-1);
        }
    }

    void selectOperation()
    {
        int choice;
        try
        {
            bool done = false;
            while (!done)
            {
                std::cout << "\nAlegeti operatiunea pentru lista:\n";

                std::cout << "1. Modificare\n";
                std::cout << "2. Adaugare\n";
                std::cout << "3. Stergere\n";
                std::cout << "0. Iesire\n";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    modify();
                    print(-1);
                    break;
                case 2:
                    add();
                    print(-1);
                    break;
                case 3:
                    deleteVs();
                    print(-1);
                    break;
                case 0:
                    done = true;
                    break;
                default:
                    std::cout << "\nValoare diferita de diapazonul oferit, introduceti din nou.\n";
                }
            }
        }
        catch (std::ios_base::failure const &ex)
        {
            std::cout << "\nValoare diferita de int.\n";
            return;
        }
    }

public:
    bool fail = false;
    int isMade = 0;
    bool shouldSave = true;
    string name;
    linked_list list[100];
    int v;

    void addEnding()
    {
        for (int i = 0; i < v; i++)
        {
            if (list[i].size() > 0)
            {
                if (list[i].getTail()->data != 0)
                    list[i].push(0);
            }
        }
    }

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

    void print(int i)
    {
        switch (i)
        {
        case -1:
            std::cout << "\nGraful rezultant:\n";
            break;
        default:
            std::cout << "\nLista de adiacenta pentru graful \"" << name << "\":\n";
        }
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
        print(1);
        try
        {
            while (true)
            {
                std::cout << "\nDoriti sa modificati graful dat? (1/0)\n";
                cin >> change;
                if (change != 1 && change != 0)
                {
                    std::cout << "\nValoare diferita de diapazonul oferit, introduceti din nou.\n";
                }
                else if (change == 1)
                {
                    selectOperation();
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

    void make()
    {

        cin.exceptions(std::ios_base::failbit);

        allocate();
        if (!fail)
        {
            introduce();
            if (!fail)
            {
                cout << "\nCum se va numi graful dat? (fara spatii)\n";
                cin >> name;
                print(1);
                isMade = 1;
            }
        }
    }

    void serialize(std::ostream &out)
    {
        if (shouldSave)
        {
            int **arr = new int *[v];
            for (int i = 0; i < v; i++)
            {
                if (list[i].size() >= 1)
                    arr[i] = list[i].to_array();
                else
                {
                    arr[i] = new int;
                    arr[i][0] = 0;
                }
            }
            if (!out)
            {
                cout << "Nu poate fi deschis fisierul!" << endl;
            }
            out << name << ' ';
            out << v << ' ';
            int j = 0;
            for (int i = 0; i < v; i++)
            {
                for (j = 0; arr[i][j] != 0; j++)
                    out << arr[i][j] << ' ';
                out << arr[i][j] << ' ';
            }

            if (!out.good())
            {
                cout << "S-a produs o eroare in timpul scrierii!" << endl;
            }
            shouldSave = false;
        }
    }

    void deserialize(std::istream &file)
    {
        file >> name;
        file >> v;
        if (!file)
        {
            cout << "Nu poate fi deschis fisierul!" << endl;
            return;
        }
        int tmp;
        for (int i = 0; i < v; i++)
        {
            do
            {
                file >> tmp;
                if (file.fail()) /* handle with break or throw */
                    return;
                list[i].push(tmp);
            } while (tmp != 0);
        }
        isMade = 1;
        shouldSave = false;

        if (!file.good())
        {
            cout << "S-a produs o eroare in timpul citirii!" << endl;
            return;
        }
        return;
    }

    void freeGraph()
    {
        for (int i = 0; i < v; i++)
        {
            list[i].freeList();
        }
        isMade = false;
        shouldSave = false;
    }

};
