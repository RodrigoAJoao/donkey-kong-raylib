#include "raylib.h"
#include <string.h>
#include <stdlib.h>
#include "playerMovement.h"

#define LARGURA 540
#define ALTURA 960

int main(){
    char texto[50] = "Pressione uma seta"; //Texto inicial

    InitWindow(LARGURA, ALTURA, "Teclas"); //Inicializa janela, com certo tamanho e titulo
    SetTargetFPS(60);// Ajusta a janela para 60 frames por segundo

	Vector2 playerPosition = {(float)LARGURA/2,(float)ALTURA/2};

    //Este laco repete enquanto a janela nao for fechada
    //Utilizamos ele para atualizar o estado do programa / jogo
    while (!WindowShouldClose())
    {

		playerMovement(&playerPosition.x,&playerPosition.y);

		// Atualiza o que eh mostrado na tela a partir do estado do jogo
		BeginDrawing(); //Inicia o ambiente de desenho na tela
			ClearBackground(RAYWHITE); //Limpa a tela e define cor de fundo
			DrawRectangle(playerPosition.x,playerPosition.y,30,30,RED);
		EndDrawing(); //Finaliza o ambiente de desenho na tela
    }

    CloseWindow(); // Fecha a janela
    return 0;
}