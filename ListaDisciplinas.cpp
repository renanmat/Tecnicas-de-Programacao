#include "ListaDisciplinas.hpp"
#include "Disciplina.hpp"

#include "string.h"
#include <iostream>
using std::cout;
using std::endl;

ListaDisciplinas::ListaDisciplinas(int nd, const char* n)
{
    strcpy(nome, n);
    pElDiscPrim = nullptr;
    pElDiscAtual = nullptr;
    numero_disciplinas = nd;
    cont = 0;
    id = 0;
}

ListaDisciplinas::~ListaDisciplinas()
{
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

void ListaDisciplinas::inclui_disciplina(Disciplina* pd)
{
    //verifica se o ponteiro  é valido e se nao atingiu o numero maximo de elementos na lista
    //"numero_disciplina === -1" server quando nao se quer especificar o numero maximo de disciplinas
    //-1 permite inserir um numero  infinito de disciplinas
    if( (pd != nullptr && cont < numero_disciplinas) || (pd != nullptr && numero_disciplinas == -1))
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
         cont++; 
         cout<<"Disciplina cadastrada!!"<<endl;
    }
    else
    {
        if(pd != nullptr)
        {
            cout<<"Departamento atingiu o numero maximo de Disciplinas!\nDisciplina NAO foi cadastrada"<<endl;
        }
        else
        {
            cout<<"Ponteiro para Disciplina é NULO!! Disciplina NAO foi cadastrada."<<endl;
        }
        
    }
    
}


void ListaDisciplinas::liste_disciplinas()
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


void ListaDisciplinas::liste_disciplinas2()
{
    ElDisciplina* pAux = pElDiscAtual;

    cout<<"Departamento "<<nome<<" lista 2 de disciplinas:"<<endl;

    while(pAux)
    {
        Disciplina* pDisc = pAux->get_disciplina();

        cout<<" - "<<pDisc->get_nome()<< endl;

        pAux = pAux->get_antElDisc();
    }
}

void ListaDisciplinas::set_id(int i) { id = i; }
int ListaDisciplinas::get_id() { return id; }