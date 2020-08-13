#include "ListaAlunos.hpp"

ListaAlunos::ListaAlunos(int quatAl, const char* n)
{ 
    cont_alunos = 0;
    num_alunos = quatAl;
    strcpy(nome, n);
    pElAlunoPrim = nullptr;
    pElAlunoAtual = nullptr;
}
ListaAlunos::~ListaAlunos()
{
    //deleta elementos da lista encadiada
    ElAluno* pAux = pElAlunoPrim;
    while(pElAlunoPrim)
    {
        pElAlunoPrim = pAux->get_prox();
        delete pAux;
        pAux = pElAlunoPrim;
    }

    //Aterra ponteiros
    pElAlunoAtual = nullptr;

    cont_alunos = 0;
}

void ListaAlunos::set_nome(const char* n){ strcpy(nome, n); }


void ListaAlunos::inclui_aluno(Aluno* pa)
{
    //verifica se o ponteiro pa de aluno é nulo e verifica se qunatidade de alunos ainda é menor que 45  
    if(pa != nullptr && cont_alunos < num_alunos)
    {
        //Cria ponteiro tipo ElAluno
        ElAluno* pAux;
        //Aloca dinamicamente com o operador NEW
        pAux = new ElAluno();
        //seta o aluno em elemento aluno.
        pAux->set_aluno(pa);

        if(pElAlunoPrim == nullptr)
        {
            pElAlunoPrim = pAux;
            pElAlunoAtual = pAux;
        }
        else
        {
            pElAlunoAtual->set_prox(pAux);
            pAux->set_ant(pElAlunoAtual);
            pElAlunoAtual = pAux;
        } 
           
        cont_alunos++;
    }
    else
    {
        if(pa != nullptr)
        {
            cout<<"Numero maximo de alunos atingido."<<endl;
        }
        else
        {
            cout<<"ponteiro para aluno eh NULL."<<endl;
        }
        
        
    }
    
}


void ListaAlunos::liste_alunos()
{
    //pAux recebe o primeiro elemento da lista
    ElAluno* pAux = pElAlunoPrim;

    cout<<"Disciplina "<<nome<<" lista de Alunos:"<<endl;

    //verifica se nao é nulo
    while(pAux)
    {
        // pAluno recebe o ponteiro para aluno
        Aluno* pAluno = pAux->get_aluno();
        //mostra nome do aluno
        cout<<" - "<<pAluno->get_nome()<<endl;
        //pAux recebe o proximo elemento da lista
        pAux = pAux->get_prox();
    }
}

void ListaAlunos::liste_alunos2()
{
    //pAux recebe o ultimo elemento da lista
     ElAluno* pAux = pElAlunoAtual;

    cout<<"Disciplina "<<nome<<" lista 2 de Alunos:"<<endl;
    //verifica se nao é nulo
    while(pAux)
    {
        // pAluno recebe o ponteiro para aluno
        Aluno* pAluno = pAux->get_aluno();
        //mostra nome do aluno
        cout<<" - "<<pAluno->get_nome()<<endl;
        //pAux recebe o elemento anterior da lista
        pAux = pAux->get_ant();
    }
}

ElAluno* ListaAlunos::get_alunoList(int ra)
{
    ElAluno* pAux = pElAlunoPrim;
    while(pAux)
    {
        Aluno* pAluno = pAux->get_aluno();

        if(pAluno->get_ra() == ra)
        {
            return pAux;
        }

        pAux = pAux->get_prox();
    }
    return nullptr;
}

void ListaAlunos::set_notas(int ra, double n1, double n2, double f, int nFalt)
{
    ElAluno* pAux = get_alunoList(ra);
    Nota* pNota = pAux->get_notas();

    pNota->set_primParcial(n1);
    pNota->set_secParcial(n2);
    pNota->set_final(f);
    pNota->set_nFaltas(nFalt);
}

void ListaAlunos::info_aluno(int ra)
{
    ElAluno* pAux = get_alunoList(ra);

    if(pAux != nullptr)
    {
        Aluno* pAluno = pAux->get_aluno();
        Nota* pNotas = pAux->get_notas();

        cout<<"Diciplina: "<< nome<<endl;
        cout<<"RA: "<<pAluno->get_ra()<<" Nome: "<<pAluno->get_nome()<<endl;
        cout<<"Notas: "<<"\n- Primeira parcial: "<< pNotas->get_primParcial()<<endl;
        cout<<"- Segunda parcial: "<<pNotas->get_secParcial()<<"\n- Final: "<<pNotas->get_final()<<endl;
        cout<<"- Numero de faltas: "<<pNotas->get_nFaltas()<<endl;
    }
    else
    {
        cout<<"Aluno nao encontrado!!!"<<endl;
    }
    
}