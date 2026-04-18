#include <stdio.h>

void cabecalho() {
    printf("****************\n");
    printf("*   Potencia   *\n");
    printf("****************\n");
    printf("1 - Calcular a potencia de um numero inteiro.\n");
    printf("2 - Sair do programa.\n");
}

void potencia(int conta) {
    int base, expoente;
    int resultado = 1;

    printf("Digite a base: ");
    scanf(" %d", &base);
    printf("Digite o expoente: ");
    scanf(" %d", &expoente);

    if (expoente < 0) {
        printf("Expoente negativo nao e permitido.\n"); // Expoente negativo
        potencia(conta); // Chama a função novamente para solicitar novos valores
        return; // Sai da função atual para evitar a execução do código abaixo
    }

    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }

    printf("%d elevado a %d e: %d\n\n", base, expoente, resultado);

}

int main() {
    int opcao;
    int conta = 0;
    
while (opcao != 2){
    cabecalho();
    printf("Digite a opcao desejada: ");
    scanf(" %d", &opcao);

        switch (opcao){
        case 1:
        potencia(conta);
        break;
        
        case 2:
            printf("Saindo do programa...\n");
            break;

        default:
            printf("Opcao invalida! Por favor, escolha uma opcao valida.\n\n");
            break;
        }
    }

    return 0;
}