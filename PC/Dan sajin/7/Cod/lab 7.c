
//Structura Restaurant cu câmpurile: denumirea, adresa, telefonul, categoria, numărul de locuri, specializarea.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char denumirea[100];
    char adresa[100];
    char telefonul[100];
    char categoria[100];
    int nr_locuri;
    char specializarea[100];
}Restaurant;
Restaurant *restaurante;

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

void restaurantAlloc(){
    printf("\nCâte restaurante se vor afla în tablou?\n");

    if(!scanf("%d%*c", &SIZE)){
        printf("Valoare invalidă.\n");
        restaurante = NULL;
        return;
    }

    restaurante = (Restaurant *)malloc(SIZE * sizeof(Restaurant));

    if(restaurante == NULL) {
        printf("A eșuat alocarea memoriei pentru tabloul de structuri.");
    }

    IS_FREED = 0;
}

int addValues(int i) {
    scanf("%*c");
    printf("\nCare e denumirea restaurantului %d?\n", i);
    fgets(restaurante[i].denumirea, sizeof(restaurante[i].denumirea), stdin);
    restaurante[i].denumirea[ strlen(restaurante[i].denumirea) - 1] = '\0';

    printf("\nCe adresă are restaurantul %d?\n", i);
    fgets(restaurante[i].adresa, sizeof(restaurante[i].adresa), stdin);
    restaurante[i].adresa[ strlen(restaurante[i].adresa) - 1] = '\0';

    printf("\nCare e telefonul restaurantului %d?\n", i);
    fgets(restaurante[i].telefonul, sizeof(restaurante[i].telefonul), stdin);
    restaurante[i].telefonul[ strlen(restaurante[i].telefonul) - 1] = '\0';

    printf("\nCare e categoria restaurantului %d?\n", i);
    fgets(restaurante[i].categoria, sizeof(restaurante[i].categoria), stdin);
    restaurante[i].categoria[ strlen(restaurante[i].categoria) - 1] = '\0';

    printf("\nCare e specializarea restaurantului %d?\n", i);
    fgets(restaurante[i].specializarea, sizeof(restaurante[i].specializarea), stdin);
    restaurante[i].specializarea[ strlen(restaurante[i].specializarea) - 1] = '\0';

    printf("\nCâte locuri are restaurantul %d?\n", i);
    if(!scanf("%d", &restaurante[i].nr_locuri)){
        return(0);
    }

    return (1);
}

int introduce(){
    if(!restaurante){
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
    if(!restaurante && i >= 1){
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

void showRestaurant(int i) {
    printf("\nRestaurantul %d:\n", i);

    printf("\t1.denumirea: %s;\n", restaurante[i].denumirea);

    printf("\t2.adresa: %s;\n", restaurante[i].adresa);

    printf("\t3.telefonul: %s;\n", restaurante[i].telefonul);

    printf("\t4.categoria: %s;\n", restaurante[i].categoria);

    printf("\t5.numărul de locuri: %d;\n", restaurante[i].nr_locuri);

    printf("\t6.specializarea: %s.\n", restaurante[i].specializarea);

}

void show() {

    for (int i = 0; i < SIZE; i++) {
        showRestaurant(i);
    }
}

int push() {
    SIZE++;

    restaurante = (Restaurant *)realloc(restaurante, SIZE * sizeof(Restaurant));

    if(!addValues(SIZE - 1)){
        printf("Valoare invalidă.\n");
        return(0);
    }

    if(restaurante == NULL) {
        printf("A eșuat realocarea memoriei pentru tabloul de structuri.");
    }
}

int modify() {

    printf("\nElementele tabloului:\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d: denumirea %s\n", i, restaurante[i].denumirea);
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

    showRestaurant(i);

    int j = 0;
    printf("\nCe proprietate doriți să schimbați? (1-6/sau 0 pentru tot)\n");
    if(!scanf("%d", &j)){
        printf("Valoare invalidă.\n");
        return(0);
    }

    switch(j){
        case 1: scanf("%*c");
                printf("\nCare e denumirea restaurantului %d?\n", i);
                fgets(restaurante[i].denumirea, sizeof(restaurante[i].denumirea), stdin);
                restaurante[i].denumirea[ strlen(restaurante[i].denumirea) - 1] = '\0';
                break;

        case 2: scanf("%*c");
                printf("\nCe adresă are restaurantul %d?\n", i);
                fgets(restaurante[i].adresa, sizeof(restaurante[i].adresa), stdin);
                restaurante[i].adresa[ strlen(restaurante[i].adresa) - 1] = '\0';
                break;

        case 3: scanf("%*c");
                printf("\nCare e telefonul restaurantului %d?\n", i);
                fgets(restaurante[i].telefonul, sizeof(restaurante[i].telefonul), stdin);
                restaurante[i].telefonul[ strlen(restaurante[i].telefonul) - 1] = '\0';
                break;

        case 4: scanf("%*c");
                printf("\nCare e categoria restaurantului %d?\n", i);
                fgets(restaurante[i].categoria, sizeof(restaurante[i].categoria), stdin);
                restaurante[i].categoria[ strlen(restaurante[i].categoria) - 1] = '\0';
                break;

        case 5: scanf("%*c");
                printf("\nCâte locuri are restaurantul %d?\n", i);
                if(!scanf("%d", &restaurante[i].nr_locuri)){
                    return(0);
                }
                break;

        case 6: scanf("%*c");
                printf("\nCare e specializarea restaurantului %d?\n", i);
                fgets(restaurante[i].specializarea, sizeof(restaurante[i].specializarea), stdin);
                restaurante[i].specializarea[ strlen(restaurante[i].specializarea) - 1] = '\0';
                break;
        
        case 0: addValues(i);
                break;

        default: printf("\nNu există proprietatea cu numarul %d\n", j);
    }

    return (1);
}

void nameSearch(char *cmp) {

    printf("\nRestaurante de denumirea căutată de voi:\n");
    for (int i = 0; i < SIZE; i++) {
        if(strcmp(restaurante[i].denumirea, cmp) == 0){
            printf("%d\n", i);
        }
    }
}

void placesSearch(int cmp) {

    printf("\nRestaurante cu numărul de locuri căutat de voi:\n");
    for (int i = 0; i < SIZE; i++) {
        if(restaurante[i].nr_locuri == cmp){
            printf("%d\n", i);
        }
    }
}

int search() {
    printf("\nProprietăți disponibile: \n");
    printf("1.denumirea\n2.numărul de locuri");
    printf("\nPrin care proprietate doriți să căutați?\n");

    int i;
    if(!scanf("%d", &i)){
        printf("Valoare invalidă.\n");
        return(0);
    }

    char scmp[100];
    int icmp;

    scanf("%*c");
    switch(i){
        case 1: printf("\nCe model doriți să căutați?\n");
                fgets(scmp, sizeof(scmp), stdin);
                scmp[ strlen(scmp) - 1] = '\0';
                nameSearch(scmp);
            break;

        case 2: printf("\nCe număr de locuri doriți să căutați?\n");
                if(!scanf("%d", &icmp)){
                    printf("Valoare invalidă.\n");
                    return(0);
                }
                placesSearch(icmp);
            break;
        default: printf("Proprietatea cu numărul dat nu există.\n");
    }
    return(1);
}

void nameSort() {
    Restaurant tmp;

    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {

            if(strcmp(restaurante[i].denumirea, restaurante[j].denumirea) > 0) {
                tmp = restaurante[i];
                restaurante[i] = restaurante[j];
                restaurante[j] = tmp;
            }
        }
    }
}

void placesSort() {
    Restaurant tmp;

    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {

            if(restaurante[i].nr_locuri < restaurante[j].nr_locuri) {
                tmp = restaurante[i];
                restaurante[i] = restaurante[j];
                restaurante[j] = tmp;
            }
        }
    }
}

int sort() {
    printf("\nProprietăți disponibile: \n");
    printf("1.denumirea\n2.numărul de locuri");
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

        case 2: placesSort();
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

    Restaurant *tmp;
    tmp = (Restaurant *)malloc((SIZE - 1) * sizeof(Restaurant));

    if(tmp == NULL) {
        printf("A eșuat alocarea memoriei pentru noul tablou de structuri.");
    }
    for (int i = 0, j = 0; i < SIZE; i++){
        if(i != del){
            tmp[j] = restaurante[i];
            j++;
        }
    }

    SIZE--;
    restaurante = NULL;
    restaurante = tmp;
    
}

int handleOptions(int in) {
    switch(in) {
        case 1: restaurantAlloc();
                if(restaurante == NULL){
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
                    free(restaurante);
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
Structura Restaurant cu câmpurile: denumirea, adresa, telefonul, categoria, numărul de locuri, specializarea.
*/