#include "game_structs.h"
#include <stdio.h>

void updateCollision(PLAYER *p, ENEMY *e, MAP *m)
{
    //printf("enemyCounter %d", m->enemyCounter);
    Rectangle playerHitbox = { p->position.x, p->position.y,30,30};

    if(m->enemyCounter > 0)
    {
        Rectangle enemyHitbox[m->enemyCounter];

        for(int i = 0; i < m->enemyCounter; i++)
        {
            enemyHitbox[i] = (Rectangle){e[i].position.x, e[i].position.y, 30,30};

            if(CheckCollisionRecs(playerHitbox, enemyHitbox[i]))
            {
                //printf("MORREU\n");
            }
        }
    }
   
}