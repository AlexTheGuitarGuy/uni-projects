#include <stdio.h>
#include <math.h>

int main ()
{
    int a = 0, b = 0, c = 0, tmp = 0;
    printf("\nNumere ce urmează principiul propus:\n");
    for(int i = 100; i <= 999; i++){
        tmp = i;
        c = tmp % 10;
        tmp /= 10;
        b = tmp % 10;
        tmp /= 10;
        a = tmp % 10;
        tmp /= 10;
        if(pow(a, 3) + pow(b, 3) + pow(c, 3) == i)
            printf("%d\n", i);
    }

    return (0);
}

/*
13. determină toate numerele întregi de trei cifre cu 
proprietatea că suma cifrelor acestuia ridicate la cub 
să fie egală cu numărul inițial, ca exemplu dacă numărul 
n este alcătuit din cifrele a, b și c, 
atunci a3 +b3 + c3 = n3
*/