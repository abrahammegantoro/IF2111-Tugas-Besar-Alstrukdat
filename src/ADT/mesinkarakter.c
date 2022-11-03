# include "mesinkarakter.h"
# include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START(){
    pita = stdin;
    fseek(pita, 0, SEEK_END);   // Pindah ke belakang pita
    fputc('.', pita);           // Tambahin . di akhir
    rewind(pita);               // Kembali ke awal pita
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