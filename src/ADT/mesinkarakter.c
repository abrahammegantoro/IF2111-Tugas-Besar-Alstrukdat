# include "mesinkarakter.h"
# include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START(char* filesrc){
    pita = fopen(filesrc, "r");
    if (pita != NULL) {
        ADV();
    } else {
        printf("File tidak ditemukan.\n");
    }
}

void ADV(){
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if(EOP) {
        fclose(pita);
    }
}

char GetCC(){
    return currentChar;
}

boolean IsEOP(){
    return currentChar == MARK;
}