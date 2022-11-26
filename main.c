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
# include "src/history.h"
# include "src/resethistory.h"
# include "src/scoreboard.h"
# include "src/resetScoreboard.h"
# include "unistd.h"

int main(){
    TabKata Game;
    MakeEmpty(&Game);

    Stack historyGame;
    CreateEmptyStack(&historyGame);

    Queue antrianGame;
    CreateQueue(&antrianGame);
    
    ListScore scoreBoard[100];
    CreateListScore((&scoreBoard)[0]);
    /*
    system("cls");
    for (int i = 0; i < 8; i++) {
        if (i % 4 == 0) {system("cls"); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         ||  /          \n _ _      ______  ______  ______   _____        |   ._.   || /       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         \n\n");}
        if (i % 4 == 1) {system("cls"); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         || |           \n _ _      ______  ______  ______   _____        |   ._.   || /       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         \n\n");}
        if (i % 4 == 2) {system("cls"); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         || |           \n _ _      ______  ______  ______   _____        |   ._.   || |       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         \n\n");}
        if (i % 4 == 3) {system("cls"); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         || |           \n _ _      ______  ______  ______   _____        |   ._.   || /       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         \n\n");}
        sleep(1);
    }

    */
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
                    start(&Game, &historyGame);
                }
            } else if (WordCompare(currentWord, toKata("LOAD"))){
                ADVWORD();
                Word fileName = currentWord;
                ADVWORD();
                if (EndWord){
                    system("cls");
                    isStarted = true;
                    load(fileName, &Game, &historyGame);
                }
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
                    deleteGame(&Game, antrianGame, &historyGame);
                } else {
                    printf("Perintah tidak dikenali\n");
                }
            }
        } else if (WordCompare(currentWord, toKata("LIST"))){
            ADVWORD();
            if (WordCompare(currentWord, toKata("GAME"))){
                ADVWORD();
                if (EndWord){
                    printf("   _   _____     _____   ______   _________   _    \n  / / |_   _|   |_   _|.' ____ \\ |  _   _  | \\ \\   \n / /    | |       | |  | (___ \\_||_/ | | \\_|  \\ \\  \n< <     | |   _   | |   _.____`.     | |       > > \n \\ \\   _| |__/ | _| |_ | \\____) |   _| |_     / /  \n  \\_\\ |________||_____| \\______.'  |_____|   /_/   \n                                                   \n");
                    printf(" ______  ______  ______  ______  ______  ______  ______  \n|______||______||______||______||______||______||______| \n                                                         \n");
                    listGame(Game);
                    printf(" ______  ______  ______  ______  ______  ______  ______  \n|______||______||______||______||______||______||______| \n                                                         \n");
                } else {
                    printf("Perintah tidak dikenali\n");
                }
            } else {
                printf("Perintah tidak dikenali.\n");
            }
        } else if (WordCompare(currentWord, toKata("SAVE"))){
            ADVWORD();
            if (EndWord){
                printf("Perintah tidak dikenali\n");
            } else {
                Word fileName = currentWord;
                ADVWORD();
                if (EndWord){
                    save(Game, fileName, historyGame);
                } else {
                    printf("Perintah tidak dikenali\n");
                }
            }
        } else if (WordCompare(currentWord, toKata("SAVE"))){
            ADVWORD();
            if (EndWord){
                printf("Perintah tidak dikenali\n");
            } else {
                Word fileName = currentWord;
                ADVWORD();
                if (EndWord){
                    save(Game, fileName, historyGame);
                } else {
                    printf("Perintah tidak dikenali\n");
                }
            }
        } else if (WordCompare(currentWord, toKata("PLAY"))){
            ADVWORD();
            if (WordCompare(currentWord, toKata("GAME"))){
                ADVWORD();
                if (EndWord){
                    playGame(&antrianGame, &historyGame);
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
                    printf("           _____  _     _ _______ _     _ _______          \n  _  _    / ___ \\| |   | (_______) |   | (_______)   _  _  \n / )/ )  | |   | | |   | |_____  | |   | |_____     ( \\( \\ \n( (( (   | |   |_| |   | |  ___) | |   | |  ___)     ) )) )\n \\_)\\_)   \\ \\____| |___| | |_____| |___| | |_____   (_/(_/ \n           \\_____)\\______|_______)\\______|_______)         \n                                                           \n");
                    printf(" ______  ______  ______  ______  ______  ______  ______  \n|______||______||______||______||______||______||______| \n                                                         \n");
                    queueGame(Game, &antrianGame);
                    printf(" ______  ______  ______  ______  ______  ______  ______  \n|______||______||______||______||______||______||______| \n                                                         \n");
                } else {
                    printf("Perintah tidak dikenali\n");
                }
            } else {
                printf("Perintah tidak dikenali.\n");
            }
        } else if (WordCompare(currentWord, toKata("SKIP"))){
            ADVWORD();
            if (WordCompare(currentWord, toKata("GAME")))
            {
                ADVWORD();
                if (EndWord){
                    printf("Perintah tidak dikenali. Masukkan jumlah skip <SKIP GAME n>\n");
                } else {
                    Word n = currentWord;
                    ADVWORD();
                    if (EndWord){
                        skipGame(&antrianGame, n, &historyGame);
                    } else {
                        printf("Perintah tidak dikenali\n");
                    }
                }
            }
        } else if(WordCompare(currentWord, toKata("LOAD"))){
            ADVWORD();
            if (EndWord){
                load(currentWord, &Game, &historyGame);
            } else {
                printf("Perintah tidak dikenali\n");
            }
        } else if(WordCompare(currentWord, toKata("HELP"))){
            ADVWORD();
            if (EndWord) {
                printf("   _   ____  ____  ________  _____     _______    _    \n  / / |_   ||   _||_   __  ||_   _|   |_   __ \\  \\ \\   \n / /    | |__| |    | |_ \\_|  | |       | |__) |  \\ \\  \n< <     |  __  |    |  _| _   | |   _   |  ___/    > > \n \\ \\   _| |  | |_  _| |__/ | _| |__/ | _| |_      / /  \n  \\_\\ |____||____||________||________||_____|    /_/   \n                                                       \n");
                printf(" ______  ______  ______  ______  ______  ______  ______  \n|______||______||______||______||______||______||______| \n                                                         \n");
                help(); 
                printf(" ______  ______  ______  ______  ______  ______  ______  \n|______||______||______||______||______||______||______| \n                                                         \n");
            } else {
                printf("Perintah tidak dikenali\n");
            }
        } else if (WordCompare(currentWord, toKata("HISTORY"))) {
            ADVWORD();
            Word num = currentWord;
            ADVWORD();
            if (EndWord){
                history(historyGame, num);
            } else {
                printf("Perintah tidak dikenali.\n");
            }
        } else if (WordCompare(currentWord, toKata("RESET"))) {
            ADVWORD();
            if (WordCompare(currentWord, toKata("HISTORY")))
            {
                ADVWORD();
                if (EndWord){
                    resethistory(&historyGame);
                } else {
                    printf("Perintah tidak dikenali.\n");
                }
            }
            else if (WordCompare(currentWord, toKata("SCOREBOARD")))
            {
                ADVWORD();
                if (EndWord){
                    resetScoreboard(Game, &(scoreBoard[0]));
                } else {
                    printf("Perintah tidak dikenali.\n");
                }
            }
        }
        else if (WordCompare(currentWord, toKata("SCOREBOARD"))){
            ADVWORD();
            if (EndWord){
                int o = 0;
                int l, j;
                for (j=0; j < Game.Neff; j++){
                    for (o = 0; o < 4; o++){
                        printf("nama ");
                        STARTINPUT();
                        printf("\n");
                        while(InsertSet((&(scoreBoard[j].Nama)), currentWord) == 0){
                            printf("nama ");
                            STARTINPUT();
                            printf("\n");
                        }
                        printf("skor ");
                        STARTINPUT();
                        printf("\n");
                        l = WordToInt(currentWord);
                        InsertMapSorted(&scoreBoard[j].Score, o, l);}
                }
                if (o != 0){
                    printf("   _   _____     _____   ______   _________   _    \n  / / |_   _|   |_   _|.' ____ \\ |  _   _  | \\ \\   \n / /    | |       | |  | (___ \\_||_/ | | \\_|  \\ \\  \n< <     | |   _   | |   _.____`.     | |       > > \n \\ \\   _| |__/ | _| |_ | \\____) |   _| |_     / /  \n  \\_\\ |________||_____| \\______.'  |_____|   /_/   \n                                                   \n");
                    printf(" ______  ______  ______  ______  ______  ______  ______  \n|______||______||______||______||______||______||______| \n                                                         \n");
                        int i;
                        for (i=0;i<Game.Neff;i++){
                            printScoreboard(Game, scoreBoard[i], i );
                        }
                    printf(" ______  ______  ______  ______  ______  ______  ______  \n|______||______||______||______||______||______||______| \n                                                         \n");
                } else {
                    printf("Perintah tidak dikenali\n");
                }
            } else {
                printf("Perintah tidak dikenali.\n");
            }
        }
         else {
            printf("Perintah tidak dikenali.\n");
        }

        while (!EndWord) {
            ADVWORD();
        }

        printf("ENTER COMMAND: ");
        STARTINPUT();
        system("cls");
    }
    quit(Game, &antrianGame, historyGame);
    return 0;
}
