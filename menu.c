#include <stdio.h>
#include <stdlib.h>


int exibirMenuPrincipal() {
    int escolha;
    printf("\n");
    printf("  =======================================================\n");
    printf("         AVALIACAO DE DESEMPENHO - ORDENACAO             \n");
    printf("  =======================================================\n");
    printf("  [01] Bubble Sort            [07] Counting Sort         \n");
    printf("  [02] Selection Sort         [08] Radix Sort            \n");
    printf("  [03] Insertion Sort         [09] Bucket Sort           \n");
    printf("  [04] Merge Sort             [10] Heap Sort             \n");
    printf("  [05] Quick Sort             [11] Shell Sort            \n");
    printf("  [06] Insertion Otimizado                               \n");
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
    printf("  | Algoritmo selecionado: [%02d]                       |\n", escolhaALG);
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
