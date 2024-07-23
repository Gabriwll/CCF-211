#ifndef TADJOGO_H
#define TADJOGO_H

typedef struct Jogo{
    Tabuleiro tabuleiro;
    Jogador* jogadores; //requer alocação de memória para cada jogador na mesa
    int numJogadores;
    int numRodadas;
}Jogo;

void preencheTabuleiro(Tabuleiro* tabuleiro);
void adicionaJogador();
int rolaDados(int quantDados);
void movimentaJogador(Jogador* jogador);
void compraPropriedade();
void pagaAluguel();
void constroiCasa();
int verificaFalencia();
void proximaRodada();
void imprimeEstadoJogo();

#endif