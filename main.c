#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"
#include "menu.h"

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
