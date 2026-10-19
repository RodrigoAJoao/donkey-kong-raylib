#include "raylib.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "playerMovement.h"
#include "map.h"
#include "render_mapa.h"

#define LARGURA 990 // 990 pois temos a matriz do mapa 30x30 e uma margem de 90 para caber tudo na tela
#define ALTURA 990

int main(){

    srand(time(NULL)); //Inicializa seed de número aleatório

    InitWindow(LARGURA, ALTURA, "Teclas"); //Inicializa janela, com certo tamanho e titulo
    SetTargetFPS(60);// Ajusta a janela para 60 frames por segundo

	Vector2 playerPosition = {(float)LARGURA/2,(float)ALTURA/2};

    //Função que carrega o mapa a partir do txt
    char mapMatriz[LINHA][COLUNA + 1];//Coluna + 1 para comportar o \n e o \0 no final
    map("maps/mapa_n_vel_1.txt", mapMatriz);


    //Este laco repete enquanto a janela nao for fechada
    //Utilizamos ele para atualizar o estado do programa / jogo
    while (!WindowShouldClose())
    {
        //Função atualiza a posição do player a cada frame
		playerMovement(&playerPosition.x,&playerPosition.y);

		// Atualiza o que eh mostrado na tela a partir do estado do jogo
		BeginDrawing(); //Inicia o ambiente de desenho na tela
			ClearBackground(RAYWHITE); //Limpa a tela e define cor de fundo
			DrawRectangle(playerPosition.x,playerPosition.y,30,30,RED);
            render_mapa(mapMatriz);
            /*DrawRectangle(60,ALTURA - 60,30,30,BLUE);
            DrawRectangle(90,ALTURA - 60,30,30,BLUE);
            DrawRectangle(60,60,30,30,BLUE);*/
		EndDrawing(); //Finaliza o ambiente de desenho na tela
    }

    CloseWindow(); // Fecha a janela
    return 0;
}