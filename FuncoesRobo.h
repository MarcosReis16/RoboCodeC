#define LINHA 5
#define COLUNA 15

struct robo{
    char nome[15];
    int hp;
    int tiro;
    int linha;
    int coluna;
    void (*ptr)(int mat[LINHA][COLUNA], struct robo *r,struct robo *r2);
    void (*ptr2)(struct robo *r3);
};
typedef struct robo Robo;
Robo* cria_robo();
void construct(Robo *robo,Robo* robo2);
void preenche_arena(int mat[LINHA][COLUNA]);
void play_game(int mat[LINHA][COLUNA],Robo *robo,Robo *robo2);
void atirar(int mat[LINHA][COLUNA], Robo* robo,Robo *robo2);
void verifica(Robo* robo,Robo *robo2);
void arena(int tabuleiro[LINHA][COLUNA],Robo *robo,Robo *robo2,int validador);
void mostrarRobo(int mat[LINHA][COLUNA],Robo *robo,Robo* robo2);
void apagaRobo(int mat[LINHA][COLUNA],Robo *robo,Robo *robo2);
void tiro(int mat[LINHA][COLUNA],int i,int j,int validador);
void limpaTiro(int mat[LINHA][COLUNA],int i,int j);
int tiro_robo2(int mat[LINHA][COLUNA],int i,int j);
void metodo(Robo *robo);
void metodo2(Robo *robo);
