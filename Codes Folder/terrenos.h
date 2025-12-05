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