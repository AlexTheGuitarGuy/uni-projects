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
    
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int repeats = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == max) {
            repeats++;
        }
    }

    float media = 0;
    int sum = 0;
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            num++;
            sum += arr[i];
        }
    }
    media = (float)sum / num;

    printf("Valoarea maximală dintre elementele tabloului: %d\n", max);
    printf("Numărul de elemente cu această valoare: %d\n", repeats);
    if(num > 0)
        printf("Media aritmetică a tuturor elementelor pozitive în tablou: %f\n", media);
    else
        printf("Tabloul nu are elemente pozitive, și, astfel, nu poate fi calculată media lor.");
    printf("\n");

    return (0);
}

/*Varianta 13. Să se determine valoarea maximală 
dintre elementele tabloului și numărul de
elemente cu această valoare, precum și media 
aritmetică a tuturor elementelor pozitive în tablou.*/
