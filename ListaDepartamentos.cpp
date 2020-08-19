#include "ListaDepartamentos.hpp"

#include <iostream>
using std::cout;
using std::endl;

ListaDepartamentos::ListaDepartamentos(int nd, const char* n)
{
    strcpy(nome, n);
    pElDepPrim = nullptr;
    pElDepAtual = nullptr;
    numero_depart = nd;
    cont = 0;
    id = 0;
}

ListaDepartamentos::~ListaDepartamentos()
{
    ElDepartamento* pAux = pElDepPrim;
    while(pElDepPrim != nullptr)
    {
        pElDepPrim = pAux->get_prox();
        delete pAux;
        pAux = pElDepPrim;
    }

    pElDepAtual = nullptr;
    cont = 0;
    numero_depart = 0;
}

void ListaDepartamentos::set_nome(const char* n)
{
    strcpy(nome,n);
}

void ListaDepartamentos::inclui_depart(Departamento* pd)
{
    if( (pd != nullptr && cont < numero_depart) || (pd != nullptr && numero_depart == -1) ) 
    {
        ElDepartamento* pAux = new ElDepartamento();
        pAux->set_depart(pd);

        if(pElDepPrim == nullptr)
        {
            pElDepPrim = pAux;
            pElDepAtual = pAux;
        }
        else
        {
            pElDepAtual->set_prox(pAux);
            pAux->set_ant(pElDepAtual);
            pElDepAtual = pAux;
        }
        cont++;
        cout<<"Departamento cadastrado!!"<<endl;
    }
    else
    {
        if (pd != nullptr)
        {
            cout<<"Numero maximo de departamentos atingido!\nDepartamento NAO foi cadastrado!"<<endl;
        }
        else
        {
            cout<<"Ponteiro para departamento é nulo!\nDepartamento NAO foi cadastrado"<<endl;
        }     
    }  
}

void ListaDepartamentos::liste_depart()
{
    cout<<nome<<" lista de departamentos:"<<endl;

    ElDepartamento* pAux = pElDepPrim;
    while(pAux)
    {
        cout<<" - "<< pAux->get_nomeDepart()<<endl;

        pAux = pAux->get_prox();
    }
}

void ListaDepartamentos::liste_depart2()
{
    cout<<"Universidade "<<nome<<" - lista 2 de departamentos:"<<endl;

    ElDepartamento* pAux = pElDepAtual;
    while(pAux)
    {
        cout<<" - "<< pAux->get_nomeDepart()<<endl;

        pAux = pAux->get_ant();
    }
}

Departamento* ListaDepartamentos::localiza_depart(const char* n)
{
    ElDepartamento* pAux = pElDepPrim;
    while(pAux)
    {
        if(0 == strcmp(n, pAux->get_nomeDepart()) )
        {
            return pAux->get_depart();
        }
        pAux = pAux->get_prox();
    }
    return nullptr;
}

void ListaDepartamentos::set_id(int i) { id = i; }
int ListaDepartamentos::get_id() { return id; }