#include<stdio.h> 

void menu(){
    printf("--- SISTEMA DE NOTAS ---\n");
    printf("1 - MEDIA DO ALUNO\n");
    printf("2 - VERIFICADOR DE PRESENCA\n");
    printf("3 - SITUACAO FINAL DO ALUNO\n");
    printf("4 - SAIR DO PROGRAMA.\n");
    printf("SELECIONE UMA DAS OPCOES ACIMA: ");
}

float calcular_media(){
    
    float n1, n2, n3, n4;

    printf("\n--- CALCULAR MEDIA ---\n");
    printf("Digite as quatro notas (0-10):\n");
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);

    if (n1 >= 0 && n1 <= 10 &&
        n2 >= 0 && n2 <= 10 &&
        n3 >= 0 && n3 <= 10 &&
        n4 >= 0 && n4 <= 10){
        float media = (n1 + n2 + n3 + n4) / 4.0;
        printf("A media do aluno e: %.2f\n\n", media);
        return media; // Retorna a média calculada
    } else {
        printf("Valores invalidos, digite novamente. \n");
        return -1; // Retorna -1 para indicar que a média não foi calculada devido a valores inválidos
    
    }
}

int verificar_presenca(char nome[50]){
    int presenca;

    printf("\n--- VERIFICADOR DE PRESENCA ---\n");
    printf("Digite o nome do aluno: ");
    scanf("%s", nome);
    printf("Digite a presenca do aluno (0-100): ");
    scanf("%d", &presenca);

    if (presenca >= 75 && presenca <= 100){
        printf("O aluno %s nao esta pendente. Percentual de %d%%.\n\n", nome, presenca);
    } else if (presenca >= 0 && presenca < 75){
        printf("O aluno %s esta pendente. Percentual de %d%%\n\n", nome, presenca);
    } else {
        printf("Valor de presenca invalido.\n\n");
        return -1; // Retorna -1 para indicar que a presença não foi verificada devido a um valor inválido
    }

    return presenca;

}

void situacao_final(char nome[50], float media, int presenca){
    printf("\n--- SITUACAO FINAL ---\n");

    if (media >= 6 && presenca >= 75){
        printf("O aluno %s esta aprovado.\n\n", nome);
    } else {
        printf("O aluno %s esta reprovado.\n\n", nome);
    }
}

int main(){

    int opcao = 0;
    int presenca;
    float media;
    char nome[50];


while (opcao != 4){
    menu();
    scanf("%d", &opcao);

    
    switch(opcao){

        case 1: 
        media = calcular_media();
        break;

        case 2:
        presenca = verificar_presenca(nome);
        break;

        case 3:
        situacao_final(nome, media, presenca);
        break;

        case 4:
        printf("Programa finalizado.\n");
        break;

        default: 
        printf("Opcao Invalida!\n");
        break;    
    
        }
    }

    return 0;
}