#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENT_NUM 100
#define MAX_NAME_LEN 20

typedef struct inElev
{
    char name[MAX_NAME_LEN];
    int grades[5];
} inElev;
const char *INPUT_TMP = "%s %d %d %d %d %d\n";

typedef struct outElev
{
    char name[MAX_NAME_LEN];
    float mean;
} outElev;
const char *OUTPUT_TMP = "%s %f\n";

int studentNum = 0;
char repeated[MAX_STUDENT_NUM / 2][MAX_STUDENT_NUM];

void sort(outElev *input)
{
    outElev tmp;

    for (int i = 0; i < studentNum; i++)
    {
        for (int j = i + 1; j < studentNum; j++)
        {

            if (input[i].mean < input[j].mean)
            {
                tmp = input[i];
                input[i] = input[j];
                input[j] = tmp;
            }
        }
    }
}

int repeats(char *name, outElev *input)
{
    int repeats = 0;
    for (int i = 0, j = 0; i < studentNum; i++)
    {
        if (strcmp(name, input[i].name) == 0)
            repeats++;
    }

    return (repeats > 1 ? 1 : 0);
}

int isInRepList(char *name)
{
    for (int i = 0, j = 0; i < studentNum; i++)
    {
        if (strcmp(name, repeated[i]) == 0)
            return 1;
    }

    return 0;
}

void getRepeats(outElev *input)
{
    int j = 0;

    for (int i = 0; i < studentNum; i++)
    {
        if (repeats(input[i].name, input) && !isInRepList(input[i].name))
        {
            strcpy(repeated[j], input[i].name);
            j++;
        }
    }
}

int main()
{
    // -- OPEN --
    FILE *in;
    fopen_s(&in, "input.txt", "r");
    if (in == NULL)
    {
        printf("\nS-a produs o eroare in procesul deschiderii fisierului pentru citire.\n");
        return 1;
    }

    FILE *out;
    fopen_s(&out, "output.txt", "w");
    if (out == NULL)
    {
        printf("\nS-a produs o eroare in procesul deschiderii fisierului pentru scriere.\n");
        return 3;
    }

    FILE *err;
    fopen_s(&err, "eronat.txt", "w");
    if (err == NULL)
    {
        printf("\nS-a produs o eroare in procesul deschiderii fisierului pentru scriere.\n");
        return 3;
    }

    int elements_read = 0;
    inElev input[MAX_STUDENT_NUM];
    outElev output[MAX_STUDENT_NUM];
    int elems_wrote = 0;
    while (!feof(in))
    {
        // -- READ --
        elements_read += fscanf(in, INPUT_TMP,
                                input[studentNum].name,
                                &input[studentNum].grades[0],
                                &input[studentNum].grades[1],
                                &input[studentNum].grades[2],
                                &input[studentNum].grades[3],
                                &input[studentNum].grades[4]);

        // -- CALCULATE --
        strcpy(output[studentNum].name, input[studentNum].name);
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += input[studentNum].grades[i];
        }
        output[studentNum].mean = (float)sum / 5;

        studentNum++;
    }

    sort(output);
    getRepeats(output);

    // -- WRITE --
    for (int i = 0; i < studentNum; i++)
    {
        if (!isInRepList(output[i].name))
            elems_wrote += fprintf(out, OUTPUT_TMP, output[i].name, output[i].mean);
        if (isInRepList(input[i].name))
            elems_wrote += fprintf(err, INPUT_TMP,
                                   input[i].name,
                                   input[i].grades[0],
                                   input[i].grades[1],
                                   input[i].grades[2],
                                   input[i].grades[3],
                                   input[i].grades[4]);
    }

    // -- CLOSE --
    fclose(in);
    if (elements_read < studentNum * 6)
    {
        printf("\nS-a produs o eroare in procesul de citire a datelor.\n");
        return 2;
    }

    fclose(out);
    fclose(err);
    if (elems_wrote <= 0)
    {
        printf("\nS-a produs o eroare in procesul de scriere a datelor.\n");
        return 4;
    }

    return 0;
}

/*15.Se dă un fișier care conține pe fiecare rând un nume (un cuvânt) urmat de 5 note.
Se cere să se construiască un al doilea fișier care conține numele urmat de medie,
ordonat descrescător după medie. Dacă un nume apare pe mai multe linii in
fișierul original, liniile respective vor fi scrise într-un fișier cu numele 'eronat', și
pentru acestea nu se va calcula media.*/