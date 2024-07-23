#ifndef TADALUNO_H
#define TADALUNO_H

typedef struct{
    char nome[10];
    char genero;
    int matricula;
    int idade;
}Aluno;

Aluno* inicializaAluno(char nome[], char genero, int matricula, int idade);
void imprimeAluno(Aluno* aluno);
int destroiAluno(Aluno* aluno);

#endif