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
    int ord[n];

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

    //Sorteaza
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

    printf("Tabloul sortat:\n");
    for (int i = 0; i < n; i++){

        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
    printf("\n");

    return (0);
}
