#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terrenos.h"

int main(int argc, char *argv[]) {
  clearScreen();
  slowPrint("===== SISTEMA GERENCIADOR DE BAIRROS =====\n", 60);
  slowPrint("Desenvolvido por:\nAmanda Sales Alborgueti\nAryan Douglas Borges Rodrigues\nRenato Ikeda Bressan\n    ", 80);
  terreno **t;
  char option = 'x';
  int c, idTeste, count, checkup = 0;
  double valorTerreno, valorTotal;
  int ids[100], ids_count = 0;
  const char *nomeArquivo = "terrenos_padrao.txt";
  if (argc > 1) nomeArquivo = argv[1];
  clearScreen();
  inicializarVetor(&t);
  while (option != '0') {
    slowPrint("===== MENU =====\nOpcoes:\n", 50);
    slowPrint("A. Criar um terreno\n", 25);
    slowPrint("B. Deletar os terrenos\n", 25);
    slowPrint("C. Mostrar um terreno\n", 25);
    slowPrint("D. Editar um terreno\n", 25);
    slowPrint("E. Calcular o valor de um terreno\n", 25);
    slowPrint("F. Contar os terrenos ocupados\n", 25);
    slowPrint("G. Contar os terrenos livres\n", 25);
    slowPrint("H. Calcular o valor de todos os terrenos\n", 25);
    slowPrint("I. Salvar os terrenos\n", 25);
    slowPrint("J. Carregar os terrenos\n", 25);
    slowPrint("0. Encerrar o programa\n", 25);
    slowPrint("Escolha uma das opcoes acima: ", 50);
    option = getchar();
    while ((c = getchar()) != '\n' && c != EOF) {}
    clearScreen();
    switch (option) {
      case 'A':
      case 'a':
        if (checkup == 0) inicializarVetor(&t);
        criarTerreno(t, ids, &ids_count);
        checkup = 1;
        break;
      case 'B':
      case 'b':
        deletarTerreno(&t, ids, &ids_count);
        checkup = 0;
        break;
      case 'C':
      case 'c':
        if (*t == NULL) {
          slowPrint("Nao ha terrenos para mostrar!\n", 50);
          slowPrint("---------------------------------------------\n", 25);
          break;
        } else {
          printf("Insira um ID para procura do terreno: ");
          scanf("%d", &idTeste);
          limparBuffer();
          mostrarTerreno(t, idTeste);
        }
        break;
      case 'D':
      case 'd':
        if (*t == NULL) {
          slowPrint("Nao ha terrenos para editar!\n", 50);
          slowPrint("---------------------------------------------\n", 25);
          break;
        } else {
          printf("Insira um ID para procura do terreno: ");
          scanf("%d", &idTeste);
          limparBuffer();
          editarTerreno(t, idTeste);
        }
        break;
      case 'E':
      case 'e':
        if (*t == NULL) {
          slowPrint("Nao ha terrenos para calcular o valor!\n", 50);
          slowPrint("---------------------------------------------\n", 25);
          break;
        } else {
          printf("Insira um ID para procura do terreno: ");
          scanf("%d", &idTeste);
          limparBuffer();
          valorTerreno = calcularValorTerreno(t, idTeste);
          if (valorTerreno == -1) break;
          else {
            printf("Valor do Terreno de ID %d: R$ %.2f\n", idTeste, valorTerreno);
            slowPrint("---------------------------------------------\n", 25);
          }
        }
        break;
      case 'F':
      case 'f':
        count = contarTerrenosOcupados(&t);
        printf("Terrenos Ocupados: %d\n", count);
        slowPrint("---------------------------------------------\n", 25);
        break;
      case 'G':
      case 'g':
        count = contarTerrenosLivres(&t);
        printf("Terrenos Livres: %d\n", count);
        slowPrint("---------------------------------------------\n", 25);
        break;
      case 'H':
      case 'h':
        valorTotal = calcularValorTotal(t);
        printf("Valor Total de todos os Terrenos: R$ %.2f\n", valorTotal);
        slowPrint("---------------------------------------------\n", 25);
        break;
      case 'I':
      case 'i':
        salvarTerrenos(t, nomeArquivo);
        break;
      case 'J':
      case 'j':
        carregarTerrenos(t, nomeArquivo);
        break;
      case '0':
        slowPrint("Encerrando o programa...\n", 75);
        break;
      default: printf("Opcao invalida! Pressione ENTER para voltar:\n"); getchar();
    } 
  }
  liberarTodosTerrenos(t);
  clearScreen();
  return 0;
}