#include "TADJogo.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void preencheTabuleiro(struct Jogo* jogo){
    FILE* arquivoLocalidade;

    if((arquivoLocalidade = fopen("../Entrada/localidades.txt", "r")) == NULL){
        printf("Erro na abertura do arquivo 'localidades.txt'.");
    }

    fscanf(arquivoLocalidade, "%d\n", jogo->tabuleiro.tamanho);

    for(int i = 0; i < jogo->tabuleiro.tamanho; i++){
        insereLocalidade(&jogo->tabuleiro, arquivoLocalidade);
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

struct Celula* movimentaJogador(struct Jogador* jogador, int quantCasas){
    for(int i = 0; i < quantCasas; i++){
        jogador->posicaoAtual = jogador->posicaoAtual->prox;
    }

    return jogador->posicaoAtual;
}

void pagaAluguel(struct Jogador* jogador, struct Localidade* localidade){
    removeSaldo(jogador, localidade->valorAluguel);
}

int constroiCasa(struct Tabuleiro* tabuleiro, struct Jogador* jogador){
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

int verificaMonopolio(struct Tabuleiro* tabuleiro, struct Jogador* jogador){
    char corAlvo[MAX_CARACTERES];
    Celula* posicaoAtual = tabuleiro->primeiro->prox;
    int monopolio = 1;

    strcpy(corAlvo, jogador->posicaoAtual->elemento.cor);

    for(int i = 0; i < tabuleiro->tamanho; i++){
        if((strcmp(posicaoAtual->elemento.cor, corAlvo) != 0) && posicaoAtual->elemento.proprietario != jogador){
            monopolio = 0;
        }
    }

    return monopolio;
}

int verificaFalencia(struct Jogador* jogador){

    /*teremos problemas caso o código rode toda a verificação em todos os casos.
    * outro problema pode se gerar a partir da passagem de parâmetro da função fabs(double)
    * (a variável jogador->dinheiro é do tipo inteiro).
    */
    if((jogador->dinheiro >= 0) || salvaguarda(jogador)){
        return 0;
    }

    return 1;
}

int salvaguarda(struct Jogador* jogador){
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

void proximaRodada(struct VetorJogadores* vetorJogadores, int* numRodadas){
    if(*numRodadas > MAX_RODADAS){
        //finalizaJogo();
    }
    if(vetorJogadores->posicaoAtual == (vetorJogadores->final - 1)){
        *numRodadas++;
    }
    
    do{ //são necessários testes para averiaguar se essa aritmética percorre corretamente os turnos do jogo
        vetorJogadores->posicaoAtual = (vetorJogadores->posicaoAtual + 1) % vetorJogadores->quantJogadores;
    
    }while((vetorJogadores->jogador[vetorJogadores->posicaoAtual].jogando) == 0);

}

void imprimeEstadoJogo(struct Jogo* jogo){
    printf("Jogadores:\n");

    for(int i = 0; i < jogo->numJogadores; i++){
        printf("\nJogador %d:\n\n", jogo->vetorJogadores->jogador[i].id);
        
        printf("Nome: %s\tDinheiro: %d\n", jogo->vetorJogadores->jogador[i].nome, 
                                           jogo->vetorJogadores->jogador[i].dinheiro);

        printf("Propriedades:\n");
        
        for(int j = 0; j < jogo->vetorJogadores->jogador[i].quantBens; j++){
            if(jogo->vetorJogadores->jogador[i].bens[j]->nivelConstrucao == 1){
                printf("[#] ");
            }
            if(jogo->vetorJogadores->jogador[i].bens[j]->nivelConstrucao == 2){
                printf("[@] ");
            }

            printf("%s\n", jogo->vetorJogadores->jogador[i].bens[j]->endereco);
        }
        
    }
}

void finalizaJogo(struct Jogo* jogo){
    FILE* arquivoFimDeJogo;
    FILE* arquivoTabuleiroFinal;

    Celula* posicaoAtual = jogo->tabuleiro.primeiro;

    if((arquivoFimDeJogo = fopen("../Saida/fim_de_jogo.txt", "w")) == NULL){
        printf("falha ao abrir o arquivo fim_de_jogo.txt.\n");
        return;
    }

    /*A forma como o sistema preenche o arquivo pode ser alterada a fim de comportar melhor a lista de 
    * propriedades de cada jogador
    */
    for(int i = 0; i < jogo->numJogadores; i++){
        fprintf(arquivoFimDeJogo, "\nJogador %d:\n\n", jogo->vetorJogadores->jogador[i].id);
        
        fprintf(arquivoFimDeJogo, "Nome: %s\tDinheiro: %d\n", jogo->vetorJogadores->jogador[i].nome, 
                                           jogo->vetorJogadores->jogador[i].dinheiro);

        fprintf(arquivoFimDeJogo, "Propriedades:\n");
        
        for(int j = 0; j < jogo->vetorJogadores->jogador[i].quantBens; j++){
            if(jogo->vetorJogadores->jogador[i].bens[j]->nivelConstrucao == 1){
                fprintf(arquivoFimDeJogo, "[#] ");
            }
            if(jogo->vetorJogadores->jogador[i].bens[j]->nivelConstrucao == 2){
                fprintf(arquivoFimDeJogo, "[@] ");
            }

            fprintf(arquivoFimDeJogo, "%s\n", jogo->vetorJogadores->jogador[i].bens[j]->endereco);
        }
        
    }

    fclose(arquivoFimDeJogo);

    if(arquivoTabuleiroFinal = fopen("../Saida/tabuleiro_final.txt", "w") == NULL){
        printf("falha ao abrir o arquivo tabuleiro_final.txt.\n");
        return;
    }

    fprintf(arquivoTabuleiroFinal, "Tabuleiro Final:\nInicio");

    while(posicaoAtual != jogo->tabuleiro.primeiro){
        fprintf(arquivoTabuleiroFinal, " -> %s", posicaoAtual->elemento.endereco);

        if(posicaoAtual->elemento.nivelConstrucao == 1){
            fprintf(arquivoTabuleiroFinal, " [#]");
        }
        if(posicaoAtual->elemento.nivelConstrucao == 2){
            fprintf(arquivoTabuleiroFinal, " [@]");
        }
    }

    fclose(arquivoTabuleiroFinal);
    
    free(jogo->vetorJogadores->jogador);
    destroiTabuleiro(&jogo->tabuleiro);
    
}