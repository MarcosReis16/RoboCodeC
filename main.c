#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
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

        if(rand()%10 == 0 || rand()%10 == 1 || rand()%10 == 2 || rand()%10 == 3){
            robo->ptr2(robo);
            robo2->ptr2(robo2);
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
