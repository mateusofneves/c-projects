#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Semente para gerar números aleatórios diferentes a cada execução
    srand(time(NULL));

    // Gera um número entre 1 e 100
    int numeroSecreto = rand() % 100 + 1;
    int nivel;
    int chute;
    int tentativas = 7;
    int tentativa_atual = 0;
    double pontos = 1000;

    printf("==========================================\n");
    printf("   BEM-VINDO AO JOGO DE ADIVINHACAO!    \n");
    printf("==========================================\n");
    printf("Eu escolhi um numero entre 1 e 100.\n");
    printf("Sera que voce consegue descobrir qual e?\n\n");
    printf("Escolha o nivel de dificuldade:\n");
    printf("1 - Facil (10 tentativas)\n");
    printf("2 - Medio (7 tentativas)\n");
    printf("3 - Dificil (5 tentativas)\n");
    printf("Digite o numero correspondente ao nivel: ");
    scanf("%d", &nivel);

    if (nivel == 1){
        tentativas = 10;
        pontos = 1000;
    } else if (nivel == 2){
        tentativas = 7;
        pontos = 1500;
    } else if (nivel == 3){
        tentativas = 5;
        pontos = 2000;
    } else {
        printf("Nivel invalido! Definindo nivel Medio por padrao.\n");
        tentativas = 7;
        pontos = 1500;
    }

    // Loop do jogo
    for (int i = 0; i < tentativas; i++) {
        printf("Digite seu chute: ");
        printf("(Tentativa %d de %d) ", i + 1, tentativas);
        scanf("%d", &chute);
        tentativa_atual++;
    
        if (chute < 1 || chute > 100) {
            printf("Chute invalido! Digite entre 1 e 100.\n\n");
            i--; // volta a tentativa
            continue;
        }

        else if (chute < numeroSecreto) {
            printf("Muito baixo! Tente um numero maior. ->\n\n");
        } 

        else if (chute > numeroSecreto) {
            printf("Muito alto! Tente um numero menor. <-\n\n");
        } 

        else {
            printf("------------------------------------------\n");
            printf("PARABENS! Voce acertou em %d tentativas!\n", i + 1);
            printf("O numero era %d.\n", numeroSecreto);
            printf("Sua pontuacao final e: %.2f pontos.\n", pontos);
            printf("------------------------------------------\n");
            
            break; // Sai do loop
        }
    
        if (chute != numeroSecreto && i == tentativas - 1) {
            printf("------------------------------------------\n");
            printf("GAME OVER! Voce esgotou suas tentativas.\n");
            printf("O numero era %d. Tente novamente!\n", numeroSecreto);
            printf("------------------------------------------\n");

            break; // Sai do loop
        }

        // Calcula os pontos perdidos com base na diferença entre o chute e o número secreto
        double pontos_perdidos = abs(chute - numeroSecreto) / (double)2;
        pontos -= pontos_perdidos;

        if (pontos < 0) {
            pontos = 0;
        }
    }

    return 0;
}