#include <stdio.h>

void insertionSort(int *arr, int n){
    int i, j, aux;
    for(i = 1; i < n; i++){
        aux = arr[i];
        for(j = i; (j > 0) && (aux < arr[j-1]); j--){
            arr[j] = arr[j-1];
        }
        arr[j] = aux;
    }
}
