#include <stdio.h>
#include "raylib.h"
#include "game_structs.h"


void score(SCORE *score)
{

    //TITULO DE CADA COMPONENTE
    DrawText("HIGH SCORE", (LARGURA/2) - 90,15,30,RED);
    DrawText("LIFE", (LARGURA/4) - 50,15,30,RED);
    DrawText("TIME", ((3 * LARGURA)/4),15,30,RED);
    //printf("tempo: %f", *tempo);
    //printf("HIGHScore = %d\n", score->highScore);
    DrawText(TextFormat("%05i",score->highScore),(LARGURA/2)-45,50,30,WHITE);
    //DrawText(TextFormat("%05i",score->oneUp),(LARGURA/4) - 75,50,30,WHITE);
    DrawText(TextFormat("%03i",(int)score->tempo),((3 * LARGURA)/4) + 20,50,30,WHITE);


    for(int i = 0; i < score->oneUp; i++)
    {
        DrawRectangle(((LARGURA/4) - 75) + i * 50,50,30,30,PINK);
    }

    
    if(score->flagPopUp == 1)
    {
        DrawText("500", score->scorePopUp.x, score->scorePopUp.y + 30,30,WHITE);
    }




    /*DrawLine(LARGURA/2,0,LARGURA/2,ALTURA,WHITE);
    DrawLine(((3 * LARGURA)/4),0,((3 * LARGURA)/4),ALTURA,WHITE); //DEBUG DE POSICIONAMENTO DO HUD
    DrawLine((LARGURA/4),0,(LARGURA/4),ALTURA,WHITE);*/
}