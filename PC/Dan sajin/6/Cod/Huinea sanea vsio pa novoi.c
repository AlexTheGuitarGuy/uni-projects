#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *deleteExtraSpaces(char *in) {
    char *out = (char *)malloc(strlen(in) * sizeof(char));
    
    for(int i = 0, j = 0; i < strlen(in); i++, j++) {
        out[j] = in[i];
        if(in[i] == ' '){
            while(in[i + 1] == ' ')
                i++;
        }
    }
    out[strlen(out)] = '\0';

    return(out);
}

void filterDuplicates(char *in, char *cmp){

    int isSame;
    int wordBegin;


    for(int i = 0; i < strlen(in); i++) {
        isSame = 1;
        wordBegin = i;

        if(i == 0 || in[i - 1] == ' '){

            for(int j = 0; j < strlen(cmp); j++, i++) {

                if(in[i] != cmp[j]){
                    isSame = 0;
                    break;
                }

            }

            if(isSame) {
                while(in [wordBegin] != ' ' && in[wordBegin]){
                    in [wordBegin] = ' ';
                    wordBegin++;
                }
                
            }
        }
        
    }

}

void evaluate(char *in){
    int wordEnd;

    for(int i = 0; i < strlen(in); i++) {
        char *word;
        wordEnd = i;

        while(wordEnd < strlen(in) && in[wordEnd] != ' ') {
            wordEnd++;
        }

        word = (char *)malloc((wordEnd - i) * sizeof(char));

        for (int j = 0; i < wordEnd; j++, i++) {
            word[j] = in[i];
        }

        filterDuplicates(&in[wordEnd], word);
        in = deleteExtraSpaces(in);

        i = wordEnd;
    }

    printf("\nRezultatul eliminării cuvintelor identice: \n");
    printf("%s", out);

    printf("\n");
}

int main () {
    int lim = 100;
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
