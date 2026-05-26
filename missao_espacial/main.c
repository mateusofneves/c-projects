#include <stdio.h>
#include <stdlib.h>
#include "includes/sistema.h"

int main() {

    int opcao;

    do {

        menu();

        scanf("%d", &opcao);

        switch(opcao) {

            case 1:

                inserirDados();
                pausarSistema();
                break;

            case 2:

                visualizarStatus();
                pausarSistema();
                break;

            case 3:

                analisarSistema();
                pausarSistema();
                break;

            case 4:

                mostrarHistorico();
                pausarSistema();
                break;

            case 0:

                printf("\n=====================================\n");
                printf("   SISTEMA ENCERRADO COM SUCESSO\n");
                printf("=====================================\n");
                break;

            default:

                printf("\nOpcao invalida!\n");
                pausarSistema();
        }

    } while(opcao != 0);

    return 0;
}