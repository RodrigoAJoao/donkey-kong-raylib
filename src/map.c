//#include "playerMovement.h"
#include "raylib.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define LINHA 30
#define COLUNA 30

void map(const char *caminho_mapa, char mapMatriz[LINHA][COLUNA + 1] ) //Passar o local do arquivo do mapa como parametro da função
{
    FILE *mapa_txt; // Struct File precisa ser ponteiro

    mapa_txt = fopen(caminho_mapa, "r");

    if(mapa_txt == NULL)
    {
        printf("Mapa não encontrado!\n");
    }
    else
    {
        for(int j = 3; j < LINHA + 3; j++) // Começa em 3 pra dar margem no topo
            {
                if(fgets(mapMatriz[j],COLUNA + 3,mapa_txt) != NULL) {

                /*O Tamanho do bufer é COLUNA + 3 pois temos 31 colunas por conta do \n no final, 
                logo como fgets lê tamanho - 1 para encaixar o \0, precisamos de um vetor de 33 char
                para garantir que vai ler o \n e o \0 */

                printf("%s", mapMatriz[j]);
                
                }
                else
                    break;
            }
        
        fclose(mapa_txt);
    }
}