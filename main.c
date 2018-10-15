#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FuncoesRobo.h"

int main()
{
    srand(time(NULL));
    int mat[LINHA][COLUNA];
    Robo *robo = cria_robo();
    construct(robo);
    srand(time(NULL));
    preenche_arena(mat);

    mostrarRobo(mat,robo);
    arena(mat,robo);
    apagaRobo(mat,robo);

    while(1){

        if(rand()%5 == 0){
            //PRIMEIRO ROBO

            if(robo->linha_robo1 > 0)
                robo->linha_robo1 -= rand()%2;

            if(robo->coluna_robo1 > 0)
                robo->coluna_robo1 -= rand()%2;

            if(robo->linha_robo1 < LINHA-1)
                robo->linha_robo1 += rand()%2;

            if(robo->coluna_robo1 < COLUNA-1)
                robo->coluna_robo1 += rand()%2;


        //SEGUNDO ROBO

            if(robo->linha_robo2 < LINHA-1)
                robo->linha_robo2 += rand()%2;

            if(robo->coluna_robo2 < COLUNA-1)
                robo->coluna_robo2 += rand()%2;

            if(robo->linha_robo2 > 0)//robo->z > 0 -- ANDA EM TODO MAPA // robo->z > LINHA-5 (SO FICA NO CANTO)
                robo->linha_robo2 -= rand()%2;

            if(robo->coluna_robo2 > 0)//robo->z > 0 -- ANDA EM TODO MAPA //robo->k > COLUNA-5 (SO FICA NO CANTO)
                robo->coluna_robo2 -= rand()%2;

            robo->ptr(mat,robo);
        }

        if(robo->hp_robo1 <= 0 && robo->hp_robo2 <= 0){
            printf("\nDRAW GAME\n");
            break;
        }else if(robo->hp_robo2 <= 0){
            printf("\nROBO (X) WINNER!\n");
            break;
        }else if(robo->hp_robo1 <= 0){
            printf("\nROBO (@) WINNER!\n");
            break;
        }
    }

    return 0;
}
