# Praktikum-Struktur-Data-dan-Algoritma-TEAM-13
  1.MUHAMMAD RAFIE AL GHIFARI_250810701100013
  
  2.SITI FILDZAHRA REVANI_250810701100107

  3.RAYHAN FITRA_250810701100102
  











# Tugas 2 Praktikum Struktur Data dan Algoritma B
## Implementasi dan Analisis Algoritma Sorting Menggunakan Bahasa C


## Struktur File

├── sorting.h
├── sorting.c
├── main.c
├── words.txt    
└── README.md

## Cara Compile & Menjalankan

### Windows (PowerShell / Command Prompt)

**Compile:**
```powershell
gcc main.c sorting.c -o program
```

**Jalankan:**
```powershell
./program
```

### Linux / Mac

**Compile:**
```bash
gcc main.c sorting.c -o program
```

**Jalankan:**
```bash
./program
```


## Dataset

Dataset kata untuk Advance Sorting diambil dari:  
https://www.kaggle.com/datasets/jiprud/words-en

Letakkan file `words.txt` di folder yang sama dengan `main.c`.


## Algoritma yang Diimplementasikan

### Sorting Dasar (1000 data integer random)
| Algoritma | Kompleksitas Rata-rata |
|---|---|
| Bubble Sort | O(n²) |
| Insertion Sort | O(n²) |
| Selection Sort | O(n²) |

### Advance Sorting (dataset kata dari words.txt)
| Algoritma | Kompleksitas Rata-rata |
|---|---|
| Merge Sort | O(n log n) |
| Quick Sort | O(n log n) |
| Shell Sort | O(n log² n) |


## Fitur Program

- Generate 1000 data integer otomatis dengan `rand()`
- Baca dataset kata dari file `words.txt`
- Shuffle data sebelum sorting (Fisher-Yates)
- Tampilkan 10 data pertama sebelum & sesudah sorting
- Hitung waktu eksekusi menggunakan `clock()`
- Sorting ascending


## Penjelasan Kode

### sorting.h
File header yang berisi semua konstanta dan deklarasi fungsi yang digunakan program.

```c
#define DATA_SIZE     1000    // jumlah data integer yang di-generate
#define MAX_WORDS     500000  // maksimum kata yang bisa dibaca dari file
#define MAX_WORD_LEN  100     // panjang maksimum tiap kata
#define DISPLAY_COUNT 10      // jumlah data yang ditampilkan sebelum/sesudah sorting
```


### sorting.c

#### Helper Integer
Fungsi-fungsi pembantu untuk mengelola data integer.

```c
// Menukar nilai dua variabel integer
void swap_int(int *a, int *b)

// Mengacak urutan array integer menggunakan metode Fisher-Yates
void shuffle_int(int arr[], int n)

// Mengisi array dengan bilangan random antara 1 - 10000
void generate_data(int arr[], int n)

// Menyalin isi array ke array lain
void copy_int(int src[], int dst[], int n)

// Menampilkan 10 data pertama dari array
void print_int(int arr[], int n, const char *label)
```

#### Sorting Dasar - Integer

**Bubble Sort** — membandingkan dua elemen bersebelahan dan menukarnya jika urutannya salah, diulang sampai semua data terurut.
```c
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap_int(&arr[j], &arr[j + 1]);
}
```

**Insertion Sort** — mengambil satu elemen lalu menyisipkannya ke posisi yang tepat di bagian array yang sudah terurut.
```c
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

**Selection Sort** — mencari elemen terkecil dari sisa array lalu menukarnya ke posisi yang seharusnya.
```c
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        swap_int(&arr[i], &arr[min_idx]);
    }
}
```

#### Helper String
Fungsi-fungsi pembantu untuk mengelola data string (kata).

```c
// Menukar nilai dua string
void swap_str(char a[], char b[])

// Mengacak urutan array string menggunakan metode Fisher-Yates
void shuffle_str(char arr[][MAX_WORD_LEN], int n)

// Menyalin isi array string ke array lain
void copy_str(char src[][MAX_WORD_LEN], char dst[][MAX_WORD_LEN], int n)

// Menampilkan 10 kata pertama dari array
void print_str(char arr[][MAX_WORD_LEN], int n, const char *label)
```

#### Advance Sorting - String

**Merge Sort** — membagi array menjadi dua bagian secara rekursif, lalu menggabungkannya kembali dalam urutan yang benar (divide and conquer).
```c
// Fungsi utama yang membagi array secara rekursif
void merge_sort_str(char arr[][MAX_WORD_LEN], int l, int r)

// Fungsi pembantu yang menggabungkan dua bagian array yang sudah terurut
static void merge_str(char arr[][MAX_WORD_LEN], int l, int m, int r)
```

**Quick Sort** — memilih satu elemen sebagai pivot, lalu mempartisi array sehingga elemen lebih kecil dari pivot ada di kiri dan lebih besar di kanan, diulang secara rekursif.
```c
// Fungsi utama yang memanggil partisi secara rekursif
void quick_sort_str(char arr[][MAX_WORD_LEN], int low, int high)

// Fungsi pembantu yang mempartisi array berdasarkan pivot
static int partition_str(char arr[][MAX_WORD_LEN], int low, int high)
```

**Shell Sort** — pengembangan dari insertion sort yang membandingkan elemen dengan jarak (gap) tertentu, gap diperkecil secara bertahap hingga 1.
```c
void shell_sort_str(char arr[][MAX_WORD_LEN], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        // insertion sort dengan jarak gap
}
```

#### Pembaca File & Penjalankan Menu

```c
// Membaca semua kata dari file words.txt ke array global words[][]
int load_words(const char *filename)

// Menjalankan sorting dasar sesuai pilihan (1=Bubble, 2=Insertion, 3=Selection)
void run_basic_sort(int choice)

// Menjalankan advance sorting sesuai pilihan (1=Merge, 2=Quick, 3=Shell)
void run_advance_sort(int choice)
```

---

### main.c
Berisi fungsi `main()` yang menampilkan menu utama dan submenu, lalu memanggil `run_basic_sort()` atau `run_advance_sort()` sesuai pilihan pengguna.
