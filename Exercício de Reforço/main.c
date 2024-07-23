#include <stdio.h>
#include <string.h>

#include ".\Aluno\TADAluno.h"
#include ".\Instituicao\TADProfessor.h"

int main(){
    Professor* professor1;

    char nome[10];
    int matricula;
    char contrato;
    int idade;
    float salario;
    char genero;

    strcpy("ProfTeste", nome);
    
    matricula = 1980;
    contrato = 'C';
    idade = 30;
    salario = 1000.0;

    professor1 = inicializaProfessor(nome, matricula, contrato, idade, salario);
    imprimeProfessor(professor1);

    if(!destroiProfessor(professor1)){
        printf("Erro ao excluir professor");
    }

    Aluno* aluno1;

    strcpy("alunTeste", nome);
    
    genero = 'M';
    matricula = 2000;
    idade = 15;

    aluno1 = inicializaAluno(nome, genero, matricula, idade);
    imprimeAluno(aluno1);

    if(!destroiAluno(aluno1)){
        printf("Erro ao excluir aluno");
    }

    return 0;
}//Essa versão do main serve apenas para fins de teste