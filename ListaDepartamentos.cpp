#include "ListaDepartamentos.hpp"

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;
#include <string>
using std::string;

ListaDepartamentos::ListaDepartamentos(int nD):
LTDepart(),
rIterador(),
iteradorDep(),
numeroDepart(nD),
contDP(0)
{
}

ListaDepartamentos::~ListaDepartamentos()
{
    // limpar_lista();
}

void ListaDepartamentos::inclua_depart(Departamento* pd)
{
    if( (pd != nullptr && contDP < numeroDepart) || (pd != nullptr && numeroDepart == -1) )
    {
        LTDepart.push_back(pd);
        contDP++;
    }
    else
    {
        if(pd == nullptr) cout<<"Ponteiro para departamento é nulo!!"<<endl;
        else
        {
            cout<<"Numero maximo de departamentos atingido!"<<endl;
        }     
    }
    
}

void ListaDepartamentos::liste_depart()
{
    

    if(LTDepart.empty())//verifica se lista esta vazia
    {
        cout<<"Lista de departamentos vazia!!"<<endl;
    }  
    else
    {
        cout<<"Lista de departamentos:"<<endl;
        int tamV = LTDepart.size();//retorna o numero de elementos dentro da lista
        for(int i = 0; i < tamV; i++)
        {
            cout<<" - "<<(LTDepart[i])->getNome()<<endl;
        }
    }
    
}

void ListaDepartamentos::liste_depart2()
{
   rIterador = LTDepart.rbegin();

    if(LTDepart.empty())
    {
        cout<<"Lista de departamentos vazia!!"<<endl;
    }
    else
    {
        cout<<"Lista de departamentos:"<<endl;
        while(rIterador != LTDepart.rend())
        {
            cout<<" - "<<(*rIterador)->getNome()<<endl;
            rIterador++;
        }
    }
}

Departamento* ListaDepartamentos::localiza_depart(const char* n)
{
    int tam = LTDepart.size();
    Departamento* pD = nullptr;
    for(int i = 0; i < tam; i++)
    {
        pD = LTDepart[i];
        if( 0 == strcmp( n, pD->getNome() ) ) 
        {
            return pD;
        }
    }
    return nullptr;
}

void ListaDepartamentos::limpar_lista()
{
    // iteradorDep = LTDepart.begin();

    // while(iteradorDep != LTDepart.end())
    // {

    //     if( (*iteradorDep)->dynamic() ) delete (*iteradorDep);
    //     iteradorDep++;
    // }
    // LTDepart.clear();

    int tam = LTDepart.size();
    for(int i = 0; i < tam ; i++)
    {
        if((LTDepart[i])->dynamic()) delete LTDepart[i];
    }
    LTDepart.clear();
}
