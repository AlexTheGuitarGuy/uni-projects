#include <stdio.h>
#include <math.h>

int main ()
{
    int n, start = 1;
    char sign;

    printf("\nIntroduceti: ");
    if (!scanf("%d", &n)) {
        printf("\nEroare: valoare invalida.\n");
        return (1);
    }

    if(n > 0)
        sign = '+';
    else if (n < 0)
        sign = '-';
    else {
        printf("\nRezultat: -1+1\n");
        return (0);
    }

    printf("\nRezultat: ");

    if (sign == '+') {

        for (int ord = n; ord > 0; ord--){ 

            for(int count = 1; count <= ord; count++){ 
                if(ord < n)
                    start += 2;
            } 
        } //afla unde se incepe

        for (int end = 1; end <= n; end++, 
                                    start += 2){
            printf("%d", start); 
            if (end < n)
                printf("%c", sign);
        } //printeaza n termeni impari care compun numarul n^3
    }
    else {
        
        for (int ord = -n + 1; ord > 1; ord--){ 
            
            for(int count = 1; count <= ord; count++){ 
                if(ord < -n + 1)
                    start += 2;
            } 
        }

        start = -start;

        for (int end = -n; end > 0; end--, 
                                    start += 2){
            printf("%d", start);
        }
    } //la else actioneaza acelasi principiu, doar ca putin schimbat pentru ca numerele sa ramana succesive
    printf("\n");

    return (0);
}

/*
principiul de baza e ca fiecare numar n^3 e compus din
n termeni impari consecutivi celor din care e compus 
predecesorul lui n.
*/