#include "../ADT/listsom.h"
#include <stdio.h>

int main() {
    ListSnake L;
    CreateEmptySnake(&L);
    printf("1. List berhasil dibuat\n");
    printf("2. List kosong? %s\n", IsEmptySnake(L) ? "true" : "false");
    int x, y;
    Point P;
    for (int i = 0; i < 5; i++) {
        x = i;
        y = i;
        InsVFirstSnake(&L, MakePoint(x, y));
    }
    printf("3. List setelah diisi 5 elemen: ");
    PrintInfoSnake(L);
    printf("4. Cari elemen (3,3) di list: ");
    printf("Index ke - %d\n", SearchSnake(L, MakePoint(3, 3)));
    printf("5. Cari alamat elemen (3,3) di list: ");
    printf("%p\n", SearchAddressSnake(L, MakePoint(3, 3)));
    printf("6. Hapus elemen pertama: ");
    DelVFirstSnake(&L, &P);
    PrintInfoSnake(L);
    printf("7. Hapus elemen terakhir: ");
    DelVLastSnake(&L, &P);
    PrintInfoSnake(L);
    printf("8. Hapus elemen (2,2): ");
    DelPSnake(&L, MakePoint(2, 2));
    PrintInfoSnake(L);
    printf("9. Tambah elemen terakhir dengan (7,7): ");
    InsVLastSnake(&L, MakePoint(7, 7));
    PrintInfoSnake(L);
    return 0;
}