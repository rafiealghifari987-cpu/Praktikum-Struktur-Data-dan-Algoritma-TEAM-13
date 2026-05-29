#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

/* Forward declaration */
void run_basic_sort(int choice);
void run_advance_sort(int choice);


int main(void) {
    srand((unsigned)time(NULL));

    int menu, sub;
    do {
        printf("       MENU UTAMA            \n");
        printf("  1. Sorting Dasar\n");
        printf("  2. Advance Sorting\n");
        printf("  3. Keluar\n");
        printf("Pilih menu : ");
        scanf("%d", &menu);
        printf("\n");

        if (menu == 1) {
            do {
                printf("      SORTING DASAR          \n");
                printf("  1. Bubble Sort\n");
                printf("  2. Insertion Sort\n");
                printf("  3. Selection Sort\n");
                printf("  4. Kembali\n");
                printf("Pilih metode : ");
                scanf("%d", &sub);
                printf("\n");
                if (sub >= 1 && sub <= 3) run_basic_sort(sub);
            } while (sub != 4);

        } else if (menu == 2) {
            do {
                printf("      ADVANCE SORTING        \n");
                printf("  1. Merge Sort\n");
                printf("  2. Quick Sort\n");
                printf("  3. Shell Sort\n");
                printf("  4. Kembali\n");
                printf("Pilih metode : ");
                scanf("%d", &sub);
                printf("\n");
                if (sub >= 1 && sub <= 3) run_advance_sort(sub);
            } while (sub != 4);
        }

    } while (menu != 3);

    printf("Terima kasih! Program selesai.\n");
    return 0;
}