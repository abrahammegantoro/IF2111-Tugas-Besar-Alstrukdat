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
            ADV();
            ADVWORD();
            Word currentGame = currentWord;
            while (currentChar != '\n') {
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

boolean cekAlphabet(Word alphabet, TabKata listHuruf){
    int i = 0;
    boolean found = false;
    while (i < listHuruf.Neff && !found) {
        if (WordCompare(listHuruf.TI[i], alphabet)) {
            found = true;
        } else {
            i++;
        }
    }
    return found;
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
    TabKata listJawaban, guessedAlphabet, unguessedAlphabet, strip;
    MakeEmpty(&listJawaban);

    if(readHangmanFile("../../data/hangman.txt", &listJawaban)){
        int i, kesempatan = 10, score = 0, jumlahstrip, j = 0;
        boolean correctWord = false, correctGuess, isStarted = false;
        Word jawaban;

        system("cls");
        while (!isStarted){
            printHangman(999);
            printf("      -------\n");
            printf("      |     |\n");
            printf("      |     @\n");
            printf("      |    /|\\\t Fruits Edition (in Bahasa) \n");
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
            if (WordCompare(currentWord,toKata("1"))){
                ADVWORD();
                if(EndWord){
                    printf("\n  Start Playing.");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    currentWord.Length = 0;
                    while (kesempatan > 0){
                        system("cls");
                        MakeEmpty(&guessedAlphabet);
                        MakeEmpty(&unguessedAlphabet);
                        MakeEmpty(&strip);

                        insertAlphabet(&unguessedAlphabet);
                        int random = getRandomWord(listJawaban);
                        jawaban = listJawaban.TI[random-1];

                        insertStrip(jawaban, &strip);
                        jumlahstrip = strip.Neff;
                        
                        printf("\n");
                        printHangman(kesempatan);
                        printf("  Kata : ");
                        printArray(strip);
                        printf("\n");
                        printf("  Kesempatan : %d\n", kesempatan);

                        printf("  Unguessed Letters : ");
                        printArray(unguessedAlphabet);
                        printf("\n");
                        printf("  Guessed Letters : ");
                        printArray(guessedAlphabet);
                        printf("\n");
                        
                        
                        printf("  Masukkan tebakan : ");
                        STARTINPUT();
                        printf("\n");
                        
                        while (!correctWord && kesempatan > 0){
                            if (currentWord.Length == 1 && cekAlphabet(currentWord, unguessedAlphabet) && !isNotUpperCase(currentWord)){
                                system("cls");
                                correctGuess = false;
                                delElmtArray(&unguessedAlphabet, currentWord);
                                SetEl(&guessedAlphabet, j, currentWord);

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
                                } else{
                                    if (kesempatan != 0){
                                        printf("\n");
                                        printHangman(kesempatan);
                                        printf("  Kata : ");
                                        printArray(strip);
                                        printf("\n");
                                        
                                        printf("  Kesempatan : %d\n", kesempatan);

                                        printf("  Unguessed Letters : ");
                                        printArray(unguessedAlphabet);
                                        printf("\n");
                                        printf("  Guessed Letters : ");
                                        printArray(guessedAlphabet);
                                        printf("\n");

                                        printf("  Masukkan tebakan : ");
                                
                                        STARTINPUT();
                                        printf("\n");
                                        j++;
                                    }
                                }
                            } else if (currentWord.Length != 1 || isNotUpperCase(currentWord)){
                                printf("  MASUKKAN SATU HURUF KAPITAL!\n");
                                sleep(1);
                                system("cls");
                                
                                printf("\n");
                                printHangman(kesempatan);
                                printf("  Kata : ");
                                printArray(strip);
                                printf("\n");
                                
                                printf("  Kesempatan : %d\n", kesempatan);

                                printf("  Unguessed Letters : ");
                                printArray(unguessedAlphabet);
                                printf("\n");
                                printf("  Guessed Letters : ");
                                printArray(guessedAlphabet);
                                printf("\n");

                                printf("  Masukkan tebakan : ");
                        
                                STARTINPUT();
                                printf("\n");
                            } else {
                                printf("  HURUF SUDAH DITEBAK!\n");
                                sleep(1);
                                system("cls");
                                
                                printf("\n");
                                printHangman(kesempatan);
                                printf("  Kata : ");
                                printArray(strip);
                                printf("\n");
                                
                                printf("  Kesempatan : %d\n", kesempatan);

                                printf("  Unguessed Letters : ");
                                printArray(unguessedAlphabet);
                                printf("\n");
                                printf("  Guessed Letters : ");
                                printArray(guessedAlphabet);
                                printf("\n");

                                printf("  Masukkan tebakan : ");
                        
                                STARTINPUT();
                                printf("\n");
                            }
                        }
                        j = 0;
                        correctWord = false;
                    }
                    system("cls");
                    // kesempatan--;
                    printHangman(kesempatan);
                    printf("\n  Last Answer : ");
                    PrintWord(jawaban);
                    printf("\n  Your Score : %d\n", score);
                    isStarted = true;
                    return score;
                } else {
                    printf("INPUT TIDAK VALID! MASUKKAN ANGKA 1 ATAU 2\n");
                    sleep(1);
                    system("cls");
                }
            } else if (WordCompare(currentWord,toKata("2"))){
                ADVWORD();
                if (EndWord){
                    currentWord.Length = 0;
                    system("cls");
                    printHangman(999);
                    printf("\n  Input Nama Buah : ");
                    STARTINPUT();
                    printf("\n");
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
                            printf("  Kata berhasil ditambahkan\n");
                            writeHangmanGame("../../data/hangman.txt", listJawaban);
                            sleep(1);
                        } else
                        {
                            printf("  Gagal menambahkan Kata! Kata sudah terdapat di dalam list kata!\n");
                            sleep(1);
                        }
                        system("cls");
                    } else {
                        printf("  INPUT TIDAK VALID! MASUKKAN SATU NAMA BUAH DALAM HURUF KAPITAL!\n");
                        sleep(1);
                        system("cls");
                    }

                } else {
                    printf("  INPUT TIDAK VALID! MASUKKAN ANGKA 1 ATAU 2!\n");
                    sleep(1);
                    system("cls");
                }
            } else {
                printf("  INPUT TIDAK VALID! MASUKKAN ANGKA 1 ATAU 2!\n");
                sleep(1);
                system("cls");
            }
        }
    }
}

int main(){
    hangman();
    return 0;
}