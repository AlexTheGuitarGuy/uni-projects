#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "includes.h"

Str_Node *str_root = NULL;

int arr_to_int(int *array, int len)
{
    int i, k = 0;
    for (i = 0; i < len; i++)
        k = 10 * k + array[i];
    return k;
}

char buffer[MAX_BUFFER_LEN];
int bufferIndex = 0;
void dec_to_hex(long int decimalNumber)
{
    long int remainder, quotient;
    int i = 1, j, temp;
    char hexadecimalNumber[100];

    quotient = decimalNumber;
    while (quotient != 0)
    {
        temp = quotient % 16;

        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;
        hexadecimalNumber[i++] = temp;
        quotient = quotient / 16;
    }

    char *nb = (char *)malloc(MAX_ARR_LEN * sizeof(char));

    int k = 0;
    for (j = i - 1; j > 0; j--, k++)
        nb[k] = hexadecimalNumber[j];

    nb[k] = '\0';

    sprintf(&buffer[bufferIndex], "%.*s ", k, nb);
    bufferIndex += k + 1;
}

void str_insert_end(char *data)
{
    Str_Node *new_node = malloc(sizeof(Str_Node));
    if (new_node == NULL)
    {
        exit(1);
    }
    new_node->next = NULL;
    new_node->prev = NULL;
    strcpy(new_node->data, data);

    if (str_root == NULL)
    {
        str_root = new_node;
        return;
    }

    Str_Node *curr = str_root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->prev = curr;
}

char **str_split(char *a_str, const char a_delim)
{
    char **result = 0;
    size_t count = 0;
    char *tmp = a_str;
    char *last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);

    count++;

    result = malloc(sizeof(char *) * count);

    if (result)
    {
        size_t idx = 0;
        char *token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

void parse_buffer()
{
    char **tokens;

    tokens = str_split(buffer, ' ');

    if (tokens)
    {
        int i;
        for (i = 0; *(tokens + i); i++)
        {
            str_insert_end(*(tokens + i));
            free(*(tokens + i));
        }
        printf("\n");
        free(tokens);
    }
}

void str_create_list(int *arr)
{
    for (int i = 0; i < MAX_LIST_LEN; i++)
        dec_to_hex(arr[i]);
    parse_buffer();
}

void str_show()
{
    Str_Node *tmp = str_root;
    for (; tmp->next != NULL; tmp = tmp->next)
    {
        printf("%s ", tmp->data);
    }
    printf("%s\n\n", tmp->data);
}

int str_count()
{
    int c = 1;
    for (Str_Node *curr = str_root; curr->next != NULL; curr = curr->next)
    {
        c++;
    }
    return c;
}

Str_Node *str_get_node(int index)
{
    int i = 0;
    for (Str_Node *tmp = str_root; tmp->next != NULL; tmp = tmp->next, i++)
    {
        if (i == index)
            return tmp;
    }
}

void str_free_list()
{
    Str_Node *curr = str_root;
    while (curr != NULL)
    {
        Str_Node *aux = curr;
        curr = curr->next;
        free(aux);
    }
    str_root = NULL;
}
