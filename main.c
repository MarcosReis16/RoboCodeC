#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FuncoesRobo.h"

int main()
{
    Robo *robo = cria_robo();
    construct(robo);
    int aux;
    srand(time(NULL));

    while(1){
        robo->ptr(robo);
        aux = rand()%2;
        if(aux == 0){
            if(robo->x > 0)
                robo->x--;
        }else if(aux == 1){
            if(robo->x < 20)
                robo->x++;
        }
        system("clear");
    }
    return 0;
}
