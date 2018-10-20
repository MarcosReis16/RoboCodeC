#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include "FuncoesRobo.h"



/*########################################################
Curso: Análise e Desenvolvimento de Sistemas
Alunos: Roger Maurício M. Souza
        Marcos Vinícius Pereira dos Reis

##########################################################*/



int main()
{

    srand(time(NULL));
    int mat[LINHA][COLUNA];
    Robo *robo = cria_robo();
    Robo *robo2 = cria_robo();
    Robo *robo3 = cria_robo();
    robo->vitorias = robo2->vitorias = robo3->vitorias = 0;
    construct(robo,robo2,robo3);
    srand(time(NULL));
    preenche_arena(mat);

    mostrarRobo(mat,robo,robo2,robo3);
    arena(mat,robo,robo2,robo3,0);
    apagaRobo(mat,robo,robo2,robo3);

    while(1){

        if(rand()%10 == 0 || rand()%10 == 1 || rand()%10 == 2 || rand()%10 == 3){
            if(robo->ptr2(mat,robo)){
               robo->ptr2(mat,robo);
                Sleep(200);
            }
            if(robo2->ptr2(mat,robo2)){
               robo2->ptr2(mat,robo2);
                Sleep(200);
            }
            if(robo3->ptr2(mat,robo3))
               robo3->ptr2(mat,robo3);

            verifica(robo,robo2,robo3);
            play_game(mat,robo,robo2,robo3);
        }

        if(robo->hp <= 0 && robo2->hp <= 0){
            printf("\n\nROBO(%s) WINNER!\n",robo3->nome);
            robo3->vitorias++;

            break;
        }else if(robo->hp <= 0 && robo3->hp <= 0){
            printf("\n\nROBO(%s) WINNER!\n",robo2->nome);
            robo2->vitorias++;
            break;
        }else if(robo2->hp <= 0 && robo3->hp <= 0){
            printf("\n\nROBO(%s) WINNER!\n",robo->nome);
            robo->vitorias++;
            break;
        }
    }
    return 0;
}

