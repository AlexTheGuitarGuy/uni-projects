#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRLEN 20

typedef struct
{
    char modelul[MAX_STRLEN];
    char procesorul[MAX_STRLEN];
    float memoria;
    float viteza;
    float pretul;
} Computer;

typedef struct Node
{
    Computer value;
    struct Node *left;
    struct Node *right;
} Node;

Node *root = NULL;

Computer introduce_struct()
{
    Computer in;
    printf("modelul: ");
    scanf("%s", in.modelul);
    printf("procesorul: ");
    scanf("%s", in.procesorul);
    printf("memoria: ");
    scanf("%f", &in.memoria);
    printf("viteza: ");
    scanf("%f", &in.viteza);
    printf("pretul: ");
    scanf("%f", &in.pretul);
    printf("\n");
    return in;
}

Node *createNode(Computer value)
{
    Node *result = malloc(sizeof(Node));
    if (result != NULL)
    {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

bool insertStruct(Node **rootptr, Computer value)
{
    Node *root = *rootptr;

    if (root == NULL)
    {
        (*rootptr) = createNode(value);
        return true;
    }

    if (strcmp(value.modelul, root->value.modelul) == 0)
        return false;

    if (strcmp(value.modelul, root->value.modelul) < 0)
        return insertStruct(&(root->left), value);
    else
        return insertStruct(&(root->right), value);
}

int treeNodeNum = 0;
void createTree()
{

    while (true)
    {
        Computer in;
        printf("valoarea nodului %d:\n", treeNodeNum);
        in = introduce_struct();

        if (!insertStruct(&root, in))
            printf("valoarea data deja exista.\n");
        treeNodeNum++;

        int choice;
        printf("doriti sa mai introduceti o structura? (1/0) ");
        if (scanf("%d", &choice) && choice == 0)
            return;
        else if (choice != 1)
            break;
    }
}

void show_struct(Computer in)
{
    printf("modelul: ");
    printf("%s\n", in.modelul);

    printf("procesorul: ");
    printf("%s\n", in.procesorul);

    printf("memoria: ");
    printf("%f\n", in.memoria);

    printf("viteza: ");
    printf("%f\n", in.viteza);

    printf("pretul: ");
    printf("%f\n", in.pretul);

    printf("\n");
}

void printTreeRec(Node *root)
{
    if (root != NULL)
    {
        printTreeRec(root->left);
        printTreeRec(root->right);
        show_struct(root->value);
    }
}

void printTree()
{
    printTreeRec(root);
}

int main()
{
    createTree();
    printTree();
}
