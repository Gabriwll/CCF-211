#include "TADJogo.h"

#include "../Tabuleiro/TADTabuleiro.h"
#include "../Jogador/TADJogador.h"
#include "../Localidade/TADLocalidade.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

void pagaAluguel(Jogador* jogador, Localidade* localidade){
    jogador->dinheiro -= localidade->valorAluguel;
    
    if(verificaFalencia(jogador)){
        
    }
}

int verificaFalencia(Jogador* jogador){

    /*teremos problemas caso o código rode toda a verificação em todos os casos.
    * outro problema pode se gerar a partir da passagem de parâmetro da função fabs(double)
    * (a variável jogador->dinheiro é do tipo inteiro).
    */
    if((jogador->dinheiro >= 0) || !salvaguarda(jogador, (int)fabs(jogador->dinheiro))){
        return 1;
    }

    return 0;
}

int salvaguarda(Jogador* jogador, int divida){
    int i = 0;

    while(divida < 0){
        venderPropriedade(jogador, jogador->bens[i]);
        i++;
    }
}