#ifndef TADJOGADOR_H
#define TADJOGADOR_H

#define MAX_CARACTERES 50

typedef struct Jogador{
    char nome[MAX_CARACTERES];
    int id;
    int dinheiro;
    Localidade* localidade;
}Jogador;

void inicializaJogadores(Jogador* jogador);
int adicionaSaldo(Jogador* jogador, int saldo);
int removeSaldo(Jogador* Jogador, int saldo);

#endif