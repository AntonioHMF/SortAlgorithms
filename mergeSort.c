#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"

void mergeSort(int *arr, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);
        merge(arr, inicio, meio, fim);
    }
}

void merge(int *arr, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int*) malloc(tamanho * sizeof(int));
    if(temp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(arr[p1] < arr[p2]){
                    temp[i] = arr[p1];
                    p1++;
                }else{
                    temp[i] = arr[p2];
                    p2++;
                }
                if(p1 > meio){
                    fim1 = 1;
                }
                if(p2 > fim){
                    fim2 = 1;
                }
            }else{
                if(!fim1){
                    temp[i] = arr[p1++];
                }else{
                    temp[i] = arr[p2++];
                }
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++, k++){
            arr[k] = temp[j];
        }
    }
    free(temp);
}
