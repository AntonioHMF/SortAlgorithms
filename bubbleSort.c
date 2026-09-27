#include <stdio.h>
#include "algoritmos.h"

void bubbleSort(int *arr, int n){
    int i, continua, aux, fim = n;
    do{
        continua = 0;
        for(i = 0; i < fim - 1; i++){
            if(arr[i] > arr[i+1]){
                aux = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);
}
