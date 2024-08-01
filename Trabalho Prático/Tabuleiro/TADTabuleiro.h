#ifndef TADTABULEIRO_H
#define TADTABULEIRO_H


typedef struct Celula{
    struct Localidade elemento;
    struct Celula* prox;
} Celula;

typedef struct Tabuleiro{
    int tamanho;
    struct Celula* primeiro;
    struct Celula* ultimo;
} Tabuleiro;


void inicializaTabuleiro(Tabuleiro* tabuleiro);
int verificaTamanho(Tabuleiro* tabuleiro);
void insereLocalidade(Tabuleiro* tabuleiro, FILE* arquivoLocalidade);
Localidade avancaCasa(Tabuleiro* tabuleiro, Localidade* localidadeInicial, int quantCasas);
void imprimeTabuleiro(Tabuleiro* tabuleiro);
void destroiTabuleiro(Tabuleiro* tabuleiro);

#endif