# include "src/start.h"
# include "src/createGame.h"
# include "src/deleteGame.h"
# include "src/listGame.h"
# include "src/load.h"
# include "src/save.h"
# include "src/playGame.h"
# include "src/queueGame.h"
# include "src/skipGame.h"
# include "src/help.h"
# include "src/quit.h"
# include "unistd.h"

int main(){
    TabKata Game;
    MakeEmpty(&Game);

    Queue antrianGame;
    CreateQueue(&antrianGame);

    system("cls");
    for (int i = 0; i < 8; i++) {
        if (i % 4 == 0) {system("cls"); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         ||  /          \n _ _      ______  ______  ______   _____        |   ._.   || /       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         \n\n");}
        if (i % 4 == 1) {system("cls"); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         || |           \n _ _      ______  ______  ______   _____        |   ._.   || /       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         \n\n");}
        if (i % 4 == 2) {system("cls"); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         || |           \n _ _      ______  ______  ______   _____        |   ._.   || |       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         \n\n");}
        if (i % 4 == 3) {system("cls"); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         || |           \n _ _      ______  ______  ______   _____        |   ._.   || /       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         \n\n");}
        sleep(1);
    }

    

    printf("Welcome to BNMO!\n\n");
    while (Game.Neff == 0) {
        boolean isStarted = false;
        printf("Ketik 'START' atau 'LOAD <filename.txt>' untuk mulai bermain\n");
        printf("ENTER COMMAND: ");
        STARTINPUT();
        
        while(!isStarted){
            if (WordCompare(currentWord, toKata("START"))){
                ADVWORD();
                if (EndWord){
                    system("cls");
                    isStarted = true;
                    start(&Game);
                }
            } else if (WordCompare(currentWord, toKata("LOAD"))){
                ADVWORD();
                Word fileName = currentWord;
                ADVWORD();
                if (EndWord){
                    system("cls");
                    isStarted = true;
                    load(fileName, &Game);
                }
            }
            while (!EndWord) {
                ADVWORD();
            }
            if (!isStarted){
                system("cls");
                printf("Perintah tidak dikenali\n\n");
                printf("Ketik 'START' atau 'LOAD <filename.txt>' untuk mulai bermain\n");
                printf("ENTER COMMAND: ");
                STARTINPUT();
            }
        }
    }

    printf("ENTER COMMAND: ");
    STARTINPUT();
    system("cls");
    while (!(WordCompare(currentWord,toKata("QUIT")))){
        if (WordCompare(currentWord, toKata("CREATE"))){
            ADVWORD();
            if (WordCompare(currentWord, toKata("GAME"))){
                ADVWORD();
                if (EndWord){
                    createGame(&Game);                    
                } else {
                    printf("Perintah tidak dikenali\n");
                }
            }
        } else if (WordCompare(currentWord, toKata("DELETE"))){
            ADVWORD();
            if (WordCompare(currentWord, toKata("GAME"))){
                ADVWORD();
                if (EndWord){
                    listGame(Game);
                    deleteGame(&Game, antrianGame);
                } else {
                    printf("Perintah tidak dikenali\n");
                }
            }
        } else if (WordCompare(currentWord, toKata("LIST"))){
            ADVWORD();
            if (WordCompare(currentWord, toKata("GAME"))){
                ADVWORD();
                if (EndWord){
                    listGame(Game);
                } else {
                    printf("Perintah tidak dikenali\n");
                }
            } else {
                printf("Perintah tidak dikenali.\n");
            }
        } else if (WordCompare(currentWord, toKata("SAVE"))){
            ADVWORD();
            if (EndWord){
                save(Game, currentWord);
            } else {
                printf("Perintah tidak dikenali\n");
            }
        } else if (WordCompare(currentWord, toKata("PLAY"))){
            ADVWORD();
            if (WordCompare(currentWord, toKata("GAME"))){
                ADVWORD();
                if (EndWord){
                    playGame(&antrianGame);
                } else {
                    printf("Perintah tidak dikenali\n");
                }
            } else {
                printf("Perintah tidak dikenali.\n");
            }
        } else if (WordCompare(currentWord, toKata("QUEUE"))){
            ADVWORD();
            if (WordCompare(currentWord, toKata("GAME"))){
                ADVWORD();
                if (EndWord){
                    queueGame(Game, &antrianGame);
                } else {
                    printf("Perintah tidak dikenali\n");
                }
            } else {
                printf("Perintah tidak dikenali.\n");
            }
        } else if (WordCompare(currentWord, toKata("SKIPGAME"))){
            ADVWORD();
            Word fileName = currentWord;
            ADVWORD();
            if (EndWord){
                skipGame(&antrianGame, currentWord);
            } else {
                printf("Perintah tidak dikenali\n");
            }
        } else if(WordCompare(currentWord, toKata("LOAD"))){
            ADVWORD();
            if (EndWord){
                load(currentWord, &Game);
            } else {
                printf("Perintah tidak dikenali\n");
            }
        } else if(WordCompare(currentWord, toKata("HELP"))){
            if (EndWord) {
                help(); 
            } else {
                printf("Perintah tidak dikenali\n");
            }
        } else {
            printf("Perintah tidak dikenali.\n");
        }

        printf("ENTER COMMAND: ");
        STARTINPUT();
        system("cls");
    }
    quit(Game, &antrianGame);
    return 0;
}
