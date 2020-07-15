#include "Departamento.hpp"

 Departamento::Departamento(const char* pNome)
 {
     strcpy(nome,pNome);
     pUniversidade = nullptr;
 }

Departamento::~Departamento()
{

}

void Departamento::setDepart(const char* pNome)
{
    strcpy(nome, pNome);
}

char* Departamento::getDepart()
{
    return nome;
}

void Departamento::setUniversidade(Universidade* pUni)
{
    pUniversidade = pUni;
}