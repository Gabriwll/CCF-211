#include <stdio.h>
#include <string.h>

#include "TADAluno.h"

void inicializaAluno(Aluno* aluno, char nome[], char genero, int matricula, int idade){
    strcpy(aluno->nome, nome);
    
    aluno->genero = genero;
    aluno->matricula = matricula;
    aluno->idade = idade;
}

void imprimeAluno(Aluno* aluno){
    printf("Nome: %s\n", aluno->nome);
    printf("Matricula: %d\n", aluno->matricula);
    printf("Idade: %d\n", aluno->idade);
    printf("Genero: %c\n", aluno->genero);
}