#include <stdio.h>
#include <stdlib.h>

#include "TADJogador.h"
#include "TADCarta.h"

#define QUANT_CARTAS_INICIAIS 2 //Número inicial de cartas que cada jogador recebe

Jogador inicializaJogador(char nome[]){ //Talvez o endereço de memória sendo o retorno dessa função torne-a
                                        //menos custosa
    
    Jogador jogador;

    strcpy(jogador.nome, nome);
    jogador.score = 0;

    for(int i = 0; i < MAX_CARTAS; i++){
        jogador.maoJogador[i].used = 1;
    }

    return jogador;
}

void comprarCarta(Jogador* jogador, Carta* carta){
    for(int i =  0; i < MAX_CARTAS; i++){
        if(jogador->maoJogador[i].used == 1){
            
            jogador->maoJogador[i] = sorteiaCarta(carta);
            jogador->score = jogador->maoJogador[i].num;
            jogador->maoJogador[i].used = 0;

            return;
        }
    }

    printf("Sua mao esta cheia.\n");
}//não sei se isso funciona

/*O pensamento é o seguinte, quando o jogador compra a carta, o for percorre a mão do jogador até encontrar
* um espaço livre. Quando encontra, é sorteada uma carta e dentro da 'classe' "Carta" é atribuido a marca de
* que esta agora está sendo utilizada, impossibilitando-a de ser sorteada novamente.
*/

void imprimeMao(Jogador* jogador){
    for(int i = 0; i < MAX_CARTAS; i++){
        if(jogador->maoJogador[i].used == 1){
            imprimeCarta(jogador->maoJogador[i]);
        
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