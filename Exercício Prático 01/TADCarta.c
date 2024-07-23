#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "TADCarta.h"

#define TAM_BARALHO 52

Carta* inicializaBaralho(){
    Carta carta[TAM_BARALHO];

    for(int i = 0; i < 4; i++){
        for(int q = 0; q < (TAM_BARALHO/4); q++){
            carta[q + (i * 13)].num = (q + 1);
            carta[q + (i * 13)].used = 1;
            
            switch (i){
            case 0:
                carta[q + (i * 13)].naipe = 'C';

                break;

            case 1:
                carta[q + (i * 13)].naipe = 'E';

                break;
            
            case 2:
                carta[q + (i * 13)].naipe = 'P';

                break;

            case 3:
                carta[q + (i * 13)].naipe = 'O';
                
                break;
            }
        }
    }

    return &carta;
}
/*Como o baralho possui um número limitado de cartas, não faz sentido simplesmente gerar cartas cada
* vez que ocorrer uma compra, deve haver um baralho definido.
*/

void imprimeBaralho(Carta* carta){
    for(int i = 0; i < TAM_BARALHO; i++){
        imprimeCarta(carta[i]);
    }
}


int verificaBaralho(Carta* carta){
    int temBaralho;

    for(int i = 0; i < TAM_BARALHO; i++){
        if(carta[i].used == 1){
            temBaralho = 0;
            
            return 0;

        }else if(carta[i].used == 0){
            temBaralho = 1;
        }
    }

    return 1;
}
/*verificaBaralho:
* Função criada para verificar se ainda há cartas no baralho.
*/


Carta sorteiaCarta(Carta *carta){   //preciso desenvolver uma solução para não chamar essa função caso não 
                                    //tenha baralho

    srand(time(NULL));
    
    int num = (rand() % (TAM_BARALHO -1));

    while(carta[num].used == 0){
        if(num >= (TAM_BARALHO - 1)){
            num = 0;
        }else{
            num++;
        }
    }

    return carta[num];
}

void imprimeCarta(Carta carta){
    if(carta.num == 1 || carta.num > 10){
        switch (carta.num){
        case 1:
            printf("Valor: A\nNaipe: %c\n", carta.naipe);

            break;
        
        case 11:
            printf("Valor: J\nNaipe: %c\n", carta.naipe);
            
            break;

        case 12:
            printf("Valor: Q\nNaipe: %c\n", carta.naipe);

            break;

        case 13:
            printf("Valor: K\nNaipe: %c\n", carta.naipe);

            break;
        }

    }else{
        printf("Valor: %d\nNaipe: %c\n", carta.num, carta.naipe);

    }
}

void imprimeCartaASCII(Carta* carta){
    printf("._________.");

    if(carta->num >= 10){
        printf("| %d %c    |", carta->num, carta->naipe);
    
    }else{
        printf("| %d %c     |", carta->num, carta->naipe);
    
    }

    printf("|         |");
    printf("|    %c    |", carta->naipe);
    printf("|         |");

    if(carta->num >= 10){
        printf("|    %d %c |", carta->num, carta->naipe);
    
    }else{
        printf("|     %d %c |", carta->num, carta->naipe);
    
    }
    printf("|_________|");
}