#include "../ADT/listsom.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SnakeHead 0
#define Fruit 111
#define Meteor 222
#define Obstacle 333
#define Empty -1


boolean IsGameOver(ListSnake S, ListObstacle obstacle);
/* Mengembalikan true jika snake mati */

void InitialSnake(ListSnake *S);
/* Menginisialisasi snake dengan panjang 3 
    I.S. S terdefinisi
    F.S. S terisi dengan panjang 3 */

void InitialFood(ListSnake S, Point *fruit, ListObstacle obstacle);
/* Menginisialisasi food dengan posisi random
    I.S. S dan fruit terdefinisi
    F.S. fruit terisi dengan posisi random */

void InitialMeteor(Point *meteor, Point fruit, ListObstacle obstacle);
/* Menginisialisasi meteor dengan posisi random
    I.S. meteor dan fruit terdefinisi
    F.S. meteor terisi dengan posisi random */

void InitialObstacle(ListSnake S, ListObstacle *obstacle);
/* Menginisialisasi obstacle dengan posisi random
    I.S. S dan obstacle terdefinisi
    F.S. obstacle terisi dengan posisi random */

void ReadInput(ListSnake *S, Point meteor, ListObstacle obstacle);
/* Membaca input dari user
    I.S. S terdefinisi
    F.S. S terisi dengan posisi baru */

boolean IsInputValid(Word input);
/* Mengembalikan true jika input valid */

void MoveSnake(ListSnake *S, Point meteor, ListObstacle obstacle, Word Input);
/* Menggerakkan snake
    I.S. S terdefinisi
    F.S. S terisi dengan posisi baru */

void EatFruit(ListSnake *S, Point *fruit, Point Tail, ListObstacle obstacle);
/* Makan buah
    I.S. S dan fruit terdefinisi
    F.S. S bertambah panjang dan fruit terisi dengan posisi baru */

void GrowSnake(ListSnake *S, Point Tail);
/* Membesarkan snake
    I.S. S dan Tail terdefinisi
    F.S. S bertambah panjang */

boolean IsHit(ListSnake *S, Point meteor);
/* Mengembalikan true jika snake terkena meteor */

void HitMeteor(ListSnake *S, Point meteor, boolean *isGameOver);
/* Menggerakkan snake jika terkena meteor
    I.S. S dan meteor terdefinisi
    F.S. S tergerak jika terkena meteor */

void DisplayRow(ListSnake S, Point fruit, Point meteor, ListObstacle obstacle, int i);
/* Menampilkan isi baris ke-i
    I.S. S, fruit, meteor, dan obstacle terdefinisi
    F.S. Isi baris ke-i tercetak */

void DisplayValue(int value);
/* Menampilkan isi value
    I.S. value terdefinisi
    F.S. Isi value tercetak */

void DisplaySpace(int value);
/* Menampilkan spasi
    I.S. value terdefinisi
    F.S. Spasi tercetak */

void DisplayMap(ListSnake S, Point fruit, Point meteor, ListObstacle obstacle);
/* Menampilkan map
    I.S. S, fruit, meteor, dan obstacle terdefinisi
    F.S. Map tercetak */

int RunSnakeOnMeteor();
/* Memainkan game Snake on Meteor dan mengembalikan skor permainan */

