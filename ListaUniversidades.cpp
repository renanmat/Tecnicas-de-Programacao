#include "ListaUniversidades.hpp"

ListaUniversidades::ListaUniversidades()
{
    pElUnivPrim = nullptr;
    pElUnivAtual = nullptr;
    id = 0;
}
ListaUniversidades::~ListaUniversidades()
{
    //desaloca(deleta) elementos da lista
    ElUniversidade* pAux = pElUnivPrim;
    while(pElUnivPrim != nullptr)
    {
        pElUnivPrim = pAux->get_prox();
        delete pAux;
        pAux = pElUnivPrim;
    }

    pElUnivAtual = nullptr;
}

void ListaUniversidades::inclui_univ(Universidade* pu)
{
    if(pu != nullptr)
    {
        ElUniversidade* pAux = new ElUniversidade();
        pAux->set_univ(pu);

        if(pElUnivPrim == nullptr)
        {
            pElUnivPrim = pAux;
            pElUnivAtual = pAux;
        }
        else
        {
            pElUnivAtual->set_prox(pAux);
            pAux->set_ant(pElUnivAtual);
            pElUnivAtual = pAux;
        }
        cout<<"Universidade cadastrada!!"<<endl;
    }
    else
    {
        cout<<"Ponteiro de universidade é NULO!\nUniversidade NAO foi cadastrada!"<<endl;
    }
    
}

void ListaUniversidades::liste_univ()
{
    ElUniversidade* pAux = pElUnivPrim;

    cout<<"Lista de Universidades:"<<endl;
    while(pAux)
    {
        cout<<"- "<<pAux->get_nomeUniv()<<endl;
        pAux = pAux->get_prox();
    }
}

void ListaUniversidades::liste_univ2()
{
    ElUniversidade* pAux = pElUnivAtual;

    cout<<"Lista de Universidades:"<<endl;
    while(pAux)
    {
        cout<<"- "<<pAux->get_nomeUniv()<<endl;
        pAux = pAux->get_ant();
    }
}


Universidade* ListaUniversidades::localiza_universidade(const char* nUniv)
{
    ElUniversidade* pAux = pElUnivPrim;
    while(pAux)
    {
        if( 0 == strcmp(nUniv, pAux->get_nomeUniv() ) )
        {
            return pAux->get_univ();
        }

        pAux = pAux->get_prox();
    }
    
    return nullptr;
}

void ListaUniversidades::set_id(int i) { id = i; }
int ListaUniversidades::get_id() { return id; }
