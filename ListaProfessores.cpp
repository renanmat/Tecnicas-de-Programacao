#include "ListaProfessores.hpp"

ListaProfessores::ListaProfessores(int nP):
LTProf(),
numeroProf(nP),
contProf(0)
{
}

ListaProfessores::~ListaProfessores()
{
    limpar_lista();
}

void ListaProfessores::inclua_professor(Professor* pP)
{
    if( ( pP != nullptr && contProf < numeroProf ) || (pP != nullptr && numeroProf == -1) )
    {
        LTProf.inclua_info(pP);
        contProf++;
    }
    else
    {
        if(pP == nullptr)
        {
            cout<<"Ponteiro para professor nulo!"<<endl;
            getchar();
        }
        else
        {
            cout<<"Numero maximo de professores atingido!!"<<endl;
            getchar();
        }
        
    }
    
}

void ListaProfessores::liste_professores()
{
    Lista<Professor>::Elemento* pAux = LTProf.get_primeiro();

    if(pAux != nullptr)
    {
        Professor* pP = nullptr;

        cout<<" Lista de Professores:"<<endl;
        while(pAux != nullptr)
        {
            pP = pAux->get_info();
            cout<<" - "<<pP->get_nome()<<endl;

            pAux = pAux->get_prox();
        }
    }
    else
    {
        cout<<"Lista de professores vazia!!"<<endl;
    }
}
void ListaProfessores::liste_professores2()
{
    Lista<Professor>::Elemento* pAux = LTProf.get_atual();

    if(pAux != nullptr)
    {
        Professor* pP = nullptr;

        cout<<" Lista de Professores:"<<endl;

        while(pAux != nullptr)
        {
            pP = pAux->get_info();
            cout<<" - "<<pP->get_nome()<<endl;

            pAux = pAux->get_ant();
        }
    }
    else
    {
        cout<<"Lista de professores vazia!!"<<endl;
    } 
}

void ListaProfessores::liste_conhecimento()
{
    Lista<Professor>::Elemento* pAux = LTProf.get_primeiro();
    if(pAux != nullptr)
    {
        Professor* pP = nullptr;

        while(pAux)
        {
            pP = pAux->get_info();

            cout<<"Prof. "<<pP->get_nome()<<" tem o dominio em "<<pP->get_dominio()<<"."<<endl;

            pAux = pAux->get_prox();
        }
    }
    else
    {
        cout<<"Lista de professores esta vazia!!"<<endl;
    }
    
}

void ListaProfessores::limpar_lista()
{
    LTProf.limpar();
}