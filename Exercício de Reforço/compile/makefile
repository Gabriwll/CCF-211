all: sapiens_cosplay.exe

TADAluno.o: TADAluno.c
	gcc -c ./Aluno/TADAluno.c -o ./output/TADAluno.o

TADProfessor.o: TADProfessor.c
	gcc -c ./Instituicao/TADProfessor.c -o ./output/TADProfessor.o

main.o: main.c
	gcc -c main.c -o main.o

sapiens_cosplay.exe: ./output/TADAluno.o ./output/TADProfessor.o ./output/main.o
	gcc ./output/TADAluno.o ./output/TADProfessor.o ./output/main.o -o sapiens_cosplay.exe