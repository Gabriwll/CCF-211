#ifndef TADJOGADOR_H
#define TADJOGADOR_H

#define MAX_CARACTERES 50

#include <stdlib.h>

typedef struct Jogador{
    char nome[MAX_CARACTERES];
    int id;
    int dinheiro;
    Localidade* localidade;
}Jogador;

Jogador* inicializaJogador(Jogador* jogador, int quantJogadores);

//flag
int alocaMemoria(Jogador* jogador){
    realloc();
}

#endif