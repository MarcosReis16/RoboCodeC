#define LINHA 5
#define COLUNA 15

struct robo{
    int hp_robo1;
    int tiro_robo1;
    int hp_robo2;
    int tiro_robo2;
    int linha_robo1;//robo 1 - LINHA
    int coluna_robo1;//robo 1 - COLUNA
    int linha_robo2;//robo 2 - LINHA
    int coluna_robo2;//robo 2 - COLUNA
    void (*ptr)(int mat[LINHA][COLUNA], struct robo *r);
};
typedef struct robo Robo;
Robo* cria_robo();
void construct(Robo *robo);
void preenche_arena(int mat[LINHA][COLUNA]);
void play_game(int mat[LINHA][COLUNA],Robo *robo);
void atirar(int mat[LINHA][COLUNA], Robo* robo);
void verifica(Robo* robo);
void arena(int tabuleiro[LINHA][COLUNA],Robo *robo);
void mostrarRobo(int mat[LINHA][COLUNA],Robo *robo);
void apagaRobo(int mat[LINHA][COLUNA],Robo *robo);
void tiro(int mat[LINHA][COLUNA],Robo *robo,int i,int j);
void limpaTiro(int mat[LINHA][COLUNA],Robo *robo,int i,int j);

