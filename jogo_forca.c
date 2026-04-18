#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "jogo_forca.h"

//variáveis globais
char palavrasecreta[20];
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

void desenhaforca() {

    for(int i = 0; i < strlen(palavrasecreta); i++) {

            int achou = jachutou(palavrasecreta[i]);

            if(achou) {
                printf("%c ", palavrasecreta[i]);
            } else {
                printf("_ ");
            }
        }
        
        printf("\n");

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

int enforcou() {

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

    return erros >= 5;
}

int acertou () {

    for (int i = 0; i < strlen(palavrasecreta); i++) {
        if (!jachutou(palavrasecreta[i])) {
            return 0; // Ainda tem letra não chutada, o jogador não ganhou
        }
    }

    return 1; // Todas as letras foram chutadas, o jogador ganhou

}

int main() {

    escolhepalavra();
    abertura();

    do {

        desenhaforca();
        chuta();

    } while (!acertou() && !enforcou());

}