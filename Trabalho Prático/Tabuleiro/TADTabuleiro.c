#include "./TADTabuleiro.h"

#include <stdio.h>
#include <stdlib.h>

void inicializaTabuleiro(struct Tabuleiro* tabuleiro){
    tabuleiro->primeiro = (Celula*)malloc(sizeof(Celula));
    tabuleiro->ultimo = tabuleiro->primeiro;
    tabuleiro->primeiro->prox = tabuleiro->primeiro;
    //talvez a linha acima não funcione e eu precise, inicialmente, apontar para nulo, como convencionalmente
    //é feito
    tabuleiro->tamanho = 0;
}

int verificaTamanho(struct Tabuleiro* tabuleiro){
    int tamanho = 1;
    Celula* posicaoAtual = tabuleiro->primeiro;

    do{
        posicaoAtual = posicaoAtual->prox;
        tamanho++;

    }while(posicaoAtual == tabuleiro->primeiro);

    return tamanho;
}

//É necessário verificar se o número de localidades presentes no arquivo está consistente

void insereLocalidade(struct Tabuleiro* tabuleiro, FILE* arquivoLocalidade){
    tabuleiro->ultimo->prox = (Celula*)malloc(sizeof(Celula));
    tabuleiro->ultimo = tabuleiro->ultimo->prox;

    tabuleiro->ultimo->prox = tabuleiro->primeiro;
    tabuleiro->tamanho++;

    inicializaLocalidade(arquivoLocalidade, &(tabuleiro->ultimo->elemento), tabuleiro->tamanho);
    /*talvez o último parâmetro seja um erro, passar o tamanho atual do tabuleiro como posição do próximo item
    * parece estranho, pela contagem ou não da célula head
    */
}

/*Essa função não faz sentido, eu acho

Localidade avancaCasa(struct Tabuleiro* tabuleiro, struct Localidade* localidadeInicial, int quantCasas){
    Celula* posicaoFinal = tabuleiro->primeiro->prox;
    
    for(int i = 0; i < (localidadeInicial + quantCasas); i++){
        posicaoFinal = posicaoFinal->prox;
    }

    return posicaoFinal->elemento;
}//talvez seja interessante salvar essa célula retornada pela função em um novo atributo na struct jogador
*/

void imprimeTabuleiro(struct Tabuleiro* tabuleiro){
    Celula* casaAtual = tabuleiro->primeiro->prox;

    printf("Inicio");

    do{
        printf(" -> %s", casaAtual->elemento.endereco);

        casaAtual = casaAtual->prox;
    }while(casaAtual != tabuleiro->primeiro);
}

void destroiTabuleiro(struct Tabuleiro* tabuleiro){
    Celula* posicaoAtual = tabuleiro->primeiro->prox;

    while(posicaoAtual != tabuleiro->primeiro){
        Celula* prox = posicaoAtual->prox;
        free(posicaoAtual);
        posicaoAtual = prox;
    }

    free(tabuleiro->primeiro);
    free(tabuleiro);
}

//Início -> endereço1 -> endereço2 -> ... -> endereçoN -> Início