#include "Professor.hpp"

Professor::Professor(int diaNas, int mesNas, int anoNas, const char *nomep):
Pessoa(diaNas,mesNas,anoNas,nomep)
{
    pUniversidade = nullptr;
    pDepartamento = nullptr;
}

Professor::Professor(int i):
Pessoa(i)
{
    pUniversidade = nullptr;
    pDepartamento = nullptr;
}

Professor::~Professor()
{
    pUniversidade = nullptr;
    pDepartamento = nullptr;
}

void Professor::setUniversidade(Universidade* pUni)
{
    pUniversidade = pUni;
}

void Professor::infoUniversidade()
{
    cout<<nome<<" trabalha na universidade "<<pUniversidade->getNome()<<endl;
}

void Professor::setDepartamento(Departamento* pDep)
{
    pDepartamento = pDep;
}

void Professor::infoDepartamento()
{
    cout<<nome<<" eh associado ao departamento "<<pDepartamento->getNome()<<endl;
}