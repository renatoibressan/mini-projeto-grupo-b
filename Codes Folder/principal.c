#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terrenos.h"

int main(char *nomeArquivo) {
  clearScreen();
  slowPrint("===== SISTEMA GERENCIADOR DE BAIRROS =====\n", 50);
  slowPrint("Desenvolvido por:\nAmanda Sales Alborgueti\nAryan Douglas Borges Rodrigues\nRenato Ikeda Bressan\n", 100);
  char option = 'x';
  terreno **t;
  int i, idTeste, count;
  double valorTerreno, valorTotal;
  inicializarVetor(&t);
  clearScreen();
  while (option != '0') {
    slowPrint("===== MENU =====\nOpcoes:\n", 50);
    slowPrint("A. Criar um terreno\n", 25);
    slowPrint("B. Deletar um terreno\n", 25);
    slowPrint("C. Mostrar um terreno\n", 25);
    slowPrint("D. Editar um terreno\n", 25);
    slowPrint("E. Calcular o valor de um terreno\n", 25);
    slowPrint("F. Contar os terrenos ocupados\n", 25);
    slowPrint("G. Contar os terrenos livres\n", 25);
    slowPrint("H. Calcular o valor de todos os terrenos\n", 25);
    slowPrint("I. Salvar os terrenos\n", 25);
    slowPrint("J. Carregar os terrenos\n", 25);
    slowPrint("0. Encerrar o programa.\n", 25);
    slowPrint("Escolha uma das opcoes acima: ", 50);
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
        if (*t == NULL) {
          slowPrint("Nao ha terrenos para mostrar!\n", 50);
          slowPrint("---------------------------------------------\n", 25);
          break;
        } else {
          printf("Insira um ID para procura do terreno: ");
          scanf("%d", &idTeste);
          mostrarTerreno(t, idTeste);
        }
        break;
      case 'D':
        if (*t == NULL) {
          slowPrint("Nao ha terrenos para editar!\n", 50);
          slowPrint("---------------------------------------------\n", 25);
          break;
        } else {
          printf("Insira um ID para procura do terreno: ");
          scanf("%d", &idTeste);
          editarTerreno(t, idTeste);
        }
        break;
      case 'E':
        if (*t == NULL) {
          slowPrint("Nao ha terrenos para calcular o valor!\n", 50);
          slowPrint("---------------------------------------------\n", 25);
          break;
        } else {
          printf("Insira um ID para procura do terreno: ");
          scanf("%d", &idTeste);
          valorTerreno = calcularValorTerreno(t, idTeste);
          if (valorTerreno == -1) break;
          else {
            printf("Valor do Terreno de ID %d: R$ %.2f\n", idTeste, valorTerreno);
            slowPrint("---------------------------------------------\n", 25);
          }
        }
        break;
      case 'F':
        count = contarTerrenosOcupados(&t);
        printf("Terrenos Ocupados: %d\n", count);
        slowPrint("---------------------------------------------\n", 25);
        break;
      case 'G':
        count = contarTerrenosLivres(&t);
        printf("Terrenos Livres: %d\n", count);
        slowPrint("---------------------------------------------\n", 25);
        break;
      case 'H':
        valorTotal = calcularValorTotal(t);
        printf("Valor Total de todos os Terrenos: R$ %.2f\n", valorTotal);
        slowPrint("---------------------------------------------\n", 25);
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
        slowPrint("Encerrando o programa...\n", 50); 
        break;
      default: printf("Opcao invalida! Pressione ENTER para voltar: "); getchar();
    } 
  }
  liberarTodosTerrenos(t);
  clearScreen();
  return 0;
}