#include <stdio.h>
#include "raylib.h"

#define LARGURA 960 // PASSAR DEPOIS COMO PARAMETRO
#define ALTURA 960


void score(float *highScore,float *tempo,int *time,int *oneUp)
{

    //TITULO DE CADA COMPONENTE
    DrawText("HIGH SCORE", (LARGURA/2) - 90,15,30,RED);
    DrawText("1UP", (LARGURA/4) - 50,15,30,RED);
    DrawText("TIME", ((3 * LARGURA)/4),15,30,RED);
    
    
    *tempo += GetFrameTime();
    printf("tempo: %f", *tempo);
    DrawText(TextFormat("%05i",*highScore),(LARGURA/2)-45,50,30,WHITE);
    DrawText(TextFormat("%05i",*oneUp),(LARGURA/4) - 75,50,30,WHITE);
    DrawText(TextFormat("%03i",(int)*tempo),((3 * LARGURA)/4) + 20,50,30,WHITE);

    





    /*DrawLine(LARGURA/2,0,LARGURA/2,ALTURA,WHITE);
    DrawLine(((3 * LARGURA)/4),0,((3 * LARGURA)/4),ALTURA,WHITE); //DEBUG DE POSICIONAMENTO DO HUD
    DrawLine((LARGURA/4),0,(LARGURA/4),ALTURA,WHITE);*/
}