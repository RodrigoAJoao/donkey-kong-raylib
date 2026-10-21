#include "playerMovement.h"
#include "raylib.h"
#include "map.h"
#include "stdio.h"
#include "renderMapa.h"
#include <math.h>
#include "mapTransition.h"
#include <string.h>
#include "initPos.h"

void mapTransition(Vector2 *playerPosition, int linhaPlayer, int colunaPlayer, char mapmatriz[LINHA][COLUNA + 1])
{
    map("maps/mapa2.txt", mapmatriz);
    initPos(mapmatriz, playerPosition);
}