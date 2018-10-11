#define LINHA 20
#define COLUNA 20

struct robo{
    int hp;
    int x;
    int y;
    int z;
    int k;
    int mat[LINHA][COLUNA];
    void (*ptr)(Robo);
};
typedef struct robo Robo;
Robo* cria_robo();
void mapa(Robo *robo);
void construct(Robo *robo);
void tabuleiro(int mat[LINHA][COLUNA]);
void mostraTabuleiro(int mat[LINHA][COLUNA],int x,int y,int z,int k);

