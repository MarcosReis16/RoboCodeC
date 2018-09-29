#include <stdio.h>
#include <stdlib.h>
#include "FuncoesRobo.h"

//Roger Mauricio e Marcos Reis

//Função para criar o Robô sem precisar instanciar um objeto na Main.
void criaRobo(int hp){
    Robo *r1 = (Robo*)malloc(sizeof(Robo));
    r1->hp = hp;

    if(r1!=NULL)
        return;
    else
        printf("Memoria insuficiente.\n");
}


