#include <stdio.h>
#include "algoritmos.h"

void selectionSort(int *arr, int n){
    int i, j, menor;
    for(i = 0; i < n - 1; i++){
            menor = i;
        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca(&arr[i], &arr[menor]);
        }
    }
}
