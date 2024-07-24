#ifndef TADJOGADOR_H
#define TADJOGADOR_H

#define MAX_CARACTERES 50

typedef struct Jogador{
    char nome[MAX_CARACTERES];
    int id;
    int dinheiro;
    Localidade* localidade;
}Jogador;

Jogador* inicializaJogador(Jogador* jogador, int quantJogadores);

#endif