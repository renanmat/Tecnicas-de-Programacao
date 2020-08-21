#include "Pessoa.hpp"

Pessoa::Pessoa(int diaNas, int mesNas, int anoNas, const char *nomep)  
{
    id = - 1;
    inicializa(diaNas,mesNas,anoNas, nomep);
}

Pessoa::Pessoa(int i):
id{i}
{
    inicializa(0,0,0);
}

Pessoa::~Pessoa()
{
    inicializa(0,0,0);
}

void Pessoa::inicializa(int diaNas, int mesNas, int anoNas, const char *nomep)
{
    strcpy(nome, nomep);
    dia = diaNas;
    mes = mesNas;
    ano = anoNas;
    idade = -1;
}

void Pessoa::set_nome(const char* n) { strcpy(nome, n); }
char* Pessoa::get_nome() { return nome; }

void Pessoa::set_id(int i){ id = i;}
int Pessoa::get_id(){ return id; }

void Pessoa::calc_idade(int diaAt, int mesAt, int ano_atual){
    idade = ano_atual - ano;
    if(mes > mesAt)
    {
        idade -= 1;
    } else 
        if (mes == mesAt)
        {
            if(dia > diaAt) idade -= 1;
        }
    
}

void Pessoa::imprime_idade()
{
    cout<<nome<<" tem "<<idade<<" anos de idade."<<endl;
}

void Pessoa::calc_imprime_idade(int diaAt, int mesAt, int ano_atual)
{
    calc_idade(diaAt,mesAt,ano_atual);
    imprime_idade();
}

int Pessoa::getIdade()
{
    return idade;
}