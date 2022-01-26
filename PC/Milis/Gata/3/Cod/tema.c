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
    
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int repeats = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == min) {
            repeats++;
        }
    }

    float media;
    int sum = 0;
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            num++;
            sum += arr[i];
        }
    }
    media = (float)sum / num;

    printf("Valoarea minimală dintre elementele tabloului: %d\n", min);
    printf("Numărul de elemente cu această valoare: %d\n", repeats);
    printf("Media aritmetică a tuturor elementelor nenule în tablou: %f\n", media);
    printf("\n");

    return (0);
}

/*Varianta 14. Să se determine valoarea minimală dintre
 elementele tabloului și numărul de elemente cu această valoare, 
 precum și media aritmetică a tuturor elementelor nenule în tablou.*/
