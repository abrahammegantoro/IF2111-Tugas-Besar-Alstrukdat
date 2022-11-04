# include "start.h"
# include "createGame.h"
# include "deleteGame.h"
# include "listGame.h"
# include "load.h"
# include "save.h"
# include "playGame.h"
# include "queueGame.h"
# include "skipGame.h"

int main(){
    TabKata Game;
    MakeEmpty(&Game);

    Queue antrianGame;
    CreateQueue(&antrianGame);

    printf("Welcome to BNMO!\n");
    printf("ENTER COMMAND: ");
    STARTINPUT();
    if(WordCompare(currentWord, toKata("START"))){
        start(&Game);
    } else if(WordCompare(currentWord, toKata("LOAD"))){
        load(currentWord, &Game);
    }
    while (!(WordCompare(currentWord,toKata("QUIT")))){
        printf("ENTER COMMAND: ");
        if (WordCompare(currentWord, toKata("CREATE GAME"))){
            createGame(&Game);
        } else if (WordCompare(currentWord, toKata("DELETE GAME"))){
            listGame(Game);
            deleteGame(&Game);
        } else if (WordCompare(currentWord, toKata("LIST GAME"))){
            listGame(Game);
        } else if (WordCompare(currentWord, toKata("SAVE"))){
            save(Game, getFile(currentWord));
        } else if (WordCompare(currentWord, toKata("PLAY GAME"))){
            playGame(&antrianGame);
        } else if (WordCompare(currentWord, toKata("QUEUE GAME"))){
            queueGame(Game, &antrianGame);
        } else if (WordCompare(currentWord, toKata("SKIP"))){
            skipGame(&Game, getFile(currentWord));
        } else {
            printf("Perintah tidak dikenali.\n");
        }
    }
    return 0;
}