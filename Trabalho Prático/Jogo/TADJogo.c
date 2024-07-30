#include "TADJogo.h"

#include "../Tabuleiro/TADTabuleiro.h"
#include "../Jogador/TADJogador.h"
#include "../Localidade/TADLocalidade.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void preencheTabuleiro(Tabuleiro* tabuleiro){
    FILE* arquivoLocalidade;

    if((arquivoLocalidade = fopen("../Entrada/localidades.txt", "r")) == NULL){
        printf("Erro na abertura do arquivo 'localidades.txt'.");
    }

    fscanf(arquivoLocalidade, "%d\n", tabuleiro->tamanho);

    for(int i = 0; i < tabuleiro->tamanho; i++){
        insereLocalidade(tabuleiro, arquivoLocalidade);
    }

    fclose(arquivoLocalidade);
}

int rolaDados(int quantDados){
    int dado = 0;
    
    srand(time(NULL));
    
    for(int i = 0; i < quantDados; i++){
        dado += (rand() % 6) + 1;
    }

    if(dado < 1 || dado > 6){
        return -1;

    }else{
        return dado;

    }
}

Celula* movimentaJogador(Jogador* jogador, int quantCasas){
    for(int i = 0; i < quantCasas; i++){
        jogador->posicaoAtual = jogador->posicaoAtual->prox;
    }

    return jogador->posicaoAtual;
}

void pagaAluguel(Jogador* jogador, Localidade* localidade){
    removeSaldo(jogador, localidade->valorAluguel);
}

int constroiCasa(Tabuleiro* tabuleiro, Jogador* jogador){
    if(jogador->posicaoAtual->elemento.proprietario != jogador){
        if(!verificaMonopolio(tabuleiro, jogador)){
            printf("Impossivel construir, nao ha monopolio");
            return 0;
        }

        if(jogador->posicaoAtual->elemento.proprietario != NULL){
            printf("Localidade ja possui proprietario.");
            return 0;
        }
    }

    removeSaldo(jogador, jogador->posicaoAtual->elemento.custoCompra);
    jogador->posicaoAtual->elemento.nivelConstrucao++;

    return 1;
}

int verificaMonopolio(Tabuleiro* tabuleiro, Jogador* jogador){
    char corAlvo[MAX_CARACTERES] = jogador->posicaoAtual->elemento.cor;
    Celula* posicaoAtual = tabuleiro->primeiro->prox;
    int monopolio = 1;

    for(int i = 0; i < tabuleiro->tamanho; i++){
        if((strcmp(posicaoAtual->elemento.cor, corAlvo) != 0) && posicaoAtual->elemento.proprietario != jogador){
            monopolio = 0;
        }
    }

    return monopolio;
}

int verificaFalencia(Jogador* jogador){

    /*teremos problemas caso o código rode toda a verificação em todos os casos.
    * outro problema pode se gerar a partir da passagem de parâmetro da função fabs(double)
    * (a variável jogador->dinheiro é do tipo inteiro).
    */
    if((jogador->dinheiro >= 0) || salvaguarda(jogador)){
        return 0;
    }

    return 1;
}

int salvaguarda(Jogador* jogador){
    int i = 0;

    while(jogador->dinheiro < 0){//acrescentar melhores controles para o jogador
        venderPropriedade(jogador, jogador->bens[i]);
        i++;
    }

    if(jogador->dinheiro > 0){
        return 1;
    }
    return 0;
}