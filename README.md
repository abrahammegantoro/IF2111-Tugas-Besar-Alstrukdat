# IF2111-Tugas-Besar-Alstrukdat

Indra dan Doni memiliki sebuah robot game console yang diberi nama BNMO. Pada tugas besar sebelumnya, BNMO yang sempat rusak berhasil diprogram ulang untuk diperbaiki bug yang ada di dalamnya. Indra dan Doni menjadi lebih bahagia dengan fitur dasar yang sudah diimplementasikan pada BNMO sehingga pada kesempatan kali ini, mereka ingin melakukan pengembangan lebih lanjut dengan menambahkan fitur serta permainan pada BNMO.

Sebagai robot game console, BNMO memiliki peran untuk menjalankan permainan yang terdapat di dalamnya. Beberapa fitur dasar yang dapat dijalankan oleh BNMO sudah diimplementasikan pada tugas sebelumnya, antara lain : 
- Memainkan game, 
- Menambahkan game, 
- Menghapus game, dan 
- Mengurutkan game yang akan dimainkan. 

Kini, Indra dan Doni ingin supaya BNMO ditambah beberapa fitur tambahan, seperti menampilkan game yang telah dimainkan (history) dan menampilkan scoreboard game setiap pemainnya.
  
## Cara Bermain

1. Masuk ke folder bin melalui terminal

```
cd bin
```

2. Ketik `make main` pada terminal

```
make main
```

3. Keluar dari folder terminal

```
cd ..
```

4. Jalankan program BNMO di terminal

```
./BNMO atau BNMO
```

## Fitur BNMO

- `START`            : Command ini digunakan untuk menjalankan program BNMO
- `LOAD <filename>`  : Command ini digunakan untuk membaca file yang telah disimpan dan menjalankan program BNMO
- `SAVE <filename>`  : Command ini digunakan untuk menyimpan state game pemain saat ini ke dalam suatu file.
- `CREATE GAME`      : Command ini digunakan untuk menambahkan game baru pada daftar game.
- `LIST GAME`        : Command ini digunakan untuk menampilkan daftar game yang disediakan oleh sistem.
- `DELETE GAME`      : Command ini digunakan untuk menghapus sebuah game dari daftar game.
- `QUEUE GAME`       : Command ini digunakan untuk mendaftarkan permainan kedalam list.
- `PLAY GAME`        : Command ini digunakan untuk memainkan sebuah permainan sesuai dengan spesifikasi.
- `SKIPGAME <n>`     : Command ini digunakan untuk melewatkan permainan sebanyak n.
- `SCOREBOARD`       : Command ini digunakan untuk menampilkan papan skor dari semua game yang tersedia.
- `RESET SCOREBOARD` : Command ini digunakan untuk menghapus semua informasi dari scoreboard pada game yang diinginkan.
- `HISTORY <n>`      : Command ini digunakan untuk melihat permainan apa saja yang telah dimainkan sebanyak n jumlah permainan.
- `RESET HISTORY`    : Command ini digunakan untuk menghapus semua history permainan yang dimainkan.
- `QUIT`             : Command ini digunakan untuk keluar dari program.
- `HELP`             : Command ini digunakan untuk memberikan bantuan penjelasan atas command-command yang dapat dijalasakan dalam BNMO.

## Cara Menjalankan Driver Abstract Data Type

1. Masuk ke folder bin melalui terminal

```
cd bin
```

2. Ketik `make <ADT>`  pada terminal

```
make set
```

3. Keluar dari folder terminal

```
cd ..
```

4. Jalankan driver di terminal dengan format `<ADT>Driver`

```
./setDriver atau setDriver
```

## Anggota Kelompok 6

| No. | NIM | Nama |
|-----|-----|------|
| 1 | 18221157 | Cathleen Lauretta |
| 2 | 18221123 | Abraham Megantoro Samudra |
| 3 | 18221065 | Josua Adriel Sinabutar |
| 4 | 18221121 | Rozan Ghosani |
| 5 | 18221143 | Lie, Kevin Sebastian S. T. |