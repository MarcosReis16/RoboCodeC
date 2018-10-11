#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include "FuncoesRobo.h"


int main()
{
    srand(time(NULL));
    int mat[LINHA][COLUNA];
    Robo *robo = cria_robo();
    construct(robo);
    srand(time(NULL));


    /*while(1){

        robo->ptr(robo);
        aux = rand()%2;
        if(aux == 0){
            if(robo->x > 0)
                robo->x--;
        }else if(aux == 1){
            if(robo->x < COLUNA)
                robo->x++;
        }
        system("cls");
    }*/
    tabuleiro(mat);

    while(1){
        if(rand()%3 == 0){
            if(robo->x > 0){
                robo->x -= rand()%2;
                robo->y -= rand()%2;
            }
            if(robo->x < 20){
                robo->x += rand()%2;
                robo->y += rand()%2;
            }
        }
        if(rand()%3 == 0){
            if(robo->z > 0){
                robo->z -= rand()%2;
                robo->k -= rand()%2;
            }
            if(robo->z < 20){
                robo->z += rand()%2;
                robo->y += rand()%2;
            }
        }
        mostraTabuleiro(mat,robo->x,robo->y,robo->z,robo->k);
        //robo->x += rand()%2;
        //robo->y += rand()%2;
        /*if(rand()%2 == 0){
            robo->x -= rand()%2;
            robo->y -= rand()%2;
        }*/

        system("clear");//MUDAR PARA "cls" CASO USE NO WINDOWS
        //Sleep(100);
    }
    return 0;
}
