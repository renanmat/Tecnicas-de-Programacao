#include "ListaDepartamentos.hpp"

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;
#include <string>
using std::string;

void grava_stringDep(const char* n, ofstream* arq)
{
    string nomeN(n); // nomeN recebe o nome  do elemento da lista
    int tamanho = nomeN.size(); // 'tamanho' recebe o tamnho da string

    arq->write((char*)&tamanho,sizeof(tamanho));//grava primeiro o tamnho da string
    arq->write((char*)&nomeN[0], tamanho);//depois grava a string
}

string recuperar_stringDep(ifstream* arq)
{
    string nomeN;
    int tamanho = 0;

    arq->read((char*)&tamanho,sizeof(tamanho)); // recupera o tanho da string

    nomeN.resize(tamanho);// 'nomeDep' realoca o tamho para caber a string
    arq->read((char*)&nomeN[0],tamanho); // recupera a string
    
    return nomeN;
}

ListaDepartamentos::ListaDepartamentos(int nD):
LTDepart(),
numeroDepart(nD),
contDP(0)
{
}

ListaDepartamentos::~ListaDepartamentos()
{
    limpar_lista();
}

void ListaDepartamentos::inclua_depart(Departamento* pd)
{
    if( (pd != nullptr && contDP < numeroDepart) || (pd != nullptr && numeroDepart == -1) )
    {
        LTDepart.inclua_info(pd);
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
    Elemento<Departamento>* pAux = LTDepart.get_primeiro();
    Departamento* pD = nullptr;

    if(pAux != nullptr)
    {
        cout<<"Lista de departamentos:"<<endl;
        while(pAux)
        {
            pD = pAux->get_info();
            cout<<" - "<< pD->getNome()<<endl;

            pAux = pAux->get_prox();
        }
    }  
    else
    {
        cout<<"Lista de departamentos vazia!!"<<endl;
    }
    
}

void ListaDepartamentos::liste_depart2()
{
    Elemento<Departamento>* pAux = LTDepart.get_atual();
    Departamento* pD = nullptr;

    if(pAux != nullptr)
    {
        cout<<"Lista 2 de departamentos:"<<endl;
        while(pAux)
        {
            pD = pAux->get_info();
            cout<<" - "<< pD->getNome()<<endl;

            pAux = pAux->get_ant();
        }
    }
    else
    {
        cout<<"Lista de departamentos vazia!!"<<endl;
    }
}

Departamento* ListaDepartamentos::localiza_depart(const char* n)
{
    Elemento<Departamento>* pAux = LTDepart.get_primeiro();
    Departamento* pD = nullptr;
    while(pAux)
    {
        pD = pAux->get_info();
        if( 0 == strcmp( n, pD->getNome() ) ) 
        {
            return pD;
        }
        pAux = pAux->get_prox();
    }
    return nullptr;
}

void ListaDepartamentos::limpar_lista()
{
    LTDepart.limpar();
}
