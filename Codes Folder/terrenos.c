#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terrenos.h"

int z = 0;
void inicializarVetor(terreno ***terrenos) {
    *terrenos = malloc(100*sizeof(terreno*));
    for (int i = 0; i < 100; i++) {
        (*terrenos)[i] = NULL;
    }
} // Function 1 - Aryan
void criarTerreno(terreno **terrenos) {
    terreno *t = malloc(sizeof(terreno));
    scanf("%d %[^\n]%*c %[^\n]%*c %d %d %d %[^\n]%*c %d %d %d %f %f %f", &((*t).id), (*t).dono.nome, (*t).dono.cpf,
        &((*t).dono.data_nascimento.dia), &((*t).dono.data_nascimento.mes), &((*t).dono.data_nascimento.ano), (*t).dono.telefone, 
        &((*t).data_compra.dia), &((*t).data_compra.mes), &((*t).data_compra.ano), &((*t).largura), &((*t).comprimento), &((*t).preco_m2));
    terrenos[z] = t;
    printf("Terreno de ID %d criado com sucesso!\n", (*terrenos[z]).id);
    z++;
} // Function 2 - Aryan
void deletarTerreno(terreno **terrenos) {
    int i;
    for (i = 0; i < 100; i++) {
      free(terrenos[i]);
    }
    free(terrenos);
    for (i = 0; i < 100; i++) {
        terrenos[i] = NULL;
        printf("Terreno #%d deletado com sucesso!\n", (i + 1));
    }
} // Function 3 - Aryan
void mostrarTerreno(terreno **terrenos, int id) {
    int i = 0;
    int encontrado = 0;
    while (i < 100) {
        (*terrenos[i]).area = (*terrenos[i]).largura * (*terrenos[i]).comprimento;
        if ((*terrenos[i]).id == id) {
            printf("---------------------------------------------\n");
            printf("Terreno encontrado!\n");
            printf("ID: %d\n", (*terrenos[i]).id);
            printf("---------------------------------------------\n");
            printf("Dono:\n");
            printf("Nome: %s\n", (*terrenos[i]).dono.nome);
            printf("CPF: %s\n", (*terrenos[i]).dono.cpf);
            printf("Data de Nascimento: %d/%d/%d\n",(*terrenos[i]).dono.data_nascimento.dia, 
                (*terrenos[i]).dono.data_nascimento.mes, 
                (*terrenos[i]).dono.data_nascimento.ano);
            printf("Telefone: %s\n", (*terrenos[i]).dono.telefone);
            printf("---------------------------------------------\n");
            printf("Data da Compra: %d/%d/%d\n",(*terrenos[i]).data_compra.dia,
                (*terrenos[i]).data_compra.mes,
                (*terrenos[i]).data_compra.ano);
            printf("Largura: %.2f m\n", (*terrenos[i]).largura);
            printf("Comprimento: %.2f m\n", (*terrenos[i]).comprimento);
            printf("Area: %.2f m2\n", (*terrenos[i]).area);
            printf("Preco por m2: R$ %.2f\n", (*terrenos[i]).preco_m2);
            printf("---------------------------------------------\n");
            encontrado = 1;
            break;
        }
        i++;
    }
    if (!encontrado) {
        printf("Nenhum terreno com ID %d foi encontrado.\n", id);
        printf("---------------------------------------------\n");
    }
} // Function 4 - Amanda
void editarTerreno(terreno **terrenos, int id) {
    int option, encontrado = 0;
    terreno *t = malloc(sizeof(terreno));
    for (int i = 0; i < 100; i++) {
        if ((*terrenos[i]).id == id) {
            printf("Opcoes:\n");
            printf("1. Editar nome do dono\n");
            printf("2. Editar CPF do dono\n");
            printf("3. Editar data de nascimento do dono\n");
            printf("4. Editar telefone do dono\n");
            printf("5. Editar data de compra do terreno\n");
            printf("6. Editar medidas do terreno\n");
            printf("7. Editar preco do m2 do terreno\n");
            printf("Qual edicao deseja realizar? ");
            scanf("%d", &option);
            switch (option) {
                case 1:
                    scanf("%[^\n]%*c", (*t).dono.nome);
                    strcpy((*terrenos[i]).dono.nome, (*t).dono.nome);
                    break;
                case 2:
                    scanf("%[^\n]%*c", (*t).dono.cpf);
                    strcpy((*terrenos[i]).dono.cpf, (*t).dono.cpf);
                    break;
                case 3:
                    scanf("%d %d %d", &((*t).dono.data_nascimento.dia), &((*t).dono.data_nascimento.mes), &((*t).dono.data_nascimento.ano));
                    (*terrenos[i]).dono.data_nascimento.dia = (*t).dono.data_nascimento.dia;
                    (*terrenos[i]).dono.data_nascimento.mes = (*t).dono.data_nascimento.mes;
                    (*terrenos[i]).dono.data_nascimento.ano = (*t).dono.data_nascimento.ano;
                    break;
                case 4:
                    scanf("%[^\n]%*c", (*t).dono.telefone);
                    strcpy((*terrenos[i]).dono.telefone, (*t).dono.telefone);
                    break;
                case 5:
                    scanf("%d %d %d", &((*t).data_compra.dia), &((*t).data_compra.mes), &((*t).data_compra.ano));
                    (*terrenos[i]).data_compra.dia = (*t).data_compra.dia;
                    (*terrenos[i]).data_compra.mes = (*t).data_compra.mes;
                    (*terrenos[i]).data_compra.ano = (*t).data_compra.ano;
                    break;
                case 6:
                    scanf("%f %f", &(*t).largura, &(*t).comprimento);
                    (*terrenos[i]).largura = (*t).largura;
                    (*terrenos[i]).comprimento = (*t).comprimento;
                    break;
                case 7:
                    scanf("%f", &(*t).preco_m2);
                    (*terrenos[i]).preco_m2 = (*t).preco_m2;
                    break;
                default:
                    printf("Opcao invalida!\n");
                    scanf("%d", &option);
            }
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Nenhum terreno com ID %d foi encontrado.\n", id);
        printf("---------------------------------------------\n");
    }
} // Function 5 - Renato
double calcularValorTerreno(terreno **terrenos, int id) {
    int encontrado = 0;
    double valor_terreno;
    for (int i = 0; i < 100; i++) {
        if (terrenos[i] != NULL) {
            terreno *t = terrenos[i];
            if((*t).area==0){
                (*t).area = (*t).largura * (*t).comprimento;
            }
            valor_terreno = (double)(*t).area * (double)(*t).preco_m2;
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Nenhum terreno com ID %d foi encontrado.\n", id);
        printf("---------------------------------------------\n");
        return -1;
    }
    else return valor_terreno;
} // Function 6 - Aryan
int contarTerrenosOcupados(terreno **terrenos) {
    int count = 0;
    for (int i = 0; i < 100; i++) {
        if (terrenos[i] != NULL) count++;
    }
    return count;
} // Function 7 - Renato
int contarTerrenosLivres(terreno **terrenos) {
    int count = 0;
    for (int i = 0; i < 100; i++) {    
        if (terrenos[i] == NULL) count++; 
    }
    return count;
} // Function 8 - Amanda
double calcularValorTotal(terreno **terrenos) {
    double valor_total_geral = 0;
    int i ;
    for (i = 0; i < 100; i++) {
        if (terrenos[i] != NULL) {
            terreno *t = terrenos[i];
            if((*t).area==0){
                (*t).area = (*t).largura * (*t).comprimento;
            }
            double valor_terreno = (double)(*t).area * (double)(*t).preco_m2;
            valor_total_geral += valor_terreno;
        }
    }
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
    for (i = 0; i < 100; i++) {
        if (terrenos[i] != NULL) {
            size_t resultado = fwrite(terrenos[i], sizeof(terrenos), 1, arquivo);
            if (resultado != 1) {
                printf("Nao foi possivel salvar o terreno ID %d.\n", (*terrenos[i]).id);
                printf("---------------------------------------------\n");
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
    printf("---------------------------------------------\n");
    if (registros_salvos > 0) {
        lista_ids[strlen(lista_ids) - 2] = '\0'; 
        printf("IDs dos terrenos salvos: [%s]\n", lista_ids);
        printf("---------------------------------------------\n");
    }
} // Function 10 - Amanda
void carregarTerrenos(terreno **terrenos, const char *nomeArquivo) {
    int registros_carregados = 0;
    char linha[200];
    int i = 0;
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Nao foi possivel carregar o arquivo '%s'.\n", nomeArquivo);
        printf("---------------------------------------------\n");
        return;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL && i < 100) {
        sscanf(linha, "%d %104[^;]; %14[^;]; %d %d %d %14[^;]; %d %d %d %f %f %f", &(*terrenos[i]).id, (*terrenos[i]).dono.nome,
            (*terrenos[i]).dono.cpf, &(*terrenos[i]).dono.data_nascimento.dia, &(*terrenos[i]).dono.data_nascimento.mes,
            &(*terrenos[i]).dono.data_nascimento.ano, (*terrenos[i]).dono.telefone, &(*terrenos[i]).data_compra.dia,
            &(*terrenos[i]).data_compra.mes, &(*terrenos[i]).data_compra.ano, &(*terrenos[i]).largura, &(*terrenos[i]).comprimento,
            &(*terrenos[i]).preco_m2);
        (*terrenos[i]).area = (*terrenos[i]).largura * (*terrenos[i]).comprimento;
        printf("ID: %d\n", (*terrenos[i]).id);
        printf("---------------------------------------------\n");
        printf("Dono:\n");
        printf("Nome: %s\n", (*terrenos[i]).dono.nome);
        printf("CPF: %s\n", (*terrenos[i]).dono.cpf);
        printf("Data de Nascimento: %d/%d/%d\n",(*terrenos[i]).dono.data_nascimento.dia, 
            (*terrenos[i]).dono.data_nascimento.mes, 
            (*terrenos[i]).dono.data_nascimento.ano);
        printf("Telefone: %s\n", (*terrenos[i]).dono.telefone);
        printf("---------------------------------------------\n");
        printf("Data da Compra: %d/%d/%d\n",(*terrenos[i]).data_compra.dia,
            (*terrenos[i]).data_compra.mes,
            (*terrenos[i]).data_compra.ano);
        printf("Largura: %.2f m\n", (*terrenos[i]).largura);
        printf("Comprimento: %.2f m\n", (*terrenos[i]).comprimento);
        printf("Area: %.2f m2\n", (*terrenos[i]).area);
        printf("Preco por m2: R$ %.2f\n", (*terrenos[i]).preco_m2);
        printf("---------------------------------------------\n");
        i++;
    }
    registros_carregados = i;
    fclose(arquivo);
    printf("Foram carregados do arquivo %d terrenos.\n", registros_carregados);
    printf("---------------------------------------------\n");
} // Function 11 - Renato
void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}