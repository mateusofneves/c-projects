#include <stdio.h>
#include <stdlib.h>
#include "../includes/sistema.h"

// variaveis globais
float temperatura = 0;
float energia = 0;
int comunicacao = 1;

float temperaturas[MAX_MISSOES];
float energias[MAX_MISSOES];
int comunicacoes[MAX_MISSOES];

int total_missoes = 0;

// menu
void menu() {

    system("cls");

    printf("\n=====================================\n");
    printf("  SISTEMA DE MONITORAMENTO ESPACIAL\n");
    printf("=====================================\n");
    printf("1 - Inserir dados da missao\n");
    printf("2 - Visualizar status atual\n");
    printf("3 - Executar analise automatica\n");
    printf("4 - Mostrar historico\n");
    printf("0 - Encerrar sistema\n");
    printf("=====================================\n");
    printf("Escolha uma opcao: ");
}

// inserir dados
void inserirDados() {

    printf("\n--- INSERIR DADOS DA MISSAO ---\n");

    printf("Digite a temperatura da nave: ");
    scanf("%f", &temperatura);

    do {

    printf("Digite a porcentagem de energia (0 a 100): ");
    scanf("%f", &energia);

    if (energia < 0 || energia > 100) {

        printf("\nValor invalido! Digite entre 0 e 100.\n\n");
    }

} while (energia < 0 || energia > 100);

    do {

    printf("Status da comunicacao (1 = OK / 0 = FALHA): ");
    scanf("%d", &comunicacao);

    if (comunicacao != 0 && comunicacao != 1) {

        printf("\nValor invalido! Digite apenas 0 ou 1.\n\n");
    }

} while (comunicacao != 0 && comunicacao != 1);

    if (total_missoes < MAX_MISSOES) {

        temperaturas[total_missoes] = temperatura;
        energias[total_missoes] = energia;
        comunicacoes[total_missoes] = comunicacao;

        total_missoes++;
    }

    printf("\nDados cadastrados com sucesso!\n");
}

// visualizar status
void visualizarStatus() {

    if (total_missoes == 0) {

        printf("\nNenhuma missao cadastrada.\n");
        return;
    }

    printf("\n--- STATUS ATUAL DA MISSAO ---\n");

    printf("Temperatura: %.2f C\n", temperatura);
    printf("Energia: %.2f%%\n", energia);

    if (comunicacao == 1) {
        printf("Comunicacao: OPERANDO\n");
    } else {
        printf("Comunicacao: FALHA\n");
    }
}

// analise
void analisarSistema() {

    if (total_missoes == 0) {

        printf("\nNenhuma missao cadastrada.\n");
        return;
    }

    printf("\n--- ANALISE AUTOMATICA ---\n");

    if (temperatura > 80) {
        printf("ALERTA: Superaquecimento detectado!\n");
    } else {
        printf("Temperatura dentro do normal.\n");
    }

    if (energia < 20) {
        printf("ALERTA: Economia de energia ativada!\n");
    } else {
        printf("Energia em nivel seguro.\n");
    }

    if (comunicacao == 0) {
        printf("ALERTA: Falha de comunicacao!\n");
    } else {
        printf("Comunicacao funcionando corretamente.\n");
    }

    if (temperatura <= 80 && energia >= 20 && comunicacao == 1) {

        printf("\nSTATUS GERAL: MISSAO OPERANDO NORMALMENTE.\n");

    } else {

        printf("\nSTATUS GERAL: MISSAO EM ESTADO DE ALERTA.\n");
    }
}

// historico
void mostrarHistorico() {

    int i;

    printf("\n--- HISTORICO DAS MISSOES ---\n");

    if (total_missoes == 0) {

        printf("Nenhuma missao cadastrada.\n");
        return;
    }

    for (i = 0; i < total_missoes; i++) {

        printf("\n=====================================\n");
        printf("MISSAO %d\n", i + 1);
        printf("=====================================\n");

        printf("Temperatura: %.2f C\n", temperaturas[i]);
        printf("Energia: %.2f%%\n", energias[i]);

        if (comunicacoes[i] == 1) {
            printf("Comunicacao: OPERANDO\n");
        } else {
            printf("Comunicacao: FALHA\n");
        }
    }
}

// pausar sistema
void pausarSistema() {

    printf("\n");
    system("pause");
}