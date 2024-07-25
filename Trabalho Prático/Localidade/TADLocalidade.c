

#include "TADLocalidade.h"
#include "../Tabuleiro/TADTabuleiro.h"
#include "../Jogador/TADJogador.h"

#include <stdio.h>

void inicializaLocalidade(FILE* arquivoLocalidade, Localidade* localidade, int posicaoTabuleiro){
    fscanf(arquivoLocalidade, "%s;%s;%d;%d\n", localidade->endereco, localidade->cor, localidade->custoCompra,
                                               localidade->valorAluguel);

    localidade->posicaoTabuleiro = posicaoTabuleiro;

}