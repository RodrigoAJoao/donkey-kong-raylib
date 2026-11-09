#include "raylib.h"
#include "map.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "renderMapa.h"
#include "game_structs.h"

void initPos(MAP *mapa, PLAYER *p, ENEMY *e)
{
    int contador = 0;

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
            }
            else if(mapa->matriz[i][j] == 'E')
            {
                e[contador].position.x = MARGEM + (j*30);
                e[contador].position.y = MARGEM + (i*30);
                e[contador].velocity.x = 0;
                e[contador].velocity.y = 0;
                contador++;
            }
        }
    }
}
