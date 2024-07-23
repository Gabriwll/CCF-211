#include "TADJogo.h"

#include "../Tabuleiro/TADTabuleiro.h"
#include "../Jogador/TADJogador.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheTabuleiro(Tabuleiro* tabuleiro){
    FILE* arquivoLocalidades = fopen("../Entrada/localidades.txt", "r");

    if(arquivoLocalidades == NULL){
        printf("erro na abertura do arquivo 'localidades.txt'.\n");
        return;
    }

    
    
    fclose(arquivoLocalidades);
}

void adicionaJogador(){
    Jogador* jogador;

    FILE* arquivoJogadores = fopen("../Entrada/jogadores.txt", "r");
    int quantJogadores;

    if(arquivoJogadores == NULL){
        printf("erro na abertura do arquivo 'jogadores.txt'. (1)\n");
        return;
    }
    fscanf(arquivoJogadores, "%d", &quantJogadores);

    fclose(arquivoJogadores);

    jogador = (Jogador*)malloc(sizeof(Jogador) * quantJogadores);

    printf("Há %d jogadores na mesa.\n", quantJogadores); //linha de teste

    for(int i = 0; i < quantJogadores; i++){
        inicializaJogador(jogador, quantJogadores);
    }
    //inicializar os jogadores e definir a posição deles na casa inicial
    //definir a quantidade inicial de capital de cada jogador

    jogador = (Jogador*)malloc(sizeof(Jogador) * quantJogadores);

    //eu estou aqui, preciso definir a posição inicial dos jogadores

    free(jogador); //esse free será removido em breve, servirá apenas enquanto não se tem certeza de que
                   //a função realmente funciona
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