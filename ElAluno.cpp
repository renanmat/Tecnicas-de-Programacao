#include "ElAluno.hpp"

ElAluno::ElAluno()
{
    pAluno = nullptr;
    pAnt = nullptr;
    pProx = nullptr;

    pNota = nullptr;
    pNota = new Nota();

    id = 0;
}
ElAluno::~ElAluno()
{
    pAluno = nullptr;
    pAnt = nullptr;
    pProx = nullptr;

    delete pNota;
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

Nota* ElAluno::get_notas()
{
    return pNota;
}

void ElAluno::set_id(int i) { id = i; }
int ElAluno::get_id() { return id; }