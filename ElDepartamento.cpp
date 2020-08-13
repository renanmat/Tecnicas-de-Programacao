#include "ElDepartamento.hpp"

ElDepartamento::ElDepartamento()
{
    pProx = nullptr;
    pAnt = nullptr;
    pDepart = nullptr;
}
ElDepartamento::~ElDepartamento()
{
    pProx = nullptr;
    pAnt = nullptr;
    pDepart = nullptr;
}

void ElDepartamento::set_prox(ElDepartamento* ped)
{
    pProx = ped;
}
ElDepartamento* ElDepartamento::get_prox()
{
    return pProx;
}

void ElDepartamento::set_ant(ElDepartamento* ped)
{
    pAnt = ped;
}
ElDepartamento* ElDepartamento::get_ant()
{
    return pAnt;
}

void ElDepartamento::set_depart(Departamento* pd)
{
    pDepart = pd;
}
Departamento* ElDepartamento::get_depart()
{
    return pDepart;
}

char* ElDepartamento::get_nomeDepart()
{
    return pDepart->getNome();
}