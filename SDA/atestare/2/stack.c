#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char denumire[100];
    char capitala[100];
    int populatie;
} Tara;

#define MAX 10

int count = 0;

struct stack
{
    Tara items[MAX];
    int top;
};
typedef struct stack st;

void createEmptyStack(st *s)
{
    s->top = -1;
}

int isfull(st *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

int isempty(st *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void push(st *s, Tara newitem)
{
    if (isfull(s))
    {
        printf("STACK FULL");
    }
    else
    {
        s->top++;
        s->items[s->top] = newitem;
    }
    count++;
}

void printStruct(Tara in)
{

    printf("\ntara: ");
    printf("%s", in.denumire);
    printf("\ncapitala: ");
    printf("%s", in.capitala);
    printf("\npopulatie: ");
    printf("%d", in.populatie);
    printf("\n");
}

void printStack(st *s)
{
    printf("Stack: ");
    for (int i = 0; i < count; i++)
    {
        printStruct(s->items[i]);
    }
    printf("\n");
}

int main()
{
    int ch;
    st *s = (st *)malloc(sizeof(st));

    createEmptyStack(s);

    Tara tari[3];
    strcpy(tari[0].denumire, "Moldova");
    strcpy(tari[0].capitala, "Chisinau");
    tari[0].populatie = 2000;
    strcpy(tari[1].denumire, "Ucraina");
    strcpy(tari[1].capitala, "Kiiv");
    tari[1].populatie = 5000;
    strcpy(tari[2].denumire, "Rusia");
    strcpy(tari[2].capitala, "Moscova");
    tari[2].populatie = 9000;

    push(s, tari[0]);
    push(s, tari[1]);
    push(s, tari[2]);

    printStack(s);
}
