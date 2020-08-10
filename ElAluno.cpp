#include "ElAluno.hpp"

ElAluno::ElAluno()
{
    pAluno = nullptr;
    pAnt = nullptr;
    pProx = nullptr;
}
ElAluno::~ElAluno()
{
    pAluno = nullptr;
    pAnt = nullptr;
    pProx = nullptr;
}

void ElAluno::set_aluno(Aluno* pa)
{
    pAluno = pa;
}
void ElAluno::set_prox(ElAluno* pElAluno)
{
    pProx = pElAluno;
}
void ElAluno::set_ant(ElAluno* pElAluno)
{
    pAnt = pElAluno;
}

Aluno* ElAluno::get_aluno()
{
    return pAluno;
}
ElAluno* ElAluno::get_prox()
{ 
    return pProx; 
}
ElAluno* ElAluno::get_ant()
{ 
    return pAnt; 
}