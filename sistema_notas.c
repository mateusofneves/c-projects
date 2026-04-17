#include<stdio.h> 

void menu(){
    printf("--- MENU ---\n");
    printf("1 - MEDIA DO ALUNO\n");
    printf("2 - VERIFICADOR DE PRESENCA\n");
    printf("3 - SAIR DO PROGRAMA.\n");
    printf("SELECIONE UMA DAS OPCOES ACIMA: ");
}

int main(){

    int opcao;
    int n1, n2, n3, n4;
    int presenca;
    char nome[50];

    menu();
    scanf("%d", &opcao);
    
    switch(opcao){

        case 1: 
        printf("\n--- CALCULAR MEDIA ---\n");
        printf("Digite a primeira nota. ");
        scanf("%d", &n1);
        printf("Digite a segunda nota. ");
        scanf("%d", &n2);
        printf("Digite a terceira nota. ");
        scanf("%d", &n3);
        printf("Digite a quarta nota. ");
        scanf("%d", &n4);

        if (n1, n2, n3, n4 >= 0 && n1, n2, n3, n4 <= 10){
            int media = (n1 + n2 + n3 + n4) / 4;
            printf("A media do aluno e: %d", media);
        } else {
            printf("Valores invalidos, digite novamente. ");
            
        }
            
        break;

        case 2:
        printf("\n--- VERIFICADOR DE PRESENCA ---\n");
        printf("Digite a presenca do aluno (0-100): ");
        scanf("%d", &presenca);

        if (presenca >= 75 && presenca <= 100){
            printf("O aluno nao esta pendente. Percentual de %d%%.", presenca);
        } else if (presenca >= 0 && presenca < 75){
            printf("O aluno esta pendente. Percentual de %d%%", presenca);
        } else {
            printf("Valor de presenca invalido.");
        }

        break;

        case 3:
        printf("Programa finalizado.");
        break;

        default: 
            printf("Opcao Invalida!");
            break;    
        
    }

    return 0;
}

// compilar no terminal: gcc (nome com a extensão, switch_case.c) -o programa
// rodar no terminal:  digitar o do executavel, programa ou programa.exe
