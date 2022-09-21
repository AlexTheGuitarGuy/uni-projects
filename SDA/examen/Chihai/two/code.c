#include <stdio.h>

int to_upper_file(FILE *fp, FILE *out);

int main(int argc, char *argv[])
{
    FILE *fp;
    FILE *out;
    int status;

    if (argc <= 2)
    {
        printf("Argumente insuficiente: ");
        printf("Nu sau dat numele fisierelor in linia de comanda");
        return 1;
    }
    if (argc > 1)
    {
        fp = fopen(argv[1], "r");
        out = fopen(argv[2], "w");

        status = to_upper_file(fp, out);

        if (status == 0)
        {
            printf("\nContinutul fisierului \"%s\" a fost convertit cu succes\n", argv[1]);
            return 1;
        }

        if (status == -1)
        {
            printf("\nNu s-a putut converti");
            return 1;
        }
    }
}

int to_upper_file(FILE *fp, FILE *out)
{
    char ch;

    if (fp == NULL)
    {
        perror("Nu s-a putut deschide fisierul");
        return -1;
    }
    else
    {
        while (ch != EOF)
        {
            ch = fgetc(fp);
            if ((ch >= 'a') && (ch <= 'z'))
            {
                ch = ch - 32;
                fseek(fp, -1, SEEK_CUR);
                fputc(ch, out);
            }
        }
        return 0;
    }
}