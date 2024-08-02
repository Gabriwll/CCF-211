#ifndef TADJOGO_H
#define TADJOGO_H

#define MAX_RODADAS 10

typedef struct Jogo{
    Tabuleiro tabuleiro; 
    /*isso deve se tornar um ponteiro, todas as operações passaram por aqui, o que diminuirá a quantidade de
    * parâmetros recebidos em diversas funções e tornará o código mais claro.
    */
    VetorJogadores* vetorJogadores;
    int numJogadores;
    int numRodadas;
}Jogo;

void preencheTabuleiro(Tabuleiro* tabuleiro);
int rolaDados(int quantDados);
Celula* movimentaJogador(Jogador* jogador, int quantCasas);
int compraPropriedade(Jogador* jogador, Localidade* localidade);
void pagaAluguel(Jogador* jogador, Localidade* localidade);
int constroiCasa(Tabuleiro* tabuleiro, Jogador* jogador);
int verificaMonopolio(Tabuleiro* tabuleiro, Jogador* jogador);
int verificaFalencia(Jogador* jogador);
int salvaguarda(Jogador* jogador);
void proximaRodada(VetorJogadores* vetorJogadores, int* numRodadas);
void imprimeEstadoJogo();
void finalizaJogo(Jogo* jogo, VetorJogadores* vetorJogadores, Tabuleiro* tabuleiro);

#endif