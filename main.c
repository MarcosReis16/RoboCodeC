#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FuncoesRobo.h"

int main()
{
    srand(time(NULL));
    int mat[LINHA][COLUNA];
    Robo *robo = cria_robo();
    Robo *robo2 = cria_robo();
    construct(robo,robo2);
    srand(time(NULL));
    preenche_arena(mat);

    mostrarRobo(mat,robo,robo2);
    arena(mat,robo,robo2,0);
    apagaRobo(mat,robo,robo2);

    while(1){

        if(rand()%5 == 0){
            //PRIMEIRO ROBO

            if(robo->linha > 0)
                robo->linha -= rand()%2;

            if(robo->coluna > 0)
                robo->coluna -= rand()%2;

            if(robo->linha < LINHA-1)
                robo->linha += rand()%2;

            if(robo->coluna < COLUNA-1)
                robo->coluna += rand()%2;


        //SEGUNDO ROBO

            if(robo2->linha < LINHA-1)
                robo2->linha += rand()%2;

            if(robo2->coluna < COLUNA-1)
                robo2->coluna += rand()%2;

            if(robo2->linha > 0)//robo->z > 0 -- ANDA EM TODO MAPA // robo->z > LINHA-5 (SO FICA NO CANTO)
                robo2->linha -= rand()%2;

            if(robo2->coluna > 0)//robo->z > 0 -- ANDA EM TODO MAPA //robo->k > COLUNA-5 (SO FICA NO CANTO)
                robo2->coluna -= rand()%2;

            robo->ptr(mat,robo,robo2);
        }

        if(robo->hp <= 0 && robo2->hp <= 0){
            printf("\nDRAW GAME\n");
            break;
        }else if(robo2->hp <= 0){
            printf("\nROBO (X) WINNER!\n");
            break;
        }else if(robo->hp <= 0){
            printf("\nROBO (@) WINNER!\n");
            break;
        }
    }

    return 0;
}
