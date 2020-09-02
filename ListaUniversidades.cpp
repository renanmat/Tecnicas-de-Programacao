#include "ListaUniversidades.hpp"
#include "Universidade.hpp"

// #include <fstream>
// using std::ofstream;
// using std::ifstream;
// using std::ios;
// #include <string>
// using std::string;

// void grava_string(const char* n, ofstream* arq)
// {
//     string nomeU(n);
//     int tamanho = nomeU.size();

//     arq->write((char*)&tamanho, sizeof(tamanho));
//     arq->write((char*)&nomeU[0],tamanho);
// }

// string recuperar_string(ifstream* arq)
// {
//     string nomeU;
//     int tamanho = 0;

//     arq->read((char*)&tamanho, sizeof(tamanho));
//     nomeU.resize(tamanho);

//     arq->read((char*)&nomeU[0], tamanho);

//     return nomeU;
// }

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
    Elemento<Universidade>* pAux = LTUniver.get_primeiro();
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
    Elemento<Universidade>* pAux = LTUniver.get_atual();
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
    Elemento<Universidade>* pAux = LTUniver.get_primeiro();
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