#include "playerMovement.h"
#include "raylib.h"
#include "map.h"
#include "stdio.h"
#include "renderMapa.h"

void playerMovement(Vector2 *playerPosition,char mapMatriz[LINHA][COLUNA + 1])
{
	//Aqui faz a transformação de posição em aspect para a posição na matriz
	int colunaPlayer = (int)((playerPosition->x - 30) / 30); 
	int linhaPlayer = (int)((playerPosition->y - 30) / 30);

	printf("linhaPlayer: %d,colunaPlayer: %d", linhaPlayer,colunaPlayer);
	//printf("mapMatriz[%d][%d] = %c", linhaPlayer, colunaPlayer, mapMatriz[linhaPlayer+1][colunaPlayer]);

	//Checa se tem uma plataforma Z embaixo do jogador
	if(mapMatriz[linhaPlayer+1][colunaPlayer] == 'Z')
	{
		// Trata entrada do usuario e atualiza estado do jogo
		if (IsKeyDown(KEY_RIGHT)) {
			playerPosition->x += 2;
		}
		if (IsKeyDown(KEY_LEFT)) {
			playerPosition->x -= 2;
		}
	}
	if(mapMatriz[linhaPlayer][colunaPlayer] == 'S' || mapMatriz[linhaPlayer - 1][colunaPlayer] == 'H' || mapMatriz[linhaPlayer - 1][colunaPlayer] == 'D')
	{
		if (IsKeyDown(KEY_UP)) {
			playerPosition->y -= 2;
		}
	}
}