#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "includes.h"

Node *root = NULL;

Film introduce_struct()
{
    Film in;
    printf("denumirea: ");
    scanf("%s", in.denumirea);
    printf("tara: ");
    scanf("%s", in.tara);
    printf("regizorul: ");
    scanf("%s", in.regizorul);
    printf("genul: ");
    scanf("%s", in.genul);
    printf("anul: ");
    scanf("%d", &in.anul);
    printf("\n");
    return in;
}

Node *createNode(Film value)
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

bool insertStruct(Node **rootptr, Film value)
{
    Node *root = *rootptr;

    if (root == NULL)
    {
        (*rootptr) = createNode(value);
        return true;
    }

    if (strcmp(value.denumirea, root->value.denumirea) == 0)
        return false;

    if (strcmp(value.denumirea, root->value.denumirea) < 0)
        return insertStruct(&(root->left), value);
    else
        return insertStruct(&(root->right), value);
}

int treeNodeNum = 0;
void createTree()
{

    while (true)
    {
        Film in;
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

void printTabs(int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("\t");
    }
}

void show_struct(Film in, int level)
{
    printTabs(level);
    printf("denumirea: ");
    printf("%s\n", in.denumirea);

    printTabs(level);
    printf("tara: ");
    printf("%s\n", in.tara);

    printTabs(level);
    printf("regizorul: ");
    printf("%s\n", in.regizorul);

    printTabs(level);
    printf("genul: ");
    printf("%s\n", in.genul);

    printTabs(level);
    printf("anul: ");
    printf("%d\n", in.anul);
}

void printTreeRec(Node *root, int level)
{
    if (root == NULL)
    {
        printTabs(level);
        printf("<empty>\n");
        return;
    }

    show_struct(root->value, level);

    printTabs(level);
    printf("left\n");

    printTreeRec(root->left, level + 1);

    printTabs(level);
    printf("right\n");

    printTreeRec(root->right, level + 1);

    printTabs(level);
    printf("done\n");
}

void printTree()
{
    printTreeRec(root, 0);
}

Node *findStructRec(Node *root, char *value)
{
    if (root == NULL)
        return NULL;
    if (strcmp(root->value.denumirea, value) == 0)
        return root;

    if (strcmp(value, root->value.denumirea) < 0)
        return findStructRec(root->left, value);
    else
        return findStructRec(root->right, value);
}

Node *findStruct(char *value)
{
    return findStructRec(root, value);
}

void modify(char *value)
{
    Node *change;

    change = findStruct(value);

    change->value = introduce_struct();
}

int countNodesRec(Node *root)
{
    int res = 0;
    if (root->right != NULL)
        res += countNodesRec(root->right) + 1;
    if (root->left != NULL)
        res += countNodesRec(root->left) + 1;

    return res;
}

int countNodes()
{
    if (root != NULL)
        return countNodesRec(root) + 1;
    else
        return 0;
}

int heightRec(Node *root)
{
    int right = 0, left = 0;
    if (root->right != NULL)
        right += heightRec(root->right) + 1;
    if (root->left != NULL)
        left += heightRec(root->left) + 1;

    if (right > left)
        return right;
    else
        return left;
}

int height()
{
    if (root != NULL)
        return heightRec(root) + 1;
    else
        return 0;
}

void freeTreeRec(Node *root)
{
    if (!root)
        return;
    freeTreeRec(root->right);
    freeTreeRec(root->left);

    free(root);
}

void freeTree()
{
    freeTreeRec(root);
}