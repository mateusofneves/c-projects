#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int uint;
typedef unsigned long ulong;

typedef struct 
{
    char rua[50];
    char bairro[50];
    char cidade[50];
    uint numero;
} Endereco;

typedef struct 
{
    uint rm;
    char nome[50];
    float nota[3];
    bool aprovacao;
    
    Endereco endereco;
} Aluno;

int main()
{
    Aluno aluno[40];
    
    // declaração (escrita)
    aluno[0].rm = 12345;
    strcpy(aluno[0].nome, "João Silva");
    
    strcpy(aluno[0].endereco.rua, "Rua 15");
    strcpy(aluno[0].endereco.bairro, "Paulista");
    strcpy(aluno[0].endereco.cidade, "São Paulo");
    aluno[0].endereco.numero = 123;
    
    aluno[0].nota[0] = 4;
    aluno[0].nota[1] = 7;
    aluno[0].nota[2] = 6;
    
    ulong tamanho = sizeof(aluno[0].nota)/sizeof(aluno[0].nota[0]);
    
    float media = (float)(
        aluno[0].nota[0] + 
        aluno[0].nota[1] + 
        aluno[0].nota[2]
        ) 
        / tamanho;
    
    // condicao para aprovacao em media
    if (media >= 6)
    {
        aluno[0].aprovacao = true;
    }
    else if (media >= 4)
    {
        printf("Você está de exame, digite suas novas notas.\n\n");
        
        aluno[0].nota[0] = 10;
        aluno[0].nota[1] = 8;
        aluno[0].nota[2] = 9;
    
        ulong tamanho = sizeof(aluno[0].nota)/sizeof(aluno[0].nota[0]);
    
        float exame = (float)(
            aluno[0].nota[0] + 
            aluno[0].nota[1] + 
            aluno[0].nota[2]
            ) 
            / tamanho;
        
        if (exame > 5) 
        {
            aluno[0].aprovacao = true;
        } 
        else
        {
            aluno[0].aprovacao = false;
        }
    }
    else
    {
        aluno[0].aprovacao = false;
    }
    
    // verificacao de aluno aprovado ou nao
    if (aluno[0].aprovacao == true)
    {
        printf("Aluno aprovado!\n\n");
    }
    else if (aluno[0].aprovacao == false)
    {
        printf("Aluno reprovado!\n\n"); 
    }
    else 
    {
        printf("Condição não reconhecida!\n\n");
    }
    
    // acesso (leitura)
    printf("Nome: %s\n", aluno[0].nome);
    printf("RM: %d\n", aluno[0].rm);
    printf("Média: %.2f\n", media);
    
    printf("\n");
    
    printf("Cidade: %s\n", aluno[0].endereco.cidade);
    printf("Bairro: %s\n", aluno[0].endereco.bairro);
    printf("Rua: %s\n", aluno[0].endereco.rua);
    printf("Numero: %d\n", aluno[0].endereco.numero);
    
    return 0;
}
