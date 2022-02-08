#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char modelul[100];
    char procesorul[100];
    float memoria;
    float viteza;
    float pretul;
}Computer;
Computer *COMPUTERE;

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

void computerAlloc(){
    printf("\nCâte computere se vor afla în tablou?\n");

    if(!scanf("%d%*c", &SIZE)){
        printf("Valoare invalidă.\n");
        COMPUTERE = NULL;
        return;
    }

    COMPUTERE = (Computer *)malloc(SIZE * sizeof(Computer));

    if(COMPUTERE == NULL) {
        printf("A eșuat alocarea memoriei pentru tabloul de structuri.");
    }

    IS_FREED = 0;
}

int addValues(int i) {
    scanf("%*c");
    printf("\nCare e modelul computerului %d?\n", i);
    fgets(COMPUTERE[i].modelul, sizeof(COMPUTERE[i].modelul), stdin);
    COMPUTERE[i].modelul[ strlen(COMPUTERE[i].modelul) - 1] = '\0';

    printf("\nCe procesor are computerul %d?\n", i);
    fgets(COMPUTERE[i].procesorul, sizeof(COMPUTERE[i].procesorul), stdin);
    COMPUTERE[i].procesorul[ strlen(COMPUTERE[i].procesorul) - 1] = '\0';

    printf("\nCâtă memorie are computerul %d? (GB)\n", i);
    if(!scanf("%f", &COMPUTERE[i].memoria)) {
        return(0);
    }

    printf("\nCe viteză are computerul %d? (MHz)\n", i);
    if(!scanf("%f", &COMPUTERE[i].viteza)){
        return(0);
    }

    printf("\nCare e prețul computerului %d? (MDL)\n", i);
    if(!scanf("%f", &COMPUTERE[i].pretul)){
        return(0);
    }

    return (1);
}

int introduce(){
    if(!COMPUTERE){
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
    if(!COMPUTERE && i >= 1){
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

void showComputer(int i) {
    printf("\nComputerul %d:\n", i);

    printf("\t1.Modelul: %s;\n", COMPUTERE[i].modelul);

    printf("\t2.Procesorul: %s;\n", COMPUTERE[i].procesorul);

    printf("\t3.Memoria: %f GB;\n", COMPUTERE[i].memoria);

    printf("\t4.Viteza: %f MHz;\n", COMPUTERE[i].viteza);

    printf("\t5.Prețul: %f MDL.\n", COMPUTERE[i].pretul);
}

void show() {

    for (int i = 0; i < SIZE; i++) {
        showComputer(i);
    }
}

int push() {
    SIZE++;

    COMPUTERE = (Computer *)realloc(COMPUTERE, SIZE * sizeof(Computer));

    if(!addValues(SIZE - 1)){
        printf("Valoare invalidă.\n");
        return(0);
    }

    if(COMPUTERE == NULL) {
        printf("A eșuat realocarea memoriei pentru tabloul de structuri.");
    }
}

int modify() {

    printf("\nElementele tabloului:\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d: modelul %s\n", i, COMPUTERE[i].modelul);
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

    showComputer(i);

    int j = 0;
    printf("\nCe proprietate doriți să schimbați? (1-5/sau 0 pentru tot)\n");
    if(!scanf("%d", &j)){
        printf("Valoare invalidă.\n");
        return(0);
    }

    switch(j){
        case 1: scanf("%*c");
                printf("\nCare e modelul computerului %d?\n", i);
                fgets(COMPUTERE[i].modelul, sizeof(COMPUTERE[i].modelul), stdin);
                COMPUTERE[i].modelul[ strlen(COMPUTERE[i].modelul) - 1] = '\0';
                break;

        case 2: scanf("%*c");
                printf("\nCe procesor are computerul %d?\n", i);
                fgets(COMPUTERE[i].procesorul, sizeof(COMPUTERE[i].procesorul), stdin);
                COMPUTERE[i].procesorul[ strlen(COMPUTERE[i].procesorul) - 1] = '\0';
                break;

        case 3: scanf("%*c");
                printf("\nCâtă memorie are computerul %d? (GB)\n", i);
                if(!scanf("%f", &COMPUTERE[i].memoria)) {
                    return(0);
                }
                break;

        case 4: scanf("%*c");
                printf("\nCe viteză are computerul %d? (MHz)\n", i);
                if(!scanf("%f", &COMPUTERE[i].viteza)){
                    return(0);
                }
                break;

        case 5: scanf("%*c");
                printf("\nCare e prețul computerului %d? (MDL)\n", i);
                if(!scanf("%f", &COMPUTERE[i].pretul)){
                    return(0);
                }
                break;
        
        case 0: addValues(i);
                break;

        default: printf("\nNu există proprietatea cu numarul %d\n", j);
    }

    return (1);
}

void modelSearch(char *cmp) {

    printf("\nComputere de modelul căutat de voi:\n");
    for (int i = 0; i < SIZE; i++) {
        if(strcmp(COMPUTERE[i].modelul, cmp) == 0){
            printf("%d\n", i);
        }
    }
}

void procSearch(char *cmp) {

    printf("\nComputere cu procesorul căutat de voi:\n");
    for (int i = 0; i < SIZE; i++) {
        if(strcmp(COMPUTERE[i].procesorul, cmp) == 0){
            printf("%d\n", i);
        }
    }
}

void memSearch(float cmp) {

    printf("\nComputere cu memoria căutată de voi:\n");
    for (int i = 0; i < SIZE; i++) {
        if(COMPUTERE[i].memoria == cmp){
            printf("%d\n", i);
        }
    }
}

void spdSearch(float cmp) {

    printf("\nComputere cu viteza căutată de voi:\n");
    for (int i = 0; i < SIZE; i++) {
        if(COMPUTERE[i].viteza == cmp){
            printf("%d\n", i);
        }
    }
}

void priceSearch(float cmp) {

    printf("\nComputere cu prețul căutat de voi:\n");
    for (int i = 0; i < SIZE; i++) {
        if(COMPUTERE[i].pretul == cmp){
            printf("%d\n", i);
        }
    }
}

int search() {
    printf("\nProprietăți disponibile: \n");
    printf("1.modelul\n2.procesorul\n3.memoria\n4.viteza\n5.pretul\n");
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
        case 1: printf("\nCe model doriți să căutați?\n");
                fgets(scmp, sizeof(scmp), stdin);
                scmp[ strlen(scmp) - 1] = '\0';
                modelSearch(scmp);
            break;

        case 2: printf("\nCe procesor doriți să căutați?\n");
                fgets(scmp, sizeof(scmp), stdin);
                scmp[ strlen(scmp) - 1] = '\0';
                procSearch(scmp);
            break;

        case 3: printf("\nCe memorie doriți să căutați?\n");
                if(!scanf("%f", &fcmp)){
                    printf("Valoare invalidă.\n");
                    return(0);
                }
                memSearch(fcmp);
            break;

        case 4: printf("\nCe viteză doriți să căutați?\n");
                if(!scanf("%f", &fcmp)){
                    printf("Valoare invalidă.\n");
                    return(0);
                }
                spdSearch(fcmp);
            break;

        case 5: printf("\nCe preț doriți să căutați?\n");
                if(!scanf("%f", &fcmp)){
                    printf("Valoare invalidă.\n");
                    return(0);
                }
                priceSearch(fcmp);
            break;
        default: printf("Proprietatea cu numărul dat nu există.\n");
    }
    return(1);
}

void modelSort() {
    Computer tmp;

    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {

            if(strcmp(COMPUTERE[i].modelul, COMPUTERE[j].modelul) > 0) {
                tmp = COMPUTERE[i];
                COMPUTERE[i] = COMPUTERE[j];
                COMPUTERE[j] = tmp;
            }
        }
    }
}

void procSort() {
    Computer tmp;

    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {

            if(strcmp(COMPUTERE[i].procesorul, COMPUTERE[j].procesorul) > 0) {
                tmp = COMPUTERE[i];
                COMPUTERE[i] = COMPUTERE[j];
                COMPUTERE[j] = tmp;
            }
        }
    }
}

void memSort() {
    Computer tmp;

    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {

            if(COMPUTERE[i].memoria < COMPUTERE[j].memoria) {
                tmp = COMPUTERE[i];
                COMPUTERE[i] = COMPUTERE[j];
                COMPUTERE[j] = tmp;
            }
        }
    }
}

void spdSort() {
    Computer tmp;

    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {

            if(COMPUTERE[i].viteza < COMPUTERE[j].viteza) {
                tmp = COMPUTERE[i];
                COMPUTERE[i] = COMPUTERE[j];
                COMPUTERE[j] = tmp;
            }
        }
    }
}

void prcSort() {
    Computer tmp;

    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {

            if(COMPUTERE[i].pretul < COMPUTERE[j].pretul) {
                tmp = COMPUTERE[i];
                COMPUTERE[i] = COMPUTERE[j];
                COMPUTERE[j] = tmp;
            }
        }
    }
}

int sort() {
    printf("\nProprietăți disponibile: \n");
    printf("1.modelul\n2.procesorul\n3.memoria\n4.viteza\n5.pretul\n");
    printf("\nDupă ce proprietate doriți să sortați?\n");

    int i;
    if(!scanf("%d", &i)){
        printf("Valoare invalidă.\n");
        return(0);
    }

    scanf("%*c");
    switch(i){
        case 1: modelSort();
            break;

        case 2: procSort();
            break;

        case 3: memSort();
            break;

        case 4: spdSort();
            break;

        case 5: prcSort();
            break;

        default: printf("Proprietatea cu numărul dat nu există.\n");
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

    Computer *tmp;
    tmp = (Computer *)malloc((SIZE - 1) * sizeof(Computer));

    if(tmp == NULL) {
        printf("A eșuat alocarea memoriei pentru noul tablou de structuri.");
    }
    for (int i = 0, j = 0; i < SIZE; i++){
        if(i != del){
            tmp[j] = COMPUTERE[i];
            j++;
        }
    }

    SIZE--;
    COMPUTERE = NULL;
    COMPUTERE = tmp;
    
}

int handleOptions(int in) {
    switch(in) {
        case 1: computerAlloc();
                if(COMPUTERE == NULL){
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
                    free(COMPUTERE);
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
15. Structura Computer cu câmpurile: modelul, procesorul, memoria, viteza, prețul.
*/