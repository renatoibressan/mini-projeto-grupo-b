#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terrenos.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int z = 0;
void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void pausas(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}
void slowPrint(const char *txt, int delay) {
    for (int i = 0; i < strlen(txt); i++) {
        putchar(txt[i]);
        fflush(stdout);
        pausas(delay);
    }
}
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
void ordenarTerrenos(terreno **terrenos) {
    terreno *temp;
    for (int i = 0; i < 99; i++) {
        if (terrenos[i] == NULL) continue;
        for (int j = i + 1; j < 100; j++) {
            if (terrenos[j] == NULL) continue;
            if ((*terrenos[i]).id > (*terrenos[j]).id) {
                temp = terrenos[i];
                terrenos[i] = terrenos[j];
                terrenos[j] = temp;
            }
        }
    }
}
int idExiste(int id, int ids[], int count) {
    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            return 1;
        }
    }
    return 0; 
}
void inicializarVetor(terreno ***terrenos) {
    *terrenos = malloc(100*sizeof(terreno*));
    for (int i = 0; i < 100; i++) {
        (*terrenos)[i] = NULL;
    }
}
void criarTerreno(terreno **terrenos, int ids[], int *ids_count) {
    int novoID;
    terreno *t = malloc(sizeof(terreno));
    printf("Por favor, insira os dados.\n");
    do {
        printf("ID do terreno: ");  
        scanf("%d", &novoID);
        limparBuffer();
        if (idExiste(novoID, ids, *ids_count)) {
            slowPrint("---------------------------------------------\n", 25);
            printf("O ID %d ja esta em uso. Por favor, digite outro ID.\n", novoID);
            slowPrint("---------------------------------------------\n", 25);
        } else {
            (*t).id = novoID;
            break;
        }
    } while (1);
    printf("Nome completo do dono: ");
    scanf(" %[^\n]%*c", (*t).dono.nome);
    printf("CPF do dono (XXX.XXX.XXX-XX): ");
    scanf("%[^\n]%*c", (*t).dono.cpf);
    printf("Data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &((*t).dono.data_nascimento.dia), &((*t).dono.data_nascimento.mes), &((*t).dono.data_nascimento.ano));
    limparBuffer();
    printf("Telefone do dono (DD-9XXXX-XXXX): ");
    scanf(" %[^\n]%*c", (*t).dono.telefone);
    printf("Data de compra do terreno (DD MM AAAA): ");
    scanf("%d %d %d", &((*t).data_compra.dia), &((*t).data_compra.mes), &((*t).data_compra.ano));
    limparBuffer();
    printf("Medidas de largura e comprimento: ");
    scanf("%f %f", &((*t).largura),&((*t).comprimento));
    limparBuffer();
    printf("Valor do m2: ");
    scanf("%f", &((*t).preco_m2));
    limparBuffer();
    terrenos[z] = t;
    ids[*ids_count] = (*terrenos[z]).id;
    (*ids_count)++;
    slowPrint("---------------------------------------------\n", 25);
    printf("Terreno de ID %d criado com sucesso!\n", (*terrenos[z]).id);
    slowPrint("---------------------------------------------\n", 25);
    z++;
}
void deletarTerreno(terreno ***terrenos, int ids[], int *ids_count) {
    int i;
    for (i = 0; i < 100; i++) {
        if ((*terrenos)[i] != NULL) {
            printf("Terreno de ID %d deletado com sucesso!\n", (*(*terrenos)[i]).id);
            free((*terrenos)[i]);
            (*terrenos)[i] = NULL;
        }
    }
    *ids_count = 0;
    for (i = 0; i < 100; i++) {
        ids[i] = 0;
    }
    z = 0;
    printf("Terrenos deletados com sucesso!\n");
    slowPrint("---------------------------------------------\n", 25);
}
void mostrarTerreno(terreno **terrenos, int id) {
    int i = 0;
    int encontrado = 0;
    ordenarTerrenos(terrenos);
    while (i < z) {
        (*terrenos[i]).area = (*terrenos[i]).largura * (*terrenos[i]).comprimento;
        if ((*terrenos[i]).id == id) {
            slowPrint("---------------------------------------------\n", 25);
            printf("Terreno encontrado!\n");
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
            encontrado = 1;
            break;
        }
        i++;
    }
    if (!encontrado) {
        printf("Nenhum terreno com ID %d foi encontrado.\n", id);
        slowPrint("---------------------------------------------\n", 25);
        return;
    }
}
