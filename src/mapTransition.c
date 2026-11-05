#include "playerMovement.h"
#include "raylib.h"
#include "map.h"
#include "stdio.h"
#include "renderMapa.h"
#include <math.h>
#include "mapTransition.h"
#include <string.h>
#include "initPos.h"
#include "game_structs.h"

void mapTransition(PLAYER *p, MAP *mapa, ENEMY *e, int linhaPlayer, int colunaPlayer)
{
    strcpy(mapa->local,"maps/mapa2.txt");
    map(mapa);
    initPos(mapa,p,e);
}