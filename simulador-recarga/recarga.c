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
int recarga_celular(int *tipo, char id[], float *valor, int *tempo, char operadora[]) {
    
    *tipo = 1;

    printf("\n");

    printf("Escolha sua operadora: \n");
    printf("1. Claro\n");
    printf("2. Vivo\n");
    printf("3. Tim\n");
    printf("4. Oi\n");
    int op;
    printf("Opcao: ");
    scanf("%d", &op);

    switch(op) {
    case 1:
        strcpy(operadora, "Claro");
        break;
    case 2:
        strcpy(operadora, "Vivo");
        break;
    case 3:
        strcpy(operadora, "Tim");
        break;
    case 4:
        strcpy(operadora, "Oi");
        break;
    default:
        printf("Operadora invalida.\n");
        return 1;
    }

    printf("Digite o numero do celular: ");
    scanf("%s", id);

    printf("Escolha o valor da recarga: \n");
    printf("1. R$5\n");
    printf("2. R$10\n");
    printf("3. R$20\n");
    printf("4. R$30\n");
    printf("5. R$50\n");
    int op_valor;
    printf("Opcao: ");
    scanf("%d", &op_valor);

    switch(op_valor) {
        case 1: *valor = 5; break;
        case 2: *valor = 10; break;
        case 3: *valor = 20; break;
        case 4: *valor = 30; break;
        case 5: *valor = 50; break;
        default:
            printf("Valor invalido.\n");
            return 1;
    }

    if (*valor <= 0) {
        printf("Valor de recarga invalido. A recarga nao foi realizada.\n");
        return 1; // Retorna 1 para indicar que a recarga não foi realizada devido a um valor inválido
    }

    printf("Digite o tempo de recarga (em horas): ");
    scanf("%d", tempo);

    if (*tempo <= 0) {
        printf("Tempo de recarga invalido. A recarga nao foi realizada.\n");
        return 1; // Retorna 1 para indicar que a recarga não foi realizada devido a um tempo inválido
    }

    printf("Recarga de R$%.2f para o numero %s realizada com sucesso!\n", *valor, id);

    printf("Deseja voltar ao menu? (S/N): ");
    char resposta;
    scanf(" %c", &resposta);

    return (resposta == 'S' || resposta == 's');
}

// ===== RECARGA TRANSPORTE =====
int recarga_cartao_transporte(int *tipo, char id[], float *valor, int *tempo, char tipos_cartao[][20], int total) {
    
    *tipo = 2;

    printf("\n");

    printf("Escolha o tipo do cartao de transporte: \n");
    printf("1. Cartao de onibus\n");
    printf("2. Cartao de metro\n");
    printf("3. Cartao de trem\n");
    int op_cartao;
    printf("Opcao: ");
    scanf("%d", &op_cartao);

    switch(op_cartao) {
        case 1: strcpy(tipos_cartao[total], "Cartao de onibus"); break;
        case 2: strcpy(tipos_cartao[total], "Cartao de metro"); break;
        case 3: strcpy(tipos_cartao[total], "Cartao de trem"); break;
        default: 
            printf("Tipo de cartao invalido.\n"); 
            return 1;
    }

    printf("Digite o numero do cartao: ");
    scanf("%s", id);

    printf("Escolha o valor da recarga: \n");
    printf("1. R$5\n");
    printf("2. R$10\n");
    printf("3. R$20\n");
    printf("4. R$30\n");
    printf("5. R$50\n");
    int op_valor;
    printf("Opcao: ");
    scanf("%d", &op_valor);

    switch(op_valor) {
        case 1: *valor = 5; break;
        case 2: *valor = 10; break;
        case 3: *valor = 20; break;
        case 4: *valor = 30; break;
        case 5: *valor = 50; break;
        default:
            printf("Valor invalido.\n");
            return 1;
    }

    if (*valor <= 0) {
        printf("Valor de recarga invalido. A recarga nao foi realizada.\n");
        return 1; // Retorna 1 para indicar que a recarga não foi realizada devido a um valor inválido
    }

    printf("Digite o tempo de recarga (em horas): ");
    scanf("%d", tempo);

    if (*tempo <= 0) {
        printf("Tempo de recarga invalido. A recarga nao foi realizada.\n");
        return 1; // Retorna 1 para indicar que a recarga não foi realizada devido a um tempo inválido
    }

    printf("Recarga de R$%.2f para o cartao %s realizada com sucesso!\n", *valor, id);

    printf("Deseja voltar ao menu? (S/N): ");
    char resposta;
    scanf(" %c", &resposta);

    return (resposta == 'S' || resposta == 's');
}

// ===== RELATÓRIO =====
void relatorio(int tipos[], char ids[][20], char operadoras[][20], float valores[], int tempos[], char tipos_cartao[][20], int total) {
    
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
        printf("Operadora: %s\n", (tipos[i] == 1) ? operadoras[i] : "N/A"); // Exibe a operadora apenas para recargas de celular
        printf("Tipo de Cartao: %s\n", (tipos[i] == 2) ? tipos_cartao[i] : "N/A"); // Exibe o tipo de cartão apenas para recargas de cartão de transporte
        printf("Valor: R$%.2f\n", valores[i]);

        float potencia = 0.5; // Simulação de potência para cálculo de energia
        float tarifa = 0.8; // Simulação de tarifa para cálculo de custo (quanto custa 1 kwh)
        float energia = potencia * tempos[i]; // Cálculo de energia com base na potência e tempo
        float custo = energia * tarifa; // Cálculo de custo com base na energia consumida

        energia_total += energia; // Acumula a energia total
        custo_total += custo; // Acumula o custo total

        printf("\n--- DETALHES TECNICOS ---\n");
        printf("Tempo: %d horas\n", tempos[i]);
        printf("Potencia: %.2f kW\n", potencia);
        printf("Energia: %.2f kWh\n", energia);

        printf("\n--- CUSTOS ---\n");
        printf("Tarifa: R$ %.2f/kWh\n", tarifa);
        printf("Custo energia consumida: R$ %.2f\n", custo);

        printf("===============================");

    }

    printf("\n--- Total Geral ---\n");
    printf("Energia total: %.2f kWh\n", energia_total);
    printf("Custo energia consumida: R$ %.2f\n", custo_total);
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
    char operadoras[MAX_RECARGAS][20];
    float valores[MAX_RECARGAS];
    char tipos_cartao[MAX_RECARGAS][20];

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
                continuar = recarga_celular(&tipo, id, &valor, &tempo, operadoras[total_recargas]);
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
                continuar = recarga_cartao_transporte(&tipo, id, &valor, &tempo, tipos_cartao, total_recargas);
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
                relatorio(tipos, ids, operadoras, valores, tempos, tipos_cartao, total_recargas);
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
