#include <stdio.h>
#include "../ADT/mesinkarakter.h"

int main()
{
    // Untuk driver ini, file input akan menggunakan stdin
    FILE *input = stdin;

    printf("Masukkan deretan karakter : ");
    START(input);

    while (!EOP)
    {
        // Jika pengguna memasukkan spasi, maka spasi akan terhitung sebagai karakter
        printf("\nKarakter yang terdapat pada jendela : ");
        char huruf = GetCC();
        printf("%c", huruf);
        ADV();
    }

    printf("\nMesin karakter sudah mencapai EOP sehingga tidak lagi dioperasikan\n");
    CLOSE();
    
    return 0;
}