

#include "TADLocalidade.h"

#include <stdio.h>

void inicializaLocalidade(FILE* arquivoLocalidade, struct Localidade* localidade, int posicaoTabuleiro){
    fscanf(arquivoLocalidade, "%s;%c;%d;%d\n", localidade->endereco, localidade->cor, localidade->custoCompra,
                                               localidade->valorAluguel);

    localidade->posicaoTabuleiro = posicaoTabuleiro;
    localidade->proprietario = NULL;

}