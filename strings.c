#include <stdio.h>
#include <string.h>

int main() {
    char inicial = 'c';
    char palavra[20] = "Bem-vindo!";
    char nome[50];

    printf("%s\n", palavra);

    printf("Digite seu nome completo: ");
    //scanf(" %s", &nome);
    fgets(nome, 50, stdin);

    printf("Estou com sono %s", nome);

    char nome_ref[50] = "Mateus Neves";
    int tamanho_nome = strlen(nome);
    int tamanho_nome_ref = strlen(nome_ref);

    printf("Tamanho do nome: %d\n", tamanho_nome);
    printf("Tamanho do nome de referencia: %d", tamanho_nome_ref);

    return 0;
}