#ifndef TADJOGADOR_H
#define TADJOGADOR_H

#include "TADCarta.h"

#define MAX_CARTAS 10 //Número máximo de cartas que pode ser atribuida a mão de um jogador

typedef struct{
    char nome[10];
    int score;
    Carta* maoJogador[MAX_CARTAS];
}Jogador;

void inicializaJogador(Jogador* jogador, char nome[]);
void comprarCarta(Jogador* jogador, Carta* carta);
void imprimeMao(Jogador* jogador);
void comecaJogo(Jogador* jogador, Carta* carta);

#endif