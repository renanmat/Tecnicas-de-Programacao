#include "Estagiario.hpp"

Estagiario::Estagiario(int ra, int diaNas,int mesNas, int anoNas, const char* nomep):
Aluno(ra,diaNas,mesNas,anoNas,nomep)
{
    inicializa();
}
Estagiario::Estagiario(int i):
Aluno(i)
{
    inicializa();
}
Estagiario::~Estagiario()
{
    inicializa();
}

void Estagiario::inicializa()
{
    bolsaEstudo = 0.0;
}

void Estagiario::set_bolsaEstudo(float be)
{
    bolsaEstudo = be;
}
float Estagiario::get_bolsaEstudo()
{
    return bolsaEstudo;
}

void Estagiario::informa_proventos()
{
    cout<<"O valor da bolsa estudo do estagiario "<<nome<<" eh R$"<<bolsaEstudo<<endl;
}