# include "mesinkarakterFile.h"
# include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START(char* filename){
    pita = fopen(filename, "r");
    ADV();
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