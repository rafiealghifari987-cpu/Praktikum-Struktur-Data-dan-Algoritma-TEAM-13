#include "sorting.h"
#include <string.h>

// ================= INT SORTING =================
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[min])
                min = j;

        int t = arr[i];
        arr[i] = arr[min];
        arr[min] = t;
    }
}

// Merge Sort INT
void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];

    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

// Quick Sort INT
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;

    for(int j=low;j<high;j++)
        if(arr[j] < pivot) {
            i++;
            int t=arr[i]; arr[i]=arr[j]; arr[j]=t;
        }

    int t=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=t;

    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

// Shell Sort INT
void shellSort(int arr[], int n) {
    for(int gap=n/2; gap>0; gap/=2)
        for(int i=gap;i<n;i++) {
            int temp=arr[i];
            int j;
            for(j=i;j>=gap && arr[j-gap]>temp;j-=gap)
                arr[j]=arr[j-gap];
            arr[j]=temp;
        }
}

// ================= STRING SORTING =================
void mergeString(char arr[][100], int l, int m, int r) {
    char L[1000][100], R[1000][100];
    int n1=m-l+1, n2=r-m;

    for(int i=0;i<n1;i++) strcpy(L[i],arr[l+i]);
    for(int j=0;j<n2;j++) strcpy(R[j],arr[m+1+j]);

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
        strcpy(arr[k++], (strcmp(L[i],R[j])<=0)?L[i++]:R[j++]);

    while(i<n1) strcpy(arr[k++],L[i++]);
    while(j<n2) strcpy(arr[k++],R[j++]);
}

void mergeSortString(char arr[][100], int l, int r) {
    if(l<r){
        int m=(l+r)/2;
        mergeSortString(arr,l,m);
        mergeSortString(arr,m+1,r);
        mergeString(arr,l,m,r);
    }
}

// Quick Sort STRING
int partitionString(char arr[][100], int low, int high) {
    char pivot[100];
    strcpy(pivot,arr[high]);

    int i=low-1;

    for(int j=low;j<high;j++)
        if(strcmp(arr[j],pivot)<0){
            i++;
            char t[100];
            strcpy(t,arr[i]);
            strcpy(arr[i],arr[j]);
            strcpy(arr[j],t);
        }

    char t[100];
    strcpy(t,arr[i+1]);
    strcpy(arr[i+1],arr[high]);
    strcpy(arr[high],t);

    return i+1;
}

void quickSortString(char arr[][100], int low, int high) {
    if(low<high){
        int pi=partitionString(arr,low,high);
        quickSortString(arr,low,pi-1);
        quickSortString(arr,pi+1,high);
    }
}

// Shell Sort STRING
void shellSortString(char arr[][100], int n) {
    for(int gap=n/2;gap>0;gap/=2)
        for(int i=gap;i<n;i++){
            char temp[100];
            strcpy(temp,arr[i]);

            int j;
            for(j=i;j>=gap && strcmp(arr[j-gap],temp)>0;j-=gap)
                strcpy(arr[j],arr[j-gap]);

            strcpy(arr[j],temp);
        }
}