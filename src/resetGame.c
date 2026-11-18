#include "raylib.h"
#include "game_structs.h"
#include "initPos.h"
#include "map.h"
#include <string.h>
#include <stdio.h>

void resetGame(PLAYER *p, ENEMY *e, MAP *m, SCORE *s, ESTADOS *state)
{
    //ESTADOS
    *state = (ESTADOS){
        .flagMenu = 1,
        .flagGameOver = 0,
        .flagRanking = 0,
        .flagStart = 0,
        .flagPause = 1};

    //SCORE
    s->oneUp = 3;
    s->highScore = 0;
    s->tempo = 0;

    //PLAYER
    p->vida = 3;
    p->velocity.x = 5;
    p->velocity.y = 5;
    p->isJumping = 0;
    p->subirEscada = 0;

    //MAPA
    memset(m->matriz, ' ', sizeof(m->matriz));
    m->enemyCounter = 0;
    map(m);

    //ENEMY
    printf("m->enemyCounter %d", m->enemyCounter);
    memset(e, 0, sizeof(ENEMY) * (m->enemyCounter > 0 ? m->enemyCounter : 1));

    //Atribui a posição inicial do player (e inimigos(colocar depois)) com base na matriz do txt
    initPos(m,p,e);

}
