#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista
{
    char nume[20];
    float nota;
    struct Lista *next;
} Lista;
Lista *prim = NULL;
int firstRun = 1;

int subMeniu()
{
    printf("Dupa nume..............1\n");
    printf("Dupa nota..............2\n");
    printf("Dupa numar de ordine...3\n");
    printf("Anulare................0\n");
    int sm;
    scanf("%d", &sm);
    return sm;
}

void Creare()
{
    char rasp;
    Lista *p, *q;
    int i = 0;
    /*q = (Lista *)malloc(sizeof(Lista));
    printf("Introduceti datele despre studentul %d:\n", ++i);
    printf("Numele: "); scanf("%s", q->nume);
    printf("Nota: "); scanf("%f", &q->nota);
    q->next = NULL;
    prim = q;//q a devenit primul si unicul element al listei
    p = q;//p- ultimul element*/
    do
    {
        q = (Lista *)malloc(sizeof(Lista));
        printf("Introduceti datele despre studentul %d:\n", ++i);
        printf("Numele: ");
        scanf("%s", q->nume);
        printf("Nota: ");
        scanf("%f", &q->nota);
        q->next = NULL;
        if (prim == NULL)
            prim = q; // q a devenit primul si unicul element al listei
        else
            p->next = q; // facem legatura- elementul care a fost ultimul va contine adresa nodului nou adaugat
        p = q;           // p- adresa ultimului element
        printf("Mai introduceti date despre studenti?[d/n]-> ");
        rasp = getchar();
        printf("\n");
    } while (rasp == 'd');
    printf("Datele despre %d studenti au fost inscrise in lista!\n", i);
}

void Afisare()
{
    Lista *p;
    int i = 1;
    if (prim == NULL)
        printf("Lista este vida! Mai intai alocati memorie!\n");
    else
    {
        printf("Lista studentilor: \n");
        p = prim;
        while (p)
        {
            printf("%2d) %-10s Nota: %4.2f\n", i++, p->nume, p->nota);
            p = p->next;
        }
    }
}

void Adaugare()
{
    Lista *p, *q;
    int i = 0;
    if (prim == NULL)
    {
        printf("Lista este vida! \n"); // Apelam functia de creare a listei!\n");
        // Creare();
        // return;
    }
    else
    {
        p = prim;
        // int i = 1;
        while (p->next)
        { // p va contine adresa ultimului element
            i++;
            p = p->next;
        }
        i++;
    }
    q = (Lista *)malloc(sizeof(Lista));
    printf("Introduceti datele despre studentul %d:\n", ++i);
    printf("Numele: ");
    scanf("%s", q->nume);
    printf("Nota: ");
    scanf("%f", &q->nota);
    q->next = NULL;
    if (prim == NULL)
        prim = q; // q a devenit primul si unicul element al listei
    else
        p->next = q; // facem legatura- elementul care a fost ultimul va contine adresa nodului nou adaugat
    // p = q;//p- adresa ultimului element- aici nu este necesar, deoarece adaugam doar un student
}

Lista *Cautare()
{
    if (prim == NULL)
    {
        printf("Lista este vida!\n");
        return NULL;
    }
    Lista *p, *q = NULL;
    int sm = subMeniu();
    switch (sm)
    {
    case 1:
    {
        char nume[20];
        printf("Introduceti numele: ");
        scanf("%s", nume);
        printf("Lista studentilor cu numele %s:\n", nume);
        p = prim;
        // int i = 1;
        while (p)
        {
            if (strcmp(p->nume, nume) == 0)
            {
                printf("%-10s Nota: %4.2f\n", p->nume, p->nota);
                if (q == NULL)
                    q = p; // vom pastra adresa primului nod cu nota indicata
            }
            p = p->next;
        }
        // printf("q=%p", q);
        if (q == NULL) // daca nu am gasit asa studenti
            printf("Nu am gasit asa student!\n");
        return q;
    }
    break;

    case 2:
    {
        float nota;
        // q = NULL;
        printf("Introduceti nota: ");
        scanf("%f", &nota);
        printf("Lista studentilor cu nota %4.2f:\n", nota);
        p = prim;
        // int i = 1;
        while (p)
        {
            if (p->nota == nota)
            {
                printf("%-10s Nota: %4.2f\n", p->nume, p->nota);
                if (q == NULL)
                    q = p; // vom pastra adresa primului nod cu nota indicata
            }
            p = p->next;
        }
        // printf("q=%p", q);
        if (q == NULL) // daca nu am gasit asa studenti
            printf("Nu am gasit asa student!\n");
        return q;
    }
    break;

    case 3:
    {
        int nr;
        printf("Introduceti numarul de ordine (numerotare de la 1): ");
        scanf("%d", &nr);
        p = prim;
        int i = 1;
        while (p && i != nr)
        {
            p = p->next;
            i++;
        }
        if (p == NULL)
            printf("Nu am gasit asa student!\n");
        else
            printf("%2d) %s Nota: %4.2f\n", nr, p->nume, p->nota);
        return p;
    }
    break;

    default:
        printf("Criteriu incorect!\n");
    }
}

void Modificare()
{
    printf("Atentie! Daca exista mai multi studenti cu numele sau nota introdusa se va modifica doar primul!\n");
    Lista *q = Cautare();
    if (q)
    {
        printf("Numele nou: ");
        scanf("%s", q->nume);
        printf("Nota noua: ");
        scanf("%f", &q->nota);
    }
}

void Eliminare()
{
    if (prim == NULL)
    {
        printf("Lista este vida!\n");
        return;
    }
    // de realizat
}

void Sortare()
{
}

void StergereLista()
{
    Lista *p, *q;
    if (prim == NULL)
    {
        printf("Lista este vida!\n");
        return;
    }
    // p = prim;
    while (prim)
    {
        p = prim;          // salvam adresa fostului prim element, care va fi sters
        prim = prim->next; // al doilea element devine primul; cand ajungem la ultimul element prim va primi valoarea NULL
        free(p);
    }
    printf("Lista a fost stearsa cu succes!\n");
}

int Meniu()
{
    if (firstRun)
        firstRun = 0;
    else
    {
        system("pause");
        system("cls");
    }
    printf("Crearea si completarea listei..1\n");
    printf("Afisarea studentilor...........2\n");
    printf("Adaugarea unui student.........3\n");
    printf("Modificarea unui student.......4\n");
    printf("Cautarea studentului...........5\n");
    printf("Eliminarea unui student........6\n");
    printf("Sortarea listei de studenti....7\n");
    printf("Stergerea listei...............8\n");
    printf("Iesire din program.............0\n");
    int m;
    scanf("%d", &m);
    return m;
}

int main()
{
    int m;
    do
    {
        m = Meniu();
        switch (m)
        {
        case 1:
            Creare();
            break;
        case 2:
            Afisare();
            break;
        case 3:
            Adaugare();
            break;
        case 4:
            Modificare();
            break;
        case 5:
            Cautare();
            break;

        case 8:
            StergereLista();
            break;

        case 0:
            StergereLista();
            printf("Autorul programului este Mititelu Vitalii!\n");
            break;
        default:
            printf("Optiune incorecta! Mai incercati!\n");
        }
    } while (m != 0);

    return 0;
}
