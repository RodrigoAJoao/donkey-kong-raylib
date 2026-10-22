#include "raylib.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "playerMovement.h"
#include "map.h"
#include "renderMapa.h"
#include "initPos.h"
#include "mainMenu.h"
#include "rankingMenu.h"
#include"score.h"


#define LARGURA 960 // 990 pois temos a matriz do mapa 30x30 e uma margem de 90 para caber tudo na tela
#define ALTURA 960

int main(){
    //Inicializa seed de número aleatório
    srand(time(NULL));
    //Inicializa janela, com certo tamanho e titulo
    InitWindow(LARGURA, ALTURA, "Donkey Kong Raylib");
    // Ajusta a janela para 60 frames por segundo
    SetTargetFPS(60);

    //MAPA
    //Coluna + 1 para comportar o \n e o \0 no final
    char mapMatriz[LINHA][COLUNA + 1];
    //memset limpa todo o lixo que tiver na memória
    memset(mapMatriz, ' ', sizeof(mapMatriz));
    //Função que carrega o mapa a partir do txt
    map("maps/mapa1.txt", mapMatriz);


    //PLAYER
    Vector2 playerPosition = {0,0};
    //Atribui a posição inicial do player (e inimigos(colocar depois)) com base na matriz do txt
    initPos(mapMatriz, &playerPosition);
    //Flag de se o player está em uma escada
    int subirEscada = 0;
    //Pega a linha e coluna de D quando o jogador está numa escada
    int linhaInicioEscada = 0;
    int linhaFimEscada = 0;
    int colunaEscada = 0;
    //IMPORTANTE TRANSFORMAR ISSO EM STRUCT OU COLOCAR UMA LÓGICA MELHOR ORGANIZADA

    //ESTADOS
    int flagMenu = 1;
    int flagRanking = 0;
    int flagStart = 0;

    //SCORE
    float highScore = 0;
    int oneUp = 0;
    float tempo = 0;
    int time = 0;

    

    //Este laco repete enquanto a janela nao for fechada
    //Utilizamos ele para atualizar o estado do programa / jogo
    while (!WindowShouldClose())
    {
        if(flagMenu == 0 && flagRanking == 0)
        {   //Função atualiza a posição do player a cada frame
		    playerMovement(&playerPosition,mapMatriz,&subirEscada,&linhaInicioEscada,&linhaFimEscada,&colunaEscada);
        }

		// Atualiza o que eh mostrado na tela a partir do estado do jogo
		BeginDrawing(); //Inicia o ambiente de desenho na tela
            if(flagMenu == 1 && flagRanking == 0)
            {
                mainMenu(&flagMenu,&flagRanking,&flagStart);
            }
            else if(flagRanking == 1 && flagMenu == 0)
            {
                rankingMenu();
            }
            else if(flagStart == 1)
            {
                ClearBackground(BLACK); //Limpa a tela e define cor de fundo
                renderMapa(mapMatriz);
                DrawRectangle(playerPosition.x,playerPosition.y,30,30,PINK);
                score(&highScore,&tempo,&time,&oneUp);
            }
		EndDrawing(); //Finaliza o ambiente de desenho na tela
    }

    CloseWindow(); // Fecha a janela
    return 0;
}