# Sistema de Monitoramento Espacial 

Projeto desenvolvido em linguagem C para monitoramento básico de uma missão espacial experimental.

O sistema realiza:
- cadastro de informações da missão;
- análise automática das condições da nave;
- verificação de falhas;
- armazenamento de histórico das leituras.

---

# Funcionalidades

✅ Inserção de dados da missão  
✅ Monitoramento de temperatura  
✅ Controle de energia  
✅ Verificação da comunicação  
✅ Análise automática da missão  
✅ Histórico das leituras  
✅ Menu interativo utilizando `switch()`  
✅ Organização modular do código  

---

# Tecnologias Utilizadas

- Linguagem C
- GCC
- Terminal/Console

---

# Estrutura do Projeto

```text
missao_espacial/
│
├── main.c
│
├── .gitignore
│
├── fluxograma/
│   └── fluxograma_missao.drawio.png
│
├── includes/
│   └── sistema.h
│
├── src/
│   └── sistema.c
│
└── README.md
```

---

# Como Executar

## Compilar o projeto

No terminal, execute:

```bash
gcc main.c src/sistema.c -o sistema.exe
```

---

## Executar o programa

Depois da compilação:

```bash
./sistema.exe
```

---

# Regras do Sistema

O programa executa alertas automáticos para:

| Condição | Resposta |
|---|---|
| Temperatura > 80 | Alerta de superaquecimento |
| Energia < 20 | Economia de energia |
| Comunicação = 0 | Falha de comunicação |

---

# Conceitos Utilizados

O projeto utiliza conceitos fundamentais de programação em C:

- Variáveis globais
- Vetores
- Estruturas condicionais
- Estruturas de repetição
- Funções
- Modularização
- Arquivos `.h`
- Separação de código em múltiplos arquivos

---

# Integrantes

| Integrantes | RM |
|---|---|
| Mateus de Oliveira Fernandes Neves | 572431
| Marcelo do Nascimento Batista Pereira | 569410
| Nathan Hiroshi Watanabe | 572806

---

# Demonstração

O sistema permite:
1. Inserir dados da missão;
2. Visualizar status atual;
3. Executar análise automática;
4. Visualizar histórico completo das missões.
