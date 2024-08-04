#ifndef TADJOGADOR_H
#define TADJOGADOR_H

#include "../Jogo/TADJogo.h"
#include "../Localidade/TADLocalidade.h"
#include "../Tabuleiro/TADTabuleiro.h"

#define MAX_CARACTERES 50

typedef struct Jogador{
    //atributos básicos
    char nome[MAX_CARACTERES];
    int id;
    int dinheiro;

    //movimentação e pertences.
    struct Localidade** bens;
    int quantBens; //código ainda não adaptado para receber esse atributo novo
    struct Celula* posicaoAtual;

    //auxiliar de gerenciador de turnos
    int jogando;
}Jogador;

typedef struct VetorJogadores{
    struct Jogador* jogador;

    int comeco;
    int final;
    int posicaoAtual;

    int quantJogadores;
}VetorJogadores;

int inicializaJogadores(struct VetorJogadores* vetorJogadores, struct Tabuleiro* tabuleiro);
int adicionaSaldo(struct Jogador* jogador, int saldo);
int removeSaldo(struct Jogador* jogador, int saldo);
int compraPropriedade(struct Jogador* jogador, struct Localidade* localidade);
int venderPropriedade(struct Jogador* jogador, struct Localidade* localidade);

#endif