#include <stdio.h>
#include "raylib.h"
#include "game_structs.h"


void score(SCORE *score)
{

    //TITULO DE CADA COMPONENTE
    DrawText("HIGH SCORE", (LARGURA/2) - 90,15,30,RED);
    DrawText("1UP", (LARGURA/4) - 50,15,30,RED);
    DrawText("TIME", ((3 * LARGURA)/4),15,30,RED);
    
    
    score->tempo += GetFrameTime();
    //printf("tempo: %f", *tempo);
    DrawText(TextFormat("%05i",score->highScore),(LARGURA/2)-45,50,30,WHITE);
    DrawText(TextFormat("%05i",score->oneUp),(LARGURA/4) - 75,50,30,WHITE);
    DrawText(TextFormat("%03i",(int)score->tempo),((3 * LARGURA)/4) + 20,50,30,WHITE);

    





    /*DrawLine(LARGURA/2,0,LARGURA/2,ALTURA,WHITE);
    DrawLine(((3 * LARGURA)/4),0,((3 * LARGURA)/4),ALTURA,WHITE); //DEBUG DE POSICIONAMENTO DO HUD
    DrawLine((LARGURA/4),0,(LARGURA/4),ALTURA,WHITE);*/
}