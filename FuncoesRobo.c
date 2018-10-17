#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include <time.h>
#include "robo.h"

Robo* cria_robo(){
    Robo *r = (Robo*)malloc(sizeof(Robo));
    if(r == NULL)
        exit(1);

    return r;
}

void metodo(Robo *robo){
            //PRIMEIRO ROBO

        if(robo->linha > 0)
            robo->linha -= rand()%2;

        if(robo->coluna > 0)
            robo->coluna -= rand()%2;

        if(robo->linha < LINHA-1)
            robo->linha += rand()%2;

        if(robo->coluna < COLUNA-1)
            robo->coluna += rand()%2;

}
void metodo2(Robo *robo2){
            //SEGUNDO ROBO

        if(robo2->linha < LINHA-1)
            robo2->linha += rand()%2;

        if(robo2->coluna < COLUNA-1)
            robo2->coluna += rand()%2;

        if(robo2->linha > 0)//robo->z > 0 -- ANDA EM TODO MAPA // robo->z > LINHA-5 (SO FICA NO CANTO)
            robo2->linha -= rand()%2;

        if(robo2->coluna > 0)//robo->z > 0 -- ANDA EM TODO MAPA //robo->k > COLUNA-5 (SO FICA NO CANTO)
            robo2->coluna -= rand()%2;

}
void arena(int tabuleiro[LINHA][COLUNA],Robo *robo,Robo *robo2,int validador){
    int linha,coluna;

    for(linha=0;linha<COLUNA;linha++){
        if(linha==0)
            printf(" -");
        else
            printf("-");
    }
    printf("\n");
    for(linha=0 ; linha < LINHA ; linha++ ){
            printf("|");
            for(coluna=0 ; coluna < COLUNA ; coluna++ ){
                if(tabuleiro[linha][coluna]==-1){
                    printf(" ");
                }else if(tabuleiro[linha][coluna]==0){
                    printf("%s",robo->nome);
                }else if(tabuleiro[linha][coluna]==1){
					printf("%s",robo2->nome);
				}else if(tabuleiro[linha][coluna]==2){
				    if(rand()%2 == 0)
                        printf("*");
                    else
                        printf(".");
                }else if(tabuleiro[linha][coluna]==3){
                    if(rand()%2 == 0)
                        printf("*");
                    else
                        printf(".");
                }
            }
            if(coluna == COLUNA)
                printf("|");
            printf("\n");
    }
    for(linha=0;linha<COLUNA;linha++){
        if(linha==0)
            printf(" -");
        else
            printf("-");
    }
    if(validador == 0){
        if(robo->linha == robo2->linha)
            robo->hp -= rand()%2;//PROVAVELMENTE VAI SERVIR PARA POTENCIA DO TIRO DO ADVERSARIO
        if(robo->coluna == robo2->coluna)
            robo2->hp -= rand()%2;
    }
        printf("\n\nHP ROBO (X) = %d\n(Robo X so atira na horizontal)",robo->hp);
        printf("\n\nHP ROBO (@) = %d\n(Robo @ so atira na vertical)",robo2->hp);
}
void mostrarRobo(int mat[LINHA][COLUNA],Robo *robo,Robo* robo2){
    mat[robo->linha][robo->coluna] = 0;
    mat[robo2->linha][robo2->coluna] = 1;
}
void apagaRobo(int mat[LINHA][COLUNA],Robo *robo,Robo* robo2){
    mat[robo->linha][robo->coluna] = -1;
    mat[robo2->linha][robo2->coluna] = -1;
}
void tiro(int mat[LINHA][COLUNA],int i,int j,int validador){
    if(validador == 0)
        mat[i][j] = 2;
    else
        mat[i][j] = 3;
}
void limpaTiro(int mat[LINHA][COLUNA],int i,int j){
        mat[i][j] = -1;
}
int tiro_robo2(int mat[LINHA][COLUNA],int i,int j){
    if(mat[i][j] == 0)
        return 1;
    return 0;
}
void play_game(int mat[LINHA][COLUNA],Robo *robo,Robo *robo2){
    system("cls");
    verifica(robo,robo2);
    mostrarRobo(mat,robo,robo2);
    arena(mat,robo,robo2,0);
    apagaRobo(mat,robo,robo2);
    Sleep(370);
    atirar(mat,robo,robo2);
    int i;
    //for(i=0;i<9999999;i++){}
    //Sleep(370);
}
void construct(Robo *robo, Robo* robo2){
    strcpy(robo->nome,"X");
    strcpy(robo2->nome,"@");
    robo->hp = 100;
    robo2->hp = 100;
    //robo->tiro_robo1 = rand()%5;
    //robo->tiro_robo2 = 4;
    robo->linha = 0;
    robo->coluna = 0;
    robo2->linha = LINHA-1;
    robo2->coluna = COLUNA-1;
    robo->ptr = play_game;
    robo->ptr2 = metodo;
    robo2->ptr2 = metodo2;
}
void preenche_arena(int mat[LINHA][COLUNA]){
    int i,j;

    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            mat[i][j] = -1;
        }
    }
}
void atirar(int mat[LINHA][COLUNA],Robo* robo,Robo *robo2){
    //robo X
    if(robo->linha == robo2->linha){
        if(robo->coluna < robo2->coluna){
            int aux = robo->coluna;
            int validador = 0;
            while(aux < robo2->coluna-1){
                mostrarRobo(mat,robo,robo2);
                tiro(mat,robo->linha,aux+1,0);
                system("cls");
                arena(mat,robo,robo2,validador);
                limpaTiro(mat,robo->linha,aux+1);
                aux++;
                validador++;
            }
            apagaRobo(mat,robo,robo2);
        }else{//robo X
            int aux = robo->coluna;
            int validador = 0;
            while(aux > robo2->coluna+1){
                mostrarRobo(mat,robo,robo2);
                tiro(mat,robo->linha,aux-1,0);
                system("cls");
                arena(mat,robo,robo2,validador);
                limpaTiro(mat,robo->linha,aux-1);
                aux--;
                validador++;
            }
                apagaRobo(mat,robo,robo2);
            }

    }
            //robo @
    if(robo2->coluna == robo->coluna){
        if(robo2->linha < robo->linha){
            int aux = robo2->linha;
            int validador = 0;
            while(aux < robo->linha-1){
                mostrarRobo(mat,robo,robo2);
                tiro(mat,aux+1,robo2->coluna,1);
                system("cls");
                arena(mat,robo,robo2,validador);
                limpaTiro(mat,aux+1,robo2->coluna);
                aux++;
                validador++;
            }
                apagaRobo(mat,robo,robo2);
    }else{//robo @
        int aux = robo2->linha;
        int validador = 0;
        while(aux > robo->linha+1){
            mostrarRobo(mat,robo,robo2);
            tiro(mat,aux-1,robo2->coluna,1);
            system("cls");
            arena(mat,robo,robo2,validador);
            limpaTiro(mat,aux-1,robo2->coluna);
            aux--;
            validador++;
        }
            apagaRobo(mat,robo,robo2);
        }
    }
}
void verifica(Robo* robo,Robo* robo2){
    if((robo->linha - robo2->linha) == 1 || (robo->linha - robo2->linha) == -1  && (robo->coluna - robo2->coluna) == 1 || (robo->coluna - robo2->coluna) == -1){
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




