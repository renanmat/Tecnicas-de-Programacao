#include "ListaAlunos.hpp"


ListaAlunos::ListaAlunos(int nA):
LTAlunos(),
numeroAlunos(nA),
contAluno(0)
{ 
}

ListaAlunos::~ListaAlunos()
{
    limpar_lista();
}

void ListaAlunos::inclua_aluno(Aluno* pa)
{
    if( (pa != nullptr && contAluno < numeroAlunos) || (pa != nullptr && numeroAlunos == -1) )
    {
        LTAlunos.inclua_info(pa);
        contAluno++;
    }
    else
    {
        if(pa == nullptr)
        {
            cout<<"Ponteiro para aluno eh nulo!"<<endl;
            getchar();
        }
        else
        {
            cout<<"Numero maximo de alunos atingido!!"<<endl;
            getchar();
        }      
    }    
}

void ListaAlunos::liste_alunos()
{
    //pAux recebe o primeiro elemento da lista
    Lista<Aluno>::Elemento* pAux = LTAlunos.get_primeiro();

    if(pAux != nullptr)
    {
        cout<<"Lista de Alunos:"<<endl;

        //verifica se nao é nulo
        while(pAux)
        {
            // pAluno recebe o ponteiro para aluno
            Aluno* pAluno = pAux->get_info();
            //mostra nome do aluno
            cout<<" - "<<pAluno->get_nome()<<endl;
            //pAux recebe o proximo elemento da lista
            pAux = pAux->get_prox();
        }
    }
    else
    {
        cout<<"Lista de alunos esta vazia!!"<<endl;
    }
    
}

void ListaAlunos::liste_alunos2()
{
    //pAux recebe o ultimo elemento da lista
    Lista<Aluno>::Elemento* pAux = LTAlunos.get_atual();

    if(pAux != nullptr)
    {
        cout<<"Lista 2 de Alunos:"<<endl;
        //verifica se nao é nulo
        while(pAux)
        {
            // pAluno recebe o ponteiro para aluno
            Aluno* pAluno = pAux->get_info();
            //mostra nome do aluno
            cout<<" - "<<pAluno->get_nome()<<endl;
            //pAux recebe o elemento anterior da lista
            pAux = pAux->get_ant();
        }
    }
    else
    {
        cout<<"Lista de alunos esta vazia!!"<<endl;
    }   
}

void ListaAlunos::limpar_lista()
{
    LTAlunos.limpar();
}