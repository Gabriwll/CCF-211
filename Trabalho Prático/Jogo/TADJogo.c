#include "TADJogo.h"

#include "../Tabuleiro/TADTabuleiro.h"
#include "../Jogador/TADJogador.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void movimentaJogador(Jogador* jogador){
    //parei por aqui

}

void compraPropriedade(){

}