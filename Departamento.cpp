#include "Departamento.hpp"

 Departamento::Departamento(const char* pNome, int i)
 {
     id = i;
     strcpy(nome,pNome);
     pUniversidade = nullptr;
 }

Departamento::Departamento()
{
    pUniversidade = nullptr;
}

Departamento::~Departamento()
{
    pUniversidade = nullptr;
}

void Departamento::setId(int i)
{
    id = i;
}

int Departamento::getId()
{
    return id;
}

void Departamento::setNome(const char* pNome)
{
    strcpy(nome, pNome);
}

char* Departamento::getNome()
{
    return nome;
}

void Departamento::setUniversidade(Universidade* pUni)
{
    pUniversidade = pUni;
}