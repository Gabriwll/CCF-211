#include "TADJogador.h"
#include "../Jogo/TADJogo.h"
#include "../Localidade/TADLocalidade.h"
#include "../Tabuleiro/TADTabuleiro.h"

#include <stdio.h>
#include <stdlib.h>

int inicializaJogadores(VetorJogadores* vetorJogadores, Tabuleiro* tabuleiro){
    FILE* arquivoJogadores = fopen("../Entrada/jogadores.txt", "r");
    int quantJogadores;

    if(arquivoJogadores == NULL){
        printf("erro na abertura do arquivo 'jogadores.txt'. (1)\n");
        return;
    }
    fscanf(arquivoJogadores, "%d", &quantJogadores);

    vetorJogadores->jogador = (Jogador*)malloc(sizeof(Jogador) * quantJogadores);

    for(int i = 0; i < quantJogadores; i++){
        fscanf(arquivoJogadores, "%s;%d;%d\n", vetorJogadores->jogador[i].nome, 
                                               vetorJogadores->jogador[i].dinheiro, 
                                               vetorJogadores->jogador[i].id);
        
        vetorJogadores->jogador[i].posicaoAtual = tabuleiro->primeiro;
        vetorJogadores->jogador[i].jogando = 1;
    }

    fclose(arquivoJogadores);

    vetorJogadores->comeco = 0;
    vetorJogadores->final = quantJogadores - 1;
    vetorJogadores->posicaoAtual = 0;

    //linhas de teste a seguir:

    for(int i = 0; i < quantJogadores; i++){
        printf("Jogador %d:\nNome: %s\nId: %d\nDinheiro: %d\n\n", (i+1), vetorJogadores->jogador[i].nome, vetorJogadores->jogador[i].id, 
                                                                  vetorJogadores->jogador[i].dinheiro);
    }

    //fim das linhas de teste.

    return 1;
}

int adicionaSaldo(Jogador* jogador, int saldo){
    jogador->dinheiro += saldo;

    printf("%d acrescidos com sucesso!\n Saldo atual de %s: %d", saldo, jogador->nome, jogador->dinheiro);

    return 1;
}

int removeSaldo(Jogador* jogador, int saldo){
    jogador->dinheiro -= saldo;

    if(jogador->dinheiro < 0){
        verificaFalencia(jogador);
    }

    printf("%d acrescidos com sucesso!\n Saldo atual de %s: %d", saldo, jogador->nome, jogador->dinheiro);

    return 1;
}

int compraPropriedade(Jogador* jogador, Localidade* localidade){
    if(localidade->proprietario != NULL){
        if(jogador->dinheiro > localidade->custoCompra){
            localidade->proprietario = &jogador;
            removeSaldo(jogador, localidade->custoCompra);
            printf("%s adquirida com sucesso!", localidade->endereco);

            return 1;
        }
        printf("Saldo insuficiente.");
    }
    printf("localidade ja possui dono.");

    return 0;
}

int venderPropriedade(Jogador* jogador, Localidade* localidade){
    if(localidade->proprietario == jogador){ //testar se a relação de ponteiro para proprietário está correta
        jogador->dinheiro += (localidade->custoCompra * 0.6) * localidade->nivelConstrucao;
        //perde 60% do valor da localidade
        localidade->nivelConstrucao = 1;
        localidade->proprietario = NULL;

        return 1;
    }

    return 0;
}