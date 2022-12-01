# include "hangman.h"

boolean readHangmanFile(char* filesrc, TabKata* listGame){
    FILE* input = fopen(filesrc, "r");
    int lines = 0;
    
    if (input == NULL) {
        printf("File tidak ditemukan.\n");
        return false;
    } else {
        STARTWORD(input);
        lines = WordToInt(currentWord);
        for (int i = 0; i < lines; i++) {
            if (currentChar == '\r'){
                ADV();
            }
            ADV();
            ADVWORD();
            Word currentGame = currentWord;
            while (currentChar != '\n' && currentChar != '\r') {
                ADVWORD();
                currentGame.TabWord[currentGame.Length] = ' ';
                currentGame.Length++;
                for (int i = 0; i < currentWord.Length; i++) {
                    currentGame.TabWord[currentGame.Length] = currentWord.TabWord[i];
                    currentGame.Length++;
                }
            }
            SetEl(listGame, i, currentGame);
        }
    }
    fclose(input);
    return true;
}

void writeHangmanGame(char* filetarget, TabKata listGame){
    FILE *file;
    int i, j;
    // ALGORITMA
    file = fopen(filetarget, "w");

    fprintf(file, "%d\n", listGame.Neff);
    for (i = 0; i < listGame.Neff; i++) {
        for (j = 0; j < listGame.TI[i].Length; j++) {
            fprintf(file, "%c", listGame.TI[i].TabWord[j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, " ");

    fclose(file);
}

int getRandomWord(TabKata listKata){
    int num;
    srand(time(0));
    num = rand() % listKata.Neff + 1;
    return num;    
}

void insertAlphabet(TabKata* huruf){
    int i = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
        Word currentWord;
        currentWord.Length = 1;
        currentWord.TabWord[0] = c;
        SetEl(huruf, i, currentWord);
        i++;
    }
}

void printArray(TabKata huruf){
    for (int i = 0; i < huruf.Neff; i++) {
        printf("%c ", huruf.TI[i].TabWord[0]);
    }
}

void delElmtArray(TabKata* listhuruf, Word alphabet){
    int i = 0;
    while (i < listhuruf->Neff && !WordCompare(listhuruf->TI[i], alphabet)) {
        i++;
    }
    if (i < listhuruf->Neff) {
        for (int j = i; j < listhuruf->Neff - 1; j++) {
            listhuruf->TI[j] = listhuruf->TI[j + 1];
        }
        listhuruf->Neff--;
    }
}

void insertStrip(Word huruf, TabKata* strip){
    for (int i = 0; i < huruf.Length; i++) {
        Word currentWord;
        currentWord.Length = 1;
        currentWord.TabWord[0] = '_';
        SetEl(strip, i, currentWord);
    }
}

void printSet(Set S){
    int i;
    for (i = 0; i < S.Count; i++) {
        PrintWord(S.Elements[i]);
        printf(" ");
    }
}

void printHangman(int kesempatan){
    if (kesempatan == 10){
        printf("               \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("  ______________`\n\n");
    } else if(kesempatan == 9){
        printf("       ----------\n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("  ______________`\n\n");
    } else if(kesempatan == 8){
        printf("       ----------\n");
        printf("       |     |\n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("  ______________`\n\n");
    } else if (kesempatan == 7){
        printf("       ----------\n");
        printf("       |     |\n");
        printf("       |     @\n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("  ______________`\n\n");
    } else if(kesempatan == 6){
        printf("       ----------\n");
        printf("       |     |\n");
        printf("       |     @\n");
        printf("       |     |\n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("  ______________`\n\n");
    } else if (kesempatan == 5){
        printf("       ----------\n");
        printf("       |     |\n");
        printf("       |     @\n");
        printf("       |     |\n");
        printf("       |     |\n");
        printf("       |     \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("  ______________`\n\n");
    } else if (kesempatan == 4){
        printf("       ----------\n");
        printf("       |     |\n");
        printf("       |     @\n");
        printf("       |     |\n");
        printf("       |     |\n");
        printf("       |    / \n");
        printf("       |     \n");
        printf("       |     \n");
        printf("  ______________`\n\n");
    } else if (kesempatan == 3){
        printf("       ----------\n");
        printf("       |     |\n");
        printf("       |     @\n");
        printf("       |     |\n");
        printf("       |     |\n");
        printf("       |    / \\\n");
        printf("       |     \n");
        printf("       |     \n");
        printf("  ______________`\n\n");
    } else if (kesempatan == 2){
        printf("       ----------\n");
        printf("       |     |\n");
        printf("       |     @\n");
        printf("       |    \\|\n");
        printf("       |     |\n");
        printf("       |    / \\\n");
        printf("       |     \n");
        printf("       |     \n");
        printf("  ______________`\n\n");
    } else if (kesempatan == 1){
        printf("       ----------\n");
        printf("       |     |\n");
        printf("       |     @\n");
        printf("       |    \\|/\n");
        printf("       |     |\n");
        printf("       |    / \\\n");
        printf("       |     \n");
        printf("       |     \n");
        printf("  ______________`\n\n");
    } else if (kesempatan == 0){
        printf("\n       ----------\n");
        printf("       |     |        _____          __  __ ______    ______      ________ _____  _ \n");
        printf("       |     @       / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\| |\n");
        printf("       |    /|\\     | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | |\n");
        printf("       |     |      | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /| |\n");
        printf("       |    / \\     | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\|_|\n");
        printf("       |             \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_(_)\n");
        printf("  ______________`\n\n");
    } else if (kesempatan == 999){
        printf("\n {}    {}    {}{}     {}    {}    {}}}}}    {}      {}    {}{}     {}    {}\n");
        printf(" {}    {}   {}  {}    {}}}  {}   {}    {}   {}}}  {{{}   {}  {}    {}}}  {}\n");
        printf(" {}{{}}{}  {}{{}}{}   {} {} {}   {}         {} {{}} {}  {}{{}}{}   {} {} {}\n");
        printf(" {}    {}  {}    {}   {}  {{{}   {}  {{{{   {}  {}  {}  {}    {}   {}  {{{}\n");
        printf(" {}    {}  {}    {}   {}    {}    {}}}}}    {}      {}  {}    {}   {}    {}\n\n");
    }
}

boolean isNotUpperCase(Word currentWord){
    int i = 0;
    boolean notUpperCase = false;
    while (i < currentWord.Length && !notUpperCase) {
        if (currentWord.TabWord[i] < 'A' || currentWord.TabWord[i] > 'Z') {
            notUpperCase = true;
        } else {
            i++;
        }
    }
    return notUpperCase;
}

int hangman(){
    TabKata listJawaban, unguessedAlphabet, strip;
    Set guessedAlphabet;
    MakeEmpty(&listJawaban);

    int score = 0;

    if(readHangmanFile("./data/hangman.txt", &listJawaban)){
        int i, kesempatan = 10, jumlahstrip, j = 0;
        
        boolean correctWord = false, correctGuess, isStarted = false;
        Word jawaban;

        clear();
        while (!isStarted){
            printHangman(999);
            printf("      -------\n");
            printf("      |     |\n");
            printf("      |     @\n");
            printf("      |    /|\\\t 40++ Fruits Edition (in Bahasa) \n");
            printf("      |     |\n");
            printf("      |    / \\\n");
            printf(" _____|_________\n");
            printf("      |         /|\n");
            printf("______________ / /\n");
            printf("             |  /\n");
            printf("______________ /\n\n");
            printf("  Menu:\n");
            printf("  1: Start Playing\n");
            printf("  2: Add Dictionary\n\n");

            printf("  Input Number : ");
            
            STARTINPUT();
            Word input = currentWord;
            ADVWORD();
            if(EndWord && input.Length == 1){
                if (WordCompare(input,toKata("1"))){
                    printf("\n  Start Playing.");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    while (kesempatan > 0){
                        clear();
                        CreateEmptySet(&guessedAlphabet);
                        MakeEmpty(&unguessedAlphabet), MakeEmpty(&strip);

                        insertAlphabet(&unguessedAlphabet);
                        int random = getRandomWord(listJawaban);
                        jawaban = listJawaban.TI[random-1];

                        insertStrip(jawaban, &strip);
                        jumlahstrip = strip.Neff;
                        
                        printf("\n");
                        printHangman(kesempatan);
                        printf("  Kata : ");
                        printArray(strip);

                        printf("\n  Kesempatan : %d\n", kesempatan);

                        printf("  Unguessed Letters : ");
                        printArray(unguessedAlphabet);
                        printf("\n  Guessed Letters : ");
                        printSet(guessedAlphabet);
                        
                        
                        printf("\n  Masukkan tebakan : ");
                        STARTINPUT();
                        
                        while (!correctWord && kesempatan > 0){
                            ADVWORD();
                            if (EndWord){
                                if (!IsMemberSet(guessedAlphabet, currentWord) && !isNotUpperCase(currentWord) && currentWord.Length == 1){
                                    clear();
                                    correctGuess = false;
                                    delElmtArray(&unguessedAlphabet, currentWord);
                                    InsertSet(&guessedAlphabet, currentWord);

                                    for (i = 0; i < jawaban.Length; i++) {
                                        if(jawaban.TabWord[i] == currentWord.TabWord[0]){
                                            SetEl(&strip, i, currentWord);
                                            strip.Neff--;
                                            jumlahstrip--;
                                            correctGuess = true;
                                        }
                                    }

                                    if (!correctGuess){
                                        kesempatan--;
                                    }

                                    j++;
                                } else if (currentWord.Length != 1 || isNotUpperCase(currentWord)){
                                    printf("\n  MASUKKAN SATU HURUF KAPITAL!\n");
                                    sleep(1);
                                    clear();
                                } else if (currentWord.Length != 0){
                                    printf("\n  HURUF SUDAH DITEBAK!\n");
                                    sleep(1);
                                    clear();
                                }
                            } else{
                                printf("\n  MASUKKAN SATU HURUF KAPITAL!\n");
                                sleep(1);
                                clear();
                            }
                            
                            if (jumlahstrip == 0){
                                score += jawaban.Length;
                                correctWord = true;
                                printf("\n     _____ ____  _____  _____  ______ _____ _______ \n");
                                printf("    / ____/ __ \\|  __ \\|  __ \\|  ____/ ____|__   __|\n");
                                printf("   | |   | |  | | |__) | |__) | |__ | |       | |   \n");
                                printf("   | |   | |  | |  _  /|  _  /|  __|| |       | |    \n");
                                printf("   | |___| |__| | | \\ \\| | \\ \\| |___| |____   | |    \n");
                                printf("    \\_____\\____/|_|  \\_\\_|  \\_\\______\\_____|  |_|    \n");
                                sleep(1);
                            } else if(kesempatan != 0 && jumlahstrip != 0){
                                printf("\n");
                                printHangman(kesempatan);
                                printf("  Kata : ");
                                printArray(strip);
                                
                                printf("\n  Kesempatan : %d\n", kesempatan);

                                printf("  Unguessed Letters : ");
                                printArray(unguessedAlphabet);
                                printf("\n  Guessed Letters : ");
                                printSet(guessedAlphabet);

                                printf("\n  Masukkan tebakan : ");
                        
                                STARTINPUT();
                            }
                        }
                        j = 0;
                        correctWord = false;
                    }
                    clear();
                    printHangman(kesempatan);
                    printf("\n  Last Answer : ");
                    PrintWord(jawaban);
                    printf("\n  Your Score : %d\n\n", score);
                    isStarted = true;
                } else if (WordCompare(input,toKata("2"))){
                    clear();
                    printHangman(999);
                    printf("\n  Input Nama Buah : ");
                    STARTINPUT();
                    Word gameName = currentWord;
                    ADVWORD();
                    if (EndWord && gameName.Length != 0 && !isNotUpperCase(gameName)){
                        int i = 0;
                        boolean found = false;

                        while (i != listJawaban.Neff && !found){
                            if (WordCompare(listJawaban.TI[i], gameName))
                            {
                                found = true;
                            }
                            else
                            {
                                i += 1;
                            }
                        }

                        if (!found)
                        {
                            listJawaban.TI[listJawaban.Neff] = gameName;
                            listJawaban.Neff += 1;
                            printf("\n  Kata berhasil ditambahkan\n");
                            writeHangmanGame("./data/hangman.txt", listJawaban);
                            sleep(1);
                        } else
                        {
                            printf("\n  Gagal menambahkan Kata! Kata sudah terdapat di dalam dictionary!\n");
                            sleep(2);
                        }
                        clear();
                    } else {
                        printf("\n  INPUT TIDAK VALID! MASUKKAN NAMA BUAH YANG TERDIRI DARI SATU KATA DALAM HURUF KAPITAL!\n");
                        sleep(3);
                        clear();
                    }
                } else {
                    printf("\n  INPUT TIDAK VALID! MASUKKAN ANGKA 1 ATAU 2!\n");
                    sleep(2);
                    clear();
                }
            } else {
                printf("\n  INPUT TIDAK VALID! MASUKKAN ANGKA 1 ATAU 2!\n");
                sleep(2);
                clear();
            }
        }
    }
    return score;
}