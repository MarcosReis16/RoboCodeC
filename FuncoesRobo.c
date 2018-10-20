#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include "FuncoesRobo.h"


Robo* cria_robo(){
    Robo *r = (Robo*)malloc(sizeof(Robo));
    if(r == NULL)
        exit(1);

    return r;
}
int metodo(int mat[LINHA][COLUNA],Robo *robo){
            //PRIMEIRO ROBO
    if(robo->hp >= 0){
        if(robo->linha > 0)
            robo->linha -= rand()%2;

        if(robo->coluna > 0)
            robo->coluna -= rand()%2;

        if(robo->linha < LINHA-1)
            robo->linha += rand()%2;

        if(robo->coluna < COLUNA-1)
            robo->coluna += rand()%2;
        return 1;
    }
    mat[robo->linha][robo->coluna] = -1;
    return 0;
}
void arena(int tabuleiro[LINHA][COLUNA],Robo *robo,Robo *robo2,Robo *robo3,int validador){
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
                    printf(".");
                }else if(tabuleiro[linha][coluna]==3){
                    printf("*");
                }else if(tabuleiro[linha][coluna]==4){
                    printf("%s",robo3->nome);
                }else if(tabuleiro[linha][coluna]==5){
                    printf("+");
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
        if(robo->linha == robo2->linha){
            robo2->hp -= robo->tiro;
            robo->qtd_tiro--;
        }
        if(robo->linha == robo3->linha){
            robo3->hp -= robo->tiro;
            robo->hp -= robo3->tiro;
            robo->qtd_tiro--;
            robo3->qtd_tiro--;
        }
        if(robo2->coluna == robo->coluna){
            robo->hp -= robo2->tiro;
            robo2->qtd_tiro--;
        }
        if(robo2->coluna == robo3->coluna){
            robo3->hp -= robo2->tiro;
            robo2->hp -= robo3->tiro;
            robo2->qtd_tiro--;
            robo3->qtd_tiro--;
        }
        if(robo3->linha == robo2->linha){
            robo2->hp -= robo3->tiro;
            robo3->qtd_tiro--;
        }
    }

        printf("\n\nHP ROBO (%s) = %d - Qtd de Tiros: %d\n(Robo %s so atira na horizontal)",robo->nome,robo->hp,robo->qtd_tiro,robo->nome);
        printf("\n\nHP ROBO (%s) = %d - Qtd de Tiros: %d\n(Robo %s so atira na vertical)",robo2->nome,robo2->hp,robo2->qtd_tiro,robo2->nome);
        printf("\n\nHP ROBO (%s) = %d - Qtd de Tiros: %d\n(Robo %s atira na horizontal e vertical)",robo3->nome,robo3->hp,robo3->qtd_tiro,robo3->nome);

}
void mostrarRobo(int mat[LINHA][COLUNA],Robo *robo,Robo* robo2,Robo *robo3){
    if(robo->hp > 0)
        mat[robo->linha][robo->coluna] = 0;
    else
        mat[robo->linha][robo->coluna] = -1;
    if(robo2->hp > 0)
        mat[robo2->linha][robo2->coluna] = 1;
    else
        mat[robo2->linha][robo2->coluna] = -1;
    if(robo3->hp > 0)
        mat[robo3->linha][robo3->coluna] = 4;
    else
        mat[robo3->linha][robo3->coluna] = -1;
}
void apagaRobo(int mat[LINHA][COLUNA],Robo *robo,Robo* robo2,Robo *robo3){
    mat[robo->linha][robo->coluna] = -1;
    mat[robo2->linha][robo2->coluna] = -1;
    mat[robo3->linha][robo3->coluna] = -1;
}
void tiro(int mat[LINHA][COLUNA],int i,int j,int validador){
    if(validador == 0)
        mat[i][j] = 2;
    else if(validador == 1)
        mat[i][j] = 3;
    else
        mat[i][j] = 5;

}
void limpaTiro(int mat[LINHA][COLUNA],int i,int j){
        mat[i][j] = -1;
}
void play_game(int mat[LINHA][COLUNA],Robo *robo,Robo *robo2,Robo *robo3){
    system("cls");
    mostrarRobo(mat,robo,robo2,robo3);
    arena(mat,robo,robo2,robo3,0);
    apagaRobo(mat,robo,robo2,robo3);
    atirar(mat,robo,robo2,robo3);
    Sleep(370);
}
void construct(Robo *robo, Robo* robo2,Robo *robo3){
    strcpy(robo->nome,"X");
    strcpy(robo2->nome,"@");
    strcpy(robo3->nome,"$");
    robo->tiro = 1+rand()%5;
    robo2->tiro = 1+rand()%5;
    robo3->tiro = 1+rand()%5;
    robo->qtd_tiro = 50+rand()%100;
    robo2->qtd_tiro = 50+rand()%100;
    robo3->qtd_tiro = 50+rand()%100;
    robo->hp = robo2->hp = robo3->hp = 100;
    robo->linha = LINHA/3;
    robo->coluna = 0;
    robo2->linha = LINHA-1;
    robo2->coluna = COLUNA/2;
    robo3->linha = 0;
    robo3->coluna = COLUNA-1;
    robo->ptr2 = metodo;
    robo2->ptr2 = metodo;
    robo3->ptr2 = metodo;

}
void preenche_arena(int mat[LINHA][COLUNA]){
    int i,j;

    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            mat[i][j] = -1;
        }
    }
}
void atirar(int mat[LINHA][COLUNA],Robo *robo,Robo *robo2,Robo *robo3){
    //robo 1 atirando no 2

    if(robo->linha == robo2->linha){
        if(robo->coluna < robo2->coluna){
            int aux = robo->coluna;
            int validador = 0;
            while(aux < robo2->coluna-1){
                mostrarRobo(mat,robo,robo2,robo3);
                tiro(mat,robo->linha,aux+1,0);
                system("cls");
                arena(mat,robo,robo2,robo3,validador);
                limpaTiro(mat,robo->linha,aux+1);
                aux++;
                validador++;

            }
            apagaRobo(mat,robo,robo2,robo3);
        }else{//robo 1 atirando no 2
            int aux = robo->coluna;
            int validador = 0;
            while(aux > robo2->coluna+1){
                mostrarRobo(mat,robo,robo2,robo3);
                tiro(mat,robo->linha,aux-1,0);
                system("cls");
                arena(mat,robo,robo2,robo3,validador);
                limpaTiro(mat,robo->linha,aux-1);
                aux--;
                validador++;

            }
                apagaRobo(mat,robo,robo2,robo3);
        }

    }



    //robo 1 atirando no 3
    if(robo->linha == robo3->linha){
        if(robo->coluna < robo3->coluna){

            int aux = robo->coluna;
            int validador = 0;
            while(aux < robo3->coluna-1){
                mostrarRobo(mat,robo,robo2,robo3);
                tiro(mat,robo->linha,aux+1,0);
                system("cls");
                arena(mat,robo,robo2,robo3,validador);
                limpaTiro(mat,robo->linha,aux+1);
                aux++;
                validador++;
            }
            apagaRobo(mat,robo,robo2,robo3);

        if(robo3->hp > 0){
            int aux = robo3->coluna;
            int validador = 0;
            while(aux > robo->coluna+1){
                mostrarRobo(mat,robo,robo2,robo3);
                tiro(mat,robo3->linha,aux-1,-1);
                system("cls");
                arena(mat,robo,robo2,robo3,validador);
                limpaTiro(mat,robo3->linha,aux-1);
                aux--;
                validador++;
            }
            apagaRobo(mat,robo,robo2,robo3);
        }

        }else{//robo 1 atirando no 3

            int aux = robo->coluna;
            int validador = 0;
            while(aux > robo3->coluna+1){
                mostrarRobo(mat,robo,robo2,robo3);
                tiro(mat,robo->linha,aux-1,0);
                system("cls");
                arena(mat,robo,robo2,robo3,validador);
                limpaTiro(mat,robo->linha,aux-1);
                aux--;
                validador++;
            }
                apagaRobo(mat,robo,robo2,robo3);


        if(robo3->hp > 0){
            int aux = robo3->coluna;
            int validador = 0;
            while(aux < robo->coluna-1){
                mostrarRobo(mat,robo,robo2,robo3);
                tiro(mat,robo3->linha,aux+1,-1);
                system("cls");
                arena(mat,robo,robo2,robo3,validador);
                limpaTiro(mat,robo3->linha,aux+1);
                aux++;
                validador++;
            }
            apagaRobo(mat,robo,robo2,robo3);
           }

        }

    }

            //robo 2 atirando no 1

    if(robo2->coluna == robo->coluna){
        if(robo2->linha < robo->linha){
            int aux = robo2->linha;
            int validador = 0;
            while(aux < robo->linha-1){
                mostrarRobo(mat,robo,robo2,robo3);
                tiro(mat,aux+1,robo2->coluna,1);
                system("cls");
                arena(mat,robo,robo2,robo3,validador);
                limpaTiro(mat,aux+1,robo2->coluna);
                aux++;
                validador++;
            }
                apagaRobo(mat,robo,robo2,robo3);
    }else{//robo 2 atirando no 1
        int aux = robo2->linha;
        int validador = 0;
        while(aux > robo->linha+1){
            mostrarRobo(mat,robo,robo2,robo3);
            tiro(mat,aux-1,robo2->coluna,1);
            system("cls");
            arena(mat,robo,robo2,robo3,validador);
            limpaTiro(mat,aux-1,robo2->coluna);
            aux--;
            validador++;
        }
            apagaRobo(mat,robo,robo2,robo3);
        }
    }

    //robo 2 atirando no 3


    if(robo2->coluna == robo3->coluna){
        if(robo2->linha < robo3->linha){
            int aux = robo2->linha;
            int validador = 0;
            while(aux < robo3->linha-1){
                mostrarRobo(mat,robo,robo2,robo3);
                tiro(mat,aux+1,robo2->coluna,1);
                system("cls");
                arena(mat,robo,robo2,robo3,validador);
                limpaTiro(mat,aux+1,robo2->coluna);
                aux++;
                validador++;
            }
                apagaRobo(mat,robo,robo2,robo3);
    }else{//robo 2 atirando no 3
        int aux = robo2->linha;
        int validador = 0;
        while(aux > robo3->linha+1){
            mostrarRobo(mat,robo,robo2,robo3);
            tiro(mat,aux-1,robo2->coluna,1);
            system("cls");
            arena(mat,robo,robo2,robo3,validador);
            limpaTiro(mat,aux-1,robo2->coluna);
            aux--;
            validador++;
        }
            apagaRobo(mat,robo,robo2,robo3);
        }
    }


    //robo 3 atirando no 2 (linha)

    if(robo3->linha == robo2->linha){
        if(robo3->coluna < robo2->coluna){
            int aux = robo3->coluna;
            int validador = 0;
            while(aux < robo2->coluna-1){
                mostrarRobo(mat,robo,robo2,robo3);
                tiro(mat,robo3->linha,aux+1,-1);
                system("cls");
                arena(mat,robo,robo2,robo3,validador);
                limpaTiro(mat,robo3->linha,aux+1);
                aux++;
                validador++;

            }
            apagaRobo(mat,robo,robo2,robo3);
        }else{//robo 3 atirando no 2 (linha)
            int aux = robo3->coluna;
            int validador = 0;
            while(aux > robo2->coluna+1){
                mostrarRobo(mat,robo,robo2,robo3);
                tiro(mat,robo3->linha,aux-1,-1);
                system("cls");
                arena(mat,robo,robo2,robo3,validador);
                limpaTiro(mat,robo3->linha,aux-1);
                aux--;
                validador++;

            }
            apagaRobo(mat,robo,robo2,robo3);
        }
    }

    //robo 3 atirando no 1 (coluna)

    if(robo3->coluna == robo->coluna){
        if(robo3->linha < robo->linha){
            int aux = robo3->linha;
            int validador = 0;
            while(aux < robo->linha-1){
                mostrarRobo(mat,robo,robo2,robo3);
                tiro(mat,aux+1,robo3->coluna,-1);
                system("cls");
                arena(mat,robo,robo2,robo3,validador);
                limpaTiro(mat,aux+1,robo3->coluna);
                aux++;
                validador++;
            }
                apagaRobo(mat,robo,robo2,robo3);
    }else{//robo 3 atirando no 1 (coluna)
        int aux = robo3->linha;
        int validador = 0;
        while(aux > robo->linha+1){
            mostrarRobo(mat,robo,robo2,robo3);
            tiro(mat,aux-1,robo2->coluna,-1);
            system("cls");
            arena(mat,robo,robo2,robo3,validador);
            limpaTiro(mat,aux-1,robo3->coluna);
            aux--;
            validador++;
        }
            apagaRobo(mat,robo,robo2,robo3);
        }
    }

    //robo 3 atirando no 2 (coluna)

    if(robo3->coluna == robo2->coluna){
        if(robo3->linha < robo2->linha){
            int aux = robo3->linha;
            int validador = 0;
            while(aux < robo2->linha-1){
                mostrarRobo(mat,robo,robo2,robo3);
                tiro(mat,aux+1,robo3->coluna,-1);
                system("cls");
                arena(mat,robo,robo2,robo3,validador);
                limpaTiro(mat,aux+1,robo3->coluna);
                aux++;
                validador++;
            }
                apagaRobo(mat,robo,robo2,robo3);
    }else{//robo 3 atirando no 2 (coluna)
        int aux = robo3->linha;
        int validador = 0;
        while(aux > robo2->linha+1){
            mostrarRobo(mat,robo,robo2,robo3);
            tiro(mat,aux-1,robo2->coluna,-1);
            system("cls");
            arena(mat,robo,robo2,robo3,validador);
            limpaTiro(mat,aux-1,robo3->coluna);
            aux--;
            validador++;
            }
            apagaRobo(mat,robo,robo2,robo3);
        }
    }

}
void verifica(Robo* robo,Robo* robo2, Robo* robo3){
    if((robo->linha - robo2->linha) == 1 || (robo->linha - robo2->linha) == -1  && (robo->coluna - robo2->coluna) == 1 || (robo->coluna - robo2->coluna) == -1 && (robo->linha - robo3->linha) == 1 || (robo->linha - robo3->linha) == -1  && (robo->coluna - robo3->coluna) == 1 || (robo->coluna - robo3->coluna) == -1 && (robo2->linha - robo3->linha) == 1 || (robo2->linha - robo3->linha) == -1  && (robo2->coluna - robo3->coluna) == 1 || (robo2->coluna - robo3->coluna) == -1){
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
        else if(robo3->linha == 0)
            robo3->linha++;
        else if(robo3->linha == LINHA-1)
            robo3->linha--;
        else if(robo3->coluna == 0)
            robo3->coluna++;
        else if(robo3->coluna == COLUNA-1)
            robo3->coluna--;

    }
}
