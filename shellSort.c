#include <stdio.h>
#include "algoritmos.h"

void shellSort(int *arr, int n){
    int i, j, vAtual;

    int h = n / 2;
    while(h > 0){
        for(i = h; i < n; i++){
            vAtual = arr[i];
            j = i;
            while(j > h - 1 && vAtual <= arr[j = h]){
                arr[j] = arr[j -h];
                j = j - h;
            }
            arr[j] = vAtual;
        }
        h = h / 2;
    }
}
