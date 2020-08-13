#include "Departamento.hpp"


#include <iostream>
using std::cout;
using std::endl;

 Departamento::Departamento(const char* pNome, int i):
 objLDisciplinas(-1,pNome)
 {
    id = i;
    strcpy(nome,pNome);
    pUniversidade = nullptr;

 }

Departamento::Departamento()
{
    id = 0;
    pUniversidade = nullptr;
}

Departamento::~Departamento()
{
    pUniversidade = nullptr;
}

void Departamento::setId(int i)
{
    id = i;
}

int Departamento::getId()
{
    return id;
}

void Departamento::setNome(const char* pNome)
{
    strcpy(nome, pNome);
}

char* Departamento::getNome()
{
    return nome;
}


void Departamento::setUniversidade(Universidade* pUni)
{
    pUniversidade = pUni;
}

//agrega as disciplinas ao departamento
//Metodos da Lista encadiada
void Departamento::inclui_disciplina(Disciplina* pd)
{
    objLDisciplinas.inclui_disciplina(pd);
}


void Departamento::liste_disciplinas()
{
    objLDisciplinas.liste_disciplinas();
}


void Departamento::liste_disciplinas2()
{
    objLDisciplinas.liste_disciplinas2();
}