#ifndef TADTABULEIRO_H
#define TADTABULEIRO_H

#include "../Localidade/TADLocalidade.h"

typedef struct Celula{
    struct Localidade elemento;
    struct Celula* prox;
} Celula;

typedef struct Tabuleiro{
    int tamanho;
    struct Celula* primeiro;
    struct Celula* ultimo;
} Tabuleiro;


void inicializaTabuleiro(struct Tabuleiro* tabuleiro);
int verificaTamanho(struct Tabuleiro* tabuleiro);
void insereLocalidade(struct Tabuleiro* tabuleiro, FILE* arquivoLocalidade);
//Localidade avancaCasa(struct Tabuleiro* tabuleiro, struct Localidade* localidadeInicial, int quantCasas);
void imprimeTabuleiro(struct Tabuleiro* tabuleiro);
void destroiTabuleiro(struct Tabuleiro* tabuleiro);

#endif