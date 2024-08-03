#ifndef TADJOGADOR_H
#define TADJOGADOR_H

#define MAX_CARACTERES 50

typedef struct Jogador{
    //atributos básicos
    char nome[MAX_CARACTERES];
    int id;
    int dinheiro;

    //movimentação e pertences.
    Localidade** bens;
    int quantBens; //código ainda não adaptado para receber esse atributo novo
    Celula* posicaoAtual;

    //auxiliar de gerenciador de turnos
    int jogando;
}Jogador;

typedef struct VetorJogadores{
    Jogador* jogador;

    int comeco;
    int final;
    int posicaoAtual;

    int quantJogadores;
}VetorJogadores;

int inicializaJogadores(VetorJogadores* vetorJogadores, Tabuleiro* tabuleiro);
int adicionaSaldo(Jogador* jogador, int saldo);
int removeSaldo(Jogador* jogador, int saldo);
int compraPropriedade(Jogador* jogador, Localidade* localidade);
int venderPropriedade(Jogador* jogador, Localidade* localidade);

#endif