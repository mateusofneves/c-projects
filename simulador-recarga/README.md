# Lógica do Código

## Visão Geral
Este projeto é um simulador de recargas desenvolvido em linguagem C. O sistema permite realizar:

- Recargas de celular
- Recargas de cartão de transporte
- Geração de relatório geral das recargas realizadas

O programa utiliza conceitos fundamentais da linguagem C, como:

- Funções
- Vetores
- Matrizes de caracteres (`strings`)
- Ponteiros
- Estruturas condicionais
- Estruturas de repetição

---

# Estrutura do Programa

O código foi dividido em funções para organizar melhor cada responsabilidade do sistema.

## Bibliotecas Utilizadas

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

### Função de cada biblioteca

- `stdio.h` → Entrada e saída de dados (`printf` e `scanf`)
- `stdlib.h` → Biblioteca padrão da linguagem C
- `string.h` → Manipulação de strings (`strcpy`)

---

# Constante do Sistema

```c
#define MAX_RECARGAS 100
```

Define o número máximo de recargas que podem ser armazenadas durante a execução do programa.

---

# Função Menu

```c
void menu()
```

Responsável por exibir o menu principal do sistema.

## Opções disponíveis

1. Recarga de celular
2. Recarga de cartão de transporte
3. Relatório geral de recargas
4. Sair

O menu é exibido continuamente dentro do loop principal do programa.

---

# Função de Recarga de Celular

```c
int recarga_celular(...)
```

Essa função realiza todo o processo de recarga de celular.

## Etapas da função

### 1. Define o tipo da recarga

```c
*tipo = 1;
```

O valor `1` representa uma recarga de celular.

---

### 2. Escolha da operadora

O usuário escolhe entre:

- Claro
- Vivo
- Tim
- Oi

O `switch` é utilizado para armazenar a operadora escolhida.

```c
switch(op)
```

A função `strcpy()` copia o nome da operadora para a variável correspondente.

---

### 3. Entrada do número do celular

```c
scanf("%s", id);
```

Armazena o número digitado pelo usuário.

---

### 4. Escolha do valor da recarga

O usuário escolhe entre valores fixos:

- R$5
- R$10
- R$20
- R$30
- R$50

O `switch` converte a opção escolhida no valor real da recarga.

---

### 5. Validação de dados

O sistema verifica:

```c
if (*valor <= 0)
```

e

```c
if (*tempo <= 0)
```

Essas validações impedem valores inválidos.

---

### 6. Tempo de recarga

O usuário informa o tempo estimado da recarga em horas.

Esse valor será usado posteriormente no cálculo energético do relatório.

---

### 7. Retorno da função

```c
return (resposta == 'S' || resposta == 's');
```

A função retorna:

- `1` → continuar no sistema
- `0` → encerrar programa

---

# Função de Recarga de Cartão de Transporte

```c
int recarga_cartao_transporte(...)
```

Possui lógica semelhante à recarga de celular.

## Diferença principal

O usuário escolhe o tipo de cartão:

- Cartão de ônibus
- Cartão de metrô
- Cartão de trem

O sistema armazena o tipo do cartão na matriz:

```c
tipos_cartao[][]
```

O tipo da recarga é definido como:

```c
*tipo = 2;
```

---

# Função Relatório

```c
void relatorio(...)
```

Responsável por exibir todas as recargas registradas no sistema.

---

# Funcionamento do Relatório

## Verificação inicial

```c
if (total == 0)
```

Caso nenhuma recarga tenha sido registrada, o sistema informa isso ao usuário.

---

## Loop das recargas

```c
for (int i = 0; i < total; i++)
```

Percorre todas as recargas armazenadas.

---

## Exibição das informações

Para cada recarga, o sistema mostra:

- Tipo da recarga
- ID (número do celular ou cartão)
- Operadora
- Tipo de cartão
- Valor da recarga
- Tempo de recarga

---

# Simulação de Consumo de Energia

O relatório também realiza cálculos técnicos simulando consumo energético.

## Potência fixa

```c
float potencia = 0.5;
```

Representa uma potência fictícia em kW.

---

## Cálculo da energia

### Fórmula

```text
Energia = Potência × Tempo
E = P × t
```

No código:

```c
float energia = potencia * tempos[i];
```

---

# Cálculo do custo energético

A tarifa simulada é:

```c
float tarifa = 0.8;
```

O custo é calculado multiplicando energia pela tarifa.

### Fórmula

```text
Custo = Energia × Tarifa
C = E × T
```

No código:

```c
float custo = energia * tarifa;
```

---

# Acumuladores Totais

O sistema soma os valores totais de energia e custo:

```c
energia_total += energia;
custo_total += custo;
```

Isso permite mostrar o consumo total de todas as recargas ao final do relatório.

---

# Função Main

```c
int main()
```

É o centro do programa.

---

# Variáveis Principais

O sistema utiliza vetores para armazenar várias recargas:

```c
tipos[]
tempos[]
ids[][]
operadoras[][]
valores[]
tipos_cartao[][]
```

Cada posição dos vetores representa uma recarga diferente.

---

# Loop Principal

```c
while (rodando)
```

Mantém o sistema funcionando até o usuário escolher sair.

---

# Controle das Opções

O `switch(opcao)` controla qual funcionalidade será executada:

- `case 1` → Recarga de celular
- `case 2` → Recarga de transporte
- `case 3` → Relatório
- `case 4` → Encerrar sistema

---

# Uso de Ponteiros

As funções utilizam ponteiros para alterar variáveis diretamente na memória.

Exemplo:

```c
int recarga_celular(int *tipo, ...)
```

Isso permite modificar os dados dentro da função sem precisar retornar múltiplos valores.

---

# Conceitos de Programação Aplicados

## Estruturas Condicionais

```c
if
else
switch
```

## Estruturas de Repetição

```c
while
for
```

## Manipulação de Strings

```c
strcpy()
```

## Vetores e Matrizes

Armazenamento das recargas realizadas.

## Ponteiros

Passagem de parâmetros por referência.

---

# Resumo Final

O projeto simula um sistema de recargas utilizando conceitos fundamentais da linguagem C.

Além do gerenciamento das recargas, o sistema também realiza uma simulação de consumo energético e custo de energia, tornando o projeto mais completo e aplicando lógica matemática dentro da programação.
