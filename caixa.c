#include <stdio.h>
#include <stdlib.h>

void exibirMenu() {
    printf("\n========================\n");
    printf("     CAIXA ELETRONICO     \n");
    printf("========================\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Realizar Saque\n");
    printf("3 - Realizar Deposito\n");
    printf("0 - Sair\n");
    printf("========================\n");
    printf("Escolha uma opcao: ");
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

void consultarSaldo(float saldo) {
    printf("\n--- SALDO ATUAL ---\n");
    printf("R$ %.2f\n", saldo);
    printf("-------------------\n");
    pausar();
}

float realizarDeposito(float saldo) {
    float valor;

    printf("Digite o valor do deposito: ");
    if (scanf("%f", &valor) != 1) {
        printf("Entrada invalida!\n");
        while (getchar() != '\n');
        return saldo;
    }

    if (valor > 0) {
        saldo += valor;
        printf("Deposito realizado com sucesso!\n");
    } else {
        printf("Valor invalido!\n");
    }

    pausar();
    return saldo;
}

float realizarSaque(float saldo) {
    float valor;

    printf("Digite o valor do saque: ");
    if (scanf("%f", &valor) != 1) {
        printf("Entrada invalida!\n");
        while (getchar() != '\n');
        return saldo;
    }

    if (valor > 0 && valor <= saldo) {
        saldo -= valor;
        printf("Saque realizado com sucesso!\n");
    } else {
        printf("Saldo insuficiente ou valor invalido!\n");
    }

    pausar();
    return saldo;
}

int main() {
    int opcao;
    float saldo = 0.0f;

    do {
        exibirMenu();

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {
            case 0:
                printf("\nObrigado por usar nosso programa!\n");
                break;

            case 1:
                consultarSaldo(saldo);
                break;

            case 2:
                saldo = realizarSaque(saldo);
                break;

            case 3:
                saldo = realizarDeposito(saldo);
                break;

            default:
                printf("Opcao invalida!\n");
                pausar();
        }

    } while (opcao != 0);

    return 0;
}