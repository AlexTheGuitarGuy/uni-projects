#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20

void createFile(FILE **in, char *mode)
{
    fopen_s(in, "studenti.txt", mode);
    if (*in == NULL)
    {
        printf("\nS-a produs o eroare in procesul deschiderii fisierului.\n");
        return;
    }
}

void writeNames(FILE *out)
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

void showFile(FILE *in)
{
    char ch;
    fseek(in, 0, SEEK_SET);
    while (!feof(in))
    {
        ch = fgetc(in);
        if (!feof(in))
            printf("%c", ch);
    }
}

int main()
{
    FILE *out;
    createFile(&out, "w+");
    writeNames(out);
    showFile(out);
    fclose(out);
    return 0;
}

/*7. Scrieți un program care sa citească de la tastatură numele a n studenți pe care să
le memoreze într-un fișier cu numele STUDENTI.TXT de tip text, numele fiind
separate între ele prin <Enter>. Afișați pe ecran ceea ce se scrie în fișier. Pentru
fișierul creat anterior să se scrie programul care îl actualizează prin adăugarea a
încă m studenți la sfârșitul fișierului. După adăugare se cere generarea unui alt
fișier cu numele studenților în ordine alfabetică.*/