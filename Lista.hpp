#pragma once

#include "string.h"
#include <iostream>
using std::cout;
using std::endl;

//Um gabarito se define inteiramente no .h
template<class TIPO>
class Lista
{
    // private:
    //     Elemento* pPrimeiro;
    //     Elemento* pAtual;

    public:
        class Elemento
        {
            private:
                Elemento* pProximo;
                Elemento* pAnterior;
                TIPO* pInfo;

            public:
                Elemento()
                {
                    pProximo = pAnterior = nullptr;
                    pInfo = nullptr;
                }
                ~Elemento()
                {
                    pProximo = pAnterior = nullptr;
                    pInfo = nullptr;
                }
                void set_prox(Elemento* pE){pProximo = pE;}
                Elemento* get_prox(){return pProximo;}
                void set_ant(Elemento* pE){pAnterior = pE;}
                Elemento* get_ant(){return pAnterior;}
                void set_info(TIPO* pI){pInfo = pI;}
                TIPO* get_info(){return pInfo;}
        };

    private:
        Elemento* pPrimeiro;
        Elemento* pAtual; 

    public:

        Lista();
        ~Lista();

        void inicializa();
        
        void limpar();

        bool inclua_elemento(Elemento* pE);
        bool inclua_info(TIPO* pI);

        Elemento* get_primeiro(){return pPrimeiro;}
        Elemento* get_atual(){return pAtual;}
    

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
    Elemento* pAux = pPrimeiro;
    while(pPrimeiro != nullptr)
    {
        pPrimeiro = pAux->get_prox();
        delete pAux;
        pAux = pPrimeiro;
    }
    pAtual = nullptr;
}



template<class TIPO>
bool Lista<TIPO>::inclua_elemento(Elemento* pE)
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
        Elemento* pEAux = new Elemento();
        pEAux->set_info(pI);

        inclua_elemento(pEAux);
        return true;
    }

    return false;
}

// template<class TIPO>
// Elemento* Lista<TIPO>::get_primeiro()
// {
//     return pPrimeiro;
// }
// template<class TIPO>
// Lista<TIPO>::Elemento* Lista<TIPO>::get_atual()
// {
//     return pAtual;
// }