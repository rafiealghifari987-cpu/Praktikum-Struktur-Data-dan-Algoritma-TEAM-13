#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorting.h"

/* Global dataset kata */
char words[MAX_WORDS][MAX_WORD_LEN];
int  word_count = 0;

/* HELPER - INTEGER */

void swap_int(int *a, int *b) {
    int tmp = *a; *a = *b; *b = tmp;
}

/* Shuffle array integer - Fisher-Yates */
void shuffle_int(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap_int(&arr[i], &arr[j]);
    }
}

void generate_data(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000 + 1;
}

void copy_int(int src[], int dst[], int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}

void print_int(int arr[], int n, const char *label) {
    printf("%s (menampilkan %d data pertama):\n", label, DISPLAY_COUNT);
    for (int i = 0; i < DISPLAY_COUNT && i < n; i++)
        printf("%d ", arr[i]);
    printf("...\n\n");
}

/* SORTING DASAR - INTEGER */

/*  Bubble Sort  */
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap_int(&arr[j], &arr[j + 1]);
}

/*  Insertion Sort */
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

/* Selection Sort */
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        swap_int(&arr[i], &arr[min_idx]);
    }
}

/* HELPER - STRING */

void swap_str(char a[], char b[]) {
    char tmp[MAX_WORD_LEN];
    strcpy(tmp, a); strcpy(a, b); strcpy(b, tmp);
}

/* Shuffle array string - Fisher-Yates */
void shuffle_str(char arr[][MAX_WORD_LEN], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap_str(arr[i], arr[j]);
    }
}

void copy_str(char src[][MAX_WORD_LEN], char dst[][MAX_WORD_LEN], int n) {
    for (int i = 0; i < n; i++) strcpy(dst[i], src[i]);
}

void print_str(char arr[][MAX_WORD_LEN], int n, const char *label) {
    printf("%s (menampilkan %d kata pertama):\n", label, DISPLAY_COUNT);
    for (int i = 0; i < DISPLAY_COUNT && i < n; i++)
        printf("%s ", arr[i]);
    printf("...\n\n");
}

/* ADVANCE SORTING (STRING) */

/*++++++ Merge Sort ++++++*/
static void merge_str(char arr[][MAX_WORD_LEN], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    char (*L)[MAX_WORD_LEN] = malloc((size_t)n1 * MAX_WORD_LEN);
    char (*R)[MAX_WORD_LEN] = malloc((size_t)n2 * MAX_WORD_LEN);

    for (int i = 0; i < n1; i++) strcpy(L[i], arr[l + i]);
    for (int j = 0; j < n2; j++) strcpy(R[j], arr[m + 1 + j]);

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (strcasecmp(L[i], R[j]) <= 0) strcpy(arr[k++], L[i++]);
        else                              strcpy(arr[k++], R[j++]);
    }
    while (i < n1) strcpy(arr[k++], L[i++]);
    while (j < n2) strcpy(arr[k++], R[j++]);

    free(L); free(R);
}

void merge_sort_str(char arr[][MAX_WORD_LEN], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort_str(arr, l, m);
        merge_sort_str(arr, m + 1, r);
        merge_str(arr, l, m, r);
    }
}

/* Quick Sort */
static int partition_str(char arr[][MAX_WORD_LEN], int low, int high) {
    char pivot[MAX_WORD_LEN];
    strcpy(pivot, arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (strcasecmp(arr[j], pivot) <= 0) {
            i++;
            swap_str(arr[i], arr[j]);
        }
    }
    swap_str(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort_str(char arr[][MAX_WORD_LEN], int low, int high) {
    if (low < high) {
        int pi = partition_str(arr, low, high);
        quick_sort_str(arr, low, pi - 1);
        quick_sort_str(arr, pi + 1, high);
    }
}

/* Shell Sort */
void shell_sort_str(char arr[][MAX_WORD_LEN], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char tmp[MAX_WORD_LEN];
            strcpy(tmp, arr[i]);
            int j = i;
            while (j >= gap && strcasecmp(arr[j - gap], tmp) > 0) {
                strcpy(arr[j], arr[j - gap]);
                j -= gap;
            }
            strcpy(arr[j], tmp);
        }
    }
}

/* FILE READER */

int load_words(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("  [ERROR] File '%s' tidak ditemukan!\n", filename);
        printf("  Pastikan file words.txt ada di folder yang sama.\n\n");
        return 0;
    }
    word_count = 0;
    while (word_count < MAX_WORDS && fscanf(f, "%99s", words[word_count]) == 1)
        word_count++;
    fclose(f);
    printf("  Berhasil memuat %d kata dari '%s'.\n\n", word_count, filename);
    return word_count;
}

/* MENU RUNNERS */

void run_basic_sort(int choice) {
    int arr[DATA_SIZE];
    generate_data(arr, DATA_SIZE);
    shuffle_int(arr, DATA_SIZE);
    print_int(arr, DATA_SIZE, "Data sebelum sorting");

    clock_t start, end;
    double elapsed;
    const char *nama;

    start = clock();
    switch (choice) {
        case 1: bubble_sort(arr, DATA_SIZE);    nama = "Bubble Sort";    break;
        case 2: insertion_sort(arr, DATA_SIZE); nama = "Insertion Sort"; break;
        case 3: selection_sort(arr, DATA_SIZE); nama = "Selection Sort"; break;
        default: return;
    }
    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

    print_int(arr, DATA_SIZE, "Data setelah sorting");
    printf("  Algoritma     : %s\n", nama);
    printf("  Jumlah data   : %d\n", DATA_SIZE);
    printf("  Waktu eksekusi: %.4f ms\n\n", elapsed);
}

void run_advance_sort(int choice) {
    if (word_count == 0) {
        printf("  [INFO] Memuat dataset kata...\n");
        if (!load_words("words.txt")) return;
    }

    char (*arr)[MAX_WORD_LEN] = malloc((size_t)word_count * MAX_WORD_LEN);
    if (!arr) { printf("  [ERROR] Alokasi memori gagal.\n"); return; }

    copy_str(words, arr, word_count);
    shuffle_str(arr, word_count);
    print_str(arr, word_count, "Data sebelum sorting");

    clock_t start, end;
    double elapsed;
    const char *nama;

    start = clock();
    switch (choice) {
        case 1: merge_sort_str(arr, 0, word_count - 1); nama = "Merge Sort"; break;
        case 2: quick_sort_str(arr, 0, word_count - 1); nama = "Quick Sort"; break;
        case 3: shell_sort_str(arr, word_count);         nama = "Shell Sort"; break;
        default: free(arr); return;
    }
    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

    print_str(arr, word_count, "Data setelah sorting");
    printf("  Algoritma     : %s\n", nama);
    printf("  Jumlah data   : %d kata\n", word_count);
    printf("  Waktu eksekusi: %.4f ms\n\n", elapsed);

    free(arr);
}