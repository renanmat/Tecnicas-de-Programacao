#include "Departamento.hpp"

 Departamento::Departamento(const char* pNome)
 {
     strcpy(nome,pNome);
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