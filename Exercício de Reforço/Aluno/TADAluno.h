#ifndef TADALUNO_H
#define TADALUNO_H

typedef struct{
    char nome[10];
    char genero;
    int matricula;
    int idade;
}Aluno;

void inicializaAluno(Aluno* aluno, char nome[], char genero, int matricula, int idade);
void imprimeAluno(Aluno* aluno);

#endif