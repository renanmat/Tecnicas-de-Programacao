#include "ListaUniversidades.hpp"
#include "Universidade.hpp"

ListaUniversidades::ListaUniversidades():
LTUniver()
{
}
ListaUniversidades::~ListaUniversidades()
{
    limpar_lista();
}

void ListaUniversidades::inclui_univ(Universidade* pU)
{
    if(pU != nullptr) LTUniver.inclua_info(pU);
    else
    {
        cout<<"Ponteiro para universidade nulo!"<<endl;
    }
    
}

void ListaUniversidades::liste_univ()
{
    Lista<Universidade>::Elemento* pAux = LTUniver.get_primeiro();
    Universidade* pU = nullptr;

    if(pAux != nullptr)
    {
        cout<<"Lista de Universidades:"<<endl;
        while(pAux)
        {
            pU = pAux->get_info();
            cout<<"- "<<pU->getNome()<<endl;
            pAux = pAux->get_prox();
        }
    }
    else
    {
        cout<<"Lista de universidades vazia!"<<endl;
    }
    
}

void ListaUniversidades::liste_univ2()
{
    Lista<Universidade>::Elemento* pAux = LTUniver.get_atual();
    Universidade* pU = nullptr;

    if(pAux != nullptr)
    {
        cout<<"Lista de Universidades:"<<endl;
        while(pAux)
        {
            pU = pAux->get_info();
            cout<<"- "<<pU->getNome()<<endl;
            pAux = pAux->get_ant();
        }
    }
    else
    {
        cout<<"Lista de universidades vazia!"<<endl;
    }
    
    
}


Universidade* ListaUniversidades::localiza_universidade(const char* nUniv)
{
    Lista<Universidade>::Elemento* pAux = LTUniver.get_primeiro();
    Universidade* pU = nullptr;
    while(pAux)
    {
        pU = pAux->get_info();
        if( 0 == strcmp(nUniv, pU->getNome() ) )
        {
            return pU;
        }

        pAux = pAux->get_prox();
    }
    
    return nullptr;
}

void ListaUniversidades::limpar_lista()
{
    LTUniver.limpar();
}