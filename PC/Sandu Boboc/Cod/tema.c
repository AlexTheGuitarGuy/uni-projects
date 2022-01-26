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
    int order, highestOrd = 1;
    int cmp;
    for (int i = 0; i < n; i++) {

        highestOrd = 1;
        for (int j = 0; j < m; j++) {

            order = 1;
            cmp = arr[i][j]; //vezi de cate ori elementul j din tablou se repeta
            for (int k = j + 1; k < m; k++){
                if (cmp == arr[i][k]) {
                    order++;
                }
            }

            if(highestOrd < order){ // vezi daca elementul j se repeta de mai multe ori decat cele trecute
                highestOrd = order;
            }

        }
        ord[i] = highestOrd;
    }

    //Sorteaza
    int temp[n];
    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) { 

            if(ord[i] < ord[j]) {  //Bubble sorting
                for (int k = 0; k < m; k++){
                    temp[k] = arr[i][k];
                }

                for (int k = 0; k < m; k++) {
                    arr[i][k] = arr[j][k]; 
                } 

                for (int k = 0; k < m; k++) {
                    arr[j][k] = temp[k];   
                } 
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

Varianta 3. Să se ordoneze liniile tabloului în 
ordinea ascendentă a numărului de elemente egale 
în fiecare linie.*/
