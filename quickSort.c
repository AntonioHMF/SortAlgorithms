#include <stdio.h>
#include "algoritmos.h"

void quickSort(int *arr, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(arr, inicio, fim);
        quickSort(arr, inicio, pivo - 1);
        quickSort(arr, pivo + 1, fim);
    }
}

int particiona(int *arr, int inicio, int fim){
    int esq, dir, pivo;
    esq = inicio;
    dir = fim;
    pivo = arr[inicio];
    while(esq < dir){
        while(arr[esq] <= pivo && esq <= fim){
            esq++;
        }
        while(arr[dir] > pivo && dir >= inicio){
            dir --;
        }
        if(esq < dir){
            troca(&arr[esq], &arr[dir]);
        }
    }
    arr[inicio] = arr[dir];
    arr[dir] = pivo;
    return dir;
}
