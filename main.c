#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorting.h"

#define SIZE 1000
#define MAX_WORDS 1000
#define WORD_LEN 100

void generateRandom(int arr[]) {
    for(int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }
}

void shuffle(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printArray(int arr[]) {
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, method;
    int arr[SIZE];

    srand(time(NULL));

    do {
        printf("\n===== MENU UTAMA =====\n");
        printf("1. Sorting Dasar\n");
        printf("2. Keluar\n");
        printf("Pilih menu : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                generateRandom(arr);
                shuffle(arr, SIZE);

                printf("\n===== SORTING DASAR =====\n");
                printf("1. Bubble Sort\n");
                printf("2. Insertion Sort\n");
                printf("3. Selection Sort\n");
                printf("Pilih metode : ");
                scanf("%d", &method);

                printf("\nData sebelum sorting:\n");
                printArray(arr);

                clock_t start = clock();

                if(method == 1)
                    bubbleSort(arr, SIZE);
                else if(method == 2)
                    insertionSort(arr, SIZE);
                else if(method == 3)
                    selectionSort(arr, SIZE);

                clock_t end = clock();

                printf("\nData setelah sorting:\n");
                printArray(arr);

                double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

                printf("\nWaktu eksekusi: %f detik\n", time_taken);

                break;

            case 2:
                printf("Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }

    } while(choice != 2);

    return 0;
}
