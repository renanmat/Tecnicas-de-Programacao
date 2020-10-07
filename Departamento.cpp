#include "Departamento.hpp"

#include "Disciplina.hpp"

#include <iostream>
using std::cout;
using std::endl;

 Departamento::Departamento(const char* pNome, int i):
 objLDisciplinas(-1),
 flag(true)
 {
    id = i;
    strcpy(nome,pNome);
    pUniversidade = nullptr;

 }

Departamento::~Departamento()
{
    pUniversidade = nullptr;
}

void Departamento::set_id(int i)
{
    id = i;
}

int Departamento::get_id()
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

//agrega fracamente universidade ao departamento
void Departamento::set_univerAssocida(Universidade* pUni)
{
    pUniversidade = pUni;
    
    // inclui departamento na lista da universidade agregada
    pUni->inclui_depart(this);
}

//agrega as disciplinas ao departamento
//Metodos da Lista encadiada
void Departamento::inclui_disciplina(Disciplina* pd)
{
    objLDisciplinas.inclua_disciplina(pd);
}


void Departamento::liste_disciplinas()
{
    cout<<"-="<<nome<<"=-"<<endl;
    objLDisciplinas.liste_disciplinas();
}


void Departamento::liste_disciplinas2()
{
    cout<<"-="<<nome<<"=-"<<endl;
    objLDisciplinas.liste_disciplinas2();
}

void Departamento::set_dynamic(bool f)
{
    flag = f;
}
bool Departamento::dynamic()
{
    return flag;
}