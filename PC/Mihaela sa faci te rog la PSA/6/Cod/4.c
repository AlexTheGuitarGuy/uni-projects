#include <stdio.h>

int main () {

    int n, m;

    printf ("\nCâte rânduri (n > 1) doriți să introduceți? ");//afla numarul randurilor
    if (!scanf("%d", &n) || n <= 1) {//iful dat arata ca daca n nu e integer sau daca e <= 1 atunci nu se poate executa programul
        printf ("Valoare n invalidă.\n");
        return (1);
    }

    printf ("\nCâte coloane (m > 1) doriți să introduceți? ");//afla numarul coloanelor
    if (!scanf("%d", &m) || m <= 1) {
        printf ("Valoare m invalidă.\n");
        return (1);
    }

    int arr[n][m];//initializeaza tabloul bidimensional
    int sum[n];//intializeaza tabloul ce va tine suma elementlor negative
    float mean[n];//intializeaza tabloul ce va tine media maximului si minimului

    printf("\nIntroduceți %d numere: \n", n*m);//introdu elementele in tabloul bidimensional
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

    printf("Tabloul:\n");//printeaza tabloul
    for (int i = 0; i < n; i++){

        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
    printf("\n");

    //calculeaza media maximului si minimului
    int max = arr[0][0], min = arr[0][0];
    for (int i = 0; i < n; i++){

        for (int j = 0; j < m; j++) {
            if (max < arr[i][j]){
                max = arr[i][j];
            }
            if (min > arr[i][j]){
                min = arr[i][j];
            }
        }
        mean[i] = (float)(max+min) / 2;
        min = arr[i + 1][0];
        max = arr[i + 1][0];
    }

    printf("Rezultatul calculării mediei maximelor și minimelor rândurilor: \n");
    for (int i = 0; i < n; i++){
        printf("Rândul %d: %f \n", i, mean[i]);
    }
    printf("\n");

    //calculeaza suma elementlor negative
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if(arr[i][j] < 0) {
                sum[i] += arr[i][j];
            }
        }
    }
    printf("\n");


    printf("Rezultatul calculării sumei elementelor negative ale fiecărui rând: \n");
    for (int i = 0; i < n; i++){
        if(sum[i] == 0)
            printf("Rândul %d nu are elemente negative.\n", i);
        else
            printf("Randul %d: %d \n", i, sum[i]);
    }
    printf("\n");

    return (0);
}

/*Varianta 2. Să se determine suma 
elementelor negative din fiecare linie 
și media elementului maximal și cel minimal.*/