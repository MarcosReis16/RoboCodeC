#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include "FuncoesRobo.h"

Robo* cria_robo(){
    Robo *r = (Robo*)malloc(sizeof(Robo));
    if(r == NULL)
        exit(1);

    return r;
}
void arena(int tabuleiro[LINHA][COLUNA],Robo *robo){
    int linha,coluna;

    for(linha=0 ; linha < LINHA ; linha++ ){
            printf("|");
            for(coluna=0 ; coluna < COLUNA ; coluna++ ){
                if(tabuleiro[linha][coluna]==-1){
                    printf(" ");
                }else if(tabuleiro[linha][coluna]==0){
                    printf("X");
                }else if(tabuleiro[linha][coluna]==1){
					printf("@");
				}else if(tabuleiro[linha][coluna]==2)
                    printf("*");
            }
            if(coluna == COLUNA)
                printf("|");
            printf("\n");
    }

    if(robo->linha_robo1 == robo->linha_robo2 || robo->coluna_robo1 == robo->coluna_robo2){
        robo->hp_robo1 -= rand()%2;//PROVAVELMENTE VAI SERVIR PARA POTENCIA DO TIRO DO ADVERSARIO
        robo->hp_robo2 -= rand()%2;
    }
        printf("\n\nHP ROBO (X) = %d",robo->hp_robo1);
        printf("\nHP ROBO (@) = %d",robo->hp_robo2);
}
void mostrarRobo(int mat[LINHA][COLUNA],Robo *robo){
    mat[robo->linha_robo1][robo->coluna_robo1] = 0;
    mat[robo->linha_robo2][robo->coluna_robo2] = 1;
}
void apagaRobo(int mat[LINHA][COLUNA],Robo *robo){
    mat[robo->linha_robo1][robo->coluna_robo1] = -1;
    mat[robo->linha_robo2][robo->coluna_robo2] = -1;
}
void tiro(int mat[LINHA][COLUNA],Robo *robo,int i,int j){
        mat[i][j] = 2;

}
void limpaTiro(int mat[LINHA][COLUNA],Robo *robo,int i,int j){
        mat[i][j] = -1;

}
void play_game(int mat[LINHA][COLUNA],Robo *robo){
    int i,j,aux;

    system("cls");
    verifica(robo);
    mostrarRobo(mat,robo);
    arena(mat,robo);
    apagaRobo(mat,robo);
    atirar(mat,robo);

        /*if(robo->x == robo->z || robo->y == robo->k){
            robo->hp_robo1 -= rand()%3;//PROVAVELMENTE VAI SERVIR PARA POTENCIA DO TIRO DO ADVERSARIO
            robo->hp_robo2 -= rand()%3;
        }
        printf("\n\nHP ROBO (X) = %d",robo->hp_robo1);
        printf("\nHP ROBO (@) = %d",robo->hp_robo2);*/
    Sleep(370);
}
void construct(Robo *robo){
    robo->hp_robo1 = 100;
    robo->hp_robo2 = 100;
    //robo->tiro_robo1 = rand()%5;
    //robo->tiro_robo2 = 4;
    robo->linha_robo1 = 0;
    robo->coluna_robo1 = 0;
    robo->linha_robo2 = LINHA-1;
    robo->coluna_robo2 = COLUNA-1;
    robo->ptr = play_game;
}
void preenche_arena(int mat[LINHA][COLUNA]){
    int i,j;

    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            mat[i][j] = -1;
        }
    }
}
void atirar(int mat[LINHA][COLUNA], Robo* robo){
    if(robo->linha_robo1 == robo->linha_robo2 /*|| robo->y == robo->k*/){//robo X
                if(robo->coluna_robo1 < robo->coluna_robo2){
                    int aux = robo->coluna_robo1;
                    while(aux < robo->coluna_robo2-1){
                        mostrarRobo(mat,robo);
                        tiro(mat,robo,robo->linha_robo1,aux+1);
                        system("cls");
                        arena(mat,robo);
                        limpaTiro(mat,robo,robo->linha_robo1,aux+1);
                        aux++;
                    }
                    apagaRobo(mat,robo);
                }else{//robo X
                    int aux = robo->coluna_robo1;
                    while(aux > robo->coluna_robo2+1){
                        mostrarRobo(mat,robo);
                        tiro(mat,robo,robo->linha_robo1,aux-1);
                        system("cls");
                        arena(mat,robo);
                        limpaTiro(mat,robo,robo->linha_robo1,aux-1);
                        aux--;
                    }
                    apagaRobo(mat,robo);
                }

                if(robo->coluna_robo2 < robo->coluna_robo1){//robo @
                    int aux = robo->coluna_robo2;
                    while(aux < robo->coluna_robo1-1){
                        mostrarRobo(mat,robo);
                        tiro(mat,robo,robo->linha_robo2,aux+1);
                        system("cls");
                        arena(mat,robo);
                        limpaTiro(mat,robo,robo->linha_robo2,aux+1);
                        aux++;
                    }
                    apagaRobo(mat,robo);
                }else{//robo @
                    int aux = robo->coluna_robo2;
                    while(aux > robo->coluna_robo1+1){
                        mostrarRobo(mat,robo);
                        tiro(mat,robo,robo->linha_robo2,aux-1);
                        system("cls");
                        arena(mat,robo);
                        limpaTiro(mat,robo,robo->linha_robo2,aux-1);
                        aux--;
                    }
                    apagaRobo(mat,robo);
                }
            }
}
void verifica(Robo* robo){
    if(robo->linha_robo1 == robo->linha_robo2 && robo->coluna_robo1 == robo->coluna_robo2){
        if(robo->linha_robo1 == 0)
            robo->linha_robo1++;
        else if(robo->linha_robo1 == LINHA-1)
            robo->linha_robo1--;
        else if(robo->coluna_robo1 == 0)
            robo->coluna_robo1++;
        else if(robo->coluna_robo1 == COLUNA-1)
            robo->coluna_robo1--;
        else if(robo->linha_robo2 == 0)
            robo->linha_robo2++;
        else if(robo->linha_robo2 == LINHA-1)
            robo->linha_robo2--;
        else if(robo->coluna_robo2 == 0)
            robo->coluna_robo2++;
        else if(robo->coluna_robo2 == COLUNA-1)
            robo->coluna_robo2--;
    }
}





