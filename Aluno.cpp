#include "Aluno.hpp"

 Aluno::Aluno(int ra, int diaNas, int mesNas, int anoNas, const char *nomep):
 Pessoa(diaNas,mesNas,anoNas,nomep)
 {
     regAc = ra;
     //Ponteiro para o anterior e proximo aluno
    pProx = nullptr;
    pAnt = nullptr;
 }

Aluno::Aluno(int i):
Pessoa(i)
{
    regAc = 0;
    pProx = nullptr;
    pAnt = nullptr;
}

Aluno::~Aluno()
{
    regAc = 0;
    pProx = nullptr;
    pAnt = nullptr;
}

void Aluno::set_ra(int ra)
{
    regAc = ra;
}

int Aluno::get_ra()
{
    return regAc;
}

//gets e sets para o anterior e proximo aluno da lista encadeada
void Aluno::set_pProx(Aluno* pa){ pProx = pa;}
Aluno* Aluno::get_pProx(){ return pProx; }

void Aluno::set_pAnt(Aluno* pa){ pAnt = pa; }
Aluno* Aluno::get_pAnt(){ return pAnt; }