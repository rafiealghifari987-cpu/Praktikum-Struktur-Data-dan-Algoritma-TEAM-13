#ifndef SORTING_H
#define SORTING_H


void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);
void shellSort(int arr[], int n);


void mergeSortString(char arr[][100], int left, int right);
void quickSortString(char arr[][100], int low, int high);
void shellSortString(char arr[][100], int n);

#endif