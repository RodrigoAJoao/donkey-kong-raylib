#include "raylib.h"

#define LARGURA 960 // PASSAR DEPOIS COMO PARAMETRO
#define ALTURA 930

void mainMenu(int *flagMenu)
{
    Rectangle botao_start = { (LARGURA/2) - 100, ALTURA/3, 200, 75};

    ClearBackground(RAYWHITE);
    DrawRectangleRec(botao_start,BLACK);
    DrawText("START",((LARGURA/2) - 100) + 10,(ALTURA/3) + 15,50,WHITE);

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 mouse_pos = GetMousePosition();

        if(CheckCollisionPointRec(mouse_pos,botao_start))
        {
            *flagMenu = 0;
        }
    }
}