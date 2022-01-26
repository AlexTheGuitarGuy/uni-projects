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

int **iArrAllocate() {

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

float **fArrAllocate() {

    float **arr = (float **)malloc(n * sizeof(float*));

    if(arr == NULL) {
        printf("A eșuat alocarea memoriei pentru întregul tablou.");
        return(NULL);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = (float *)malloc(m * sizeof(float));
        if(arr[i] == NULL) {
            printf("A eșuat alocarea memoriei pentru subtabloul %d al tabloului bidimensional.", i);
            return(NULL);
        }
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

void iArrPrint(int **arr) {

    for (int i = 0; i < n; i++){

        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");

    }
    printf("\n");

}

void fArrPrint(float **arr) {

    for (int i = 0; i < n; i++){

        for (int j = 0; j < m; j++) {
            printf("%f ", arr[i][j]);
        }
        printf("\n");

    }
    printf("\n");

}

void evaluate(int **arr, float **res){

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

}

int main () {

    if(!getSize()){
        return(1);
    }

    int **in = iArrAllocate();
    float **out = fArrAllocate();

    if(in == NULL || out == NULL){
        return(1);
    }

    if(!arrIntroduce(in)) {
        return (1);
    }

    printf("Tabloul:\n");
    iArrPrint(in);

    evaluate(in, out); 

    printf("Rezultatul uniformizării tabloului:\n");
    fArrPrint(out);

    return (0);
}

/*Scrieți un program care citește de la tastatură numărul 
n>1 de rânduri și numărul m>1 de coloane ale tabloului bidimensional 
(mnatricei), apoi citește de la tastatură aceste n X m elemente 
ale tabloului, efectuează calculele indicate în variantă și afișează 
pe ecran rezultatul:

Varianta 15. Să se efectueze uniformizarea tabloului. Operația de uniformizare a tabloului se
efectuează prin înlocuirea fiecărui element cu media aritmetică a tuturor vecinilor.*/
