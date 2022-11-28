#include"resetScoreboard.h"

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
        printf("\n");
        if (WordCompare(toKata("YA"), currentWord)){
            for (j = 0; j < x.Neff; j++){
<<<<<<< Updated upstream
                for (y=0; y < scoreBoard[j].Score.Count; y++){
                    scoreBoard[j].Score.Elements[y].Value = 0;}
        }
    }
    }else{
        for (y=0; y < scoreBoard[k-1].Score.Count; y++){
            scoreBoard[k-1].Score.Elements[y].Value = 0;}
=======
                CreateListScore(&scoreBoard[j]);
            //     for (y=0; y <= scoreBoard[j].Score.Count; y++){
            //         // scoreBoard[j].Score.Elements[y].Value = 0;
            //         DeleteSet(&(scoreBoard[j]).Nama, scoreBoard[j].Nama.Elements[y]);
            //         DeleteMap(&(scoreBoard[j]).Score, scoreBoard[j].Score.Elements[y].Key);
                 }
                 printf("Scoreboard berhasil di-reset.\n");
        //}
    }
    }else{
        CreateEmptySet(&(scoreBoard[k-1]).Nama);
        CreateEmptyMap(&(scoreBoard[k-1]).Score);
        // for (y=0; y <= scoreBoard[k-1].Score.Count; y++){
        //     DeleteSet(&(scoreBoard[k-1]).Nama, scoreBoard[k-1].Nama.Elements[y]);
        //     DeleteMap(&(scoreBoard[k-1]).Score, scoreBoard[k-1].Score.Elements[y].Key);
        // }
        printf("Scoreboard berhasil di-reset.\n");
>>>>>>> Stashed changes
    }
};

// SCOREBOARD YANG INGIN DIHAPUS: 0

// 

// Scoreboard berhasil di-reset.
