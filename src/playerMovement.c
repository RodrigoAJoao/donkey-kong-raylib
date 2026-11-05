#include "playerMovement.h"
#include "raylib.h"
#include "map.h"
#include "stdio.h"
#include "renderMapa.h"
#include <math.h>
#include "mapTransition.h"
#include "game_structs.h"



void playerMovement(PLAYER *p, MAP *mapa, ENEMY *e)
{
	//Aqui faz a transformação de posição em aspect para a posição na matriz
	int colunaPlayer = (int)((p->position.x - 30) / 30);
	float colunaPlayerFloat = ((p->position.x - 30) / 30);
	int linhaPlayer = (int)((p->position.y - 30) / 30);
	float linhaPlayerFloat = ((p->position.y - 30) / 30);

	
	printf("mapaMatriz[%d][%d] = %c\n colunaPlayertrue = %0.2f linhaPlayerTrue = %0.2f \n", linhaPlayer, colunaPlayer, mapa->matriz[linhaPlayer][colunaPlayer],colunaPlayerFloat,linhaPlayerFloat);
	printf("%d", p->isJumping);

	//MOVIMENTO HORIZONTAL
	//Checa se tem uma plataforma Z embaixo do jogador
	if( mapa->matriz[linhaPlayer][colunaPlayer] == 'S'|| mapa->matriz[linhaPlayer][colunaPlayer] == ' ' || mapa->matriz[linhaPlayer][colunaPlayer] == 'D' || mapa->matriz[linhaPlayer][colunaPlayer] == 'P' && p->subirEscada == 0) //O jogador somente consegue se mover horizontalmente se tem Z Embaixo dele ou D quando sair de escadas
	{
			// Trata entrada do usuario e atualiza estado do jogo
			if (IsKeyDown(KEY_RIGHT)) {
				p->position.x += 5;
			}
			if (IsKeyDown(KEY_LEFT)) {
				p->position.x -= 5;
			}

			if(IsKeyPressed(KEY_SPACE) && p->isJumping == 0){
				p->isJumping = 1;
				p->velocity.y = 7.5;
			}

	}
	else
	{
		printf("Morreu"); //Checagem se o jogador caiu da plataforma. garante que ele não está em uma escada
	}

	if(p->isJumping == 1)	
	{
		p->position.y -= p->velocity.y;
		p->velocity.y -= 1;
		if(p->velocity.y < 0){
			if(mapa->matriz[linhaPlayer + 1][colunaPlayer] == 'Z' && linhaPlayerFloat == linhaPlayer)
			{
				p->position.y = (linhaPlayerFloat * 30) + 30;
				p->velocity.y = 0;
				p->isJumping =0;

			}	
		}	
	}


	//ESCADAS
	
	//Cáluculo da posição de D quando o jogador estiver em uma posição S, garante que seja modular independente do número de H entre S e D.
	//A flag subirEscada garante que essa função seja chamada somente quando o jogador estiver em S
	if(mapa->matriz[linhaPlayer][colunaPlayer] == 'S' && p->subirEscada == 0)
	{
			if(IsKeyDown(KEY_UP))
			{
				p->linhaInicioEscada = linhaPlayer; //Atribui a linha de S à variável.
				int contador = 1;
				int d = 0;

				while(d == 0) //Loop garante a posição de D independente do número de H, e é sempre calculada independente de qual S o jogador está.
				{
					if(mapa->matriz[linhaPlayer - contador][colunaPlayer] == 'D')
					{
						p->linhaFimEscada = linhaPlayer - contador;
						p->colunaEscada = colunaPlayer;
						d++;
					}
					contador++;
				}
				p->subirEscada = 1; //Atualiza a flag para chamar a função de subirescada
			}
	}

	//Calculo de S, baseado em D, serve para se o jogador estiver descendo
	if(mapa->matriz[linhaPlayer][colunaPlayer] == 'D' && p->subirEscada == 0)
	{
		if(IsKeyDown(KEY_DOWN)) // Garante que o jogador só vai interagir com a escada ao clickar no botão
		{
			p->linhaFimEscada = linhaPlayer;
			int contador = 1;
			int s = 0;

			while(s == 0)
			{
				if(mapa->matriz[linhaPlayer + contador][colunaPlayer] == 'S')
				{
					p->linhaInicioEscada = linhaPlayer + contador;
					p->colunaEscada = colunaPlayer;
					s++;
				}
				contador++;
			}
			p->subirEscada = 1;
		}
	}
	

	//Lógica para subir escadas, a variável é passada por referência pois esta função roda 60 vezes por segundo.
	if(p->subirEscada == 1 && colunaPlayer == p->colunaEscada)  //Só passa se a flag estiver ativa e o jogador estiver na coluna da escada
	{
		p->position.x = ((p->colunaEscada * 30) + 30); //Garante que o player não consiga sair da coluna da escada enquanto nela

		//printf("FIM= %d, INICIO -%d",p->linhaFimEscada,p->linhaInicioEscada);

		if(linhaPlayerFloat >= (p->linhaFimEscada) && linhaPlayerFloat <= p->linhaInicioEscada) //Intervalo da escada, que impede o jogador ultrapasssar S e vai até D+1
		{
			if (IsKeyDown(KEY_UP)) p->position.y -= 2;
			if (IsKeyDown(KEY_DOWN)) p->position.y += 2;
		}
		if(linhaPlayerFloat < (p->linhaFimEscada)) //Se passar de D+1 ele realoca para o centro da posição D+1
		{
			p->position.y = ((p->linhaFimEscada)* 30) + 30;
			p->subirEscada = 0; //Desativa a flag da escada
		}
		else if(linhaPlayerFloat > p->linhaInicioEscada) // Se tentar passar de S, realoca para o centro de S
		{
			p->position.y = (p->linhaInicioEscada* 30) + 30;
			p->subirEscada = 0;
		}
	}
	else //Flag desativada
	{
		p->subirEscada = 0;
	}



	//TRANSIÇÃO DE FASE
	if(mapa->matriz[linhaPlayer][colunaPlayer] == 'F')
	{
		mapTransition(p,mapa,e,linhaPlayer, colunaPlayer);
	}

}