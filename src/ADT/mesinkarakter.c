# include "mesinkarakter.h"
# include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
int retval;

void START(FILE *input){
    pita = input;
    // fseek(pita, 0, SEEK_END);   // Pindah ke belakang pita
    // fputc(MARK, pita);           // Tambahin . di akhir
    // rewind(pita);               // Kembali ke awal pita
    ADV();
}

void ADV(){
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK || currentChar == '\r');
}

void CLOSE(){
    fclose(pita);
}

char GetCC(){
    return currentChar;
}

boolean IsEOP(){
    return false;
}