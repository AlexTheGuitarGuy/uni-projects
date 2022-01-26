#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int lim = 100;

int getWordsNum(char *in) {
    
    int out = 0;
    for(int i = 0; in[i]; i++){
        if(in[i] == ' ')
            out++;
        while(in[i] == ' ')
            i++;
    }
    return(out);
}


void checkRepetitions(char *in, char *word){
    char *cmpWord;
    char tokin[lim];
    int nextWord;

    strcpy(tokin, in);
    cmpWord = strtok(tokin, " ,.");

    while( cmpWord != NULL ){
        nextWord += strlen(cmpWord) + 1;

        printf("'%s' cmp '%s'\n", word, cmpWord);
        
        if (strcmp(word, cmpWord) == 0) {
           strcpy(&in[nextWord - strlen(cmpWord)], &in[nextWord]);
           printf("6666666666%s\n", in);
        }
    
        cmpWord = strtok(NULL, " ,.");
    }
}

void evaluate(char *in){
    char *word;
    char tokin[lim];
    int i = 0, i1, nextWord,
    wordsNum = getWordsNum(in);
  
    while(1){
        strcpy(tokin, in);
        word = strtok(tokin, " ,.");

        i1 = 0;
        while(i1 < i){
            word = strtok(NULL, " ,.");
            i1++;
        }

        nextWord += strlen(word) + 1;

        if(word == NULL || i == wordsNum){
            break;
        }

        printf("!!!!!%s 1111%s\n", word, &in[nextWord]);
        checkRepetitions(&in[nextWord], word);

        i++;
    }
    


    printf("\nRezultatul eliminării cuvintelor identice: %s\n", in);


    printf("\n");
}

int main () {
    char in[lim];

    printf("\nIntroduceți o propoziție: ");
    if(!gets(in)) {
        printf("Valoare invalidă.");
        return(1);
    }

    evaluate(in);

    return (0);
}

/*Scrieți un program care citește de la 
tastatură o propoziție, apoi efectuează 
calculele indicate în variantă și afișează 
pe ecran rezultatul

Varianta 15. Să se elimine din propoziție cuvintele identice.*/
