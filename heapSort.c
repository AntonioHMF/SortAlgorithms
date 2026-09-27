#include <stdio.h>
#include "algoritmos.h"

void heapSort(int *arr, int n){
    int i, aux;
    for(i = (n-1) / 2; i >= 0; i--){
        criaHeap(arr, i, n-1);
    }
    for(i = n - 1; i >= 1; i--){
        troca(&arr[0], &arr[i]);
        criaHeap(arr, 0, i - 1);
    }
}

void criaHeap(int *arr, int i, int f){
    int aux = arr[i];
    int j = i * 2 + 1;
    while(j <= f){
        if(j < f){
            if(arr[j] < arr[j+1]){
                j = j + 1;
            }
        }
        if(aux < arr[j]){
            arr[i] = arr[j];
            i = j;
            j = 2 * i + 1;
        }else{
            j = f + 1;
        }
    }
    arr[i] = aux;
}
