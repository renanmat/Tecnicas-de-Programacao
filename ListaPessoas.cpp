#include "ListaPessoas.hpp"

ListaPessoas::ListaPessoas():
LTPessoas()
{
}

ListaPessoas::~ListaPessoas()
{
    limpar_lista();
}

void ListaPessoas::inclua_pessoa(Pessoa* p)
{
    if(p != nullptr)
    {
        LTPessoas.inclua_info(p);
    }
    else
    {
        cout<<"Ponteiro para pessoa é NULO!!"<<endl;
        getchar();
    }
    
}

void ListaPessoas::liste_pessoas()
{
    Lista<Pessoa>::Elemento* pAux = LTPessoas.get_primeiro();

    if(pAux != nullptr)
    {
        Pessoa* pP = nullptr;

        cout<<"Lista de Pessoas: "<<endl;
        while(pAux != nullptr)
        {
            pP = pAux->get_info();
            cout<<" - "<<pP->get_nome()<<endl;

            pAux = pAux->get_prox();
        }
    }
    else
    {
        cout<<"Lista de pessoas esta vazia!!"<<endl;
    }   
}

void ListaPessoas::limpar_lista()
{
    LTPessoas.limpar();
}

void ListaPessoas::liste_proventos()
{
    Lista<Pessoa>::Elemento* pAux = LTPessoas.get_primeiro();
    if(pAux != nullptr)
    {
        Pessoa* pP = nullptr;

        while(pAux != nullptr)
        {
            pP = pAux->get_info();
            pP->informa_proventos();

            pAux = pAux->get_prox(); 
        }
    }
    else
    {
        cout<<"Lista de pessoas esta vazia!!"<<endl;
    }
}