#include "ListaDisciplinas.hpp"
#include "Disciplina.hpp"

ListaDisciplinas::ListaDisciplinas(int nd):
LTDisciplinas(),
numeroDisc(nd),
contDisc(0)
{
}

ListaDisciplinas::~ListaDisciplinas()
{
    limpar_lista();
}

void ListaDisciplinas::inclua_disciplina(Disciplina* pd)
{
    if( (pd != nullptr && contDisc < numeroDisc) || (pd != nullptr && numeroDisc == -1)) 
    {
        LTDisciplinas.inclua_info(pd);
        contDisc++;
    }
    
    else
    {
        if(pd == nullptr) cout<<"Ponteiro para disciplina nulo!!"<<endl;
        else
        {
            cout<<"Numero maximo de disciplinas atingido!!"<<endl;
        }
        
    }  
}

void ListaDisciplinas::liste_disciplinas()
{
    Lista<Disciplina>::Elemento* pAux = LTDisciplinas.get_primeiro();

    if(pAux != nullptr)
    {
        cout<<"Lista de disciplinas:"<<endl;
    
        while(pAux != nullptr)
        {
            Disciplina* pDisc = pAux->get_info();

            cout<<" - "<<pDisc->get_nome()<< endl;

            pAux = pAux->get_prox();
        }
    }
    else
    {
        cout<<"Lista de disciplinas vazia!!"<<endl;
    }
}

void ListaDisciplinas::liste_disciplinas2()
{
    Lista<Disciplina>::Elemento* pAux = LTDisciplinas.get_atual();

    if(pAux != nullptr)
    {
        cout<<"Lista de disciplinas:"<<endl;
    
        while(pAux != nullptr)
        {
            Disciplina* pDisc = pAux->get_info();

            cout<<" - "<<pDisc->get_nome()<< endl;

            pAux = pAux->get_ant();
        }
    }
    else
    {
        cout<<"Lista de disciplinas vazia!!"<<endl;
    }
}

void ListaDisciplinas::limpar_lista()
{
    LTDisciplinas.limpar();
}
