#include <stdio.h>
#include "algoritmos.h"
#include <time.h>
#include <stdlib.h>

void countingSort(int arr[], int n, int exp){
    int *output = (int*) malloc(n * sizeof(int));
    int count[10] = {0};

    //Conta quantas vezes um número de 0 a 9 aparece em cada dígito
    for(int i = 0; i < n; i++){
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    //Altera o array count para armazenar as posições dos dígitos
    for(int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    //Construindo o Output array
    for(int i = n - 1; i >= 0; i--){
        int index = (arr[i] / exp) % 10; //Pega o dígito da posição específica
        output[count[index] - 1] = arr[i]; //Copia o número na posição anterior ao index que foi pego
        count[index]--; // Diminui o valor da posição no count
    }

    //Copiando os array
    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }

    free(output);
}

void radixSort(int arr[], int n){
    int max_val = maxValor(arr, n);

    for(int exp = 1; max_val / exp > 0; exp *= 10){
        countingSort(arr, n, exp);
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

        /********************************************************************************************************************
        *Exemplo:                                                                                                           *
        *                                                                                                                   *
        * count[10] = { 1, 2, 1, 3, 0, 0, 0, 0, 0, 0}                                                                       *
        *                                                                                                                   *
        * *Depois da função for                                                                                             *
        *                                                                                                                   *
        * count[10] = {1, 3, 4, 7, 7, 7, 7, 7, 7, 7}                                                                        *
        * count[0] = 1, quer dizer que há 1 elemento com dígito <= 0. Portanto a posíção dele index 1 - 1 = 0               *
        * count[1] = 3, quer dizer que há 3 elementos com dígito <= 1. Portanto a posição deles vai até index 3 - 1 = 2     *
        * count[2] = 4, quer dizer que há 4 elementos com dígito <= 2. Portanto a posição dele vai até index 4 - 1 = 3      *
        * count[3] = 7, quer dizre que há 7 elementos com dígito <= 3. Portanto a posição deles vai até index 7 - 1 = 6     *
        ********************************************************************************************************************/

        /************************************************
        * count[10] = {1, 3, 4, 7, 7, 7, 7, 7, 7, 7}    *
        * arr[7 - 1] = 143;                             *
        * index = (143 / 1) % 10 = 3                    *
        * count[index] =  7                             *
        * output[count[index] - 1] = 143;               *
        * count[index]-- = 6                            *
        ************************************************/
