#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *out = fopen("D:\\numbers.txt", "w+");
    FILE *avg = fopen("average.txt", "w+");

    printf("\nintroduceti numere intregi in perechi de cate 5 sau o valoare diferita de integer pentru a continua:\n");
    int tmp, nums = 0, sum = 0;
    for (int i = 1; 1; i++)
    {
        if (scanf("%d", &tmp))
        {
            fprintf(out, "%d ", tmp);
            sum += tmp;
            nums++;
            if (i % 5 == 0)
                fprintf(out, "\n");
        }
        else
        {
            break;
        }
    }
    tmp = 0;

    fseek(out, 0, SEEK_SET);
    for (int i = 1; i <= nums; i++)
    {
        if (fscanf(out, "%d", &tmp))
        {
            fprintf(avg, "%d ", tmp);
            if (i % 5 == 0)
            {
                fscanf(out, "\n");
                fprintf(avg, "\n");
            }
        }
    }

    if (nums != 0)
    {
        fprintf(avg, "\n%f", (float)sum / (float)nums);
    }
    else
    {
        printf("\nmedia nu poate fi inscrisa, deoarece in fisier se afla 0 numere.");
    }

    printf("\ncontinutul fisierului average.txt:\n");
    fseek(avg, 0, SEEK_SET);
    for (int i = 1; i <= nums; i++)
    {
        if (fscanf(avg, "%d", &tmp))
        {
            printf("%d ", tmp);
            if (i % 5 == 0)
            {
                fscanf(avg, "\n");
                printf("\n");
            }
        }
    }
    float average;
    if (nums != 0)
    {
        fscanf(avg, "%f", &average);
        printf("\n%f", average);
    }

    fclose(out);
    fclose(avg);
    return 0;
}

/*2.Sa se scrie un program care creează un fișier „numbers.txt” pe discul D, în care
înscrie câte 5 numere întregi, introduse de la tastatura. Fiecare grup de câte 5
numere se scrie în linie nouă. De citit aceste numere din fișierul „numbers.txt” și
de le înscris în fișierul „average.txt” împreună cu media lor aritmetică. De afișat
pe ecran conținutul fișierului „average.txt”.*/