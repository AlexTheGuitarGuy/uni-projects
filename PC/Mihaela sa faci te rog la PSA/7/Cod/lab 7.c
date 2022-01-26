#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char denumirea[100];
    char tara[100];
    char regizorul[100];
    char genul[100];
    int anul;
}Film;
Film *FILME;

int SIZE = 0;
int IS_FREED = 0;
int IS_INITIALIZED = 0;

void showOptions() {
    printf("\nMeniu:\n");
    printf("1. Alocarea dinamică a memoriei pentru tabloul de structuri.\n");
    printf("2. Introducerea elementelor tabloului de la tastatură.\n");
    printf("3. Afișarea elementelor tabloului la ecran.\n");
    printf("4. Adăugarea unui element nou la sfârșit.\n");
    printf("5. Modificarea elementului tabloului.\n");
    printf("6. Căutarea elementului tabloului.\n");
    printf("7. Sortarea tabloului.\n");
    printf("8. Eliminarea elementului indicat din tablou.\n");
    printf("9. Eliberarea memoriei alocate pentru tablou.\n");
    printf("0. Ieșire din program.\n");
}

void filmAlloc(){
    printf("\nCâte filme se vor afla în tablou?\n");

    if(!scanf("%d%*c", &SIZE)){
        printf("Valoare invalidă.\n");
        FILME = NULL;
        return;
    }

    FILME = (Film *)malloc(SIZE * sizeof(Film));

    if(FILME == NULL) {
        printf("A eșuat alocarea memoriei pentru tabloul de structuri.");
    }

    IS_FREED = 0;
}

int addValues(int i) {
    scanf("%*c");
    printf("\nCare e denumirea filmului %d?\n", i);
    fgets(FILME[i].denumirea, sizeof(FILME[i].denumirea), stdin);
    FILME[i].denumirea[ strlen(FILME[i].denumirea) - 1] = '\0';

    printf("\nDin ce țară provine filmul %d?\n", i);
    fgets(FILME[i].tara, sizeof(FILME[i].tara), stdin);
    FILME[i].tara[ strlen(FILME[i].tara) - 1] = '\0';

    printf("\nCine e regizorul filmului %d?\n", i);
    fgets(FILME[i].regizorul, sizeof(FILME[i].regizorul), stdin);
    FILME[i].regizorul[ strlen(FILME[i].regizorul) - 1] = '\0';

    printf("\nDe ce gen e filmul %d?\n", i);
    fgets(FILME[i].genul, sizeof(FILME[i].genul), stdin);
    FILME[i].genul[ strlen(FILME[i].genul) - 1] = '\0';

    printf("\nÎn ce an a fost produs filmul %d?\n", i);
    if(!scanf("%d", &FILME[i].anul)){
        return(0);
    }

    return (1);
}

int introduce(){
    if(!FILME){
        printf("Tabloului de structuri nu i s-a alocat memorie.\n");
        return(1);
    }

    for (int i = 0; i < SIZE; i++) {
        if(!addValues(i)){
            printf("Valoare invalidă\n");
            return(0);
        }
    }

    IS_INITIALIZED = 1;
    return(1);
}

int validityCheck(unsigned int i) {
    if(!FILME && i >= 1){
        printf("Tabloului de structuri nu i s-a alocat memorie.\n");
        return 0;
    }

    if(IS_FREED && i >= 2) {
        printf("Memoria alocată pentru tablou a fost eliberată, iar operații cu dânsul pot fi imprevizibile.\n");
        return(0);
    }
    
    if(!IS_INITIALIZED && i >= 3) {
        printf("Tabloul nu a fost inițializat.\n");
        return 0;
    }


    return 1;
}

void showFilm(int i) {
    printf("\nFilmul %d:\n", i);

    printf("\t1.Denumirea: %s;\n", FILME[i].denumirea);

    printf("\t2.Țara: %s;\n", FILME[i].tara);

    printf("\t3.Regizorul: %s;\n", FILME[i].regizorul);

    printf("\t4.Genul: %s;\n", FILME[i].genul);

    printf("\t5.Anul: %d.\n", FILME[i].anul);
}

void show() {

    for (int i = 0; i < SIZE; i++) {
        showFilm(i);
    }
}

int push() {
    SIZE++;

    FILME = (Film *)realloc(FILME, SIZE * sizeof(Film));

    if(!addValues(SIZE - 1)){
        printf("Valoare invalidă.\n");
        return(0);
    }

    if(FILME == NULL) {
        printf("A eșuat realocarea memoriei pentru tabloul de structuri.");
    }
}

int modify() {

    printf("\nElementele tabloului:\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d: filmul %s\n", i, FILME[i].denumirea);
    }

    int i = 0;
    printf("\nIntroduceți numărul elementului pe care doriți să-l modificați: ");
    if(!scanf("%d", &i)){
        printf("Valoare invalidă.\n");
        return(0);
    }

    if (i >= SIZE || i < 0) {
        printf("Elementul %d nu se află în tablou\n", i);
        return(1);
    }

    showFilm(i);

    int j = 0;
    printf("\nCe proprietate doriți să schimbați? (1-5/sau 0 pentru tot)\n");
    if(!scanf("%d", &j)){
        printf("Valoare invalidă.\n");
        return(0);
    }

    switch(j){
        case 1: scanf("%*c");
                printf("\nCare e denumirea filmului %d?\n", i);
                fgets(FILME[i].denumirea, sizeof(FILME[i].denumirea), stdin);
                FILME[i].denumirea[ strlen(FILME[i].denumirea) - 1] = '\0';
                break;

        case 2: scanf("%*c");
                printf("\nDin ce țară provine filmul %d?\n", i);
                fgets(FILME[i].tara, sizeof(FILME[i].tara), stdin);
                FILME[i].tara[ strlen(FILME[i].tara) - 1] = '\0';
                break;

        case 3: scanf("%*c");
                printf("\nCine e regizorul filmului %d?\n", i);
                fgets(FILME[i].regizorul, sizeof(FILME[i].regizorul), stdin);
                FILME[i].regizorul[ strlen(FILME[i].regizorul) - 1] = '\0';
                break;

        case 4: scanf("%*c");
                printf("\nDe ce gen e filmul %d?\n", i);
                fgets(FILME[i].genul, sizeof(FILME[i].genul), stdin);
                FILME[i].genul[ strlen(FILME[i].genul) - 1] = '\0';
                break;

        case 5: scanf("%*c");
                printf("\nÎn ce an a fost produs filmul %d?\n", i);
                if(!scanf("%d", &FILME[i].anul)){
                    return(0);
                }
                break;
        
        case 0: addValues(i);
                break;

        default: printf("\nNu există proprietatea cu numărul %d\n", j);
    }

    return (1);
}

void genSearch(char *cmp) {

    printf("\nFilme de genul căutat de voi:\n");
    for (int i = 0; i < SIZE; i++) {
        if(strcmp(FILME[i].genul, cmp) == 0){
            printf("%d\n", i);
        }
    }
}

void yearSearch(float cmp) {

    printf("\nFilme din anul căutat de voi:\n");
    for (int i = 0; i < SIZE; i++) {
        if(FILME[i].anul == cmp){
            printf("%d\n", i);
        }
    }
}

int search() {
    printf("\nProprietăți disponibile pentru căutare: \n");
    printf("1.genul\n2.anul\n");
    printf("\nPrin care proprietate doriți să căutați?\n");

    int i;
    if(!scanf("%d", &i)){
        printf("Valoare invalidă.\n");
        return(0);
    }

    char scmp[100];
    float fcmp;

    scanf("%*c");
    switch(i){
        case 1: printf("\nCe gen doriți să căutați?\n");
                fgets(scmp, sizeof(scmp), stdin);
                scmp[ strlen(scmp) - 1] = '\0';
                genSearch(scmp);
            break;

        case 2: scanf("%*c");
                printf("\nCe an doriți să căutați?\n");
                if(!scanf("%f", &fcmp)){
                    printf("Valoare invalidă.\n");
                    return(0);
                }
                yearSearch(fcmp);
                break;
            break;
        default: printf("Proprietatea cu numărul dat nu există sau prin ea nu se poate căuta.\n");
    }
    return(1);
}

void nameSort() {
    Film tmp;

    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {

            if(strcmp(FILME[i].denumirea, FILME[j].denumirea) > 0) {
                tmp = FILME[i];
                FILME[i] = FILME[j];
                FILME[j] = tmp;
            }
        }
    }
}

void yearSort() {
    Film tmp;

    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {

            if(FILME[i].anul < FILME[j].anul) {
                tmp = FILME[i];
                FILME[i] = FILME[j];
                FILME[j] = tmp;
            }
        }
    }
}

int sort() {
    printf("\nProprietăți disponibile: \n");
    printf("1.denumirea\n5.anul\n");
    printf("\nDupă ce proprietate doriți să sortați?\n");

    int i;
    if(!scanf("%d", &i)){
        printf("Valoare invalidă.\n");
        return(0);
    }

    scanf("%*c");
    switch(i){
        case 1: nameSort();
            break;

        case 2: yearSort();
            break;

        default: printf("Proprietatea cu numărul dat nu există sau prin ea nu se poate sorta.\n");
    }
    return(1);
}

int delete() {
    show();
    printf("\nCe element ați dori sa eliminați?\n");

    int del;
    if(!scanf("%d", &del) || del >= SIZE || del < 0){
        printf("Valoare invalidă.\n");
        return(0);
    }

    Film *tmp;
    tmp = (Film *)malloc((SIZE - 1) * sizeof(Film));

    if(tmp == NULL) {
        printf("A eșuat alocarea memoriei pentru noul tablou de structuri.");
    }
    for (int i = 0, j = 0; i < SIZE; i++){
        if(i != del){
            tmp[j] = FILME[i];
            j++;
        }
    }

    SIZE--;
    FILME = NULL;
    FILME = tmp;
    
}

int handleOptions(int in) {
    switch(in) {
        case 1: filmAlloc();
                if(FILME == NULL){
                    return(0);
                }
                break;

        case 2: if (validityCheck(2)){
                    if(!introduce()){
                        return(0);
                    }
                }
                break;

        case 3: if(validityCheck(3)) {
                    show();
                }
                break;

        case 4: if(validityCheck(3)){
                    if(!push()) {
                        return (0);
                    }
                }
                break;

        case 5: if(validityCheck(3)){
                    if(!modify()) {
                        return (0);
                    }
                }
                break;

        case 6: if(validityCheck(3)) {
                   if(!search()) {
                       return(0);
                   } 
                }
                break;

        case 7: if(validityCheck(3)) {
                    if(!sort()) {
                        return(0);
                    }
                }
                break;

        case 8: if(validityCheck(3)) {
                    if(!delete()) {
                        return(0);
                    }
                }
                break;

        case 9: if(validityCheck(2)) {
                    free(FILME);
                    IS_FREED = 1;
                    IS_INITIALIZED = 0;
                }
                break;

        case 0:
            return 1;
        default:printf("Valoarea %d nu există în meniul de opțiuni, introduceți o altă valoare.\n", in);
    }

    return (1);
}

int evaluate() {
    int in;

    do{
        showOptions();
        printf("\nCe operațiune doriți să efectuați?\n");

        if(!scanf("%d", &in)){
            printf("Valoare invalidă.\n");
            return (0);
        }
        else if(!handleOptions(in)){
            return(0);
        }

    }  while(in != 0);

    return (1);
}

int main () {

    if (!evaluate()){
        return(1);
    }

    return (0);
}


/*
Pentru tabloul unidimensional dat cu elemente de tip structură (conform
variantelor) să se afișeze la ecran următorul meniu de opțiuni:
1. Alocarea dinamică a memoriei pentru tabloul de structuri.
2. Introducerea elementelor tabloului de la tastatură.
3. Afișarea elementelor tabloului la ecran.
4. Adăugarea unui element nou la sfârșit.
5. Modificarea elementului tabloului.
6. Căutarea elementului tabloului.
7. Sortarea tabloului.
8. Eliminarea elementului indicat din tablou.
9. Eliberarea memoriei alocate pentru tablou.
0. Ieșire din program.
Să se elaboreze funcțiile pentru implementarea opțiunilor meniului.
*/

/*
15. Structura Film cu câmpurile: denumirea, tara, memoria, viteza, prețul.
*/