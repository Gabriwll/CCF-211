#include "TADJogador.h"
#include "../Localidade/TADLocalidade.h"

#include <stdio.h>
#include <stdlib.h>

void inicializaJogadores(Jogador* jogador){
    FILE* arquivoJogadores = fopen("../Entrada/jogadores.txt", "r");
    int quantJogadores;

    if(arquivoJogadores == NULL){
        printf("erro na abertura do arquivo 'jogadores.txt'. (1)\n");
        return;
    }
    fscanf(arquivoJogadores, "%d", &quantJogadores);

    jogador = (Jogador*)malloc(sizeof(Jogador) * quantJogadores);

    for(int i = 0; i < quantJogadores; i++){
        fscanf(arquivoJogadores, "%s;%d;%d\n", jogador[i].nome, jogador[i].dinheiro, jogador[i].id);
    }

    fclose(arquivoJogadores);

    //linhas de teste a seguir:

    for(int i = 0; i < quantJogadores; i++){
        printf("Jogador %d:\nNome: %s\nId: %d\nDinheiro: %d\n\n", (i+1), jogador[i].nome, jogador[i].id, 
                                                                  jogador[i].dinheiro);
    }

    //fim das linhas de teste.
}

int adicionaSaldo(Jogador* jogador, int saldo){
    jogador->dinheiro += saldo;

    printf("%d acrescidos com sucesso!\n Saldo atual de %s: %d", saldo, jogador->nome, jogador->dinheiro);

    return 1;
}

int removeSaldo(Jogador* jogador, int saldo){
    if((jogador->dinheiro - saldo) < 0){
        return 0;
    }

    jogador->dinheiro -= saldo;

    printf("%d acrescidos com sucesso!\n Saldo atual de %s: %d", saldo, jogador->nome, jogador->dinheiro);

    return 1;
}