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
void arena(int tabuleiro[LINHA][COLUNA],Robo *robo,Robo *robo2,int validador){
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
    if(validador == 0){
        if(robo->linha == robo2->linha || robo->coluna == robo2->coluna){
            robo->hp -= rand()%2;//PROVAVELMENTE VAI SERVIR PARA POTENCIA DO TIRO DO ADVERSARIO
            robo2->hp -= rand()%2;
        }
    }
        printf("\n\nHP ROBO (X) = %d",robo->hp);
        printf("\nHP ROBO (@) = %d",robo2->hp);
}
void mostrarRobo(int mat[LINHA][COLUNA],Robo *robo,Robo* robo2){
    mat[robo->linha][robo->coluna] = 0;
    mat[robo2->linha][robo2->coluna] = 1;
}
void apagaRobo(int mat[LINHA][COLUNA],Robo *robo,Robo* robo2){
    mat[robo->linha][robo->coluna] = -1;
    mat[robo2->linha][robo2->coluna] = -1;
}
void tiro(int mat[LINHA][COLUNA],int i,int j){
        mat[i][j] = 2;

}
void limpaTiro(int mat[LINHA][COLUNA],Robo *robo,int i,int j){
        mat[i][j] = -1;

}
void play_game(int mat[LINHA][COLUNA],Robo *robo,Robo *robo2){

    system("cls");
    verifica(robo,robo2);
    mostrarRobo(mat,robo,robo2);
    arena(mat,robo,robo2,0);
    apagaRobo(mat,robo,robo2);
    atirar(mat,robo,robo2);

    Sleep(370);
}
void construct(Robo *robo, Robo* robo2){
    robo->hp = 100;
    robo2->hp = 100;
    //robo->tiro_robo1 = rand()%5;
    //robo->tiro_robo2 = 4;
    robo->linha = 0;
    robo->coluna = 0;
    robo2->linha = LINHA-1;
    robo2->coluna = COLUNA-1;
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
void atirar(int mat[LINHA][COLUNA], Robo* robo,Robo *robo2){
    if(robo->linha == robo2->linha /*|| robo->y == robo->k*/){//robo X
                if(robo->coluna < robo2->coluna){
                    int aux = robo->coluna;
                    int validador = 0;
                    while(aux < robo2->coluna-1){
                        mostrarRobo(mat,robo,robo2);
                        tiro(mat,robo->linha,aux+1);
                        system("cls");
                        arena(mat,robo,robo2,validador);
                        limpaTiro(mat,robo,robo->linha,aux+1);
                        aux++;
                        validador++;
                    }
                    apagaRobo(mat,robo,robo2);
                }else{//robo X
                    int aux = robo->coluna;
                    int validador = 0;
                    while(aux > robo2->coluna+1){
                        mostrarRobo(mat,robo,robo2);
                        tiro(mat,robo->linha,aux-1);
                        system("cls");
                        arena(mat,robo,robo2,validador);
                        limpaTiro(mat,robo,robo->linha,aux-1);
                        aux--;
                        validador++;
                    }
                    apagaRobo(mat,robo,robo2);
                }

                if(robo2->coluna < robo->coluna){//robo @
                    int aux = robo2->coluna;
                    int validador = 0;
                    while(aux < robo->coluna-1){
                        mostrarRobo(mat,robo,robo2);
                        tiro(mat,robo2->linha,aux+1);
                        system("cls");
                        arena(mat,robo,robo2,validador);
                        limpaTiro(mat,robo,robo2->linha,aux+1);
                        aux++;
                        validador++;
                    }
                    apagaRobo(mat,robo,robo2);
                }else{//robo @
                    int aux = robo2->coluna;
                    int validador = 0;
                    while(aux > robo->coluna+1){
                        mostrarRobo(mat,robo,robo2);
                        tiro(mat,robo2->linha,aux-1);
                        system("cls");
                        arena(mat,robo,robo2,validador);
                        limpaTiro(mat,robo,robo2->linha,aux-1);
                        aux--;
                        validador++;
                    }
                    apagaRobo(mat,robo,robo2);
                }
            }
}
void verifica(Robo* robo,Robo* robo2){
    if(robo->linha == robo2->linha && robo->coluna == robo2->coluna){
        if(robo->linha == 0)
            robo->linha++;
        else if(robo->linha == LINHA-1)
            robo->linha--;
        else if(robo->coluna == 0)
            robo->coluna++;
        else if(robo->coluna == COLUNA-1)
            robo->coluna--;
        else if(robo2->linha == 0)
            robo2->linha++;
        else if(robo2->linha == LINHA-1)
            robo2->linha--;
        else if(robo2->coluna == 0)
            robo2->coluna++;
        else if(robo2->coluna == COLUNA-1)
            robo2->coluna--;
    }
}





