# include <stdio.h>
# include <stdlib.h>
# include "array.h"

void load(char *filename, TabInt file){
    FILE *files;
    files = fopen(filename,"r");
    if (files != NULL){
        char c;

        c = fgetc(filename);
        int i = 0;

        while(!IsEOP(c)){
            file.TI[i] = c;
        }
        printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
}