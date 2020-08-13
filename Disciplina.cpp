#include "Disciplina.hpp"
#include "Departamento.hpp"

#include "string.h"
#include <iostream>
using std::cout;
using std::endl;

Disciplina::Disciplina(int numAlunos, const char* n):
objLAlunos(numAlunos, n)
{
    strcpy(area_conhecimento, "");
    id = 0;
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
    objLAlunos.set_nome(n);
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
    objLAlunos.inclui_aluno(pa);
}

void Disciplina::liste_alunos()
{
    objLAlunos.liste_alunos();
}

void Disciplina::liste_alunos2()
{
    objLAlunos.liste_alunos2();
}

void Disciplina::set_notas(int ra, double n1, double n2, double f, int nFalt)
{
    objLAlunos.set_notas(ra, n1, n2, f, nFalt);
}

void Disciplina::info_aluno(int ra)
{
    objLAlunos.info_aluno(ra);   
}