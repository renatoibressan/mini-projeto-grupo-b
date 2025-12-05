#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terrenos.h"

int main(const char *nomeArquivo) {
  int option = -1;
  terreno **t;
  int i;
  inicializarVetor(t);
  while (option != 0) {
    option = -1;
    clearScreen();
    printf("===== SISTEMA GERENCIADOR DE BAIRROS =====\n");
    printf("Desenvolvido por:\nAmanda Sales Alborgueti\nAryan Douglas Borges Rodrigues\nRenato Ikeda Bressan\n");
    printf("===== MENU =====\nOpcoes:\n");
    printf("1. Criar um terreno\n");
    printf("2. Deletar um terreno\n");
    printf("3. Mostrar um terreno\n");
    printf("4. Editar um terreno\n");
    printf("5. Calcular o valor de um terreno\n");
    printf("6. Contar os terrenos ocupados\n");
    printf("7. Contar os terrenos livres\n");
    printf("8. Calcular o valor de todos os terrenos\n");
    printf("9. Salvar os terrenos\n");
    printf("10. Carregar os terrenos\n");
    printf("Escolha uma das opcoes acima: ");
    scanf("%d", &option);
    switch (option) {
      case 1: funcao2(); break;
      case 2: funcao3(); break;
      case 3: funcao4(); break;
      case 4: funcao5(); break;
      case 5: funcao6(); break;
      case 6: funcao7(); break;
      case 7: funcao8(); break;
      case 8: funcao9(); break;
      case 9: funcao10(); break;
      case 10: funcao11(); break;
      case 0: printf("Encerrando o programa...\n"); break;
      default: printf("Opcao invalida!\nPor favor, insira novamente uma opcao valida: "); scanf("%d", &option);
    } 
  }
  return 0;
}