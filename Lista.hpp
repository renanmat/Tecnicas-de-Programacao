#pragma once

#include "Elemento.hpp"
#include "string.h"
#include <iostream>
using std::cout;
using std::endl;

//Um gabarito se define inteiramente no .h
template<class TIPO>
class Lista
{
    private:
        Elemento<TIPO>* pPrimeiro;
        Elemento<TIPO>* pAtual;    
    public:

        Lista();
        ~Lista();

        void inicializa();
        
        void limpar();

        bool inclua_elemento(Elemento<TIPO>* pE);
        bool inclua_info(TIPO* pI);

        Elemento<TIPO>* get_primeiro();
        Elemento<TIPO>* get_atual();

};

template<class TIPO>
Lista<TIPO>::Lista()
{
    inicializa();
}
template<class TIPO>
Lista<TIPO>::~Lista()
{
    limpar();
}

template<class TIPO>
void Lista<TIPO>::inicializa()
{
    pPrimeiro = nullptr;
    pAtual = nullptr;
}

template<class TIPO>
void Lista<TIPO>::limpar()
{
     // Limpa lista
    Elemento<TIPO>* pAux = pPrimeiro;
    while(pPrimeiro != nullptr)
    {
        pPrimeiro = pAux->get_prox();
        delete pAux;
        pAux = pPrimeiro;
    }
    pAtual = nullptr;
}



template<class TIPO>
bool Lista<TIPO>::inclua_elemento(Elemento<TIPO>* pE)
{
    if(pE != nullptr)
    {
        if(pPrimeiro == nullptr)
        {
            pPrimeiro = pE;
            pAtual = pE;
        }
        else
        {
            pAtual->set_prox(pE);
            pE->set_ant(pAtual);
            pAtual = pE;
        } 
        return true;   
    }

    return false;
    
}

template<class TIPO>
bool Lista<TIPO>::inclua_info(TIPO* pI)
{
    if(pI != nullptr)
    {
        Elemento<TIPO>* pEAux = new Elemento<TIPO>;
        pEAux->set_info(pI);

        inclua_elemento(pEAux);
        return true;
    }

    return false;
}

template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::get_primeiro()
{
    return pPrimeiro;
}
template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::get_atual()
{
    return pAtual;
}