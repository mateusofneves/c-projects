# Simulador de Sessão de Recarga em C

Este projeto consiste no desenvolvimento de um simulador de sessões de recarga utilizando a linguagem C.  
O sistema é executado via terminal e permite ao usuário realizar recargas, registrar dados e visualizar relatórios.

A aplicação simula aspectos básicos de um sistema real, incluindo controle de energia, tempo de uso e cálculo de custos.

---

## Objetivo

O sistema foi desenvolvido para:

- Simular o início e o fim de sessões de recarga  
- Controlar o consumo de energia de forma simplificada  
- Registrar múltiplas recargas  
- Aplicar regras básicas de tarifação  
- Exibir relatórios detalhados  

---

## Estrutura do Programa

O código foi organizado em funções para melhor legibilidade e manutenção.

### Menu Principal

O menu permite ao usuário escolher entre:

- Recarga de celular  
- Recarga de cartão de transporte  
- Relatório geral de recargas  
- Sair do programa  

---

### Funções de Recarga

#### Recarga de celular  
#### Recarga de cartão de transporte  

Ambas seguem a mesma lógica:

- Recebem dados do usuário (ID, valor e tempo)  
- Validam os dados inseridos  
- Executam a recarga (simulação)  
- Perguntam se o usuário deseja continuar  

#### Validações:
- Valor da recarga deve ser maior que zero  
- Tempo de recarga deve ser maior que zero  

---

## Armazenamento de Dados

O sistema utiliza arrays para armazenar múltiplas recargas:

- Tipo da recarga  
- Identificador (número ou cartão)  
- Valor inserido  
- Tempo de recarga  

```c
#define MAX_RECARGAS 100
