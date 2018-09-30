#include <stdio.h>
#include <stdlib.h>
#include "FuncoesRobo.h"

Robo* cria_robo(){
    Robo *r = (Robo*)malloc(sizeof(Robo));
    if(r == NULL)
        exit(1);

    return r;//cria alocando dinamicamente memoria pro robô
}
void mapa(Robo *robo){
    int i,j;

    for(i=0;i<10;i++){
        for(j=0;j<20;j++){
            if(j>=robo->x && j<=robo->x && i>=robo->y && i<=robo->y)
                printf("x");
            else
                printf("_");
        }
        printf("\n");
    }
    //função que faz a movimentação do robô
}
void construct(Robo *robo){//constructor
    robo->x=0;
    robo->y=0;
    robo->ptr = mapa;//metodo da classe robô
}



