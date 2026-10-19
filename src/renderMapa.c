#include "raylib.h"
#include "map.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*P Posic¸ao inicial do jogador ˜
 E  Inimigos (1 ou mais)
 Z Plataformas
 S Subida de escada
 D Descida de escada
 F Porta (Final da Fase)
 H Escada (Nenhum efeito apenas sprite visual)
*/
#define LARGURA 960 //Passar como parametro da função ou dentro de um include
#define ALTURA 960  
#define MARGEM 30


void renderMapa(char mapMatriz[LINHA][COLUNA + 1])
{
    for(int i = 0; i < LINHA; i++)
    {
        for(int j = 0; j < COLUNA + 1; j++)
        {
            switch(mapMatriz[i][j]) //Switch case com cada case sendo uma das letras e com isso renderizando cada sprite correspondente
            {
                case('Z'):
                    DrawRectangle(MARGEM + (j*30),MARGEM + (i*30),30,30,BLUE);
                    break;
                case('S'):
                    DrawRectangle(MARGEM + (j*30),MARGEM + (i*30),30,30,LIME);
                    break;
                case('H'):
                    DrawRectangle(MARGEM + (j*30),MARGEM + (i*30),30,30,GREEN);
                    break;
                case('E'):
                    DrawRectangle(MARGEM + (j*30),MARGEM + (i*30),30,30,RED);
                    break;
                case('F'):
                    DrawRectangle(MARGEM + (j*30),MARGEM + (i*30),30,30,YELLOW);
                    break;
                case('D'):
                    DrawRectangle(MARGEM + (j*30),MARGEM + (i*30),30,30,DARKGREEN);
                    break;
                default:
                    break;
            }
        }
    }
}

