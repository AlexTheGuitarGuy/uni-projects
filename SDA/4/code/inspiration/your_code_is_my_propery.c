#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int x;
    struct Node *next;
} Node;

void deallocate(Node **root)
{
    Node *curr = *root;
    while (curr != NULL)
    {
        Node *aux = curr;
        curr = curr->next;
        free(aux);
    }
    *root = NULL;
}

void insert_end(Node **root, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
    }
    new_node->next = NULL;
    new_node->x = value;

    if (*root == NULL)
    {
        *root = new_node;
        return;
    }

    Node *curr = *root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

void insert_beginning(Node **root, int value)
{
    Node *new_node = malloc(sizeof(int));
    if (new_node == NULL)
    {
        exit(3);
    }

    new_node->x = value;
    new_node->next = *root;

    *root = new_node;
}

void insert_after(Node *node, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
    }

    new_node->x = value;
    new_node->next = node->next;
    node->next = new_node;
}

void insert_sorted(Node **root, int value)
{
    if (*root == NULL || (**root).x >= value)
    {
        insert_beginning(root, value);
        return;
    }

    Node *curr = *root;
    while (curr->next != NULL)
    {
        if (curr->next->x >= value)
        {
            insert_after(curr, value);
            return;
        }
        curr = curr->next;
    }

    insert_after(curr, value);
}

void remove_element(Node **root, int value)
{
    if (*root == NULL)
    {
        return;
    }

    if ((*root)->x == value)
    {
        Node *to_remove = *root;
        *root = (*root)->next;
        free(to_remove);
        return;
    }

    for (Node *curr = *root; curr->next != NULL; curr = curr->next)
    {
        if (curr->next->x == value)
        {
            Node *to_remove = curr->next;
            curr->next = curr->next->next;
            free(to_remove);
            return;
        }
    }
}

void reverse(Node **root)
{
    Node *prev = NULL;
    Node *curr = *root;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *root = prev;
}

int has_loops(Node *root)
{
    Node *slow = NULL;
    Node *fast = NULL;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}

int count(Node *root)
{
    int c = 0;
    for (Node *curr = root; curr != NULL; curr = curr->next)
    {
        c++;
    }
    return c;
}

int count_recursive(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return 1 + count_recursive(node->next);
}

int main(int argc, char *argv[])
{
    Node *root = NULL;

    insert_sorted(&root, 11);
    insert_sorted(&root, 55);
    insert_sorted(&root, -2);
    insert_sorted(&root, 22);
    insert_sorted(&root, 30);

    reverse(&root);

    if (has_loops(root))
    {
        printf("List has loops\n");
    }
    else
    {
        printf("List has %d elements\n", count_recursive(root));
        // Iterate only if doesn't have loops
        for (Node *curr = root; curr != NULL; curr = curr->next)
        {
            printf("%d\n", curr->x);
        }
    }

    deallocate(&root);

    return 0;
}