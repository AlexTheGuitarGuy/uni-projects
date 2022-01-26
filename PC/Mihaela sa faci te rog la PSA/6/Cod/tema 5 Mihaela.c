#include <stdio.h>
#include <stdlib.h>
const int n, m;

int getSize() {

    printf ("\nCâte rânduri (n > 1) doriți să introduceți? ");
    if( !scanf("%d", &n) || n <= 1 ) {
        printf ("Valoare n invalidă.\n");
        return (0);
    }

    printf ("\nCâte coloane (m > 1) doriți să introduceți? ");
    if( !scanf("%d", &m) || m <= 1 ) {
        printf ("Valoare m invalidă.\n");
        return(0);
    }

    return(1);
}

int **i2dArrAllocate() {

    int **arr = (int **)malloc(n * sizeof(int*));
 
    if(arr == NULL) {
        printf("A eșuat alocarea memoriei pentru întregul tablou.");
        return(NULL);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(m * sizeof(int));
        if(arr[i] == NULL) {
            printf("A eșuat alocarea memoriei pentru subtabloul %d al tabloului bidimensional.", i);
            return(NULL);
        }
    }

    return(arr);
}

int *sumAllocate() {

    int *arr = (int *)malloc(n * sizeof(int));
 
    if(arr == NULL) {
        printf("A eșuat alocarea memoriei pentru întregul tablou.");
        return(NULL);
    }

    return(arr);
}

float *meanAllocate() {

    float *arr = (float *)malloc(n * sizeof(float));
 
    if(arr == NULL) {
        printf("A eșuat alocarea memoriei pentru întregul tablou.");
        return(NULL);
    }

    return(arr);
}

int arrIntroduce(int **arr) {

    printf("\nIntroduceți %d numere: \n", n*m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {

            printf("[%d][%d]: ", i, j);
            if (!scanf("%d", &arr[i][j])) {
                printf ("Valoare invalidă.\n");
                return (0);
            }

        }
    }
    printf("\n");

    return (1);
}

void i2dArrPrint(int **arr) {

    for (int i = 0; i < n; i++){

        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");

    }
    printf("\n");

}

void evaluateMean(int **arr, float *mean) {
    int max, min;

    for (int i = 0; i < n; i++){
        min = arr[i][0];
        max = arr[i][0];

        for (int j = 0; j < m; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
            }
            if (min > arr[i][j]) {
                min = arr[i][j];
            }
        }
        
        mean[i] = (float)(max+min) / 2;
    }
}

void meanPrint(float *mean) {
    for (int i = 0; i < n; i++) {
        printf("Rândul %d: %f\n", i, mean[i]);
    }
    printf("\n");
}


void evaluateSum(int **arr, int *sum) {
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if(arr[i][j] < 0){
                sum[i] += arr[i][j];
            }
        }
    }
}

void sumPrint(int *sum) {
    for (int i = 0; i < n; i++) {
        if(sum[i] == 0) {
            printf("Rândul %d nu are elemente negative.\n", i);
        }
        else {
            printf("Randul %d: %d\n", i, sum[i]);
        }
    }
    printf("\n");
}

int main () {

    if(!getSize()){
        return(1);
    }

    int **arr = i2dArrAllocate();
    int *sum = sumAllocate();
    float *mean = meanAllocate();

    if(!arrIntroduce(arr)) {
        return (1);
    }

    printf("Tabloul:\n");
    i2dArrPrint(arr);

    evaluateMean(arr, mean);
    printf("Rezultatul calculării mediei maximelor și minimelor rândurilor: \n");
    meanPrint(mean);

    evaluateSum(arr, sum);
    printf("Rezultatul calculării sumei elementelor negative ale fiecărui rând: \n");
    sumPrint(sum);

    return (0);
}

