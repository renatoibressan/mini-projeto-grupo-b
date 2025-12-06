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

void ordenarTerrenos(terreno **terrenos);
void inicializarVetor(terreno ***terrenos);
void criarTerreno(terreno **terrenos);
void deletarTerreno(terreno ***terrenos);
void mostrarTerreno(terreno **terrenos, int id);
void editarTerreno(terreno **terrenos, int id);
double calcularValorTerreno(terreno **terrenos, int id);
int contarTerrenosOcupados(terreno ***terrenos);
int contarTerrenosLivres(terreno ***terrenos);
double calcularValorTotal(terreno **terrenos);
void salvarTerrenos(terreno **terrenos, const char *nomeArquivo);
void carregarTerrenos(terreno **terrenos, const char *nomeArquivo);
void clearScreen(void);