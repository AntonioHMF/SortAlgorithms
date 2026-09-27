#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "algoritmos.h"
#include "menu.h"
#include <time.h>


#define N_Testes 10

int main(){
    //Criando as variáveis para marcação de tempo
    struct timeval Tempo_inicial, Tempo_final;
    double delta_T, tempos_Marcados[N_Testes];

    int escolhaALG, qtdeElem, i;

    do{
        limparTela();
        escolhaALG = exibirMenuPrincipal();

        if(escolhaALG == 0){
            printf("\nEncerrando o programa...\n\n\n");
            break;
        }

        if(escolhaALG >= 1 && escolhaALG <= 11){
            limparTela();
            qtdeElem = exibirMenuSecundario(escolhaALG);
        }else{
            printf("\nOpcao invalida! Pressione Enter para continuar...\n\n");
                    getchar();
            getchar();
            continue;
        }

        switch(escolhaALG){
            case 1:
                for(i = 0; i < N_Testes; i++){
                    srand(time(NULL));

                    int *arr = gerarArrayAleatorio(qtdeElem);

                    if(arr == NULL){
                        printf("Nao foi possivel alocar o array! Tente novamente!");
                        continue;
                    }

                    gettimeofday(&Tempo_inicial, NULL);

                    bubbleSort(arr, qtdeElem);

                    gettimeofday(&Tempo_final, NULL);

                    delta_T = (Tempo_final.tv_sec + Tempo_final.tv_usec / 1000000.0) - (Tempo_inicial.tv_sec + Tempo_inicial.tv_usec / 1000000.0);

                    tempos_Marcados[i] = delta_T;

                    apagarArray(arr);
                }
                break;
            case 2:
                for(i = 0; i < N_Testes; i++){
                    srand(time(NULL));

                    int *arr = gerarArrayAleatorio(qtdeElem);

                    if(arr == NULL){
                        printf("Nao foi possivel alocar o array! Tente novamente!");
                        continue;
                    }

                    gettimeofday(&Tempo_inicial, NULL);

                    bubbleSort(arr, qtdeElem);

                    gettimeofday(&Tempo_final, NULL);

                    delta_T = (Tempo_final.tv_sec + Tempo_final.tv_usec / 1000000.0) - (Tempo_inicial.tv_sec + Tempo_inicial.tv_usec / 1000000.0);

                    tempos_Marcados[i] = delta_T;

                    apagarArray(arr);
                }
                break;
            case 3:
                for(i = 0; i < N_Testes; i++){
                    srand(time(NULL));

                    int *arr = gerarArrayAleatorio(qtdeElem);

                    if(arr == NULL){
                        printf("Nao foi possivel alocar o array! Tente novamente!");
                        continue;
                    }

                    gettimeofday(&Tempo_inicial, NULL);

                    insertionSort(arr, qtdeElem);

                    gettimeofday(&Tempo_final, NULL);

                    delta_T = (Tempo_final.tv_sec + Tempo_final.tv_usec / 1000000.0) - (Tempo_inicial.tv_sec + Tempo_inicial.tv_usec / 1000000.0);

                    tempos_Marcados[i] = delta_T;

                    apagarArray(arr);
                }
                break;
            case 4:
                for(i = 0; i < N_Testes; i++){
                    srand(time(NULL));

                    int *arr = gerarArrayAleatorio(qtdeElem);

                    if(arr == NULL){
                        printf("Nao foi possivel alocar o array! Tente novamente!");
                        continue;
                    }

                    gettimeofday(&Tempo_inicial, NULL);

                    mergeSort(arr, 0, qtdeElem-1);

                    gettimeofday(&Tempo_final, NULL);

                    delta_T = (Tempo_final.tv_sec + Tempo_final.tv_usec / 1000000.0) - (Tempo_inicial.tv_sec + Tempo_inicial.tv_usec / 1000000.0);

                    tempos_Marcados[i] = delta_T;

                    apagarArray(arr);
                }
                break;
            case 5:
                for(i = 0; i < N_Testes; i++){
                    srand(time(NULL));

                    int *arr = gerarArrayAleatorio(qtdeElem);

                    if(arr == NULL){
                        printf("Nao foi possivel alocar o array! Tente novamente!");
                        continue;
                    }

                    gettimeofday(&Tempo_inicial, NULL);

                    quickSort(arr, 0, qtdeElem-1);

                    gettimeofday(&Tempo_final, NULL);

                    delta_T = (Tempo_final.tv_sec + Tempo_final.tv_usec / 1000000.0) - (Tempo_inicial.tv_sec + Tempo_inicial.tv_usec / 1000000.0);

                    tempos_Marcados[i] = delta_T;

                    apagarArray(arr);
                }
                break;
            case 6:
                for(i = 0; i < N_Testes; i++){
                    srand(time(NULL));

                    int *arr = gerarArrayAleatorio(qtdeElem);

                    if(arr == NULL){
                        printf("Nao foi possivel alocar o array! Tente novamente!");
                        continue;
                    }

                    gettimeofday(&Tempo_inicial, NULL);

                    shellSort(arr, qtdeElem);

                    gettimeofday(&Tempo_final, NULL);

                    delta_T = (Tempo_final.tv_sec + Tempo_final.tv_usec / 1000000.0) - (Tempo_inicial.tv_sec + Tempo_inicial.tv_usec / 1000000.0);

                    tempos_Marcados[i] = delta_T;

                    apagarArray(arr);
                }
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                for(i = 0; i < N_Testes; i++){
                    //Iniciando uma semente, para os array serem aleatórios;
                    srand(time(NULL));

                    int *arr = gerarArrayAleatorio(qtdeElem);

                    if(arr == NULL){
                        printf("Nao foi possivel alocar o array! Tente novamente!");
                        continue;
                    }

                    gettimeofday(&Tempo_inicial, NULL);

                    radixSort(arr, qtdeElem);

                    gettimeofday(&Tempo_final, NULL);

                    delta_T = (Tempo_final.tv_sec + Tempo_final.tv_usec / 1000000.0) - (Tempo_inicial.tv_sec + Tempo_inicial.tv_usec / 1000000.0);

                    tempos_Marcados[i] = delta_T;

                    apagarArray(arr);
                }
                break;
            case 10:
                break;
            case 11:
                break;
        }

        if(escolhaALG != 0){
            exibirRelatorioResultados(escolhaALG, qtdeElem, tempos_Marcados, N_Testes);
        }


    }while (escolhaALG != 0);


    return 0;
}
