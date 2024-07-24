#ifndef TADLOCALIDADE_H
#define TADLOCALIDADE_H

#define MAX_CARACTERES 50

typedef struct Localidade{
    char endereco[MAX_CARACTERES];
    int posicaoTabuleiro; //posição = 0 representa a casa de início da lista

    char cor;
    int custoCompra;
    int valorAluguel;
    struct Jogador* proprietario;
    
}Localidade;

void inicializaLocalidade(FILE* arquivoLocalidade, Localidade* localidade, int posicaoTabuleiro);

#endif