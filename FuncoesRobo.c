#include <stdio.h>
#include <stdlib.h>
#include "FuncoesRobo.h"

Robo* cria_robo(){
    Robo *r = (Robo*)malloc(sizeof(Robo));
    if(r == NULL)
        exit(1);

    return r;
}
void mapa(Robo *robo){
    int i,j;

    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            if(j>=robo->x && j<=robo->x && i>=robo->y && i<=robo->y)
                printf("X");
            else
                printf("_");
        }
        printf("\n");
    }
}
void construct(Robo *robo){
    robo->x = 0;
    robo->y = 0;
    robo->z = LINHA-1;
    robo->k = LINHA-1;
    robo->ptr = mapa;
}
void tabuleiro(int mat[LINHA][COLUNA]){
    int i,j;

    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            mat[i][j] = -1;
        }
    }
}
void mostraTabuleiro(int mat[LINHA][COLUNA],int x,int y,int z,int k){
    int i,j;

    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            if(i == x && j == y || i == z && j ==k){
                printf("X");
            }else
                printf("_");

        }
        printf("\n");
    }
}



