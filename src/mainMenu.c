#include "raylib.h"

#define LARGURA 960 // PASSAR DEPOIS COMO PARAMETRO
#define ALTURA 960

void mainMenu(int *flagMenu,int *flagRanking, int *flagStart)
{
    Rectangle botao_start = { (LARGURA/2) - 100, ALTURA/3, 200, 75};
    Rectangle botao_ranking = { (LARGURA/2) - 100, ALTURA/3 + 150, 250, 75};
    Rectangle botao_sair = { (LARGURA/2) - 100, ALTURA/3 + 300, 250, 75};

    ClearBackground(BLACK);
    DrawRectangleRec(botao_start,GREEN);
    DrawRectangleRec(botao_ranking,RED);
    DrawRectangleRec(botao_sair,BLUE);
    DrawText("START",((LARGURA/2) - 100) + 10,(ALTURA/3) + 15,50,WHITE);
    DrawText("RANKING",((LARGURA/2) - 100) + 10,(ALTURA/3) + 150 + 15,50,WHITE);
    DrawText("SAIR",((LARGURA/2) - 100) + 10,(ALTURA/3) + 300 + 15,50,WHITE);

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 mouse_pos = GetMousePosition();

        if(CheckCollisionPointRec(mouse_pos,botao_start))
        {
            *flagMenu = 0;
            *flagStart = 1;
            *flagRanking = 0;
        }
        else if(CheckCollisionPointRec(mouse_pos,botao_sair))
        {
            CloseWindow();
        }
        else if (CheckCollisionPointRec(mouse_pos,botao_ranking))
        {
            *flagMenu = 0;
            *flagRanking = 1;
            *flagStart = 0;
        }
        
    }
}