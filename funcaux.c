#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"

int *gerarArrayAleatorio(int qtdeElementos){
    int *p = (int*) malloc(sizeof(int) * qtdeElementos);

    if(!p){
        return NULL;
    }

    for(int i = 0; i < qtdeElementos; i++){
        p[i] = rand() %qtdeElementos;
    }

    embaralha(p, qtdeElementos);

    return p;
}

void embaralha(int *vetor, int qtdeElementos){
    for(int i = qtdeElementos - 1; i > 0; i--){
        int j = rand() % (i+1);
        int tmp = vetor[j];
        vetor[j] = vetor[i];
        vetor[i] = tmp;
    }
}

void apagarArray(int *vetor){
    if(vetor != NULL){
        free(vetor);
    }
}

int maxValor(int arr[], int n){
    int max_val = arr[0];
    for(int i = 1; i < n; i++){
        if(max_val < arr[i]){
            max_val = arr[i];
        }
    }
    return max_val;
}
