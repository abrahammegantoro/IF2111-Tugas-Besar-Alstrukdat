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
/* Membaca file hangman.txt dan menyimpan isinya ke dalam array of Word */

void writeHangmanGame(char* filetarget, TabKata listGame);
/* Membaca file hangman.txt dan menulis isi dari array of Word ke dalam file hangman.txt */

int getRandomWord();
/* Menghasilkan angka random dari rentang 1 hingga banyaknya kata pada array listGame */

void listAlphabet(TabKata* huruf);
/* Memasukkan list alphabet dari A hingga Z ke dalam array of Word 
I.S. TabKata terdefinisi kosong
F.S. TabKata terisi alphabet dari A sampai Z
*/

void printArray(TabKata huruf);
/* Menampilkan isi array dengan traversal 
I.S. TabKata terdefinisi mungkin kosong 
F.S. Menampilkan isi dari array secara Traversal
*/

void delElmtArray(TabKata* listhuruf, Word alphabet);
/* Menghapus elemen array yang telah dipilih oleh user 
I.S. TabKata terdefinisi tidak mungkin kosong
F.S. Elemen array sesuai dengan Word dihapus dari array
*/

void insertStrip(Word huruf, TabKata* strip);
/* Memasukkan strip ke dalam array of Word sebanyak panjang dari kata 
I.S. TabKata terdefinisi kosong
F.S. TabKata terisi dengan "_" sebanyak panjang dari kata
*/

void printHangman(int kesempatan);
/* Menampilkan gambar hangman sesuai dengan kesempatan yang dimiliki user */

boolean isUpper(Word currentWord);
/* Mengecek apakah kata yang dimasukkan user berupa huruf kapital */

int hangman();
/* Fungsi utama program hangman dan mengembalikan score yang diperoleh user dalam bentuk integer */

# endif