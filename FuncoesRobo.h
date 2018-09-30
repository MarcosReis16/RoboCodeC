struct robo{
    int hp;
    int x;
    int y;
    int (*ptr)(Robo);//ponteiro que recebe o método mapa
};
typedef struct robo Robo;
Robo* cria_robo();
void mapa(Robo *robo);
void construct(Robo *robo);

