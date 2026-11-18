#include "game_structs.h"
#include "resetGame.h"

void GameOver(ESTADOS *s)
{
    s->flagStart = 0;
    s->flagMenu = 1;
}