#include <stdio.h>
#include <stdlib.h>

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
