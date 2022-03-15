#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char modelul[100];
    char tara[100];
    float pretul;
} Telefon;

void printStruct(Telefon in)
{

    printf("\nSamsung ");
    printf("%s", in.modelul);
    printf("\ntara: ");
    printf("%s", in.tara);
    printf("\npretul: ");
    printf("%f", in.pretul);
    printf("\n");
}

void introduceStruct(Telefon *in)
{
    printf("modelul: ");
    scanf("%s", in->modelul);
    printf("tara: ");
    scanf("%s", in->tara);
    printf("pretul: ");
    scanf("%f", &in->pretul);
}

void createAndIntroduce()
{
    Telefon tmp;

    FILE *out;
    int lim;
    printf("Numarul de telefone: ");
    if (!scanf("%d", &lim))
    {
        printf("\nvaloare invalida.\n");
        fclose(out);
        return;
    }

    fopen_s(&out, "telefoane.bin", "wb");
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
        printf("\nTelefonul %d\n", i);
        introduceStruct(&tmp);
        elements_written += fwrite(&tmp, sizeof(Telefon), 1, out);
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
    Telefon tmp;
    FILE *in;
    fopen_s(&in, "telefoane.bin", "rb");
    if (in == NULL)
    {
        printf("s-a produs o eroare in procesul deschiderii fisierului pentru citire.");
        fclose(in);
        return;
    }

    int lim;
    size_t elements_read = 0;
    elements_read += fread(&lim, sizeof(int), 1, in);
    elements_read += fread(&tmp, sizeof(Telefon), 1, in);
    for (int i = 0; !feof(in); i++)
    {
        printf("\nTelefonul %d", i);
        printStruct(tmp);
        elements_read += fread(&tmp, sizeof(Telefon), 1, in);
    }
    fclose(in);
    if (elements_read == 0)
    {
        printf("s-a produs o eroare in procesul de citire a datelor.");
        return;
    }
}

int main()
{
    int choice;
    printf("\ntoate datele aflate acum pe fisier vor fi sterse. sunteti sigur? (1/0) ");

    if (!scanf("%d", &choice) || (choice != 0 && choice != 1))
    {
        printf("\nvaloare invalida.\n");
    }
    else if (choice == 1)
    {
        createAndIntroduce();
        printf("\n\nREZULTAT:");
        show();
    }
    return (0);
}
