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

extern int z;

void clearScreen(void);
void pausas(int ms);
void slowPrint(const char *txt, int delay);
void limparBuffer(void);
void ordenarTerrenos(terreno **terrenos);
int idExiste(int id, int ids[], int count);
void inicializarVetor(terreno ***terrenos);
void criarTerreno(terreno **terrenos, int ids[], int *ids_count);
void deletarTerreno(terreno ***terrenos, int ids[], int *ids_count);
void mostrarTerreno(terreno **terrenos, int id);
void editarTerreno(terreno **terrenos, int id);
double calcularValorTerreno(terreno **terrenos, int id);
int contarTerrenosOcupados(terreno ***terrenos);
int contarTerrenosLivres(terreno ***terrenos);
double calcularValorTotal(terreno **terrenos);
void salvarTerrenos(terreno **terrenos, const char *nomeArquivo);
void carregarTerrenos(terreno **terrenos, const char *nomeArquivo);
void liberarTodosTerrenos(terreno **terrenos);