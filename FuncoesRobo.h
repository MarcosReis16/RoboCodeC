struct robo{
    int hp;
    int x;
    int y;
    const void (*ptr)(struct robo *rb);//ponteiro que recebe o método mapa
};
typedef struct robo Robo;
Robo* cria_robo();
void construct(Robo *robo);
void mapa(Robo *robo);
