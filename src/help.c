#include "help.h"
int help(){
    printf("SAVE <filename>  : Command ini digunakan untuk menyimpan state game pemain saat ini ke dalam suatu file.\n\n");
    printf("CREATE GAME      : Command ini digunakan untuk menambahkan game baru pada daftar game.\n\n");
    printf("LIST GAME        : Command ini digunakan untuk menampilkan daftar game yang disediakan oleh sistem.\n\n");
    printf("DELETE GAME      : Command ini digunakan untuk menghapus sebuah game dari daftar game.\n\n");
    printf("QUEUE GAME       : Command ini digunakan untuk mendaftarkan permainan kedalam list.\n\n");
    printf("PLAY GAME        : Command ini digunakan untuk memainkan sebuah permainan sesuai dengan spesifikasi.\n\n");
    printf("SKIPGAME <n>     : Command ini digunakan untuk melewatkan permainan sebanyak n.\n\n");
    printf("SCOREBOARD       : Command ini digunakan untuk menampilkan papan skor dari semua game yang tersedia.\n\n");
    printf("RESET SCOREBOARD : Command ini digunakan untuk menghapus semua informasi dari scoreboard pada game yang diinginkan.\n\n");
    printf("HISTORY <n>      : Command ini digunakan untuk melihat permainan apa saja yang telah dimainkan sebanyak n jumlah permainan.\n\n");
    printf("RESET HISTORY    : Command ini digunakan untuk menghapus semua history permainan yang dimainkan.\n\n");
    printf("QUIT             : Command ini digunakan untuk keluar dari program.\n\n");
    printf("HELP             : Command ini digunakan untuk memberikan bantuan penjelasan atas command-command yang dapat dijalasakan dalam BNMO.\n\n");
    return 0;
};