#ifndef SISTEMA_H
#define SISTEMA_H

#define MAX_MISSOES 100

// variaveis globais
extern float temperatura;
extern float energia;
extern int comunicacao;

extern float temperaturas[MAX_MISSOES];
extern float energias[MAX_MISSOES];
extern int comunicacoes[MAX_MISSOES];

extern int total_missoes;

// prototipos
void menu();
void inserirDados();
void visualizarStatus();
void analisarSistema();
void mostrarHistorico();
void pausarSistema();

#endif