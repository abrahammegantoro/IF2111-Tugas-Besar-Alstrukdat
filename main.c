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

    printf("Welcome to BNMO!\n");
    printf("ENTER COMMAND: ");
    STARTINPUT();
    while(!WordCompare(currentWord, toKata("START")) && !WordCompare(currentWord, toKata("LOAD"))){
        printf("ENTER COMMAND: ");
        STARTINPUT();
    }
    if (WordCompare(currentWord, toKata("START"))){
        
        start(&Game);
    } else if (WordCompare(currentWord, toKata("LOAD"))){
        ADVWORD();
        load(currentWord, &Game);
    } 
    for (int i = 0; i < 8; i++) {
        if (i % 4 == 0) {system("cls"); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         ||  /          \n _ _      ______  ______  ______   _____        |   ._.   || /       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         ");}
        if (i % 4 == 1) {system("cls"); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         || |           \n _ _      ______  ______  ______   _____        |   ._.   || /       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         ");}
        if (i % 4 == 2) {system("cls"); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         || |           \n _ _      ______  ______  ______   _____        |   ._.   || |       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         ");}
        if (i % 4 == 3) {system("cls"); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         || |           \n _ _      ______  ______  ______   _____        |   ._.   || /       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         \n\n");}
        sleep(1);
    }
    printf("ENTER COMMAND: ");
    STARTINPUT();
    while (!(WordCompare(currentWord,toKata("QUIT")))){
        if (WordCompare(currentWord, toKata("CREATE"))){
            ADVWORD();
            if (WordCompare(currentWord, toKata("GAME"))){
                createGame(&Game);
            }
        } else if (WordCompare(currentWord, toKata("DELETE"))){
            ADVWORD();
            if (WordCompare(currentWord, toKata("GAME"))){
                listGame(Game);
                deleteGame(&Game);
            }
        } else if (WordCompare(currentWord, toKata("LIST"))){
            ADVWORD();
            if (WordCompare(currentWord, toKata("GAME"))){
                listGame(Game);
            } else {
                printf("Perintah tidak dikenali.\n");
            }
        } else if (WordCompare(currentWord, toKata("SAVE"))){
            ADVWORD();
            save(Game, currentWord);
        } else if (WordCompare(currentWord, toKata("PLAY"))){
            ADVWORD();
            if (WordCompare(currentWord, toKata("GAME"))){
                playGame(&antrianGame);
            } else {
                printf("Perintah tidak dikenali.\n");
            }
        } else if (WordCompare(currentWord, toKata("QUEUE"))){
            ADVWORD();
            if (WordCompare(currentWord, toKata("GAME"))){
                queueGame(Game, &antrianGame);
            } else {
                printf("Perintah tidak dikenali.\n");
            }
        } else if (WordCompare(currentWord, toKata("SKIP"))){
            ADVWORD();
            skipGame(&antrianGame, currentWord);
        } else if(WordCompare(currentWord, toKata("LOAD"))){
            load(currentWord, &Game);
        } else {
            printf("Perintah tidak dikenali.\n");
        }
        printf("ENTER COMMAND: ");
        STARTINPUT();
    }
    quit();
    return 0;
}
