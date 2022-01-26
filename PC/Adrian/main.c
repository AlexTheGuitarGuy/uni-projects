#include <stdio.h>


int main()
{

int lin,col,nrc,i,j,a[10][10];
printf("Introduceti nr de linii:");
scanf("%d",&lin );
printf("Introduce nr de coloane:");
scanf("%d", &col);
if (lin>10 || col>10){
printf("Eroare: dimensiune>10");

  }
  printf("Introduceti %d date ale tabelului: \n", lin*col);
   for (i=0;i<lin;i++){
     for (j=0;j<col;j++){
        printf("[%d][%d]: ", i ,j);
          scanf ("%d", &a[i][j]);
    }
  }
printf("\n");


printf("Tabloul:\n");
for (i=0;i<lin;i++) {
for (j=0;j<col;j++)
printf ("%d ",a[i][j]);
printf ("\n");
    }

int nPreced = 0, nAct = 0, loc = 0;
for(int i = 0; i < col; i++) {//liniile si coloanele se schimba cu locul in for

  for(int j = 0; j < lin; j++) {

    for(int k = 0; k < lin; k++) {//cauta in coloana actuala de cate ori se repeta numarul j

      if(a[j][i] == a[k][i]) {
        nAct++;
      }
    }

    if(nAct > nPreced) { //daca se repeta de mai multe ori decat maximul precedent, atunci il inlocuieste
      loc = i;//coloana cu maxime repetari
      nPreced = nAct;
    }
    nAct = 0;

  }
}

printf("Coloana cu cele mai multe numere identice este: %d\n", loc);
printf("Nr identice in coloana: %d\n", nPreced);

return 0;
}
