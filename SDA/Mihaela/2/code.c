#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char denumirea[20];
    char tara[20];
    char regizorul[20];
    float genul[20];
    int anul;
} Film;

void showOptions()
{
    printf("\nMeniu:\n");
    printf("1. Crearea unui fisier binar nou, introducerea campurilor structurilor de la tastatura si inscrierea lor in acest fisier.\n");
    printf("2. Afisarea elementelor fisierului binar la ecran.\n");
    printf("3. Adaugarea unei structuri noi la sfarsit de fisier.\n");
    printf("4. Modificarea unei structuri a fisierului.\n");
    printf("5. Cautarea dupa un camp al structurii in fisier.\n");
    printf("6. Sortarea structurilor fisierului dupa un careva camp.\n");
    printf("7. Eliminarea unei structuri din fisier.\n");
    printf("8. Stergerea fisierului de pe disc (la dorinta)\n");
    printf("0. Iesire din program.\n");
}

void printStruct(Film in)
{
    printf("\ndenumirea: ");
    printf("%s", in.denumirea);
    printf("\ntara: ");
    printf("%s", in.tara);
    printf("\nregizorul: ");
    printf("%s", in.regizorul);
    printf("\ngenul: ");
    printf("%s", in.genul);
    printf("\nanul: ");
    printf("%d", in.anul);
    printf("\n");
}

void introduceStruct(Film *in)
{
    printf("denumirea: ");
    scanf("%s", in->denumirea);
    printf("tara: ");
    scanf("%s", in->tara);
    printf("regizorul: ");
    scanf("%s", in->regizorul);
    printf("genul: ");
    scanf("%s", in->genul);
    printf("anul: ");
    scanf("%d", &in->anul);
}

void createAndIntroduce()
{
    Film tmp;

    FILE *out;
    int lim;
    printf("Numarul de filme: ");
    if (!scanf("%d", &lim))
    {
        printf("\nvaloare invalida.\n");
        fclose(out);
        return;
    }

    fopen_s(&out, "filme.bin", "wb");
    if (out == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru scriere.");
        fclose(out);
        return;
    }

    size_t elements_written = 0;
    elements_written += fwrite(&lim, sizeof(int), 1, out);
    for (int i = 0; i < lim; i++)
    {
        printf("\nFilmul %d\n", i);
        introduceStruct(&tmp);
        elements_written += fwrite(&tmp, sizeof(Film), 1, out);
    }
    fclose(out);
    if (elements_written == 0)
    {
        printf("s-a produs o eroare in procesul de scriere a datelor.");
        return;
    }
}

void show()
{
    Film tmp;
    FILE *in;
    fopen_s(&in, "filme.bin", "rb");
    if (in == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire.");
        fclose(in);
        return;
    }

    int lim;
    size_t elements_read = 0;
    elements_read += fread(&lim, sizeof(int), 1, in);
    elements_read += fread(&tmp, sizeof(Film), 1, in);
    for (int i = 0; !feof(in); i++)
    {
        printf("\nFilmul %d", i);
        printStruct(tmp);
        elements_read += fread(&tmp, sizeof(Film), 1, in);
    }
    fclose(in);
    if (elements_read == 0)
    {
        printf("s-a produs o eroare in procesul de citire a datelor.");
        return;
    }
}

void push()
{
    FILE *f;
    fopen_s(&f, "filme.bin", "rb+");
    if (f == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire si scriere.");
        fclose(f);
        return;
    }

    int lim;
    size_t elements_read = 0;
    size_t elements_written = 0;
    fseek(f, 0, SEEK_SET);
    elements_read += fread(&lim, sizeof(int), 1, f);
    if (elements_read == 0)
    {
        printf("s-a produs o eroare in procesul de citire a datelor.");
        fclose(f);
        return;
    }
    lim++;
    fseek(f, 0, SEEK_SET);
    elements_written += fwrite(&lim, sizeof(int), 1, f);

    Film tmp;
    introduceStruct(&tmp);
    fseek(f, 0, SEEK_END);
    elements_written += fwrite(&tmp, sizeof(Film), 1, f);

    fclose(f);
    if (elements_written == 0)
    {
        printf("s-a produs o eroare in procesul de scriere a datelor.");
        return;
    }
}

void modify()
{
    show();
    FILE *f;
    fopen_s(&f, "filme.bin", "rb+");
    if (f == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire si scriere.");
        fclose(f);
        return;
    }
    int lim;
    fread(&lim, sizeof(int), 1, f);
    printf("\nnumarul filmului care va fi modificat: ");
    int choice;
    if (!scanf("%d", &choice) || choice >= lim)
    {
        printf("\bvaloare invalida.");
        fclose(f);
        return;
    }

    size_t elements_written = 0;
    Film tmp;
    introduceStruct(&tmp);
    fseek(f, (sizeof(Film) * choice + sizeof(int)), SEEK_SET);
    elements_written += fwrite(&tmp, sizeof(Film), 1, f);

    fclose(f);
    if (elements_written == 0)
    {
        printf("s-a produs o eroare in procesul de scriere a datelor.");
        return;
    }
}

void search()
{
    Film tmp;
    FILE *in;
    fopen_s(&in, "filme.bin", "rb");
    if (in == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire.");
        fclose(in);
        return;
    }

    int choice;
    printf("\ncampuri disponibile:\n1.denumirea\n2.anul\n");
    printf("\ncampul cautat: ");
    if (!scanf("%d", &choice) || choice > 2 || choice < 1)
    {
        printf("\nvaloare invalida.\n");
        fclose(in);
        return;
    }
    show();

    char sName[20];
    int sYear;
    printf("\nvaloare cautata: ");
    switch (choice)
    {
    case 1:
        if (!scanf("%s", sName))
        {
            printf("\nvaloare invalida.\n");
            fclose(in);
            return;
        }
        break;
    case 2:
        if (!scanf("%d", &sYear))
        {
            printf("\nvaloare invalida.\n");
            fclose(in);
            return;
        }
        break;
    default:
        break;
    }

    int lim;
    size_t elements_read = 0;
    elements_read += fread(&lim, sizeof(int), 1, in);
    elements_read += fread(&tmp, sizeof(Film), 1, in);
    for (int i = 0; !feof(in); i++)
    {
        if (choice == 1 && strcmp(tmp.denumirea, sName) == 0)
        {
            printf("\nFilmul %d", i);
            printStruct(tmp);
        }
        else if (choice == 2 && tmp.anul == sYear)
        {
            printf("\nFilmul %d", i);
            printStruct(tmp);
        }
        elements_read += fread(&tmp, sizeof(Film), 1, in);
    }
    fclose(in);
    if (elements_read == 0)
    {
        printf("s-a produs o eroare in procesul de citire a datelor.");
        return;
    }
}

void writeAtIndex(Film in, int i)
{
    FILE *f;
    fopen_s(&f, "filme.bin", "rb+");
    if (f == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire si scriere.");
        fclose(f);
        return;
    }

    size_t elements_written = 0;
    fseek(f, (sizeof(Film) * i + sizeof(int)), SEEK_SET);
    elements_written += fwrite(&in, sizeof(Film), 1, f);

    fclose(f);
    if (elements_written == 0)
    {
        printf("s-a produs o eroare in procesul de scriere a datelor.");
        return;
    }
}

void sort()
{
    FILE *in;
    fopen_s(&in, "filme.bin", "rb");
    if (in == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire.");
        fclose(in);
        return;
    }

    int choice;
    printf("\ncampuri disponibile:\n1.denumirea\n2.anul\n");
    printf("\ncampul sortat: ");
    if (!scanf("%d", &choice) || choice > 2 || choice < 0)
    {
        printf("\nvaloare invalida.\n");
        fclose(in);
        return;
    }

    int lim;
    size_t elements_read = 0;
    elements_read += fread(&lim, sizeof(int), 1, in);
    Film tmp[lim];
    for (int i = 0; !feof(in); i++)
    {
        elements_read += fread(&tmp[i], sizeof(Film), 1, in);
    }
    fclose(in);
    if (elements_read == 0)
    {
        printf("s-a produs o eroare in procesul de citire a datelor.");
        return;
    }

    Film replace;
    for (int i = 0; i < lim; i++)
    {
        for (int j = i + 1; j < lim; j++)
        {

            if ((strcmp(tmp[i].denumirea, tmp[j].denumirea) > 0 && choice == 1) ||
                (tmp[i].anul < tmp[j].anul && choice == 2))
            {
                replace = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = replace;
                writeAtIndex(tmp[i], i);
                writeAtIndex(tmp[j], j);
            }
        }
    }
}

void deleteStruct()
{
    FILE *from;
    fopen_s(&from, "filme.bin", "rb");
    if (from == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire si scriere.");
        fclose(from);
        return;
    }

    int lim;
    size_t elements_read = 0;
    fseek(from, 0, SEEK_SET);
    elements_read += fread(&lim, sizeof(int), 1, from);

    Film tmp[lim];
    for (int i = 0; !feof(from); i++)
    {
        elements_read += fread(&tmp[i], sizeof(Film), 1, from);
    }

    fclose(from);
    if (elements_read == 0)
    {
        printf("s-a produs o eroare in procesul de citire a datelor.");
        return;
    }

    show();
    printf("\nnumarul filmului care va fi sters: ");
    int choice;
    if (!scanf("%d", &choice) || choice >= lim)
    {
        printf("\bvaloare invalida.");
        return;
    }

    FILE *to;
    fopen_s(&to, "tmp.bin", "wb");
    if (to == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire si scriere.");
        fclose(to);
        return;
    }

    lim--;
    size_t elements_written = 0;
    elements_written += fwrite(&lim, sizeof(int), 1, to);
    for (int i = 0; i < lim + 1; i++)
    {
        if (i != choice)
            elements_written += fwrite(&tmp[i], sizeof(Film), 1, to);
    }

    fclose(to);
    if (elements_written == 0)
    {
        printf("s-a produs o eroare in procesul de scriere a datelor.");
        return;
    }

    remove("filme.bin");
    rename("tmp.bin", "filme.bin");
}

int handleOptions(int in)
{
    int choice;
    switch (in)
    {
    case 1:
        printf("\ntoate datele aflate acum pe fisier vor fi sterse. sunteti sigur? (1/0) ");

        if (!scanf("%d", &choice) || (choice != 0 && choice != 1))
        {
            printf("\nvaloare invalida.\n");
        }
        else if (choice == 1)
            createAndIntroduce();
        break;
    case 2:
        show();
        break;
    case 3:
        push();
        break;
    case 4:
        modify();
        break;
    case 5:
        search();
        break;
    case 6:
        sort();
        break;
    case 7:
        deleteStruct();
        break;
    case 8:
        printf("\ntoate datele aflate acum pe fisier vor fi sterse. sunteti sigur? (1/0) ");
        if (!scanf("%d", &choice) || (choice != 0 && choice != 1))
        {
            printf("\nvaloare invalida.\n");
        }
        else if (choice == 1)
            remove("filme.bin");
        break;
    case 0:
        return 1;
    default:
        printf("Valoarea %d nu exista in meniul de optiuni, introduceti o alta valoare.\n", in);
    }

    return (1);
}

int handleInput()
{
    int in;

    do
    {
        showOptions();
        printf("\nCe operatiune doriti sa efectuati?\n");

        if (!scanf("%d", &in))
        {
            printf("\nvaloare invalida.\n");
            return (0);
        }
        else if (!handleOptions(in))
        {
            return (0);
        }

    } while (in != 0);

    return (1);
}

int main()
{

    if (!handleInput())
    {
        return (1);
    }

    return (0);
}
