#include "game_structs.h"
#include <stdio.h>


void scoreCounter(PLAYER *p, ENEMY *e, MAP *m, SCORE *s, ESTADOS *state)
{
    s->tempo += GetFrameTime();
    int i = 0;
    Rectangle playerHitbox = { p->position.x, p->position.y,30,30};
    

    if(m->enemyCounter > 0)
    {
        Rectangle enemyTrigger[m->enemyCounter];

        for( i = 0; i < m->enemyCounter; i++)
        {
            enemyTrigger[i] = (Rectangle){e[i].position.x, e[i].position.y - 30, 30,30};

            if(CheckCollisionRecs(playerHitbox, enemyTrigger[i]))
            {
                if(s->popUpTimer <= 0.0)
                {
                    s->popUpTimer = 1.5f;
                    s->scorePopUp.x = e[i].position.x;
                    s->scorePopUp.y = e[i].position.y;
                    s->highScore += 500;
                    s->flagPopUp = 1;

                }
            }
        }

        if(s->popUpTimer > 0.0f)
        {
            s->popUpTimer -= GetFrameTime();
        }
        else
        {
            s->flagPopUp = 0;
        }
    }

}