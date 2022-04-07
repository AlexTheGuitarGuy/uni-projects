#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_STUDENT_NUM 100

void createFile(FILE **in, char *mode)
{
    fopen_s(in, "studenti.txt", mode);
    if (*in == NULL)
    {
        printf("\nS-a produs o eroare in procesul deschiderii fisierului.\n");
        return;
    }
}

void appendNames(FILE *out)
{
    int n;
    printf("nr. de studenti inscrisi: ");
    if (!scanf("%d", &n) || n <= 0)
    {
        printf("valoare invalida.");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        char student[MAX_NAME_LEN];
        printf("numele studentului %d: ", i);
        if (!scanf("%s", student))
        {
            printf("valoare invalida.");
            return;
        }
        fprintf(out, "%s\n", student);
    }
}

char getNames(FILE *in)
{
}

void arrToFile(char **in, int n)
{
    FILE *out;
    fopen_s(&out, "studenti_sortat.txt", "w+");
    if (out == NULL)
    {
        printf("\nS-a produs o eroare in procesul deschiderii fisierului.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(out, "%s\n", in[i]);
    }

    fclose(out);
}

void swap(char *str1, char *str2)
{
    char tmp[MAX_NAME_LEN];
    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);
}

void sortedFile(FILE *f)
{
    char names[MAX_STUDENT_NUM][MAX_NAME_LEN];
    char tmp;
    int i = 0, j = 0;
    fseek(f, 0, SEEK_SET);

    while (!feof(f))
    {
        tmp = fgetc(f);
        if (!feof(f))
        {
            if (tmp != '\n')
            {
                names[i][j] = tmp;
                j++;
            }
            else
            {
                j = 0;
                i++;
            }
        }
    }
    for (int i = 0; names[i]; i++)
    {
        printf("%s\n", names[i]);
    }
    /*int i;
    for (i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (strcmp(names[i], names[j]) > 0)
            {
                // swap(names[i], names[j]);
            }
        }
    }
    // printf("%d", i);
    arrToFile(names, i);*/
}

int main()
{
    FILE *out;
    createFile(&out, "a+");
    fseek(out, 0, SEEK_END);
    appendNames(out);
    sortedFile(out);
    fclose(out);
    return 0;
}

/*7. Scrieți un program care sa citească de la tastatură numele a n studenți pe care să
le memoreze într-un fișier cu numele STUDENTI.TXT de tip text, numele fiind
separate între ele prin <Enter>. Afișați pe ecran ceea ce se scrie în fișier. Pentru
fișierul creat anterior să se scrie programul care îl actualizează prin adăugarea a
încă m studenți la sfârșitul fișierului. După adăugare se cere generarea unui alt
fișier cu numele studenților în ordine alfabetică.*/