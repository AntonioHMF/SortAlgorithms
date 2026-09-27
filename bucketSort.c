#include <stdio.h>

#define TAM 10

struct balde{
    int qtd;
    int valores[TAM];
};

void bucketSort(int *arr, int n){
    int i, j, maior, menor, N_Baldes, pos;
    struct balde *bd;

    maior = menor = arr[0];
    for(i = 1; i < n; i++){
        if(arr[i] > maior){
            maior = arr[i];
        }
        if(arr[i] < menor){
            menor = arr[i];
        }
    }

    N_Baldes = (maior - menor) / TAM + 1;
    bd = (struct balde *) malloc(N_Baldes * sizeof(struct balde));

    for(i = 0; i < N_Baldes; i++){
        bd[i].qtd = 0;
    }

    for(i = 0; i < n; i++){
        pos = (arr[i] - menor) / TAM;
        bd[pos].valores[bd[pos].qtd] = arr[i];
        bd[pos].qtd;
    }

    pos = 0;
    for(i = 0; i < N_Baldes; i++){
        insertionSort(bd[i].valores, bd[i].qtd);
        for(j = 0; j < bd[i].qtd; j++){
            arr[pos] = bd[i].valores[j];
            pos++;
        }
    }
    free(bd);
}
