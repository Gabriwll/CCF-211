#ifndef TADLOCALIDADE_H
#define TADLOCALIDADE_H

#include "../Jogador/TADJogador.h"

#define MAX_CARACTERES 50

typedef struct Localidade{
    char endereco[MAX_CARACTERES];
    int posicaoTabuleiro; //posição = 0 representa a casa de início da lista

    char cor[MAX_CARACTERES];
    int custoCompra;
    int valorAluguel;
    int nivelConstrucao;

    struct Jogador* proprietario; //o proprietário deve ser setado como NULL quando a localidade não foi adquirida
    
}Localidade;

void inicializaLocalidade(FILE* arquivoLocalidade, struct Localidade* localidade, int posicaoTabuleiro);

#endif