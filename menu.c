#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"

// Vetor com os nomes correspondentes a cada ID de 1 a 11
const char *nomesAlgoritmos[] = {
    "",                     // Índice 0 (não utilizado)
    "Bubble Sort",          // 1
    "Insertion Sort",       // 2
    "Selection Sort",       // 3
    "Merge Sort",           // 4
    "Quick Sort",           // 5
    "Shell Sort",           // 6
    "Heap Sort",            // 7
    "Bucket Sort",          // 8
    "Radix Sort (LSD)",     // 9
    "Counting Sort",        // 10
    "Tim Sort"              // 11
};

int exibirMenuPrincipal() {
    int escolha;
    printf("\n");
    printf("  =======================================================\n");
    printf("         AVALIACAO DE DESEMPENHO - ORDENACAO             \n");
    printf("  =======================================================\n");
    printf("  [01] %-16s            [07] %-16s                       \n", nomesAlgoritmos[1], nomesAlgoritmos[7]);
    printf("  [02] %-16s            [08] %-16s                       \n", nomesAlgoritmos[2], nomesAlgoritmos[8]);
    printf("  [03] %-16s            [09] %-16s                       \n", nomesAlgoritmos[3], nomesAlgoritmos[9]);
    printf("  [04] %-16s            [10] %-16s                       \n", nomesAlgoritmos[4], nomesAlgoritmos[10]);
    printf("  [05] %-16s            [11] %-16s                       \n", nomesAlgoritmos[5], nomesAlgoritmos[11]);
    printf("  [06] %-16s                                             \n", nomesAlgoritmos[6]);
    printf("  -------------------------------------------------------\n");
    printf("  [00] Sair do Programa                                  \n");
    printf("  =======================================================\n");
    printf("  Digite sua opcao [0-11]: ");
    scanf("%d", &escolha);

    return escolha;
}

int exibirMenuSecundario(int escolhaALG){
    int opcao, qtd = 0;

    printf("\n");
    printf("  +-----------------------------------------------------+\n");
    printf("  |            CONFIGURACAO DE ENTRADA DE DADOS         |\n");
    printf("  +-----------------------------------------------------+\n");
    printf("  | Algoritmo selecionado: %-25s    |\n", nomesAlgoritmos[escolhaALG]);
    printf("  +-----------------------------------------------------+\n");
    printf("  | [1] 10.000 elementos       [4] 200.000 elementos    |\n");
    printf("  | [2] 50.000 elementos       [5] 500.000 elementos    |\n");
    printf("  | [3] 100.000 elementos      [6] 1.000.000 elementos  |\n");
    printf("  +-----------------------------------------------------+\n");
    printf("  Escolha o tamanho do vetor: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            qtd = 10000;
            break;
        case 2:
            qtd = 50000;
            break;
        case 3:
            qtd = 100000;
            break;
        case 4:
            qtd = 200000;
            break;
        case 5:
            qtd = 500000;
            break;
        case 6:
            qtd = 1000000;
            break;
        default:
            printf("Opcao invalida. Definindo padrao para 10.000 elementos");
            qtd = 10000;
    }

    return qtd;
}

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

void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
