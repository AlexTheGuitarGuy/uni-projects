#include <stdio.h>
#include <stdlib.h>
int n, m;

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

int **twoDArrAllocate() {

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

void evaluate(int **arr, int *ord){

    int order = 0;
    for (int j = 0; j < m; j++) {

        for (int i = 0; i < n; i++) {

            if(arr[i][j] >= 0 && arr[i][j] % 2 == 0) {
                order += arr[i][j];
            }

        }
        ord[j] = order;       
        order = 0;
        
    }
}

void sort(int **arr, int *ord){

    int temp[n];
    int tmp;
    for (int i = 0; i <= n; i++) {

        for (int j = i + 1; j <= n; j++) { 

            if(ord[i] < ord[j]) {  //Bubble sorting
                for (int k = 0; k < n; k++){
                    temp[k] = arr[k][i];
                    arr[k][i] = arr[k][j]; 
                    arr[k][j] = temp[k];   
                }
                tmp = ord[i];
                ord[i] = ord[j];
                ord[j] = tmp;
            } 

        }     
    }     
}

int main () {

    if(!getSize()){
        return(1);
    }

    int **arr = twoDArrAllocate();
    int *ord = (int *)malloc(m * sizeof(int));

    if(arr == NULL || ord == NULL){
        return(1);
    }

    if(!arrIntroduce(arr)) {
        return (1);
    }

    printf("Tabloul:\n");
    iArrPrint(arr);

    evaluate(arr, ord);
    sort(arr, ord);

    printf("Tabloul sortat:\n");
    iArrPrint(arr);

    return (0);
}

