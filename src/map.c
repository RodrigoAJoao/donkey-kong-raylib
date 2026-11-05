//#include "playerMovement.h"
#include "raylib.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "game_structs.h"


void map(MAP *mapa) //Passar o local do arquivo do mapa como parametro da função
{
    FILE *mapa_txt; // Struct File precisa ser ponteiro

    mapa_txt = fopen(mapa->local, "r");

    if(mapa_txt == NULL)
    {
        printf("Mapa não encontrado!\n");
    }
    else
    {
        for(int j = 3; j < LINHA + 3; j++) // Começa em 3 pra dar margem no topo
            {
                if(fgets(mapa->matriz[j],COLUNA + 3,mapa_txt) != NULL) {

                /*O Tamanho do bufer é COLUNA + 3 pois temos 31 colunas por conta do \n no final, 
                logo como fgets lê tamanho - 1 para encaixar o \0, precisamos de um vetor de 33 char
                para garantir que vai ler o \n e o \0 */

                printf("%s", mapa->matriz[j]);
                
                }
                else
                    break;
            }
        
        fclose(mapa_txt);
    }
}