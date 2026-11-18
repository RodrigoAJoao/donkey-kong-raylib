#include "game_structs.h"
#include "raylib.h"

void pauseMenu(ESTADOS *state)
{
    Rectangle botaoContinuar = { (LARGURA/2) - 100, ALTURA/3, MeasureText("CONTINUAR", 50),50};
    Rectangle botaoConfiguracoes = { (LARGURA/2) - 150, ALTURA/3 + 150, MeasureText("CONFIGURACOES", 50),50};
    Rectangle botaoMenu = { (LARGURA/2) - 150, ALTURA/3 + 300, MeasureText("MENU PRINCIPAL", 50),50};


    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.6f)); //Escurece a tela do jogo

    DrawRectangleRec(botaoContinuar,GREEN);
    DrawRectangleRec(botaoConfiguracoes,BLUE);
    DrawRectangleRec(botaoMenu,RED);
    DrawText("CONTINUAR",(LARGURA/2) - 100,ALTURA/3,50,WHITE);
    DrawText("CONFIGURAÇÕES",(LARGURA/2) - 150, ALTURA/3 + 150,50,WHITE);
    DrawText("MENU PRINCIPAL",(LARGURA/2) - 150, ALTURA/3 + 300,50,WHITE);

    
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 mouse_pos = GetMousePosition();

        if(CheckCollisionPointRec(mouse_pos,botaoContinuar))
        {
            state->flagPause = 1;
        }
        else if(CheckCollisionPointRec(mouse_pos,botaoMenu))
        {
            state->flagStart = 0;
            state->flagMenu = 1;
            state->flagRanking = 0;
        }
        else if (CheckCollisionPointRec(mouse_pos,botaoConfiguracoes))
        {
            //ADICIONAR ABA CONFIGURAÇÕES
        }
        
    }

}