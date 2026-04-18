#include <stdio.h>

void soma(int numeros[10]){
    int soma = 0;

    printf("Digite 10 numeros:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }

    printf("A soma dos numeros e: %d\n", soma);
}

int main() {
    int numeros[10];
    soma(numeros);
    return 0;
}