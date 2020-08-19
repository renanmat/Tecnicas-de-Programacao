#include "ElDepartamento.hpp"

ElDepartamento::ElDepartamento()
{
    pProx = nullptr;
    pAnt = nullptr;
    pDepart = nullptr;
    id = 0;
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

void ElDepartamento::set_id(int i) { id = i; }
int ElDepartamento::get_id() { return id; }