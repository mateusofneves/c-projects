#include <stdio.h>
#include <locale.h>
#include <windows.h>

void soma(int* num, int a, int b) {
    *num = a + b;

}

int main() {

    /*
    Para aceitar acentos e caracteres especiais usa a biblioteca <locale.h> e o comando abaixo.
    Se estiver UTF-8, tente clicar e mudar para Reopen with Encoding -> Western (Windows 1252).
    Forçar via Terminal: Você pode adicionar uma biblioteca específica do Windows no topo do código:
    #include <windows.h>
    ... dentro da main:
    */

    SetConsoleOutputCP(65001); // Força o terminal a usar UTF-8
    setlocale(LC_ALL, "Portuguese");

    int num;
    int a;
    int b;

    printf("Digite o primeiro nÃºmero para calcular a soma. ");
    scanf("%d", &a);
    printf("Digite o segundo nÃºmero para calcular a soma. ");
    scanf("%d", &b);

    soma(&num, a, b);

    printf("O resultado da soma Ã© %d", num);

    return 0;
}