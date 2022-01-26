#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

const int lim = 1000;

void sort(char **in) {

    char *temp;
    for(int i = 0; in[i]; i++){

        for (int j = i + 1; in[j]; j++) {

            if(strcmp(in[i], in[j]) < 0) {
                temp = in[i];
                in[i] = in[j];
                in[j] = temp;
            }

        }
    }
}


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

void show(char *in, char **out) {

    printf("\nRezultatul eliminării cuvintelor identice:\n\n");

    int i = 0, j = 0;

    while(in[i]) {

        while(!isalpha(in[i]) && in[i]) {
            printf("%c", in[i]);
            i++;
        }

        if(isalpha(in[i]) && !isalpha(in[i - 1]) && out[j]) {

            while(isalpha(in[i])) {
                i++;
            }
            printf("%s", out[j]);
            j++;
        }
        else {
            while(isalpha(in[i])) i++;
            if(in[i] == ' ' && in[i + 1])
                i++;
        }

    }

    printf("\n");

}

int main () {
    char in[lim];

    printf("\n-Pentru programul dat, un cuvânt este\no succesiune de litere care nu e\ndelimitată de nimic.\n\n");
    printf("-Cuvintele la care majusculele și minusculele\nnu coincid nu se vor considera identice.\n\n");
    printf("Introduceți o propoziție:\n\n");
    if(!gets(in)) {
        printf("Valoare invalidă.");
        return(1);
    }

    char **out = parse(in);

    if(!out){
        return (1);
    }

    sort(out);

    show(in, out);
    
    return (0);
}

/*Varianta 13. Să se sorteze cuvintele în ordinea inversă celei alfabetice.*/