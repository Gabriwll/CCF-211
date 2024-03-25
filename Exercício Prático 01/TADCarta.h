#ifndef TADCARTA_H
#define TADCARTA_H

typedef struct{
    int num;
    int used;   //flag: is the card used? 1 == no && 0 == yes
    char naipe;

}Carta;

Carta* inicializaBaralho();
int verificaBaralho(Carta* carta);
Carta sorteiaCarta(Carta* carta);
void imprimeCarta(Carta carta);
void imprimeCartaASCII(Carta* carta);

#endif