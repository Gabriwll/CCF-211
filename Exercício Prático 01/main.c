#include <stdio.h>
#include <stdlib.h>

#include "TADCarta.h"
#include "TADJogador.h"

int main(){
    int opcao;
    char nome[10];

    int* score;
    /*Esse ponteiro vai, em breve, se tornar um vetor de tamanho n = número de jogadores.
    * Dessa forma, utilizarei do recurso de alocação dinâmica de memória.
    */

    Carta* baralho = inicializaBaralho();

    /*É interessando reconferir as funções posteriomente, a fim de ter certeza que o baralho não é modificado,
    * apenas utilizado
    */

    printf("Qual o modo de jogo desejado?\n");
    printf("(1) Teste sua sorte (single player);\n");
    printf("(2) 1 v 1 - cpu;\n");
    printf("(3) 1 v 1 - multiplayer");

    do{
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            Jogador jogador;

            printf("Insira o seu nome:\n");
            scanf(" %s", &nome);

            jogador = inicializaJogador(nome);

            comecaJogo(&jogador, baralho);

            printf("Suas cartas:\n");

            imprimeMao(&jogador);

            do{
                printf("O que deseja fazer a seguir?\n");
                printf("(1) Mostrar cartas;\n");
                printf("(2) Comprar carta;\n");
                printf("(3) Parar.");

                scanf("%d", &opcao);

                switch (opcao){
                case 1:

                    imprimeMao(&jogador);
                    
                    break;

                case 2:

                    comprarCarta(&jogador, baralho);
                    
                    break;

                case 3:

                    printf("Terminando jogo.\n");
                    
                    break;
                
                default:
                    break;
                }
            }while(opcao != 3 || jogador.score >= 21);

            if(jogador.score == 21){
                printf("Voce ganhou!\n %d pontos.", jogador.score);
            }else{
                printf("Voce perdeu.\n %d pontos.", jogador.score);
            }
            
            break;
        
        case 2:
            Jogador jogador1, jogador2;

            score = (int*)malloc(sizeof(int*) * 2); //não sei se a implementação está correta

            printf("Insira o seu nome:\n");
            scanf(" %s", &nome);

            jogador1 = inicializaJogador(nome); //talvez essa  manipulação de string não funcione
            jogador2 = inicializaJogador("Jogador_02");

            comecaJogo(&jogador1, baralho);
            comecaJogo(&jogador2, baralho);

            printf("Suas cartas:\n");

            imprimeMao(&jogador1);

            do{
                printf("O que deseja fazer a seguir?\n");
                printf("(1) Mostrar cartas;\n");
                printf("(2) Comprar carta;\n");
                printf("(3) Parar.");

                scanf("%d", &opcao);

                switch (opcao){
                case 1:

                    imprimeMao(&jogador1);
                    
                    break;

                case 2:

                    comprarCarta(&jogador1, baralho);

                    if(jogador2.score < 21){
                        comprarCarta(&jogador2, baralho);
                    }
                    
                    break;

                case 3:

                    printf("Terminando jogo.\n");
                    
                    break;
                
                default:
                    break;
                }
            }while(opcao != 3 || jogador1.score >= 21);

            //apuração dos resultados
            if(jogador1.score > 21){
                score[0] = jogador1.score - 21;
            }else{
                score[0] = 21 - jogador1.score;
            }

            if(jogador2.score > 21){
                score[1] = jogador2.score - 21;
            }else{
                score[1] = 21 - jogador2.score;
            }
            //Transformar isso em função mais tarde

            if(score[0] > score[1]){
                printf("Jogador 1 venceu.\njogador 1: %d pontos\njogador 2: %d pontos", score[0], score[1]);
            }else if(score[0] < score[1]){
                printf("Jogador 2 venceu.\njogador 1: %d pontos\njogador 2: %d pontos", score[0], score[1]);
            }else{
                printf("Empate.\njogador 1: %d pontos\njogador 2: %d pontos", score[0], score[1]);
            }
            
            free(score); //não sei se isso funciona

            break;

        case 3:
            
            /*Para desenvolver um multijogador, será desenvolvido um novo tad para operar a lógica de mais 
            * de um jogador e apurar os votos.
            */

            break;
        
        default:
            printf("Opcao invalida, tente novamente.");

            break;
        }
    }while(opcao < 1 || opcao > 3);
    

    return 0;
}