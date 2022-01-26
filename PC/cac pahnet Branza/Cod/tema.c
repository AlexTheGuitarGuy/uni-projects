#include <stdio.h>
#include <math.h>

int main ()
{
    int n;
    float res = 0;

    printf("\nIntroduceti: ");
    if (!scanf("%d", &n)) {
        printf("\nS-a produs o eroare.\n");
        return(1);
    }

    for (int i = 1, j = 1; i < pow(2, n); i *= 2, j++){
        if (j % 2 != 0)
            res += -1.0 / (pow(-1, i)) / (float) (i * 2);
        else
            res += 1.0 / (pow(-1, i)) / (float) (i * 2);
    }

    printf("\nRezultat: %f\n", res);
    return (0);
}
