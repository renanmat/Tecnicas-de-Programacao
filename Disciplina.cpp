#include "Disciplina.hpp"
#include "Departamento.hpp"

#include "string.h"
#include <iostream>
using std::cout;
using std::endl;

Disciplina::Disciplina(const char* ac)
{
    strcpy(area_conhecimento, ac);
    id = 0;
    strcpy(nome, "");
    pDepartAssociado = nullptr;

    //ponteiro lista encadeada de alunos
    pElAlunoPrim = nullptr;
    pElAlunoAtual = nullptr;

    cont_alunos = 0;

}

Disciplina::~Disciplina()
{

    //deleta elementos da lista encadiada
    ElAluno* pAux = pElAlunoPrim;
    while(pElAlunoPrim)
    {
        pElAlunoPrim = pAux->get_prox();
        delete pAux;
        pAux = pElAlunoPrim;
    }

    //Aterra ponteiros
    pElAlunoAtual = nullptr;
    pDepartAssociado = nullptr;

    cont_alunos = 0;
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


//Metodos da lista encadiada de Alunos
void Disciplina::inclui_aluno(Aluno* pa)
{
    //verifica se o ponteiro pa de aluno é nulo e verifica se qunatidade de alunos ainda é menor que 45  
    if(pa != nullptr && cont_alunos < 45)
    {
        //Cria ponteiro tipo ElAluno
        ElAluno* pAux;
        //Aloca dinamicamente com o operador NEW
        pAux = new ElAluno();
        //seta o aluno em elemento aluno.
        pAux->set_aluno(pa);

        if(pElAlunoPrim == nullptr)
        {
            pElAlunoPrim = pAux;
            pElAlunoAtual = pAux;
        }
        else
        {
            pElAlunoAtual->set_prox(pAux);
            pAux->set_ant(pElAlunoAtual);
            pElAlunoAtual = pAux;
        } 
           
        cont_alunos++;
    }
    else
    {
        cout<<"ponteiro para aluno eh NULL ou numero maximo de alunos atingido."<<endl;
    }
    
}


void Disciplina::liste_alunos()
{
    //pAux recebe o primeiro elemento da lista
    ElAluno* pAux = pElAlunoPrim;

    cout<<"Disciplina "<<nome<<" lista de Alunos:"<<endl;

    //verifica se nao é nulo
    while(pAux)
    {
        // pAluno recebe o ponteiro para aluno
        Aluno* pAluno = pAux->get_aluno();
        //mostra nome do aluno
        cout<<" - "<<pAluno->get_nome()<<endl;
        //pAux recebe o proximo elemento da lista
        pAux = pAux->get_prox();
    }
}

void Disciplina::liste_alunos2()
{
    //pAux recebe o ultimo elemento da lista
     ElAluno* pAux = pElAlunoAtual;

    cout<<"Disciplina "<<nome<<" lista de Alunos:"<<endl;
    //verifica se nao é nulo
    while(pAux)
    {
        // pAluno recebe o ponteiro para aluno
        Aluno* pAluno = pAux->get_aluno();
        //mostra nome do aluno
        cout<<" - "<<pAluno->get_nome()<<endl;
        //pAux recebe o elemento anterior da lista
        pAux = pAux->get_ant();
    }
}

ElAluno* Disciplina::get_alunoList(int ra)
{
    ElAluno* pAux = pElAlunoPrim;
    while(pAux)
    {
        Aluno* pAluno = pAux->get_aluno();

        if(pAluno->get_ra() == ra)
        {
            return pAux;
        }

        pAux = pAux->get_prox();
    }
    return nullptr;
}

void Disciplina::set_notas(int ra, double n1, double n2, double f, int nFalt)
{
    ElAluno* pAux = get_alunoList(ra);
    Nota* pNota = pAux->get_notas();

    pNota->set_primParcial(n1);
    pNota->set_secParcial(n2);
    pNota->set_final(f);
    pNota->set_nFaltas(nFalt);
}

void Disciplina::info_aluno(int ra)
{
    ElAluno* pAux = get_alunoList(ra);

    if(pAux != nullptr)
    {
        Aluno* pAluno = pAux->get_aluno();
        Nota* pNotas = pAux->get_notas();

        cout<<"Diciplina: "<< nome<<endl;
        cout<<"RA: "<<pAluno->get_ra()<<" Nome: "<<pAluno->get_nome()<<endl;
        cout<<"Notas: "<<"\n- Primeira parcial: "<< pNotas->get_primParcial()<<endl;
        cout<<"- Segunda parcial: "<<pNotas->get_secParcial()<<"\n- Final: "<<pNotas->get_final()<<endl;
        cout<<"- Numero de faltas: "<<pNotas->get_nFaltas()<<endl;
    }
    else
    {
        cout<<"Aluno nao encontrado!!"<<endl;
    }
    
}