#include "game_structs.h"
#include <stdio.h>
#include "initPos.h"
#include "GameOver.h"

void updateCollision(PLAYER *p, ENEMY *e, MAP *m, SCORE *s, ESTADOS *state)
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
                //printf("p->cooldownHit - %d", p->cooldownHit);
                //ADD COOLDOWN DO HIT DO INIMIGO
                    p->vida--;
                    s->oneUp--;

                    
                    if(p->vida <= 0)
                    {
                        state->flagGameOver = 1;
                    }
                    else
                    {
                        p->velocity.y = 0;
                        p->isJumping = 0;
                        p->subirEscada = 0;

                        initPos(m,p,e);
                    }

                    break;
                }
                
            }
        }
    }
   
