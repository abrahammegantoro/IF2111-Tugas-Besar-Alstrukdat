#include<help.h>
int help(){
    printf("START: Command ini digunakan untuk menampilkan list game yang dapat dimainkan di BNMO.\n\n");
    printf("LOAD <filename>: Command ini digunakan untuk merepresentasikan suatu save file yang ingin dibuka berisi list game yang dapat dimainkan, histori dan scoreboard game.\n\n");
    printf("SAVE<filename>: Command ini digunakan untuk menyimpan state game pemain saat ini ke dalam suatu file.\n\n");
    printf("CREATEGAME: Command ini digunakan untuk menambahkan game baru pada daftar game.\n\n");
    printf("LISTGAME: Command ini digunakan untuk menampilkan daftar game yang disediakan oleh sistem.\n\n");
    printf("DELETEGAME: Command ini digunakan untuk menghapus sebuah game dari daftar game.\n\n");
    printf("QUEUEGAME: Command ini digunakan untuk mendaftarkan permainan kedalam list.\n\n");
    printf("PLAYGAME: Command ini digunakan untuk memainkan sebuah permainan sesuai dengan spesifikasi.\n\n");
    printf("SKIPGAME <n>: Command ini digunakan untuk melewatkan permainan sebanyak n.\n\n");
    printf("QUIT: Command ini digunakan untuk keluar dari program.\n\n");
    printf("HELP: Command ini digunakan untuk memberikan bantuan penjelasan atas command-command yang dapat dijalasakan dalam BNMO.\n\n");
    return 0;
};