# include <stdio.h>
# include <stdlib.h>

void load(char *filename){
    FILE *file;
    file = fopen(filename,"r");
    if (file != NULL){
        printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
}