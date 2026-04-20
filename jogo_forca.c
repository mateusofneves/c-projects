#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "jogo_forca.h"

//variáveis globais
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

void abertura() {
    printf("*********************\n");
    printf("*   Jogo de Forca   *\n");
    printf("*********************\n\n");
}

void chuta() {
    char chute;
    scanf(" %c", &chute);

    chutes[(chutesdados)] = chute;
    (chutesdados)++;
}

 int jachutou(char letra) {
    
    int achou = 0;

    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;

}

void escolhepalavra() {
    FILE* f;
    
    f = fopen("palavras.txt", "r");
    if (f == 0){
        printf("Erro ao abrir o arquivo de palavras!\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for (int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);

}

int chuteserrados() {

    int erros = 0;

    for (int i = 0; i < chutesdados; i++) {
        
        int existe = 0;

        for (int j = 0; j < strlen(palavrasecreta); j++) {
             if (chutes[i] == palavrasecreta[j]) {
        
                existe = 1;
                break; // Letra encontrada, continua para a próxima letra
            } 
        }
    
        if (!existe) erros++;
    
    }

    return erros;

}

int enforcou() {

    return chuteserrados() >= 5;

}

int ganhou () {

    for (int i = 0; i < strlen(palavrasecreta); i++) {
        if (!jachutou(palavrasecreta[i])) {
            return 0; // Ainda tem letra não chutada, o jogador não ganhou
        }
    }

    return 1; // Todas as letras foram chutadas, o jogador ganhou

}

void adicionapalavra() {
    char quer;

    printf("Deseja adicionar uma nova palavra ao jogo? (S/N) ");
    scanf(" %c", &quer);

    if (quer == 'S' || quer == 's') {

        char novaPalavra[TAMANHO_PALAVRA];

        printf("Digite a nova palavra: ");
        scanf("%s", novaPalavra);

        FILE* f;

        f = fopen("palavras.txt", "r+");
        if (f == 0) {
            printf("Erro ao abrir o arquivo de palavras!\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++; // Incrementa a quantidade de palavras

        fseek(f, 0, SEEK_SET); // Volta para o início do arquivo
        fprintf(f, "%d\n", qtd); // Atualiza a quantidade de palavras no arquivo
        
        fseek(f, 0, SEEK_END); // Move o cursor para o final do arquivo
        fprintf(f, "%s\n", novaPalavra); // Adiciona a nova palavra ao final do arquivo
        
        fclose(f);

    } 
}

void desenhaforca() {

    int erros = chuteserrados();
    
    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %c%c%c \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c \n", (erros >= 2 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 2 ? '/' : ' '));
    printf(" |       %c    \n", (erros >= 3 ? '|' : ' '));
    printf(" |      %c %c  \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

    for (int i = 0; i < strlen(palavrasecreta); i++) {
        
        int achou = jachutou(palavrasecreta[i]);
        
        if (achou) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }

    printf("\n");

}

int main() {

    escolhepalavra();
    abertura();

    do {

        desenhaforca();
        chuta();

    } while (!ganhou() && !enforcou());

    if(ganhou()) {
        printf("\nParabens, voce ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        printf("\nPuxa, voce foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }   
    
}