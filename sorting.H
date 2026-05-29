#ifndef SORTING_H
#define SORTING_H

#define DATA_SIZE 1000
#define MAX_WORDS 100000
#define MAX_WORD_LEN 100
#define DISPLAY_COUNT 10

/*++++++++++ SORTING DASAR ++++++++++*/
void swap_int(int *a, int *b);
void shuffle_int(int arr[], int n);
void generate_data(int arr[], int n);
void copy_int(int src[], int dst[], int n);
void print_int(int arr[], int n, const char *label);
 
void bubble_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);

/*++++++++++ SORTING ADVANCE ++++++++++*/
void swap_str(char a[], char b[]);
void shuffle_str(char arr[][MAX_WORD_LEN], int n);
void copy_str(char src[][MAX_WORD_LEN], char dst[][MAX_WORD_LEN], int n);
void print_str(char arr[][MAX_WORD_LEN], int n, const char *label);
 
void merge_sort_str(char arr[][MAX_WORD_LEN], int l, int r);
void quick_sort_str(char arr[][MAX_WORD_LEN], int low, int high);
void shell_sort_str(char arr[][MAX_WORD_LEN], int n);
 
 
#endif