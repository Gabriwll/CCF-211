#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TADAluno.h"

Aluno* inicializaAluno(char nome[], char genero, int matricula, int idade){
    Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));
    
    strcpy(aluno->nome, nome);
    
    aluno->genero = genero;
    aluno->matricula = matricula;
    aluno->idade = idade;

    return aluno;
}

void imprimeAluno(Aluno* aluno){
    printf("Nome: %s\n", aluno->nome);
    printf("Matricula: %d\n", aluno->matricula);
    printf("Idade: %d\n", aluno->idade);
    printf("Genero: %c\n", aluno->genero);
}

int destroiAluno(Aluno* aluno){
    free(aluno);

    if(aluno == NULL){
        return 1;

    }else{
        return 0;
    
    }
}