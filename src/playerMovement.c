#include "playerMovement.h"
#include "raylib.h"
#include "map.h"
#include "stdio.h"
#include "renderMapa.h"
#include <math.h>

void playerMovement(Vector2 *playerPosition,char mapMatriz[LINHA][COLUNA + 1], int *subirEscada,int *linhaEscada,int *colunaEscada)
{
	//Aqui faz a transformação de posição em aspect para a posição na matriz
	int colunaPlayer = floorf((playerPosition->x - 30) / 30);
	float colunaPlayertrue = ((playerPosition->x - 30) / 30);
	int linhaPlayer = ceil((playerPosition->y - 30) / 30);
	float linhaPlayerTrue = ((playerPosition->y - 30) / 30);
	
	printf("mapMatriz[%d][%d] = %c\n colunaPlayertrue = %0.2f linhaPlayerTrue = %0.2f \n", linhaPlayer, colunaPlayer, mapMatriz[linhaPlayer][colunaPlayer],colunaPlayertrue,ceilf(linhaPlayerTrue));

	//Checa se tem uma plataforma Z embaixo do jogador
	if(mapMatriz[linhaPlayer+1][colunaPlayer] == 'Z' || *subirEscada == 0)
	{
		// Trata entrada do usuario e atualiza estado do jogo
		if (IsKeyDown(KEY_RIGHT)) {
			playerPosition->x += 2;
		}
		if (IsKeyDown(KEY_LEFT)) {
			playerPosition->x -= 2;
		}
	}

	
	if(mapMatriz[linhaPlayer][colunaPlayer] == 'S' && *subirEscada == 0)
	{
			int contador = 1;
			int d = 0;

			while(d == 0)
			{
				if(mapMatriz[linhaPlayer - contador][colunaPlayer] == 'D')
				{
					*linhaEscada = linhaPlayer - contador;
					*colunaEscada = colunaPlayer;
					d++;
				}
				contador++;
			}
			*subirEscada = 1;
	}
	

		//printf("linhaPlayer: %d,colunaPlayer: %d, mapmatriz:[%c] mapmatriz_linha+1[%c]", linhaPlayer,colunaPlayer,mapMatriz[linhaPlayer][colunaPlayer],mapMatriz[linhaPlayer-1][colunaPlayer]);
	

	if(*subirEscada == 1)
	{
		//printf("linhaPlayer-%d\n linhaEscada-1 %d", linhaPlayer,*linhaEscada - 1);
		if(linhaPlayer > *linhaEscada - 1 && colunaPlayer == *colunaEscada) // ARRUMAR A VARIÁVEL LINHAPLAYERTRUE
		{
			if (IsKeyDown(KEY_UP)) {
				playerPosition->y -= 2;
			}
			if(IsKeyDown(KEY_DOWN))
			{
				playerPosition->y +=2;
			}
		}
		else
		{
			*subirEscada = 0;
		}
	}


}