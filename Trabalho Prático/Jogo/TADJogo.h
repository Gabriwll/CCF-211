#ifndef TADJOGO_H
#define TADJOGO_H

typedef struct Jogo{
    Tabuleiro tabuleiro;
    Jogador* jogadores; //requer alocação de memória para cada jogador na mesa
    int numJogadores;
    int numRodadas;
}Jogo;

void preencheTabuleiro(Tabuleiro* tabuleiro);
int rolaDados(int quantDados);
void movimentaJogador(Jogador* jogador);
int compraPropriedade(Jogador* jogador, Localidade* localidade);
void pagaAluguel();
void constroiCasa();
int verificaFalencia(Jogador* jogador);
int salvaguarda(Jogador* jogador, int divida);
void proximaRodada();
void imprimeEstadoJogo();

#endif