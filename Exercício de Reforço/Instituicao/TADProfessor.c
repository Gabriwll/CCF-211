#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TADProfessor.h"

Professor* inicializaProfessor(char nome[], int matricula, char contrato, int idade, float salario){
    Professor* professor = (Professor*)malloc(sizeof(Professor));

    strcpy(professor->nome, nome);

    professor->matricula = matricula;
    professor->contrato = contrato;
    professor->idade = idade;
    professor->salario = salario;

    return professor;

}

void imprimeProfessor(Professor* professor){
    
    printf("Nome: %s\n", professor->nome);
    printf("Matricula: %d\n", professor->matricula);
    printf("Idade: %d\n", professor->idade);
    printf("Modalidade de contratacao: %c\n", professor->contrato);
    printf("Salario: %.2f\n", professor->salario);

}

int destroiProfessor(Professor* professor){
    free(professor);

    if(professor == NULL){
        return 1;

    }else{
        return 0;
        
    }
}