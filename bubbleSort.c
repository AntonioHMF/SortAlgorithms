#include <stdio.h>
#include "algoritmos.h"

void bubbleSort(int *arr, int n){
    int i, continua, fim = n;
    do{
        continua = 0;
        for(i = 0; i < fim - 1; i++){
            if(arr[i] > arr[i+1]){
                troca(&arr[i], &arr[i+1]);
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);
}
