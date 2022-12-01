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
# include "src/resetHistory.h"
# include "src/scoreboard.h"
# include "src/resetScoreboard.h"
# include "unistd.h"

int main(){
    int score;

    TabKata Game;
    MakeEmpty(&Game);

    Stack historyGame;
    CreateEmptyStack(&historyGame);

    Queue antrianGame;
    CreateQueue(&antrianGame);
    
    ListScore scoreBoard[100];
    for (int i = 0; i < 100; i++) {
        CreateListScore(&scoreBoard[i]);
    }
    clear();
    for (int i = 0; i < 8; i++) {
        if (i % 4 == 0) {clear(); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         ||  /          \n _ _      ______  ______  ______   _____        |   ._.   || /       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         \n\n");}
        if (i % 4 == 1) {clear(); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         || |           \n _ _      ______  ______  ______   _____        |   ._.   || /       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         \n\n");}
        if (i % 4 == 2) {clear(); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         || |           \n _ _      ______  ______  ______   _____        |   ._.   || |       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         \n\n");}
        if (i % 4 == 3) {clear(); printf("\n                                 __  _                                   \n                          _  _ _|  || |_ _  _                            \n ___ ___ ___ ___ ___ ___ / )/ |_   ||  _| \\( \\ ___ ___ ___ ___ ___ ___   \n(___|___|___|___|___|___| (( ( _|  || |_ ) )) |___|___|___|___|___|___)  \n                         \\_)\\_|_   ||  _|_/(_/   __________              \n                                |__||_|         /_________/|             \n                                                |         || |           \n _ _      ______  ______  ______   _____        |   ._.   || /       _ _ \n| | |    (____  \\|  ___ \\|  ___ \\ / ___ \\       |         |_/       | | |\n|_|_|     ____)  ) |   | | | _ | | |   | |     /|_________||        |_|_|\n _ _     |  __  (| |   | | || || | |   | |     ||         ||         _ _ \n| | |    | |__)  ) |   | | || || | |___| |     ||_________|/        | | |\n|_|_|    |______/|_|   |_|_||_||_|\\_____/        //    //           |_|_|\n                                                n/    n/                 \n         ___ ___   __           ______          \"  __ \" ___ ___          \n        |  _|_  | / _)__ ___ __(_____ \\ ___ ___ __(_ \\ |  _|_  |         \n ___ ___| |   | |/ /(___|___|___)____) |___|___|___)\\ \\| |   | |___ ___  \n(___|___) |   | ( (  ___ ___ ___/_____/ ___ ___ ___  ) ) |   | (___|___) \n        | |_ _| |\\ \\(___|___|___)______(___|___|___)/ /| |_ _| |         \n        |___|___| \\__)         (_______)          (__/ |___|___|         \n\n");}
        fflush(stdout);
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
                    clear();
                    isStarted = true;
                    start(&Game, &historyGame, &scoreBoard[0]);
                }
            } else if (WordCompare(currentWord, toKata("LOAD"))){
                ADVWORD();
                Word fileName = currentWord;
                ADVWORD();
                if (EndWord){
                    clear();
                    isStarted = true;
                    load(fileName, &Game, &historyGame, &scoreBoard[0]);
                }
            }
            if (!isStarted){
                clear();
                printf("Perintah tidak dikenali\n\n");
                printf("Ketik 'START' atau 'LOAD <filename.txt>' untuk mulai bermain\n");
                printf("ENTER COMMAND: ");
                STARTINPUT();
            }
        }
    }
    
    printf("ENTER COMMAND: ");
    STARTINPUT();
    clear();
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
                    deleteGame(&Game, antrianGame, &historyGame, scoreBoard);
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
                    save(Game, fileName, historyGame, scoreBoard);
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
                    save(Game, fileName, historyGame, scoreBoard);
                } else {
                    printf("Perintah tidak dikenali\n");
                }
            }
        } else if (WordCompare(currentWord, toKata("PLAY"))){
            ADVWORD();
            if (WordCompare(currentWord, toKata("GAME"))){
                ADVWORD();
                if (EndWord){
                    int idxGame;
                    Word name;
                    idxGame = selectGame(Game, antrianGame);
                    score = playGame(&antrianGame, &historyGame);
                    if (score != NIL) {
                        printf("<< Hanya kata pertama yang dijadikan username >>\n");
                        printf("Masukkan username : ");
                        STARTINPUT();
                        name = currentWord;
                        while (!EndWord) {
                            ADVWORD();
                        }
                        while (IsMemberSet(scoreBoard[idxGame].Nama, name) || name.Length == 0) {
                            if (IsMemberSet(scoreBoard[idxGame].Nama, name)) {
                                printf("Nama sudah ada, masukkan nama lain : ");
                            } else {
                                printf("Nama tidak boleh kosong, masukkan nama : ");
                            }
                            STARTINPUT();
                            name = currentWord;
                            while (!EndWord) {
                                ADVWORD();
                            }
                        }
                        InsertSet(&(scoreBoard[idxGame].Nama), name);
                        InsertMapSorted(&(scoreBoard[idxGame].Score), ((scoreBoard[idxGame].Nama.Count) - 1), score);
                    }
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
                    Word val;
                    ADVWORD();
                    if (EndWord){
                        score = skipGame(&antrianGame, n, &historyGame);
                        if (score != NIL) {
                            int idxGame;
                            Word name;

                            idxGame = selectGame(Game, antrianGame);
                            printf("<< Hanya kata pertama yang dijadikan username >>\n");
                            printf("Masukkan username : ");
                            STARTINPUT();
                        
                            name = currentWord;
                            while (IsMemberSet(scoreBoard[idxGame].Nama, name) || name.Length == 0){
                                if (IsMemberSet(scoreBoard[idxGame].Nama, name)) {
                                    printf("Nama sudah ada, masukkan nama lain : ");
                                } else {
                                    printf("Nama tidak boleh kosong, masukkan nama : ");
                                }
                                STARTINPUT();
                                name = currentWord;
                                while (!EndWord) {
                                    ADVWORD();
                                }
                            }
                            InsertSet(&(scoreBoard[idxGame].Nama), name);
                            InsertMapSorted(&(scoreBoard[idxGame].Score), ((scoreBoard[idxGame].Nama.Count) - 1), score);
                        }
                        dequeue(&antrianGame, &val);
                        Push(&historyGame, val);
                    } else {
                        printf("Perintah tidak dikenali\n");
                    }
                }
            }
        } else if(WordCompare(currentWord, toKata("LOAD"))){
            ADVWORD();
            if (EndWord){
                load(currentWord, &Game, &historyGame, &scoreBoard[0]);
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
            if (EndWord){
                printf("Perintah tidak dikenali. Gunakan command \"HISTORY <n>\".\n\n");
            } else {
                ADVWORD();
                if (EndWord) {
                    boolean isNumber = true;
                    for (int i = 0; i < currentWord.Length; i++) {
                        if (!(currentWord.TabWord[i] - '0' >= 0 && currentWord.TabWord[i] - '0' <= 9)) isNumber = false;
                    }
                    if (isNumber) {
                        history(historyGame, currentWord);
                    } else {
                        printf("Masukkan <n> harus berupa angka!\n\n");
                    }
                } else {
                    printf("Perintah tidak dikenali. Gunakan command \"HISTORY <n>\".\n\n");
                }
            }
        } else if (WordCompare(currentWord, toKata("RESET"))) {
            ADVWORD();
            if (WordCompare(currentWord, toKata("HISTORY")))
            {
                ADVWORD();
                if (EndWord){
                    resetHistory(&historyGame);
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
            else{
                printf("Perintah tidak dikenali.\n");
            }
        }
        else if (WordCompare(currentWord, toKata("SCOREBOARD"))){
            ADVWORD();
            if (EndWord){
                    printScoreboard(Game, scoreBoard);
                } else {
                    printf("Perintah tidak dikenali\n");
                }
        } else {
            printf("Perintah tidak dikenali.\n");
        }
        while (!EndWord) {
            ADVWORD();
        }

        printf("ENTER COMMAND: ");
        STARTINPUT();
        clear();
    }
    quit(Game, &antrianGame, historyGame, scoreBoard);
    return 0;
}
