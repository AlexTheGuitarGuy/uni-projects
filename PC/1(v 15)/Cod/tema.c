#include <stdio.h>
#include <math.h>

int main ()
{
    float a, b, c, x, F;

    printf ("\nIntroduceti a, b, c si x: ");
    scanf("%f %f %f %f", &a, &b, &c, &x);

    if (x > c + b && a != 0) { 
        printf("\nCazul 1: ");

        if (cos(x) == 0) {
            printf("\nEroare, diviziune la 0.\n");
            return (1);
        }
        else if (x + a + pow(b, 2) < 0) {
            printf("\nEroare, radacina patrata negativa.\n");
            return (1);
        } //exceptii^^

        F = sqrt(x + a + pow(b, 2)) / cos(x);
    }
    else if (x < c + b && a == 0) {
        printf("\nCazul 2: ");

        if (a <= 0 || b <= 0) {
            printf("\nEroare, logaritm mai mic sau egal cu 0.\n");
            return (1);
        }
        else if (a * x + pow(c, 2) == 0) {
            printf("\nEroare, diviziune la 0.\n");
            return (1);
        } //exceptii^^

        F = (log(a) + log(b)) / (a * x + pow(c, 2));
    }
    else {
        printf("\nCazul 3: ");

        if (x == 0) {
            printf("\nEroare, diviziune la 0.\n");
            return (1);
        } //exceptii^^

        F = (a + b + x) / pow(x, 2);
    }

    printf ("\nF = %f \nx = %f\n", F, x);
    return (0);
}
