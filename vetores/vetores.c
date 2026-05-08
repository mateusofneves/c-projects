#include <stdio.h>

int main() {
    int qtd_notas;
    //float notas[qtd_notas];
    float soma = 0;
    float media;

    float notas[] = {10, 2, 8, 5, 4};
    int tamanho = sizeof(notas) / sizeof(notas[0]);

    for (int i = 0; i < tamanho; i++) {
        soma += notas[i];
        
    }

    media = soma / tamanho;
    printf("A media do aluno e: %2.f\n", media);

    /*
    printf("Digite a quantidade de notas para digitar. ");
    scanf("%d", &qtd_notas);

    for (int i = 0; i < qtd_notas; i++) {
        printf("Digite as quatro notas do aluno. ");
        scanf("%f", &notas[i]);
        soma += notas[i];
        media = soma / qtd_notas;
    }

    printf("A media do aluno e: %2.f\n", media);
    */

    return 0;
}