#ifndef TADLOCALIDADE_H
#define TADLOCALIDADE_H

#define MAX_CARACTERES 50

typedef struct Localidade{
    char endereco[MAX_CARACTERES];
    int posicaoTabuleiro;

    char cor;
    int custoCompra;
    int valorAluguel;
    struct Jogador* proprietario;
    
}Localidade;

#endif