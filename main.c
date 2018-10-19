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
    Robo *robo3 = cria_robo();

    construct(robo,robo2,robo3);
    srand(time(NULL));
    preenche_arena(mat);

    mostrarRobo(mat,robo,robo2,robo3);
    arena(mat,robo,robo2,robo3,0);
    apagaRobo(mat,robo,robo2,robo3);

    while(1){

        if(rand()%10 == 0 || rand()%10 == 1 || rand()%10 == 2 || rand()%10 == 3){
            robo->ptr2(robo);
            Sleep(200);
            robo2->ptr2(robo2);
            verifica(robo,robo2);
            play_game(mat,robo,robo2,robo3);
        }

        //FALTA ARRUMAR A CONDIÇÃO DO HP PARA SABER QM É O GANHADOR OU SE DEU EMPATE
        if(robo->hp <= 0 && robo2->hp <= 0){
            printf("\n\nDRAW GAME\n");
            break;
        }else if(robo2->hp <= 0){
            printf("\n\nROBO (%s) WINNER!\n",robo->nome);
            break;
        }else if(robo->hp <= 0){
            printf("\n\nROBO (%s) WINNER!\n",robo2->nome);
            break;
        }
    }

    return 0;
}
