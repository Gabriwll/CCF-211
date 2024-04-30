#include <stdio.h>

#include ".\Aluno\TADAluno.h"
#include ".\Instituicao\TADProfessor.h"

int main(){
    Professor professor1;

    char nome[10];
    int matricula;
    char contrato;
    int idade;
    float salario;

    printf("Digite o nome do professor: ");
    scanf(" %s", nome);
    
    printf("Digite a matricula do professor: ");
    scanf(" %d", &matricula);

    printf("Digite a modalidade de contratacao do professor (E || C): ");
    scanf(" %c", &contrato);

    printf("Digite a idade do professor: ");
    scanf(" %d", &idade);

    printf("Digite o salario do professor: ");
    scanf(" %f", &salario);

    inicializaProfessor(&professor1, nome, matricula, contrato, idade, salario);

    imprimeProfessor(&professor1);

    Aluno aluno1;

    char genero;

    printf("Digite o nome do aluno: ");
    scanf(" %s", nome);

    printf("Digite o genero do aluno (F || M): ");
    scanf(" %c", &genero);

    printf("Digite a matricula do aluno: ");
    scanf(" %d", &matricula);

    printf("Digite a idade do aluno: ");
    scanf(" %i", &idade);

    inicializaAluno(&aluno1, nome, genero, matricula, idade);

    imprimeAluno(&aluno1);

    return 0;
}