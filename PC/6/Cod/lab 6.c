#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

const int lim = 1000;

void deleteElem(char **in, int i) {
    while(in[i + 1]){
        in[i] = in[i + 1];
        i++;
    }
    in[i] = '\0';
}

void deleteRepeat(char **in) {
    for(int times = 4; times > 0; times--){
        for(int i = 0; in[i]; i++){

            for (int j = i + 1; in[j]; j++) {

                if(strcmp(in[i], in[j]) == 0) {
                    deleteElem(in, j);
                }
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

void showMasterpiece(char *in, char **out) {

    printf("\nRezultatul eliminării cuvintelor identice:\n\n");

    int i = 0, j = 0;

    while(in[i]) {

        while(!isalpha(in[i]) && in[i]) {
            printf("%c", in[i]);
            i++;
        }

        if(isalpha(in[i]) && !isalpha(in[i - 1]) && 
            out[j] &&
            !strncmp(&in[i], out[j], strlen(out[j]))) {

            while(isalpha(in[i])) {
                printf("%c", in[i]);
                i++;
            }
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

    deleteRepeat(out);

    showMasterpiece(in, out);
    
    return (0);
}
