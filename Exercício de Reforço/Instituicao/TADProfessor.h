#ifndef TADPROFESSOR_H
#define TADPROFESSOR_H

typedef struct{
    char nome[10];
    int matricula;
    char contrato;
    int idade;
    float salario;
}Professor;

void inicializaProfessor(Professor* professor, char nome[], int matricula, char contrato, int idade, float salario);
void imprimeProfessor(Professor* professor);

#endif