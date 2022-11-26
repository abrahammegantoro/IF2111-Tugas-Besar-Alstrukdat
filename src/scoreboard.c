#include"scoreboard.h"
#include <stdio.h>

void CreateListScore(ListScore *scoreBoard){
    CreateEmptyMap(&((*scoreBoard).Score));
    CreateEmptySet(&((*scoreBoard).Nama));}

void printScoreboard(TabKata listGame, ListScore *scoreBoard){
    for (int i = 0; i < listGame.Neff; i++) {
        printf("**** SCOREBOARD GAME ");
        PrintWord(listGame.TI[i]);
        printf(" ****\n");

        int maxLen = 10;
        for (int j = 0; j < scoreBoard[i].Score.Count; j++) {
            if (scoreBoard[i].Nama.Elements[scoreBoard[i].Score.Elements[j].Key].Length > maxLen) maxLen = scoreBoard[i].Nama.Elements[scoreBoard[i].Score.Elements[j].Key].Length;
        }
        maxLen += 2;
        
        printf("| NAMA");
        for (int j = 6; j < maxLen + 1; j++) printf(" ");
        printf("| SKOR");
        for (int j = 6; j < 13; j++) printf(" ");
        printf("|\n");

        if (!IsEmptyMap(scoreBoard[i].Score)) {
            printf("|");
            for (int j = 0; j < maxLen + 13; j++) printf("-");
            printf("|\n");
            for (int j = 0; j < scoreBoard[i].Score.Count; j++) {
                printf("| ");
                PrintWord(scoreBoard[i].Nama.Elements[scoreBoard[i].Score.Elements[j].Key]);
                for (int k = scoreBoard[i].Nama.Elements[scoreBoard[i].Score.Elements[j].Key].Length; k < maxLen - 1; k++) printf(" ");
                printf("| ");
                Word score = intToWord(scoreBoard[i].Score.Elements[j].Value);
                PrintWord(score);
                for (int k = score.Length; k < 11; k++) printf(" ");
                printf("|\n");
            }
        } else {
            for (int j = 0; j < (maxLen - 6) / 2 + 1; j++) printf("-");
            printf(" SCOREBOARD KOSONG ");
            for (int j = 0; j < (maxLen - 6) / 2 + 1; j++) printf("-");
            printf("\n");
        }
        printf("\n");
    }
}




