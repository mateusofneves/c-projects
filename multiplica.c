#include <stdio.h>

int main() {
    int num1, num2;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    int resultado = num1 * num2;

    printf("O resultado da multiplicacao de %d e %d e: %d\n", num1, num2, resultado);


    return 0;

}