# Gerenciador de Terrenos em C

Este projeto implementa um sistema modular para gerenciamento de terrenos utilizando linguagem C.  
O código demonstra boas práticas de organização, uso de estruturas compostas, vetores dinâmicos, manipulação de arquivos e modularização apropriada para projetos de médio porte.

---

## 📌 Objetivos do Projeto

- Representar terrenos, proprietários e datas utilizando `struct`.
- Manipular vetores dinâmicos (incluindo realocação quando necessário).
- Implementar operações CRUD completas.
- Exercitar modularização em múltiplos arquivos `.c` e `.h`.
- Demonstrar técnicas adequadas de persistência em arquivos.
- Oferecer um sistema interativo em terminal com funções utilitárias robustas.

---

## 🧱 Estruturas Principais

O sistema define as seguintes estruturas:

### `data`
Representa uma data genérica.

### `pessoa`
Contém informações do proprietário:
- nome  
- cpf  
- data de nascimento  
- telefone  

### `terreno`
Informações completas de cada terreno:
- id único  
- proprietário (`pessoa`)  
- data de compra  
- largura, comprimento, área  
- preço por m²  

Essas estruturas são organizadas para permitir expansão e reutilização.

---

## 🧩 Funcionalidades Implementadas

### ✔ Gerenciamento completo de terrenos
- Criar novo terreno  
- Editar dados existentes  
- Excluir terreno  
- Exibir terreno específico  
- Mostrar todos os terrenos ordenados por ID  

### ✔ Cálculos automáticos
- Cálculo de área  
- Cálculo de valor total do terreno  
- Soma total do valor de todos os terrenos cadastrados  

### ✔ Persistência
- Salvar todos os terrenos em arquivo texto/binário  
- Carregar terrenos automaticamente na inicialização  

### ✔ Verificações e utilidades
- Detecção de IDs duplicados  
- Funções auxiliares para limpeza de buffer, pausas, animações e saída formatada  
- Contadores de terrenos ocupados e disponíveis  

---

## 📁 Estrutura do Repositório

📂 /Codes Folder
│── principal.c
│── terrenos.h
│── terrenos1.c
│── terrenos2.c 
└── README.md

Separar implementação e interface melhora clareza, testabilidade e manutenção do código.

---

## 🛠 Compilação

### Compilação simples
```bash

gcc *.c -o gerenciador

Compilação recomendada (com warnings e padrão C moderno)
gcc -Wall -Wextra -Wpedantic -std=c11 *.c -o gerenciador

Com Makefile
make

▶ Execução
./gerenciador

🔧 Principais Funções

O sistema fornece funções para:

Inicialização do vetor dinâmico:
inicializarVetor(terreno ***terrenos)

Criação:
criarTerreno(terreno **terrenos, int ids[], int *ids_count)

Deleção:
deletarTerreno(terreno ***terrenos, int ids[], int *ids_count)

Edição:
editarTerreno(terreno **terrenos, int id)

Consulta:
mostrarTerreno(terreno **terrenos, int id)

Persistência:
salvarTerrenos(terreno **terrenos, const char *nomeArquivo)
carregarTerrenos(terreno **terrenos, const char *nomeArquivo)

Utilidades gerais:
clearScreen(), pausas(), limparBuffer(), slowPrint()
