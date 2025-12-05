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
    int i=0;
    int encontrado=0;
    while( i < 100) {
            if ((*terrenos[i]).id == id) { 
            
                printf("Terreno encontrado\n", i);
                printf("ID: %d\n", (*terrenos[i]).id);
                
                //Pessoa
                printf("Dono:\n");
                printf("Nome: %s\n", (*terrenos[i]).dono.nome);
                printf("CPF: %s\n", (*terrenos[i]).dono.cpf);
                printf("Data Nascimento: %d/%d/%d\n",(*terrenos[i]).dono.data_nascimento.dia, 
                       (*terrenos[i]).dono.data_nascimento.mes, 
                       (*terrenos[i]).dono.data_nascimento.ano);
                printf("Telefone: %s\n", (*terrenos[i]).dono.telefone);

                //Data
                printf("Data  da Compra: %d/%d/%d\n",(*terrenos[i]).data_compra.dia,
                       (*terrenos[i]).data_compra.mes, 
                       (*terrenos[i]).data_compra.ano);
                printf("Largura: %.2f m\n", (*terrenos[i]).largura);
                printf("Comprimento: %.2f m\n", (*terrenos[i]).comprimento);
                printf("Área: %.2f m²\n", (*terrenos[i]).area);
                printf("Preço por m²: R$ %.2f\n", (*terrenos[i]).preco_m2);
                encontrado =1;
                break;
            }
        i++;
    }
    if(!encontrado){
    printf("Nenhum terreno com ID %d foi encontrado.\n", id);
    printf("----------------------------------\n");
    }
} // Function 4 - Amanda
void editarTerreno(terreno **terrenos, int id) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            scanf("%d %[^\n]%*c %[^\n]%*c %d %d %d %[^\n]%*c %d %d %d %f %f %f", 
            &(terrenos[i][j].id), (terrenos[i][j].dono.nome), (terrenos[i][j].dono.cpf), 
            &(terrenos[i][j].dono.data_nascimento.dia), &(terrenos[i][j].dono.data_nascimento.mes), 
            &(terrenos[i][j].dono.data_nascimento.ano), (terrenos[i][j].dono.telefone), 
            &(terrenos[i][j].data_compra.dia), &(terrenos[i][j].data_compra.mes), &(terrenos[i][j].data_compra.ano), 
            &(terrenos[i][j].largura), &(terrenos[i][j].comprimento), &(terrenos[i][j].preco_m2));
        }
    }
} // Function 5 - Renato
double calcularValorTerreno(terreno **terrenos, int id) {
} // Function 6 - Aryan
int contarTerrenosOcupados(terreno **terrenos) {
    int i, count;
    for (i = 0; i < 10; i++) {
        if (terrenos[i] != NULL) count++;
    }
    return count;
} // Function 7 - Renato
int contarTerrenosLivres(terreno **terrenos) {
      int livres = 0;

    for (int i = 0; i < 100; i++) {
        
        if (terrenos[i] == NULL) {
            livres++; 
        }
    }
    printf("Terrenos Livres : %d\n", livres);
    printf("---------------------------------------------\n");

    return livres;
} // Function 8 - Amanda
double calcularValorTotal(terreno **terrenos) {

    double valor_total_geral = 0;
    int i ;
    int count = 0;

    for (i = 0; i < 100; i++) {
       
        if (terrenos[i] != NULL) {
            
            Terrenos *t = terrenos[i]; 
            
            if((*t).area==0){
             (*t).area = (*t).largura * (*t).comprimento;
            }
            
            double valor_terreno = (double)(*t).area * (double)(*t).preco_m2;
            
            valor_total_geral += valor_terreno;
           
        }
    }
    
    printf("Valor Total de todos os Terrenos: R$ %.2f\n", valor_total_geral);
    printf("---------------------------------------------\n");
    
    return valor_total_geral;
} // Function 9 - Amanda
void salvarTerrenos(terreno **terrenos, const char *nomeArquivo) {
     int registros_salvos = 0;
    char lista_ids[150] = ""; 
    char id_buffer[10];  
    int i;               
  
    FILE *arquivo = fopen(nomeArquivo, "wb"); 

    if (arquivo == NULL) {
        printf("Nao foi possivel salvar o arquivo '%s'.\n", nomeArquivo);
        printf("---------------------------------------------\n");
        return;
    }

    for ( i = 0; i < 100; i++) {
        if (terrenos[i] != NULL) {
            size_t resultado = fwrite(terrenos[i], sizeof(Terrenos), 1, arquivo);
            
            if (resultado != 1) {
                printf("Nao foi possivel salvar o terreno ID %d.\n", (*terrenos[i]).id);
            } else {
                registros_salvos++;
                
                if (strlen(lista_ids) < 100) {  
                    snprintf(id_buffer, sizeof(id_buffer), "%d, ", (*terrenos[i]).id);
                   
                    strcat(lista_ids, id_buffer);
                }
            }
        }
    }
    fclose(arquivo); 

    printf("%d terrenos foram salvos no arquivo '%s'.\n", registros_salvos, nomeArquivo);

    if (registros_salvos > 0) {
       
        lista_ids[strlen(lista_ids) - 2] = '\0'; 
        printf("IDs dos terrenos salvos: [%s]\n", lista_ids);
        printf("---------------------------------------------\n");
    }
} // Function 10 - Amanda
void carregarTerrenos(terreno **terrenos, const char *nomeArquivo) {
} // Function 11 - Renato