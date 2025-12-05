#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int dia, mes, ano;
} data;
typedef struct Pessoa {
    char nome[100];
    char cpf[20];
    data data_nascimento;
    char telefone[20];
} pessoa;
typedef struct Terrenos {
    int id;
    pessoa dono;
    data data_compra;
    float largura, comprimento, area, preco_m2;
} terreno;

void funcao2(void);
void funcao3(void);
void funcao4(void);
void funcao5(void);
void funcao6(void);
void funcao7(void);
void funcao8(void);
void funcao9(void);
void funcao10(void);
void funcao11(void);
void clearScreen(void);
void inicializarVetor(terreno **terrenos); // Function 1 - Aryan
void criarTerreno(terreno **terrenos); // Function 2 - Aryan
void deletarTerreno(terreno **terrenos); // Function 3 - Aryan
void mostrarTerreno(terreno **terrenos, int id); // Function 4 - Amanda
void editarTerreno(terreno **terrenos, int id); // Function 5 - Renato
double calcularValorTerreno(terreno **terrenos, int id); // Function 6 - Aryan
int contarTerrenosOcupados(terreno **terrenos); // Function 7 - Renato
int contarTerrenosLivres(terreno **terrenos); // Function 8 - Amanda
double calcularValorTotal(terreno **terrenos); // Function 9 - Amanda
void salvarTerrenos(terreno **terrenos, const char *nomeArquivo); // Function 10 - Amanda
void carregarTerrenos(terreno **terrenos, const char *nomeArquivo); // Function 11 - Renato

int main(const char *nomeArquivo) {
    clearScreen();
    printf("===== SISTEMA GERENCIADOR DE BAIRROS =====\n");
    printf("Desenvolvido por:\nAmanda Sales Alborgueti\nAryan Douglas Borges Rodrigues\nRenato Ikeda Bressan\n");
    int option = -1;
    terreno **t;
    int i;
    inicializarVetor(t);
    do {
        option = -1;
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
            default: printf("Opcao invalida!\n");
        } 
    } while (option != 0);
    return 0;
}

void inicializarVetor(terreno **terrenos) {
    terrenos = (terreno **)malloc(100*sizeof(terreno*));
    for (int i = 0; i < 100; i++) {
        terrenos[i] = NULL;
    }
} // Function 1 - Aryan
void criarTerreno(terreno **terrenos) {
    terrenos = (terreno **)malloc(100*sizeof(terreno*));
    for (int i = 0; i < 100; i++) {
        scanf("%d %[^\n] %[^\n] %d %d %d %[^\n] %d %d %d %f %f %f", 
            &((*terrenos[i]).id), ((*terrenos[i]).dono.nome), ((*terrenos[i]).dono.cpf), 
            &((*terrenos[i]).dono.data_nascimento.dia), &((*terrenos[i]).dono.data_nascimento.mes), 
            &((*terrenos[i]).dono.data_nascimento.ano), ((*terrenos[i]).dono.telefone), 
            &((*terrenos[i]).data_compra.dia), &((*terrenos[i]).data_compra.mes), &((*terrenos[i]).data_compra.ano),  
            &((*terrenos[i]).largura), &((*terrenos[i]).comprimento), &((*terrenos[i]).preco_m2));
        printf("Terreno #%d criado com sucesso!\n", (i + 1));
        clearScreen();
    }
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
        clearScreen();
    }
} // Function 3 - Aryan
void mostrarTerreno(terreno **terrenos, int id) {
    int i = 0;
    int encontrado = 0;
    while (i < 100) {
        if ((*terrenos[i]).id == id) {
            printf("---------------------------------------------\n");
            printf("Terreno encontrado!\n");
            printf("ID: %d\n", (*terrenos[i]).id);
            printf("---------------------------------------------\n");
            //Pessoa
            printf("Dono:\n");
            printf("Nome: %s\n", (*terrenos[i]).dono.nome);
            printf("CPF: %s\n", (*terrenos[i]).dono.cpf);
            printf("Data Nascimento: %d/%d/%d\n",(*terrenos[i]).dono.data_nascimento.dia, 
                    (*terrenos[i]).dono.data_nascimento.mes, 
                    (*terrenos[i]).dono.data_nascimento.ano);
            printf("Telefone: %s\n", (*terrenos[i]).dono.telefone);
            printf("---------------------------------------------\n");
            //Data
            printf("Data  da Compra: %d/%d/%d\n",(*terrenos[i]).data_compra.dia,
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
    int found = 0;
    for (int i = 0; i < 100; i++) {
        if ((*terrenos[i]).id == id) {
            scanf("%[^\n]%*c %[^\n]%*c %d %d %d %[^\n]%*c %d %d %d %f %f %f", 
                ((*terrenos[i]).dono.nome), ((*terrenos[i]).dono.cpf), 
                &((*terrenos[i]).dono.data_nascimento.dia), &((*terrenos[i]).dono.data_nascimento.mes), 
                &((*terrenos[i]).dono.data_nascimento.ano), ((*terrenos[i]).dono.telefone), 
                &((*terrenos[i]).data_compra.dia), &((*terrenos[i]).data_compra.mes), &((*terrenos[i]).data_compra.ano),  
                &((*terrenos[i]).largura), &((*terrenos[i]).comprimento), &((*terrenos[i]).preco_m2));
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Nenhum terreno com ID %d foi encontrado.\n", id);
        printf("---------------------------------------------\n");
    }
} // Function 5 - Renato
double calcularValorTerreno(terreno **terrenos, int id) {
    int found = 0;
    double valor_terreno;
    for (int i = 0; i < 100; i++) {
        if (terrenos[i] != NULL) {
            terreno *t = terrenos[i];
            if((*t).area==0){
                (*t).area = (*t).largura * (*t).comprimento;
            }
            valor_terreno = (double)(*t).area * (double)(*t).preco_m2;
            found = 1;
            break;
        }
    }
    if (!found) {
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
    char linha[100][200];
    int i, j;
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Nao foi possivel carregar o arquivo '%s'.\n", nomeArquivo);
        printf("---------------------------------------------\n");
        return;
    }
    for (i = 0; i < 100; i++) {
        while (fgets(linha[i], sizeof(linha[i]), arquivo) != NULL) {
            printf("Informacoes do terreno #%d: %s\n", (i + 1), linha[i]);
            printf("---------------------------------------------\n");
            for (j = 0; j < 200; j++) {
                if (linha[i][j] = '\n') registros_carregados++;
            }
        }
    }
    fclose(arquivo);
    printf("Foram carregados do arquivo %d terrenos.\n", registros_carregados);
    printf("---------------------------------------------\n");
} // Function 11 - Renato
void funcao2(void) {
    terreno **t;
    criarTerreno(t);
}
void funcao3(void) {
    terreno **t;
    deletarTerreno(t);
}
void funcao4(void) {
    terreno **t;
    int id_teste;
    printf("Insira um ID para procura do terreno: ");
    scanf("%d", &id_teste);
    mostrarTerreno(t, id_teste);
}
void funcao5(void) {
    terreno **t;
    int id_teste;
    printf("Insira um ID para procura do terreno: ");
    scanf("%d", &id_teste);
    editarTerreno(t, id_teste);
}
void funcao6(void) {
    terreno **t;
    int id_teste;
    double valor_terreno;
    printf("Insira um ID para procura do terreno: ");
    scanf("%d", &id_teste);
    valor_terreno = calcularValorTerreno(t, id_teste);
    if (valor_terreno == -1) return;
    else {
        printf("Valor do Terreno de ID %d: R$ %.2f\n", id_teste, valor_terreno);
        printf("---------------------------------------------\n");
    }
}
void funcao7(void) {
    terreno **t;
    int count;
    count = contarTerrenosOcupados(t);
    printf("Terrenos Ocupados: %d\n", count);
    printf("---------------------------------------------\n");
}
void funcao8(void) {
    terreno **t;
    int count;
    count = contarTerrenosLivres(t);
    printf("Terrenos Livres: %d\n", count);
    printf("---------------------------------------------\n");
}
void funcao9(void) {
    terreno **t;
    double valor_total_geral;
    valor_total_geral = calcularValorTotal(t);
    printf("Valor Total de todos os Terrenos: R$ %.2f\n", valor_total_geral);
    printf("---------------------------------------------\n");
}
void funcao10(void) {
    terreno **t;
    const char *nomeArquivo = "terrenos.txt";
    salvarTerrenos(t, nomeArquivo);
}
void funcao11(void) {
    terreno **t;
    const char *nomeArquivo = "terrenos.txt";
    carregarTerrenos(t, nomeArquivo);
}
void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}