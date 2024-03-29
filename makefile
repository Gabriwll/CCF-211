all: blackjack.exe

TADJogador.o: TADJogador.c TADJogador.h
	gcc -c TADJogador.c -o TADJogador.o

TADCarta.o: TADCarta.c TADCarta.h
	gcc -c TADCarta.c -o TADCarta.o

main.o: main.c
	gcc -c main.c -o main.o

blackjack.exe: TADCarta.o TADJogador.o main.o
	gcc TADCarta.o TADJogador.o main.o -o blackjack.exe