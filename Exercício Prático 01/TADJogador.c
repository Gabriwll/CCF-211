#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TADJogador.h"
#include "TADCarta.h"

#define QUANT_CARTAS_INICIAIS 2 //Número inicial de cartas que cada jogador recebe

void inicializaJogador(Jogador* jogador, char nome[]){

    strcpy(jogador->nome, nome);
    jogador->score = 0;

    for(int i = 0; i < MAX_CARTAS; i++){
        jogador->maoJogador[i]->used = 1;
    }
}

void comprarCarta(Jogador* jogador, Carta* carta){
    int comprado = 1;

    for(int i =  0; i < MAX_CARTAS; i++){
        if(jogador->maoJogador[i]->used == 1){
            
            *(jogador->maoJogador[i]) = sorteiaCarta(carta);
            jogador->score += jogador->maoJogador[i]->num;
            jogador->maoJogador[i]->used = 0;

            comprado = 0;
        }
    }

    if(comprado == 1){
        printf("Sua mao esta cheia.");
    }
}//não sei se isso funciona

/*O pensamento é o seguinte, quando o jogador compra a carta, o for percorre a mão do jogador até encontrar
* um espaço livre. Quando encontra, é sorteada uma carta e dentro da 'classe' "Carta" é atribuido a marca de
* que esta agora está sendo utilizada, impossibilitando-a de ser sorteada novamente.
*/

void imprimeMao(Jogador* jogador){
    for(int i = 0; i < MAX_CARTAS; i++){
        if(jogador->maoJogador[i]->used == 1){
            imprimeCarta(*(jogador->maoJogador[i]));
        
        }else{
            break;

        }
    }
}

void imprimeMaoASCII(Jogador* jogador){
    for(int i = 0; i < MAX_CARTAS; i++){
        if(jogador->maoJogador[i]->used == 1){
            imprimeCartaASCII(jogador->maoJogador[i]);
        
        }else{
            break;

        }
    }
}

void comecaJogo(Jogador* jogador, Carta* carta){ //Talvez dê errado, revisar a lógica hierárquica das funções
    
    for(int i = 0; i < QUANT_CARTAS_INICIAIS; i++){
        comprarCarta(jogador, carta);
    }


}