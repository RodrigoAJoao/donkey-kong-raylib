
#ifndef GAME_STRUCTS_H
#define GAME_STRUCTS_H

#include "raylib.h"
#include "string.h"

#define LARGURA 960
#define ALTURA 960
#define COLUNA 30
#define LINHA 30
#define MARGEM 30   


// Declaração das structs usadas no jogo

typedef struct{
    Vector2 position;
    Vector2 velocity;
    int isJumping;
    int subirEscada;
    int linhaInicioEscada;
    int linhaFimEscada;
    int colunaEscada;
    int vida;
    int cooldownHit;
} PLAYER;

typedef struct{
    int coluna;
    int linha;
    char matriz[LINHA][COLUNA + 1];
    char local[16];
    int enemyCounter;
}MAP;

typedef struct {
    int flagMenu;
    int flagRanking;
    int flagStart;
    int flagPause;
    int flagGameOver;
    int flagDamage;
} ESTADOS;

typedef struct{
    int highScore;
    int oneUp;
    float tempo;
    int time;
    Vector2 scorePopUp;
    float popUpTimer;
    int flagPopUp;
} SCORE;


typedef struct {
    Vector2 position;
    Vector2 velocity;
}ENEMY;



#endif