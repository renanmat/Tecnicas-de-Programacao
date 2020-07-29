#include "Disciplina.hpp"

#include "string.h"

Disciplina::Disciplina(const char* ac)
{
    strcpy(area_conhecimento, ac);
    id = 0;
    strcpy(nome, "");
    pDepartAssociado = nullptr;
    pProx = nullptr;

}

Disciplina::~Disciplina()
{
    pDepartAssociado = nullptr;
    pProx = nullptr;
}

void Disciplina::set_nome(const char* n){ strcpy(nome, n); }

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

//get e set pata ponteiro pProx da lista encadeada
void Disciplina::set_pProx(Disciplina* pd){ pProx = pd; }
Disciplina* Disciplina::get_pProx(){ return pProx ;}