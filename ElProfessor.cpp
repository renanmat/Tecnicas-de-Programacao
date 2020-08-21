#include "ElProfessor.hpp"

ElProfessor::ElProfessor(Professor* p):
pProf(p),
pProx(nullptr),
pAnt(nullptr)
{
}

ElProfessor::~ElProfessor()
{
    pProf = nullptr;
    pProx = nullptr;
    pAnt = nullptr;
}

void ElProfessor::set_professor(Professor* p)
{
    pProf = p;
}
Professor* ElProfessor::get_professor()
{
    return pProf;
}

void ElProfessor::set_prox(ElProfessor* elp)
{
    pProx = elp;
}
ElProfessor* ElProfessor::get_prox()
{
    return pProx;
}

void ElProfessor::set_ant(ElProfessor* elp)
{
    pAnt = elp;
}
ElProfessor* ElProfessor::get_ant()
{
    return pAnt;
}

char* ElProfessor::get_nomeProf()
{
    return pProf->get_nome();
}