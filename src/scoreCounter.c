#include "game_structs.h"
#include <stdio.h>


void scoreCounter(PLAYER *p, ENEMY *e, MAP *m, SCORE *s, ESTADOS *state)
{
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
                if(state->flagScore <= 0.0)
                {
                    state->flagScore = 1.5f;
                    s->scorePopUp.x = e[i].position.x;
                    s->scorePopUp.y = e[i].position.y;
                    s->highScore += 500;

                }
            }
        }

        if(state->flagScore > 0.0f)
        {
            state->flagScore -= GetFrameTime();
            DrawText("500", s->scorePopUp.x, s->scorePopUp.y + 30,30,WHITE);
        }
    }

}