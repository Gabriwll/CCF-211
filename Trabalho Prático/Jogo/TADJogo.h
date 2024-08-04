#ifndef TADJOGO_H
#define TADJOGO_H

#include "../Tabuleiro/TADTabuleiro.h"
#include "../Jogador/TADJogador.h"
#include "../Localidade/TADLocalidade.h"

#define MAX_RODADAS 10

typedef struct Jogo{
    struct Tabuleiro tabuleiro; 
    /*isso deve se tornar um ponteiro, todas as operações passaram por aqui, o que diminuirá a quantidade de
    * parâmetros recebidos em diversas funções e tornará o código mais claro.
    */
    struct VetorJogadores* vetorJogadores;
    int numJogadores;
    int numRodadas;
}Jogo;

void preencheTabuleiro(struct Jogo* jogo);
int rolaDados(int quantDados);
struct Celula* movimentaJogador(struct Jogador* jogador, int quantCasas);
void pagaAluguel(struct Jogador* jogador, struct Localidade* localidade);
int constroiCasa(struct Tabuleiro* tabuleiro, struct Jogador* jogador);
int verificaMonopolio(struct Tabuleiro* tabuleiro, struct Jogador* jogador);
int verificaFalencia(struct Jogador* jogador);
int salvaguarda(struct Jogador* jogador);
void proximaRodada(struct VetorJogadores* vetorJogadores, int* numRodadas);
void imprimeEstadoJogo(struct Jogo* jogo);
void finalizaJogo(struct Jogo* jogo);

#endif