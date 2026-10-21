#include "raylib.h"
#include "map.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "renderMapa.h"

void initPos(char mapMatriz[LINHA][COLUNA + 1], Vector2 *playerPosition)
{
    for(int i = 0; i < LINHA; i++)
    {
        for(int j = 0; j < COLUNA + 1; j++)
        {
            if(mapMatriz[i][j] == 'P')
            {
                //Transforma a posição na matriz em posição de aspect
                playerPosition->x = MARGEM + (j*30);
                playerPosition->y = MARGEM + (i*30);
                printf("mapMatriz[%d][%d]",i,j);
                break;
            }
        }
    }
}
