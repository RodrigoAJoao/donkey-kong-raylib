#include "raylib.h"
#include "game_structs.h"
#include "stdio.h"


void EnemyMovement(ENEMY *e,MAP *mapa)
{
    int colunaEnemy = (int)((e->position.x - 30) / 30);
	int linhaEnemy = (int)((e->position.y - 30) / 30);

    if(e->velocity.x == 0 )
    {
        e->velocity.x = 1;
    }
    //printf("mapa->matriz[linhaEnemy][colunaEnemy] == %c VELOCITY == %0.1f\n", mapa->matriz[linhaEnemy+1][colunaEnemy+1], e->velocity.x);
    

    if(mapa->matriz[linhaEnemy][colunaEnemy] == 'E' ||mapa->matriz[linhaEnemy][colunaEnemy] == 'S'|| mapa->matriz[linhaEnemy][colunaEnemy] == ' ' || mapa->matriz[linhaEnemy][colunaEnemy] == 'D')
    {
        if(e->velocity.x > 0 && mapa->matriz[linhaEnemy + 1][colunaEnemy + 1] == ' ' || mapa->matriz[linhaEnemy + 1][colunaEnemy + 1] == '\n' )
        {
            e->velocity.x = -1;
        }
        else if(e->velocity.x < 0 && mapa->matriz[linhaEnemy + 1][colunaEnemy - 1] == ' ' || mapa->matriz[linhaEnemy + 1][colunaEnemy + 1] == '\n')
        {
            e->velocity.x = 1;
        }
        //ADD INÉRCIA POR VELOCITY AQUI DEPOIS
        e->position.x += 2 * e->velocity.x;

    }


    
}