#include "playerMovement.h"
#include "raylib.h"
#include "map.h"
#include "stdio.h"
#include "renderMapa.h"
#include <math.h>
#include "mapTransition.h"

void playerMovement(Vector2 *playerPosition,char mapMatriz[LINHA][COLUNA + 1], int *subirEscada,int *linhaInicioEscada, int *linhaFimEscada,int *colunaEscada)
{
	//Aqui faz a transformação de posição em aspect para a posição na matriz
	int colunaPlayer = (int)((playerPosition->x - 30) / 30);
	float colunaPlayerFloat = ((playerPosition->x - 30) / 30);
	int linhaPlayer = (int)((playerPosition->y - 30) / 30);
	float linhaPlayerFloat = ((playerPosition->y - 30) / 30);
	
	printf("mapMatriz[%d][%d] = %c\n colunaPlayertrue = %0.2f linhaPlayerTrue = %0.2f \n", linhaPlayer, colunaPlayer, mapMatriz[linhaPlayer][colunaPlayer],colunaPlayerFloat,linhaPlayerFloat);

	//Checa se tem uma plataforma Z embaixo do jogador
	if(mapMatriz[linhaPlayer+1][colunaPlayer] == 'Z' || mapMatriz[linhaPlayer][colunaPlayer] == 'D' && *subirEscada == 0) //O jogador somente consegue se mover horizontalmente se tem Z Embaixo dele ou D quando sair de escadas
	{
		// Trata entrada do usuario e atualiza estado do jogo
		if (IsKeyDown(KEY_RIGHT)) {
			playerPosition->x += 20;
		}
		if (IsKeyDown(KEY_LEFT)) {
			playerPosition->x -= 20;
		}
	}
	else
	{
		printf("Morreu"); //Checagem se o jogador caiu da plataforma. garante que ele não está em uma escada
	}

	
	//Cáluculo da posição de D quando o jogador estiver em uma posição S, garante que seja modular independente do número de H entre S e D.
	//A flag subirEscada garante que essa função seja chamada somente quando o jogador estiver em S
	if(mapMatriz[linhaPlayer][colunaPlayer] == 'S' && *subirEscada == 0)
	{
			if(IsKeyDown(KEY_UP))
			{
				*linhaInicioEscada = linhaPlayer; //Atribui a linha de S à variável.
				int contador = 1;
				int d = 0;

				while(d == 0) //Loop garante a posição de D independente do número de H, e é sempre calculada independente de qual S o jogador está.
				{
					if(mapMatriz[linhaPlayer - contador][colunaPlayer] == 'D')
					{
						*linhaFimEscada = linhaPlayer - contador;
						*colunaEscada = colunaPlayer;
						d++;
					}
					contador++;
				}
				*subirEscada = 1; //Atualiza a flag para chamar a função de subirescada
			}
	}

	//Calculo de S, baseado em D, serve para se o jogador estiver descendo
	if(mapMatriz[linhaPlayer][colunaPlayer] == 'D' && *subirEscada == 0)
	{
		if(IsKeyDown(KEY_DOWN)) // Garante que o jogador só vai interagir com a escada ao clickar no botão
		{
			*linhaFimEscada = linhaPlayer;
			int contador = 1;
			int s = 0;

			while(s == 0)
			{
				if(mapMatriz[linhaPlayer + contador][colunaPlayer] == 'S')
				{
					*linhaInicioEscada = linhaPlayer + contador;
					*colunaEscada = colunaPlayer;
					s++;
				}
				contador++;
			}
			*subirEscada = 1;
		}
	}
	

	//Lógica para subir escadas, a variável é passada por referência pois esta função roda 60 vezes por segundo.
	if(*subirEscada == 1 && colunaPlayer == *colunaEscada)  //Só passa se a flag estiver ativa e o jogador estiver na coluna da escada
	{
		playerPosition->x = ((*colunaEscada * 30) + 30); //Garante que o player não consiga sair da coluna da escada enquanto nela

		//printf("FIM= %d, INICIO -%d",*linhaFimEscada,*linhaInicioEscada);

		if(linhaPlayerFloat >= (*linhaFimEscada) && linhaPlayerFloat <= *linhaInicioEscada) //Intervalo da escada, que impede o jogador ultrapasssar S e vai até D+1
		{
			if (IsKeyDown(KEY_UP)) playerPosition->y -= 2;
			if (IsKeyDown(KEY_DOWN)) playerPosition->y += 2;
		}
		if(linhaPlayerFloat < (*linhaFimEscada)) //Se passar de D+1 ele realoca para o centro da posição D+1
		{
			playerPosition->y = ((*linhaFimEscada)* 30) + 30;
			*subirEscada = 0; //Desativa a flag da escada
		}
		else if(linhaPlayerFloat > *linhaInicioEscada) // Se tentar passar de S, realoca para o centro de S
		{
			playerPosition->y = (*linhaInicioEscada* 30) + 30;
			*subirEscada = 0;
		}
	}
	else //Flag desativada
	{
		*subirEscada = 0;
	}

	if(mapMatriz[linhaPlayer][colunaPlayer] == 'F')
	{
		mapTransition(playerPosition,linhaPlayer,colunaPlayer, mapMatriz);
	}
	
	


}