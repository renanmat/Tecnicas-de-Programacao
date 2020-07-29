#include "Departamento.hpp"
#include "Disciplina.hpp"
#include <iostream>
using std::cout;
using std::endl;

 Departamento::Departamento(const char* pNome, int i)
 {
    id = i;
    strcpy(nome,pNome);
    pUniversidade = nullptr;

    pDiscPrim = nullptr;
    pDiscAtual = nullptr;

 }

Departamento::Departamento()
{
    id = 0;
    pUniversidade = nullptr;
    pDiscPrim = nullptr;
    pDiscAtual = nullptr;
}

Departamento::~Departamento()
{
    pUniversidade = nullptr;
    pDiscPrim = nullptr;
    pDiscAtual = nullptr;
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
        if(pDiscPrim == nullptr)
        {
            pDiscPrim = pd;
            pDiscAtual = pd;
        }
        else
        {
            pDiscAtual->set_pProx(pd);
            pDiscAtual = pd;
        }
        
    }
}

void Departamento::liste_disciplinas()
{
    Disciplina* pAux = pDiscPrim;
    
    while(pAux != nullptr)
    {
        cout<<"Disciplina "<<pAux->get_nome()<<" pertence ao Departamento "<< nome << endl;

        pAux = pAux->get_pProx();
    }

}