#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terrenos.h"

void inicializarVetor(terreno **terrenos) {
} // Function 1 - Aryan
void criarTerreno(terreno **terrenos) {
} // Function 2 - Aryan
void deletarTerreno(terreno **terrenos) {
} // Function 3 - Aryan
void mostrarTerreno(terreno **terrenos, int id) {
} // Function 4 - Amanda
void editarTerreno(terreno **terrenos, int id) {
    int i;
    for (i = 0; i < 100; i++) {
        scanf("%d %[^\n]%*c %[^\n]%*c %d %d %d %[^\n]%*c %d %d %d %f %f %f", 
        &((*terrenos[i]).id), ((*terrenos[i]).dono.nome), ((*terrenos[i]).dono.cpf), 
        &((*terrenos[i]).dono.data_nascimento.dia), &((*terrenos[i]).dono.data_nascimento.mes), 
        &((*terrenos[i]).dono.data_nascimento.ano), ((*terrenos[i]).dono.telefone), 
        &((*terrenos[i]).data_compra.dia), &((*terrenos[i]).data_compra.mes), &((*terrenos[i]).data_compra.ano),  
        &((*terrenos[i]).largura), &((*terrenos[i]).comprimento), &((*terrenos[i]).preco_m2));
    }
} // Function 5 - Renato
double calcularValorTerreno(terreno **terrenos, int id) {
} // Function 6 - Aryan
int contarTerrenosOcupados(terreno **terrenos) {
    int i, count = 0;
    for (i = 0; i < 100; i++) {
        if (terrenos[i] != NULL) count++;
    }
    printf("Terrenos Ocupados : %d\n", count);
    printf("---------------------------------------------\n");
    return count;
} // Function 7 - Renato
int contarTerrenosLivres(terreno **terrenos) {
} // Function 8 - Amanda
double calcularValorTotal(terreno **terrenos) {
} // Function 9 - Amanda
void salvarTerrenos(terreno **terrenos, const char *nomeArquivo) {
} // Function 10 - Amanda
void carregarTerrenos(terreno **terrenos, const char *nomeArquivo) {
} // Function 11 - Renato