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
    }
    else
    {
        if (pd != nullptr)
        {
            cout<<"Numero maximo de departamentos atingido!\nDepartamento nao adicionado!"<<endl;
        }
        else
        {
            cout<<"Ponteiro para departamento nulo!"<<endl;
        }     
    }  
}

void ListaDepartamentos::liste_depart()
{
    cout<<"Universidade "<<nome<<" lista de departamentos:"<<endl;

    ElDepartamento* pAux = pElDepPrim;
    while(pAux)
    {
        cout<<" - "<< pAux->get_nomeDepart()<<endl;

        pAux = pAux->get_prox();
    }
}

void ListaDepartamentos::liste_depart2()
{
    cout<<"Universidade "<<nome<<" lista 2 de departamentos:"<<endl;

    ElDepartamento* pAux = pElDepAtual;
    while(pAux)
    {
        cout<<" - "<< pAux->get_nomeDepart()<<endl;

        pAux = pAux->get_ant();
    }
}