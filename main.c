#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorting.h"

#define SIZE 1000
#define WORD_LEN 100

void printInt(int arr[]) {
    for(int i=0;i<10;i++) printf("%d ",arr[i]);
    printf("\n");
}

void printWords(char arr[][WORD_LEN], int n) {
    for(int i=0;i<10 && i<n;i++)
        printf("%s ",arr[i]);
    printf("\n");
}

void shuffleInt(int arr[], int n){
    for(int i=0;i<n;i++){
        int j=rand()%n;
        int t=arr[i]; arr[i]=arr[j]; arr[j]=t;
    }
}

void shuffleString(char arr[][WORD_LEN], int n){
    for(int i=0;i<n;i++){
        int j=rand()%n;
        char t[WORD_LEN];
        strcpy(t,arr[i]);
        strcpy(arr[i],arr[j]);
        strcpy(arr[j],t);
    }
}

int loadWords(char arr[][WORD_LEN]){
    FILE *fp=fopen("words.txt","r");
    int count=0;

    if(!fp) return 0;

    while(fscanf(fp,"%s",arr[count])!=EOF)
        count++;

    fclose(fp);
    return count;
}

int main(){
    int choice,method;
    int arr[SIZE];
    char words[1000][WORD_LEN];
    int count;

    srand(time(NULL));

    do{
        printf("\n1. Sorting Dasar\n2. Advance Sorting\n3. Exit\n");
        printf("Pilih: ");
        scanf("%d",&choice);

        switch(choice){

        case 1:{
            for(int i=0;i<SIZE;i++) arr[i]=rand()%1000;
            shuffleInt(arr,SIZE);

            printf("\nBubble/Insertion/Selection\nPilih: ");
            scanf("%d",&method);

            clock_t s=clock();

            if(method==1) bubbleSort(arr,SIZE);
            else if(method==2) insertionSort(arr,SIZE);
            else selectionSort(arr,SIZE);

            clock_t e=clock();

            printInt(arr);
            printf("Time: %f\n",(double)(e-s)/CLOCKS_PER_SEC);

            break;
        }

        case 2: {
            count = loadWords(words);
            if(count == 0) break;

            shuffleString(words, count);

            printf("\nMerge/Quick/Shell\n");
            printf("Pilih: ");
            scanf("%d", &method);

            printf("\nSebelum sorting:\n");
            printWords(words, count);

            clock_t start = clock();

            if(method == 1)
                 mergeSortString(words, 0, count - 1);
            else if(method == 2)
                  quickSortString(words, 0, count - 1);
            else if(method == 3)
               shellSortString(words, count);
            else {
                printf("Pilihan salah!\n");
                 break;
            }

             clock_t end = clock();

                printf("\nSetelah sorting:\n");
                printWords(words, count);

                printf("Time: %f\n",
                (double)(end - start) / CLOCKS_PER_SEC);

                break;
            }
        case 3:
            printf("Exit\n");
            break;

        default:
            printf("Invalid\n");
        }

    }while(choice!=3);

    return 0;
}