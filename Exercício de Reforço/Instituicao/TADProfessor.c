#include <stdio.h>
#include <string.h>

#include "TADProfessor.h"

void inicializaProfessor(Professor* professor, char nome[], int matricula, char contrato, int idade, float salario){
    
    strcpy(professor->nome, nome);

    professor->matricula = matricula;
    professor->contrato = contrato;
    professor->idade = idade;
    professor->salario = salario;

}

void imprimeProfessor(Professor* professor){
    
    printf("Nome: %s\n", professor->nome);
    printf("Matricula: %d\n", professor->matricula);
    printf("Idade: %d\n", professor->idade);
    printf("Modalidade de contratacao: %c\n", professor->contrato);
    printf("Salario: %.2f\n", professor->salario);

}