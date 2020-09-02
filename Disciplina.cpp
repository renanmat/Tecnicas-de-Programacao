#include "Disciplina.hpp"
#include "Departamento.hpp"

#include "string.h"
#include <iostream>
using std::cout;
using std::endl;

Disciplina::Disciplina(int i, int numAlunos, const char* n):
id{i},
objLAlunos(numAlunos)
{
    strcpy(area_conhecimento, "");
    strcpy(nome, n);
    pDepartAssociado = nullptr;
}

Disciplina::~Disciplina()
{
    pDepartAssociado = nullptr;
}

void Disciplina::set_nome(const char* n)
{ 
    strcpy(nome, n); 

}

void Disciplina::set_id(int i){ id = i; }

void Disciplina::set_area_conhecimento(const char* ac)
{
    strcpy(area_conhecimento, ac);
}

char* Disciplina::get_nome(){return nome; }

int Disciplina::get_id(){ return id; }

char* Disciplina::get_are_conhecimento() {return area_conhecimento;}

//agregaçao fraca via ponteiro
//agregando Disciplina ao Departamento
void Disciplina::set_departAssociado(Departamento* pd)
{ 
    pDepartAssociado = pd; 

    //incluir(agregaçao fraca) disciplina na lista do Departamento, atravez do ponteiro "this"
    pd->inclui_disciplina(this);
}
Departamento* Disciplina::get_departAssociado(){ return pDepartAssociado; }


//Metodos da lista encadiada de Alunos
void Disciplina::inclui_aluno(Aluno* pa)
{
    objLAlunos.inclua_aluno(pa);
}

void Disciplina::liste_alunos()
{
    cout<<"-="<<nome<<"=-"<<endl;
    objLAlunos.liste_alunos();
}

void Disciplina::liste_alunos2()
{
    cout<<"-="<<nome<<"=-"<<endl;
    objLAlunos.liste_alunos2();
}
