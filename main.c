#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos.h"
#include "menu.h"

int main(){
    srand(time(NULL));
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

        int *arr = gerarArrayAleatorio(qtdeElem);

        if(arr == NULL){
            printf("Nao foi possivel alocar o array! Tente novamente!");
            continue;
        }

        switch (escolhaALG){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;

        }

        apagarArray(arr);
    }while (escolhaALG != 0);


    return 0;
}
