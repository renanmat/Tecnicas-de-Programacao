#include "Professor.hpp"

Professor::Professor(int diaNas, int mesNas, int anoNas, const char *nomep):
Pessoa(diaNas,mesNas,anoNas,nomep)
{
    pUniversidade = nullptr;
    pDepartamento = nullptr;
    salario = 0;
    bolsa_projeto = 0;
}

Professor::Professor(int rg, int idGeral):
Pessoa(),
Conhecimento()
{
    Pessoa::set_id(rg);
    Conhecimento::set_id(idGeral);

    pUniversidade = nullptr;
    pDepartamento = nullptr;
    salario = 0;
    bolsa_projeto = 0;
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

void Professor::set_salario(float s)
{
    salario = s;
}
float Professor::get_salario()
{
    return salario;
}


void Professor::set_bolsaProjeto(float bp)
{
    bolsa_projeto = bp;
}
float Professor::get_bolsaProjeto()
{
    return bolsa_projeto;
}

void Professor::informa_proventos()
{
    cout<<"O valor dos proventos do Prof "<<nome<<" é R$"<<(salario + bolsa_projeto)<<endl;
}

 void Professor::informa_antiguidade()
 {
     cout<<nome<<" tem "<<idade<<" anos de idade."<<endl;
 }