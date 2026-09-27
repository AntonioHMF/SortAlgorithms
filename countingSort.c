#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"

void countingSort(int *arr, int n){
    int i, maior, *count, *output;

    //Descobre o maior valor do vetor
    maior = maxValor(arr, n);

    count = (int*) calloc(maior + 1, sizeof(int));

    output = (int*) malloc(n * sizeof(int));

    //Conta quantas vezes cada valor aparece em arr
    for(i = 0; i < n; i++){
        count[arr[i]]++;
    }

    //Modifica o vetor count para armazenar a posição final de cada valor
    for(i = 1; i <= maior; i++){
        count[i] += count[i - 1];
    }

    //Percore o vetor de trás para frente, garantindo estabilidade, e monta o vetor output
    for(i = n - 1; i >= 0; i--){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    //copia o resultado ordenado
    for(i = 0; i < n; i ++){
        arr[i] = output[i];
    }

    free(count);
    free(output);
}
