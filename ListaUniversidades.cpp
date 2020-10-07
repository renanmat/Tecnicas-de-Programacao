#include "ListaUniversidades.hpp"
#include "Universidade.hpp"


ListaUniversidades::ListaUniversidades():
LTUniver(),
iteradorLUniv()
{
}
ListaUniversidades::~ListaUniversidades()
{
   // limpar_lista();
}

void ListaUniversidades::inclui_univ(Universidade* pU)
{
    if(pU != nullptr) LTUniver.push_back(pU);
    else
    {
        cout<<"Ponteiro para universidade nulo!"<<endl;
    }
    
}

void ListaUniversidades::liste_univ()
{
    iteradorLUniv = LTUniver.begin();//inte


    if(LTUniver.empty())//testa se a lista esta vazia
    {
        cout<<"Lista de universidades vazia!"<<endl;
    }
    else
    {
        cout<<"Lista de Universidades:"<<endl;
        while(iteradorLUniv != LTUniver.end())
        {
            
            Universidade* pU = *iteradorLUniv;
            cout<<" - "<<pU->getNome()<<endl;
            iteradorLUniv++;
        }
        
    }
    
}

void ListaUniversidades::liste_univ2()
{

    if(LTUniver.begin() == LTUniver.end()) // verifica se a lista esta vazia
    {
        cout<<"Lista de universidades vazia!"<<endl;
    }
    else
    {
        
        cout<<"Lista de Universidades:"<<endl;
        //mostra a lista de forma reversa
        for(rIterador = LTUniver.rbegin();rIterador != LTUniver.rend();++rIterador)
        {
            cout<<" - "<<(*rIterador)->getNome()<<endl;
        }   
    }
    
    
}


Universidade* ListaUniversidades::localiza_universidade(const char* nUniv)
{
    iteradorLUniv = LTUniver.begin();
    Universidade* pU = nullptr;
    while(iteradorLUniv != LTUniver.end())
    {
        pU = *iteradorLUniv;
        if( 0 == strcmp(nUniv, pU->getNome() ) )
        {
            return pU;
        }
        iteradorLUniv++;
    }
    
    return nullptr;
}

void ListaUniversidades::limpar_lista()
{
    iteradorLUniv = LTUniver.begin(); //aponta para o inicio da lista


    while(iteradorLUniv != LTUniver.end())
    {   //se o objeto for alocado de forma dinamica ele é desalocado
        if((*iteradorLUniv)->dynamic()) delete (*iteradorLUniv);
        iteradorLUniv++;
    }
    
    LTUniver.clear(); //limpa a lista
}