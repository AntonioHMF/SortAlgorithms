#include <stdio.h>
#include <stdlib.h>
#include "lib/algoritmos.h"
#include "lib/menu.h"

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

int main(){
    int escolhaALG, qtdeElem;

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
            printf("\nOpcao invalida! Pressione Enter para continuar...");
            getchar();
        }

    }while (escolhaALG != 0);

    return 0;
}
