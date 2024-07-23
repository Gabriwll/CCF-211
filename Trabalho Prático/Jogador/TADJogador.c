#include "TADJogador.h"

#include <stdio.h>
#include <stdlib.h>

void inicializaJogadores(Jogador* jogador){
    FILE* arquivoJogadores;
    int quantJogadores;

    if(arquivoJogadores == NULL){
        printf("Erro na abertura do arquivo 'jogadores.txt'. (2)\n");
        return; //não sei como operar esse retorno de erro
    }

    fscanf(arquivoJogadores, "%d", quantJogadores);
    /*Se a função fscanf trabalhar com um ponteiro que percorre o arquivo e o mantenha salvo de alguma forma,
    * esse comando vai fazer com que a leitura de arquivo salte a linha inicial.
    */
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