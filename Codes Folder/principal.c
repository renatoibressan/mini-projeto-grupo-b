#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terrenos.h"

int main(char *nomeArquivo) {
  clearScreen();
  printf("===== SISTEMA GERENCIADOR DE BAIRROS =====\n");
  printf("Desenvolvido por:\nAmanda Sales Alborgueti\nAryan Douglas Borges Rodrigues\nRenato Ikeda Bressan\n");
  char option = 'x';
  terreno **t;
  int i, idTeste, count;
  double valorTerreno, valorTotal;
  inicializarVetor(&t);
  while (option != '0') {
    printf("===== MENU =====\nOpcoes:\n");
    printf("A. Criar um terreno\n");
    printf("B. Deletar um terreno\n");
    printf("C. Mostrar um terreno\n");
    printf("D. Editar um terreno\n");
    printf("E. Calcular o valor de um terreno\n");
    printf("F. Contar os terrenos ocupados\n");
    printf("G. Contar os terrenos livres\n");
    printf("H. Calcular o valor de todos os terrenos\n");
    printf("I. Salvar os terrenos\n");
    printf("J. Carregar os terrenos\n");
    printf("Escolha uma das opcoes acima: ");
    option = getchar();
    getchar();
    if (option >= 'a' && option <= 'z') option -= 32;
    clearScreen();
    switch (option) {
      case 'A':
        criarTerreno(t);
        break;
      case 'B':
        deletarTerreno(&t);
        break;
      case 'C':
        printf("Insira um ID para procura do terreno: ");
        scanf("%d", &idTeste);
        mostrarTerreno(t,idTeste);
        break;
      case 'D':
        printf("Insira um ID para procura do terreno: ");
        scanf("%d", &idTeste);
        editarTerreno(t, idTeste);
        break;
      case 'E':
        printf("Insira um ID para procura do terreno: ");
        scanf("%d", &idTeste);
        valorTerreno = calcularValorTerreno(t, idTeste);
        if (valorTerreno == -1) break;
        else {
          printf("Valor do Terreno de ID %d: R$ %.2f\n", idTeste, valorTerreno);
          printf("---------------------------------------------\n");
        }
        break;
      case 'F':
        count = contarTerrenosOcupados(&t);
        printf("Terrenos Ocupados: %d\n", count);
        printf("---------------------------------------------\n");
        break;
      case 'G':
        count = contarTerrenosLivres(&t);
        printf("Terrenos Livres: %d\n", count);
        printf("---------------------------------------------\n");
        break;
      case 'H':
        valorTotal = calcularValorTotal(t);
        printf("Valor Total de todos os Terrenos: R$ %.2f\n", valorTotal);
        printf("---------------------------------------------\n");
        break;
      case 'I':
        nomeArquivo = "terrenos";
        salvarTerrenos(t, nomeArquivo);
        break;
      case 'J':
        nomeArquivo = "terrenos";
        carregarTerrenos(t, nomeArquivo);
        break;
      case '0':
        printf("Encerrando o programa...\n"); 
        break;
      default: printf("Opcao invalida! Pressione ENTER para voltar: "); getchar();
    } 
  }
  liberarTodosTerrenos(t);
  clearScreen();
  return 0;
}