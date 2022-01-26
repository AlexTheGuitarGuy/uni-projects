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

    //Afla cate elemente care se repeta se afla in fiecare rand
    int order = 0;
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if(arr[i][j] >= 0) {
                order++;
            }

        }
        ord[i] = order;       
        order = 0;
        
    }

    //Sorteaza
    int temp[n];
    int tmp;
    for (int i = 0; i < n; i++) {

        for (int j = i; j < n; j++) { 

            if(ord[i] > ord[j]) {  //Bubble sorting
                for (int k = 0; k < m; k++){
                    temp[k] = arr[i][k];
                    arr[i][k] = arr[j][k]; 
                    arr[j][k] = temp[k];   
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

/*Scrieți un program care citește de la tastatură numărul 
n>1 de rânduri și numărul m>1 de coloane ale tabloului bidimensional 
(mnatricei), apoi citește de la tastatură aceste n X m elemente 
ale tabloului, efectuează calculele indicate în variantă și afișează 
pe ecran rezultatul:

Varianta 14. Să se ordoneze liniile tabloului în ordinea ascendentă a numărului de elemente
pozitive în fiecare linie.*/
