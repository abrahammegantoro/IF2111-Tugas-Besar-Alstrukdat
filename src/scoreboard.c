#include"scoreboard.h"
#include <stdio.h>

void CreateListScore(ListScore *scoreBoard){
    CreateEmptyMap(&((*scoreBoard).Score));
    CreateEmptySet(&((*scoreBoard).Nama));}

void printScoreboard(TabKata x, ListScore scoreBoard, int gameKe){
    int j, k;
    printf("\t**** SCOREBOARD GAME ");
    for(int j = 0; j < x.TI[gameKe].Length; j++) {
        printf("%c", x.TI[gameKe].TabWord[j]);}
        printf(" ****\n");
        printf("| NAMA\t\t\t| SKOR\t\t\t|\n");
        printf("-------------------------------------------------\n");
        for (j = 0; j < scoreBoard.Score.Count; j++){
            printf("| ");
            for(int k = 0; k < scoreBoard.Nama.Elements[scoreBoard.Score.Elements[j].Key].Length; k++) {
                printf("%c", scoreBoard.Nama.Elements[scoreBoard.Score.Elements[j].Key].TabWord[k]);}
            printf("\t\t\t| %d\t\t\t|\n", scoreBoard.Score.Elements[j].Value);
    }
    printf("\n");
}




