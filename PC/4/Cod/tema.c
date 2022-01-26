#include <stdio.h>

int main () {

    int n, m;

    printf ("\nCâte rânduri (n > 1) doriți să introduceți? ");
    if (!scanf("%d", &n) || n <= 1) {
        printf ("Valoare n invalidă.\n");
        return (1);
    }

    printf ("\nCâte coloane (m > 1) doriți să introduceți? ");
    if (!scanf("%d", &m) || m <= 1) {
        printf ("Valoare m invalidă.\n");
        return (1);
    }

    int arr[n][m];
    float res[n][m];

    printf("\nIntroduceți %d numere: \n", n*m);
    for (int i = 0; i < n; i++){

        for (int j = 0; j < m; j++) {

            printf("[%d][%d]: ", i, j);
            if (!scanf("%d", &arr[i][j])) {
                printf ("Valoare invalidă.\n");
                return (1);
            }

        }

    }
    printf("\n");

    printf("Tabloul:\n");
    for (int i = 0; i < n; i++){

        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
    printf("\n");

    //printf("Calcule:\n");
    int sum = 0, num = 0;
    for (int i = 0; i < n; i++){

        for (int j = 0; j < m; j++) {

            if (i - 1 >= 0) {
                sum += arr[i - 1][j];
                num++;
                //printf(" %d ", arr[i - 1][j]);
            }
            if (i + 1 < n) {
                sum += arr[i + 1][j];
                num++;
                //printf(" %d ", arr[i + 1][j]);
            }
            if (j - 1 >= 0) {
                sum += arr[i][j - 1];
                num++;
                //printf(" %d ", arr[i][j - 1]);
            }
            if (j + 1 < m) {
                sum += arr[i][j + 1];
                num++;
                //printf(" %d ", arr[i][j + 1]);
            }
            //printf(" => %d / %d", sum, num);
            res[i][j] = (float) sum / (float) num;
            //printf(" = %f;\n", res[i][j]);
            num = 0;
            sum = 0;
            
        }

    }
    //printf("\n");

    printf("Rezultatul uniformizării tabloului:\n");
    for (int i = 0; i < n; i++){

        for (int j = 0; j < m; j++) {
            printf("%f ", res[i][j]);
        }
        
        printf("\n");
    }

    return (0);
}

/*Scrieți un program care citește de la tastatură numărul 
n>1 de rânduri și numărul m>1 de coloane ale tabloului bidimensional 
(mnatricei), apoi citește de la tastatură aceste n X m elemente 
ale tabloului, efectuează calculele indicate în variantă și afișează 
pe ecran rezultatul:

Varianta 15. Să se efectueze uniformizarea tabloului. Operația de uniformizare a tabloului se
efectuează prin înlocuirea fiecărui element cu media aritmetică a tuturor vecinilor.*/
