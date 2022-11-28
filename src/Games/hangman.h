# ifndef __HANGMAN_H__
# define __HANGMAN_H__

#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"
#include "../ADT/array.h"
#include "../ADT/set.h"
#include "../ADT/stack.h"
#include "../Driver/readTxtFile.h"
# include "../boolean.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

boolean readHangmanFile(char* filesrc, TabKata* listGame);

void writeHangmanGame(char* filetarget, TabKata listGame);

int getRandomWord();

void listAlphabet(TabKata* huruf);

void printArray(TabKata huruf);

void insertStrip(Word huruf, TabKata* strip);

boolean cekAlphabet(Word alphabet, TabKata listHuruf);

void printHangman(int kesempatan);

boolean isUpper(Word currentWord);

int hangman();

# endif