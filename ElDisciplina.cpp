#include "ElDisciplina.hpp"


ElDisciplina::ElDisciplina()
{
    pDisciplina = nullptr;
    pProx = nullptr;
    pAnt = nullptr;
    id = 0;
}
ElDisciplina::~ElDisciplina()
{
    pDisciplina = nullptr;
    pProx = nullptr;
    pAnt = nullptr;
}

//Disciplina 
void ElDisciplina::set_disciplina(Disciplina* pd)
{
    pDisciplina = pd;
}
Disciplina* ElDisciplina::get_disciplina()
{
    return pDisciplina;
}


//Proximo elemento da lista
void ElDisciplina::set_proxElDisc(ElDisciplina* pEd)
{
    pProx = pEd;
}

ElDisciplina* ElDisciplina::get_proxElDisc()
{
    return pProx;
}


//Elemento Anterior da lista
void ElDisciplina::set_antElDisc(ElDisciplina* pEd)
{
    pAnt = pEd;
}

ElDisciplina* ElDisciplina::get_antElDisc()
{
    return pAnt;
}

void ElDisciplina::set_id(int i) { id = i; }
int ElDisciplina::get_id() { return id; }