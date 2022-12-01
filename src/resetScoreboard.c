# include"resetScoreboard.h"
# include <unistd.h>

void resetScoreboard(TabKata x, ListScore *scoreBoard){    
    int k = 0;
    int i;
    printf("  0. ALL\n");
    for (i=IdxMin - 1; i<x.Neff; i++){
        printf("  %d. ", k+1);
        k++;
        for(int j = 0; j < x.TI[i].Length; j++) {
            printf("%c", x.TI[i].TabWord[j]);
        }
    printf("\n");
    }
    printf("SCOREBOARD YANG INGIN DIHAPUS: ");
    STARTINPUT();
    printf("\n");
    k = WordToInt(currentWord);
    int j, y;
    if (k == 0){
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)? ");
        STARTINPUT();
        Word input = currentWord;
        printf("\n");
        ADVWORD();
        if (EndWord){
            if (WordCompare(toKata("YA"), input)){
                for (j = 0; j < x.Neff; j++){
                    CreateListScore(&scoreBoard[j]);
                }
                printf("Menghapus Scoreboard.");
                fflush(stdout);
                sleep(1);
                printf(".");
                fflush(stdout);
                sleep(1);
                printf(".");
                fflush(stdout);
                sleep(1);

                clear();
                printf("Scoreboard berhasil di-reset.\n");
            } else if (WordCompare(toKata("TIDAK"), input)){
                printf("Scoreboard tidak jadi di-reset.\n");
            } else {
                printf("Input tidak valid.\n");
            }
        } else {
            printf("Input tidak valid.\n");
        }
    } else if (k >= 1 && k <= x.Neff) {
        CreateEmptySet(&(scoreBoard[k-1]).Nama);
        CreateEmptyMap(&(scoreBoard[k-1]).Score);

        printf("Menghapus Scoreboard.");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);

        clear();
        printf("Scoreboard berhasil di-reset.\n");
    } else {
        printf("Input tidak valid.\n");
    }
};

// SCOREBOARD YANG INGIN DIHAPUS: 0

// 

// Scoreboard berhasil di-reset.
