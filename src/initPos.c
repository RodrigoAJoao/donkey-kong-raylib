#include "raylib.h"
#include "map.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "renderMapa.h"
#include "game_structs.h"

void initPos(MAP *mapa, PLAYER *p, ENEMY *e)
{
    for(int i = 0; i < LINHA; i++)
    {
        for(int j = 0; j < COLUNA + 1; j++)
        {
            if(mapa->matriz[i][j] == 'P')
            {
                //Transforma a posição na matriz em posição de aspect
                p->position.x = MARGEM + (j*30);
                p->position.y = MARGEM + (i*30);
                printf("mapMatriz[%d][%d]",i,j);
                break;
            }
            else if(mapa->matriz[i][j] == 'E')
            {
                e->position.x = MARGEM + (j*30);
                e->position.y = MARGEM + (i*30);
                break;
            }
        }
    }
}
