#include <stdio.h>
#include <stdlib.h>
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
    printf("  [01] Bubble Sort            [07] Heap Sort             \n");
    printf("  [02] Insertion Sort         [08] Bucket Sort           \n");
    printf("  [03] Selection Sort         [09] Radix Sort (LSD)      \n");
    printf("  [04] Merge Sort             [10] Counting Sort         \n");
    printf("  [05] Quick Sort             [11] Tim Sort              \n");
    printf("  [06] Shell Sort                                        \n");
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
    printf("  | Algoritmo selecionado: [%02d]                       |\n", nomesAlgoritmos[escolhaALG]);
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

void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
