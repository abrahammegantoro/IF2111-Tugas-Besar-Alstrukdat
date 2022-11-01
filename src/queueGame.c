# include "queue.h"
# include "array.h"

void displayQueueGame(Queue antrianGame){
    if (!isEmpty(antrianGame)){
        printf("Berikut adalah daftar antrian game-mu\n");
        int i = IDX_HEAD(antrianGame);
        int j = 1;
        while (i != IDX_TAIL(antrianGame)){
            printf("%d. %s\n", j, antrianGame.buffer[i]);
            i++;
            j++;
        }
        printf("%d. %s\n", j, antrianGame.buffer[i]);
    } else {
        printf("Belum ada daftar antrian.\n");
    }
}
    
void queueGame(TabInt file, Queue antrianGame){
    displayQueueGame(antrianGame);
    displayArrayGame(file);
    
    int tambahGame;
    scanf("Nomor Game yang mau ditambahkan ke antrian: %d", &tambahGame);
    if(IsIdxValid(file, tambahGame)){
        enqueue(&antrianGame, file.TI[tambahGame-1]);
    }
}