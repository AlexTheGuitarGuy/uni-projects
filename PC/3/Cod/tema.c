#include <stdio.h>

int main () {

    int n;

    printf ("\nCâte numere (n > 1) doriți să introduceți? ");
    if (!scanf("%d", &n) || n <= 1) {
        printf ("Valoare invalidă.\n");
        return (1);
    }

    int arr[n];

    printf("\nIntroduceți %d numere: \n", n);
    for (int i = 0; i < n; i++){
        printf("%d: ", i);
        if(!scanf("%d", &arr[i])) {
            printf ("Valoare invalidă.\n");
            return (1);
        }
        
    }
    printf("\n");
    
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            max = arr[i];
            break;
        }
    }
    if (max >= 0) {
        printf ("Nu s-au găsit elemente negative în tablou.\n");
        return (1);
    }

    for (int i = 0; i < n; i++) {
        if(arr[i] < 0 && arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Pozițiile numărului maximal negativ %d în tablou: ", max);
    for (int i = 0; i < n; i++) {
        if(arr[i] == max) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return (0);
}

/*Varianta 15. Să se determine valoarea maximală 
negativă dintre elementele tabloului și pozițiile 
elementelor cu această valoare în tablou.*/
