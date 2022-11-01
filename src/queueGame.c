# include "queue.h"
# include "array.h"

void queueGame(TabInt file){
    
    int i = 0;
    for (i ; i < MaxNbEl ; i++){
        if (file.TI[i] != 0){
            printf("%d. %s", i, file.TI[i]);
        }
    }
}