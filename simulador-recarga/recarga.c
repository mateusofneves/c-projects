#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECARGAS 100

// ===== MENU =====
void menu () {
    printf("\nBem-vindo ao simulador de recarga!\n");
    printf("1. Recarga de celular\n");
    printf("2. Recarga de cartao de transporte\n");
    printf("3. Relatorio geral de recargas\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");

}

// ===== RECARGA CELULAR =====
int recarga_celular(int *tipo, char id[], float *valor, int *tempo) {
    *tipo = 1;

    printf("Digite o numero do celular: ");
    scanf("%s", id);

    printf("Digite o valor da recarga: ");
    scanf("%f", valor);

    printf("Digite o tempo de recarga (em horas): ");
    scanf("%d", tempo);

    if (*valor <= 0) {
        printf("Valor de recarga invalido. A recarga nao foi realizada.\n");
        return 1; // Retorna 1 para indicar que a recarga não foi realizada devido a um valor inválido
    }

    if (*tempo <= 0) {
        printf("Tempo de recarga invalido. A recarga nao foi realizada.\n");
        return 1; // Retorna 1 para indicar que a recarga não foi realizada devido a um tempo inválido
    }

    printf("Recarga de R$%.2f para o numero %s realizada com sucesso!\n", *valor, id);

    printf("Deseja realizar outra recarga? (S/N): ");
    char resposta;
    scanf(" %c", &resposta);

    return (resposta == 'S' || resposta == 's');
}

// ===== RECARGA TRANSPORTE =====
int recarga_cartao_transporte(int *tipo, char id[], float *valor, int *tempo) {
    *tipo = 2;

    printf("Digite o numero do cartao: ");
    scanf("%s", id);

    printf("Digite o valor da recarga: ");
    scanf("%f", valor);

    printf("Digite o tempo de recarga (em horas): ");
    scanf("%d", tempo);

    if (*valor <= 0) {
        printf("Valor de recarga invalido. A recarga nao foi realizada.\n");
        return 1; // Retorna 1 para indicar que a recarga não foi realizada devido a um valor inválido
    }

    if (*tempo <= 0) {
        printf("Tempo de recarga invalido. A recarga nao foi realizada.\n");
        return 1; // Retorna 1 para indicar que a recarga não foi realizada devido a um tempo inválido
    }

    printf("Recarga de R$%.2f para o cartao %s realizada com sucesso!\n", *valor, id);

    printf("Deseja realizar outra recarga? (S/N): ");
    char resposta;
    scanf(" %c", &resposta);

    return (resposta == 'S' || resposta == 's');
}

// ===== RELATÓRIO =====
void relatorio(int tipos[MAX_RECARGAS], char ids[][20], float valores[], int tempos[], int total) {
    
    if (total == 0) {
        printf("\nNenhuma recarga foi registrada ainda.\n");
        return; // Retorna para o menu se não houver recargas para relatar
    }

    float energia_total = 0;
    float custo_total = 0;

    for (int i = 0; i < total; i++) {
        printf("\n========== RECARGA %d ==========\n", i + 1);

        if (tipos[i] == 1) {
            printf("Tipo: Recarga de Celular\n");
        } else if (tipos[i] == 2) {
            printf("Tipo: Recarga de Cartao de Transporte\n");
        }

        printf("ID: %s\n", ids[i]);
        printf("Valor: R$%.2f\n", valores[i]);

        float potencia = 0.5; // Simulação de potência para cálculo de energia
        float energia = potencia * tempos[i]; // Cálculo de energia com base na potência e tempo
        float tarifa = 0.8; // Simulação de tarifa para cálculo de custo
        float custo = energia * tarifa; // Cálculo de custo com base na energia consumida

        energia_total += energia; // Acumula a energia total
        custo_total += custo; // Acumula o custo total

        printf("\n--- DETALHES TECNICOS ---\n");
        printf("Tempo: %d horas\n", tempos[i]);
        printf("Potencia: %.2f kW\n", potencia);
        printf("Energia: %.2f kWh\n", energia);

        printf("\n--- CUSTOS ---\n");
        printf("Tarifa: R$ %.2f/kWh\n", tarifa);
        printf("Custo total: R$ %.2f\n", custo);

        printf("===============================\n");

    }

    printf("\n--- Total Geral ---\n");
    printf("Energia total: %.2f kWh\n", energia_total);
    printf("Custo total: R$ %.2f\n", custo_total);
}

// ===== MAIN =====
int main() {

    // Variáveis para armazenar os dados da última recarga
    int opcao;
    int rodando = 1;
    int continuar;

    // Variáveis da "sessão"
    int tipos[MAX_RECARGAS];
    int tempos[MAX_RECARGAS];
    char ids[MAX_RECARGAS][20];
    float valores[MAX_RECARGAS];

    int total_recargas = 0;

    // Variáveis para a última recarga
    int tipo;
    char id[20];
    float valor;
    int tempo;

    // Loop principal do programa
    while (rodando) {

        menu();
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                continuar = recarga_celular(&tipo, id, &valor, &tempo);
                if (valor > 0 && tempo > 0 && total_recargas < MAX_RECARGAS) {

                tipos[total_recargas] = tipo;
                tempos[total_recargas] = tempo;
                strcpy(ids[total_recargas], id);
                valores[total_recargas] = valor;

                total_recargas++;

                } else {
                    printf("\nLimite de recargas atingido!\n");
                }

                if (!continuar) rodando = 0;
                break;

            case 2:
                continuar = recarga_cartao_transporte(&tipo, id, &valor, &tempo);
                if (valor > 0 && tempo > 0 && total_recargas < MAX_RECARGAS) {

                    tipos[total_recargas] = tipo;
                    tempos[total_recargas] = tempo;
                    strcpy(ids[total_recargas], id);
                    valores[total_recargas] = valor;
                    
                    total_recargas++;
                } else {
                    printf("\nLimite de recargas atingido!\n");
                }

                if (!continuar) rodando = 0;
                break;

            case 3:
                relatorio(tipos, ids, valores, tempos, total_recargas);
                break;
                
            case 4:
                printf("Obrigado por usar o simulador!\n");
                rodando = 0;
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    }

    return 0;
}