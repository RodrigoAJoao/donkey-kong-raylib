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
#include "EnemyMovement.h"
#include "game_structs.h"
#include "updateCollision.h"
#include "scoreCounter.h"
#include "pauseMenu.h"
#include "GameOver.h"
#include "resetGame.h"


int main(){
   
    //ESTADOS
    ESTADOS gameState = {1,0,0,.flagPause = 1};
    //SCORE
    SCORE gameScore ={.oneUp = 3};

    //MAPA
    MAP mapa = {.local = "maps/mapa1.txt", .enemyCounter = 0};
    memset(mapa.matriz, ' ', sizeof(mapa.matriz));
    map(&mapa);

    //PLAYER
    PLAYER player = {.velocity.y = 5, .velocity.x = 5, .cooldownHit = 0, .vida = 3};
    //ENEMY
    // ENEMY
    ENEMY enemy[mapa.enemyCounter];
    memset(enemy, 0, sizeof(ENEMY) * (mapa.enemyCounter > 0 ? mapa.enemyCounter : 1)); //TIRAR DEPOIS



    //Inicializa seed de número aleatório
    srand(time(NULL));
    //Inicializa janela, com certo tamanho e titulo
    InitWindow(LARGURA, ALTURA, "Donkey Kong Raylib");
    // Ajusta a janela para 60 frames por segundo
    SetTargetFPS(60);

    //Atribui a posição inicial do player (e inimigos(colocar depois)) com base na matriz do txt
    initPos(&mapa,&player,enemy);

    //Este laco repete enquanto a janela nao for fechada
    //Utilizamos ele para atualizar o estado do programa / jogo
    while (!WindowShouldClose())
    {
        if(gameState.flagStart == 1)
        {
            if(gameState.flagPause == 1)
            {   //Função atualiza a posição do player a cada frame
                playerMovement(&player,&mapa,enemy);
                for(int i = 0; i < mapa.enemyCounter; i++)
                {
                    EnemyMovement(&enemy[i],&mapa);
                }

                updateCollision(&player,enemy,&mapa, &gameScore, &gameState); // Checa colisão com o player
                scoreCounter(&player,enemy,&mapa, &gameScore, &gameState); // Checa se o jogador pulou por cima de um inimigo e atualiza o score
            }

            if(IsKeyPressed(KEY_TAB))
            {
                gameState.flagPause *= -1;
            }

            if(gameState.flagGameOver == 1)
            {
                
                //GameOver(&gameState);
                resetGame(&player,enemy,&mapa,&gameScore,&gameState);
            }
        }


		// Atualiza o que eh mostrado na tela a partir do estado do jogo
		BeginDrawing(); //Inicia o ambiente de desenho na tela
            if(gameState.flagMenu == 1)
            {
                mainMenu(&gameState);
                
            }
            else if(gameState.flagRanking == 1)
            {
                rankingMenu();
            }
            else if(gameState.flagStart == 1)
            {

                ClearBackground(BLACK); //Limpa a tela e define cor de fundo
                renderMapa(&mapa);
                //printf("player.position.x - %0.2f player.position.y - %0.2f\n", player.position.x,player.position.y);
                DrawRectangle(player.position.x,player.position.y,30,30,PINK);

                score(&gameScore);
                for(int i = 0; i < mapa.enemyCounter; i++)
                {
                    //printf("enemy_pos[%d] = %0.1f\n", i,enemy[i].position.x);
                    DrawRectangle(enemy[i].position.x,enemy[i].position.y,30,30,RED);
                }

                if(gameState.flagPause == -1)
                {
                    pauseMenu(&gameState);
                }
            }
		EndDrawing(); //Finaliza o ambiente de desenho na tela
    }

    CloseWindow(); // Fecha a janela
    return 0;
}