#include "Disciplina.hpp"

#include "string.h"

Disciplina::Disciplina(const char* ac)
{
    strcpy(area_conhecimento, ac);
    id = 0;
    strcpy(nome, "");
    pDepartAssociado = nullptr;
    pProx = nullptr;
    pAnt = nullptr; 

    //ponteiro lista encadeada de alunos
    pAlunoPrim = nullptr;
    pAlunoAtual = nullptr;

    cont_alunos = 0;

}

Disciplina::~Disciplina()
{
    pDepartAssociado = nullptr;
    pProx = nullptr;
    pAnt = nullptr;

    //ponteiro lista encadeada de alunos
    pAlunoPrim = nullptr;
    pAlunoAtual = nullptr;
    cont_alunos = 0;
}

void Disciplina::set_nome(const char* n){ strcpy(nome, n); }

void Disciplina::set_id(int i){ id = i; }

void Disciplina::set_area_conhecimento(const char* ac)
{
    strcpy(area_conhecimento, ac);
}

char* Disciplina::get_nome(){return nome; }

int Disciplina::get_id(){ return id; }

char* Disciplina::get_are_conhecimento() {return area_conhecimento;}

//agregaçao fraca via ponteiro
//agregando Disciplina ao Departamento
void Disciplina::set_departAssociado(Departamento* pd)
{ 
    pDepartAssociado = pd; 

    //incluir(agregaçao fraca) disciplina na lista do Departamento, atravez do ponteiro "this"
    pd->inclui_disciplina(this);
}
Departamento* Disciplina::get_departAssociado(){ return pDepartAssociado; }

//get e set pata ponteiros da Disciplina anterior e proxima de lista encadeada
void Disciplina::set_pProx(Disciplina* pd){ pProx = pd; }
Disciplina* Disciplina::get_pProx(){ return pProx ;}

void Disciplina::set_pAnt(Disciplina* pd) { pAnt = pd; }
Disciplina* Disciplina::get_pAnt() { return pAnt; }

//Metodos da lista encadiada de Alunos
void Disciplina::inclui_aluno(Aluno* pa)
{
    if(pa != nullptr && cont_alunos < 45)
    {
        if(pAlunoPrim == nullptr)
        {
            pAlunoPrim = pa;
            pAlunoAtual = pa;
        }
        else
        {
            pAlunoAtual->set_pProx(pa);
            pa->set_pAnt(pAlunoAtual);
            pAlunoAtual = pa;
        } 
           
        cont_alunos++;
    }
    else
    {
        cout<<"ponteiro para aluno eh NULL ou numero maximo de alunos atingido."<<endl;
    }
    
}

//Exclui aluno apenas da lista, nao exclui obj aluno.
void Disciplina::exclui_aluno(Aluno* pa)
{
    if(pa == pAlunoPrim)
    {
        pAlunoPrim = pa->get_pProx();
        pAlunoPrim->set_pAnt(nullptr);
        pa->set_pProx(nullptr);

    } 
    else if(pa == pAlunoAtual)
            {
                pAlunoAtual = pa->get_pAnt();
                pAlunoAtual->set_pProx(nullptr);
                pa->set_pAnt(nullptr);
            } 
            else
            {
                Aluno* pAux= pa->get_pAnt();
                pAux->set_pProx(pa->get_pProx());

                pAux = pa->get_pProx();
                pAux->set_pAnt(pa->get_pAnt());

                pa->set_pProx(nullptr);
                pa->set_pAnt(nullptr);
            }
}

void Disciplina::liste_alunos()
{
    Aluno* pAux = pAlunoPrim;

    cout<<"Disciplina "<<nome<<" lista de Alunos:"<<endl;
    while(pAux)
    {
        cout<<" - "<<pAux->get_nome()<<endl;

        pAux = pAux->get_pProx();
    }
}

void Disciplina::liste_alunos2()
{
    Aluno* pAux = pAlunoAtual;

    cout<<"Disciplina "<<nome<<" lista de Alunos:"<<endl;
    while(pAux)
    {
        cout<<" - "<<pAux->get_nome()<<endl;

        pAux = pAux->get_pAnt();
    }
}