#include "Departamento.hpp"
#include "ElDisciplina.hpp"

#include <iostream>
using std::cout;
using std::endl;

 Departamento::Departamento(const char* pNome, int i)
 {
    id = i;
    strcpy(nome,pNome);
    pUniversidade = nullptr;

    pElDiscPrim = nullptr;
    pElDiscAtual = nullptr;

 }

Departamento::Departamento()
{
    id = 0;
    pUniversidade = nullptr;
    pElDiscPrim = nullptr;
    pElDiscAtual = nullptr;
}

Departamento::~Departamento()
{
    pUniversidade = nullptr;

    //Desaloca todos os elementos da lista(exclui a lista)
    ElDisciplina* pAux = pElDiscPrim;

    while(pElDiscPrim != nullptr)
    {
        pElDiscPrim = pAux->get_proxElDisc();
        delete pAux;
        pAux = pElDiscPrim;
    }

    pElDiscAtual = nullptr;
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
//atraves de lista escadeada
void Departamento::inclui_disciplina(Disciplina* pd)
{
    if(pd != nullptr)
    {   
        //Cria um ponteiro e aloca dinamicamente um elemento Disciplina
        ElDisciplina* pAux = nullptr;
        pAux = new ElDisciplina();
        //agrega fracamente a Disciplina ao elemento disciplina
        pAux->set_disciplina(pd);

        //inclui elementos da diciplina na lista de disciplinas que esta agregada fracamente ao departamento
        //verifica se a lista esta vazia
        if(pElDiscPrim == nullptr)
        {
            //inclui o primeiro elemento da lista
            pElDiscPrim = pAux;
            pElDiscAtual = pAux;
        }
        else
        //se a lista nao estiver vazia
        {
            //inclui o elemento no final da lista
            pElDiscAtual->set_proxElDisc(pAux);
            pAux->set_antElDisc(pElDiscAtual);
            pElDiscAtual = pAux;
        }
        
    }
}


void Departamento::liste_disciplinas()
{
    ElDisciplina* pAux = pElDiscPrim;

    cout<<"Departamento "<<nome<<" lista de disciplinas:"<<endl;
    
    while(pAux != nullptr)
    {
        Disciplina* pDisc = pAux->get_disciplina();

        cout<<" - "<<pDisc->get_nome()<< endl;

        pAux = pAux->get_proxElDisc();
    }

}


void Departamento::liste_disciplinas2()
{
    ElDisciplina* pAux = pElDiscAtual;

    cout<<"Departamento "<<nome<<" lista de disciplinas:"<<endl;

    while(pAux)
    {
        Disciplina* pDisc = pAux->get_disciplina();

        cout<<" - "<<pDisc->get_nome()<< endl;

        pAux = pAux->get_antElDisc();
    }
}