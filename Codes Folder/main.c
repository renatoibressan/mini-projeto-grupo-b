#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terrenos.h"

int main(const char *nomeArquivo) {
  int option = -1;
  terreno **t;
  FILE *arq = NULL;
  strcpy(nomeArquivo, "arq");
  while (option != 0) {
    option = -1;
    scanf("%d", &option);
  }
  return 0;
}