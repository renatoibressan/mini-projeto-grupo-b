#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terrenos.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

extern int z;
void editarTerreno(terreno **terrenos, int id) {
    int option, encontrado = 0;
    terreno *t = malloc(sizeof(terreno));
    for (int i = 0; i < z; i++) {
        if ((*terrenos[i]).id == id) {
            slowPrint("Opcoes:\n", 25);
            slowPrint("1. Editar nome do dono\n", 25);
            slowPrint("2. Editar CPF do dono\n", 25);
            slowPrint("3. Editar data de nascimento do dono\n", 25);
            slowPrint("4. Editar telefone do dono\n", 25);
            slowPrint("5. Editar data de compra do terreno\n", 25);
            slowPrint("6. Editar medidas do terreno\n", 25);
            slowPrint("7. Editar preco do m2 do terreno\n", 25);
            slowPrint("Qual edicao deseja realizar? ", 25);
            scanf("%d", &option);
            limparBuffer();
            switch (option) {
                case 1:
                    printf("Inisra o novo nome: ");
                    scanf("%[^\n]%*c", (*t).dono.nome);
                    strcpy((*terrenos[i]).dono.nome, (*t).dono.nome);
                    break;
                case 2:
                    printf("Insira o novo CPF: ");
                    scanf("%[^\n]%*c", (*t).dono.cpf);
                    strcpy((*terrenos[i]).dono.cpf, (*t).dono.cpf);
                    break;
                case 3:
                    printf("Insira a nova data de nascimento: ");
                    scanf("%d %d %d", &((*t).dono.data_nascimento.dia), &((*t).dono.data_nascimento.mes), &((*t).dono.data_nascimento.ano));
                    limparBuffer();
                    (*terrenos[i]).dono.data_nascimento.dia = (*t).dono.data_nascimento.dia;
                    (*terrenos[i]).dono.data_nascimento.mes = (*t).dono.data_nascimento.mes;
                    (*terrenos[i]).dono.data_nascimento.ano = (*t).dono.data_nascimento.ano;
                    break;
                case 4:
                    printf("Insira o novo telefone: ");
                    scanf("%[^\n]%*c", (*t).dono.telefone);
                    strcpy((*terrenos[i]).dono.telefone, (*t).dono.telefone);
                    break;
                case 5:
                    printf("Insira a nova data de compra: ");
                    scanf("%d %d %d", &((*t).data_compra.dia), &((*t).data_compra.mes), &((*t).data_compra.ano));
                    limparBuffer();
                    (*terrenos[i]).data_compra.dia = (*t).data_compra.dia;
                    (*terrenos[i]).data_compra.mes = (*t).data_compra.mes;
                    (*terrenos[i]).data_compra.ano = (*t).data_compra.ano;
                    break;
                case 6:
                    printf("Insira as novas medidas de largura e comprimento: ");
                    scanf("%f %f", &(*t).largura, &(*t).comprimento);
                    limparBuffer();
                    (*terrenos[i]).largura = (*t).largura;
                    (*terrenos[i]).comprimento = (*t).comprimento;
                    break;
                case 7:
                    printf("Insira o novo preco do m2: ");
                    scanf("%f", &(*t).preco_m2);
                    limparBuffer();
                    (*terrenos[i]).preco_m2 = (*t).preco_m2;
                    break;
                default:
                    printf("Opcao invalida!\n");
                    scanf("%d", &option);
                    limparBuffer();
            }
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Nenhum terreno com ID %d foi encontrado.\n", id);
        slowPrint("---------------------------------------------\n", 25);
        return;
    }
}
double calcularValorTerreno(terreno **terrenos, int id) {
    for (int i = 0; i < z; i++) {
        if (terrenos[i] != NULL && (*terrenos[i]).id == id) {
            terreno *t = terrenos[i];
            (*t).area = (*t).largura * (*t).comprimento;
            double valor_terreno = (double)(*t).area * (double)(*t).preco_m2;
            return valor_terreno;
        }
    }
    printf("Nenhum terreno com ID %d foi encontrado.\n", id);
    slowPrint("---------------------------------------------\n", 25);
    return -1;
}
int contarTerrenosOcupados(terreno ***terrenos) {
    if (*terrenos == NULL) return 0;
    int count = z;
    return count;
}
int contarTerrenosLivres(terreno ***terrenos) {
    if (*terrenos == NULL) return 100;
    int count = 100 - z;
    return count;
}
double calcularValorTotal(terreno **terrenos) {
    double valor_total_geral = 0;
    int i ;
    for (i = 0; i < z; i++) {
        if (terrenos[i] != NULL) {
            terreno *t = terrenos[i];
            (*t).area = (*t).largura * (*t).comprimento;
            double valor_terreno = (double)(*t).area * (double)(*t).preco_m2;
            valor_total_geral += valor_terreno;
        }
    }
    return valor_total_geral;
}
void salvarTerrenos(terreno **terrenos, const char *nomeArquivo) {
    int registros_salvos = 0;
    char lista_ids[150] = ""; 
    char id_buffer[10];  
    int i;
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Nao foi possivel salvar o arquivo '%s'.\n", nomeArquivo);
        slowPrint("---------------------------------------------\n", 25);
        return;
    }
    ordenarTerrenos(terrenos);
    for (i = 0; i < z; i++) {
        if (terrenos[i] != NULL) {
            size_t resultado = fwrite(terrenos[i], sizeof(terreno), 1, arquivo);
            if (resultado != 1) {
                printf("Nao foi possivel salvar o terreno ID %d.\n", (*terrenos[i]).id);
                slowPrint("---------------------------------------------\n", 25);
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
    slowPrint("---------------------------------------------\n", 25);
    if (registros_salvos > 0) {
        lista_ids[strlen(lista_ids) - 2] = '\0'; 
        printf("IDs dos terrenos salvos: [%s]\n", lista_ids);
        slowPrint("---------------------------------------------\n", 25);
    }
}
void carregarTerrenos(terreno **terrenos, const char *nomeArquivo) {
    int i = 0, lidos;
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Nao foi possivel carregar o arquivo '%s'.\n", nomeArquivo);
        slowPrint("---------------------------------------------\n", 25);
        return;
    }
    while(i < z){
        lidos = fread(terrenos[i], sizeof(terreno), 1, arquivo);
        if (lidos != 1) break;
        (*terrenos[i]).area = (*terrenos[i]).largura * (*terrenos[i]).comprimento;
        printf("ID: %d\n", (*terrenos[i]).id);
        slowPrint("---------------------------------------------\n", 25);
        printf("Dono:\n");
        printf("Nome: %s\n", (*terrenos[i]).dono.nome);
        printf("CPF: %s\n", (*terrenos[i]).dono.cpf);
        printf("Data de Nascimento: %d/%d/%d\n",(*terrenos[i]).dono.data_nascimento.dia, 
            (*terrenos[i]).dono.data_nascimento.mes, 
            (*terrenos[i]).dono.data_nascimento.ano);
        printf("Telefone: %s\n", (*terrenos[i]).dono.telefone);
        slowPrint("---------------------------------------------\n", 25);
        printf("Data da Compra: %d/%d/%d\n",(*terrenos[i]).data_compra.dia,
            (*terrenos[i]).data_compra.mes,
            (*terrenos[i]).data_compra.ano);
        printf("Largura: %.2f m\n", (*terrenos[i]).largura);
        printf("Comprimento: %.2f m\n", (*terrenos[i]).comprimento);
        printf("Area: %.2f m2\n", (*terrenos[i]).area);
        printf("Preco por m2: R$ %.2f\n", (*terrenos[i]).preco_m2);
        slowPrint("---------------------------------------------\n", 25);
        i++;
    }
    fclose(arquivo);
    printf("Foram carregados do arquivo %d terrenos.\n", i);
    slowPrint("---------------------------------------------\n", 25);
}
void liberarTodosTerrenos(terreno **terrenos){
    if (terrenos == NULL) return;
    for (int i = 0; i < z; i++) {
        if (terrenos[i] != NULL) {
            free(terrenos[i]); 
            terrenos[i] = NULL; 
        }
    }
    free(terrenos);
    z = 0;
}