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

    Jogador* jogador;
    Carta* baralho = inicializaBaralho();

    /*É interessando reconferir as funções posteriomente, a fim de ter certeza que o baralho não é modificado,
    * apenas utilizado
    */

    printf("Qual o modo de jogo desejado?\n");
    printf("(1) Teste sua sorte (single player);\n");
    printf("(2) 1 v 1 - cpu;\n");
    printf("(3) 1 v 1 - multiplayer\n");

    do{
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            jogador = (Jogador*)malloc(sizeof(Jogador));

            printf("Insira o seu nome:\n");
            scanf(" %s", &nome);

            inicializaJogador(jogador, nome);

            comecaJogo(jogador, baralho);

            printf("Suas cartas:\n");

            imprimeMao(jogador);

            do{
                printf("O que deseja fazer a seguir?\n");
                printf("(1) Mostrar cartas (padrão);\n");
                printf("(2) Mostrar cartas (ASCII);\n");
                printf("(3) Comprar carta;\n");
                printf("(4) Parar.\n");

                scanf("%d", &opcao);

                switch (opcao){
                case 1:

                    imprimeMao(jogador);
                    
                    break;

                case 2:

                    imprimeMaoASCII(jogador);
                    
                    break;

                case 3:

                    comprarCarta(jogador, baralho);
                    
                    break;

                case 4:

                    printf("Terminando jogo.\n");
                    
                    break;
                
                default:
                    break;
                }
            }while(opcao != 3 || jogador->score >= 21);

            if(jogador->score == 21){
                printf("Voce ganhou!\n %d pontos.", jogador->score);
            }else{
                printf("Voce perdeu.\n %d pontos.", jogador->score);
            }
            
            free(jogador);

            break;
        
        case 2:
            jogador = (Jogador*)malloc(sizeof(Jogador) * 2);

            score = (int*)malloc(sizeof(int*) * 2); //não sei se a implementação está correta

            printf("Insira o seu nome:\n");
            scanf(" %s", &nome);

            inicializaJogador(&jogador[0], nome); //talvez essa  manipulação de string não funcione
            inicializaJogador(&jogador[1], "Jogador_02");

            comecaJogo(&jogador[0], baralho);   //fica redundante a escrita, mas deixa o código bem compreensível
            comecaJogo(&jogador[1], baralho);

            printf("Suas cartas:\n");

            imprimeMao(&jogador[0]);

            do{
                printf("O que deseja fazer a seguir?\n");
                printf("(1) Mostrar cartas;\n");
                printf("(2) Comprar carta;\n");
                printf("(3) Parar.\n");

                scanf("%d", &opcao);

                switch (opcao){
                case 1:

                    imprimeMao(&jogador[0]);
                    
                    break;

                case 2:

                    comprarCarta(&jogador[0], baralho);

                    if(jogador[1].score < 21){
                        comprarCarta(&jogador[1], baralho);
                    }
                    
                    break;

                case 3:

                    printf("Terminando jogo.\n");
                    
                    break;
                
                default:
                    break;
                }
            }while(opcao != 3 || jogador[0].score >= 21);

            //apuração dos resultados
            if(jogador[0].score > 21){
                score[0] = jogador[0].score - 21;
            }else{
                score[0] = 21 - jogador[0].score;
            }

            if(jogador[1].score > 21){
                score[1] = jogador[1].score - 21;
            }else{
                score[1] = 21 - jogador[1].score;
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
            free(jogador);

            break;

        case 3:

            printf("Nao esta pronto");
            
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