#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

const int lim = 1000;

static char delims[256];//valoare arbitrara
void initDelims() {
    int i;
    int j = 0;

    for (i = 1; i < 256; i++) {
        if (!isalpha(i))
            delims[j++] = i;
    }
    delims[j] = 0;
}

char **parse(char *in){
    initDelims();
    char *word;

    char tokIn[lim];
    strcpy(tokIn, in);

    word = strtok(tokIn, delims);

    char **parsed = (char **)malloc(lim * sizeof(char));
    if(parsed == NULL) {
        printf("A eșuat alocarea memoriei.\n");
        return NULL;
    }

    for (int i = 0; word != NULL; i++){

        parsed[i] = (char *)malloc(strlen(word) * sizeof(char));
        if(parsed[i] == NULL) {
            printf("A eșuat alocarea memoriei.\n");
            return NULL;
        }

        strcpy(parsed[i], word);

        word = strtok(NULL, delims);
    }

    return (parsed);

}

void printGreatestWord(char **words) {
    
    char *res = words[0];
    for (int i = 0; words[i]; i++) {
        if (strcmp(words[i], res) > 0) {
            strcpy(res, words[i]);
        }
    }

    printf("\nCel mai “mare” cuvânt în sens lexicografic din propoziție:\n\n%s\n", res);
}

int main () {
    char in[lim];

    printf("\nIntroduceți o propoziție:\n\n");
    if(!gets(in)) {
        printf("Valoare invalidă.");
        return(1);
    }

    char **words = parse(in);

    if(!words){
        return (1);
    }

    printGreatestWord(words);

    return (0);
}

/*Varianta 2. Să se determine cel mai 
“mare” cuvânt în sens lexicografic.*/