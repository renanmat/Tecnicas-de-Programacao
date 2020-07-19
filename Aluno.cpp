#include "Aluno.hpp"

 Aluno::Aluno(int ra, int diaNas, int mesNas, int anoNas, const char *nomep):
 Pessoa(diaNas,mesNas,anoNas,nomep)
 {
     regAc = ra;
 }

Aluno::Aluno():
Pessoa()
{
    regAc = 0;
}

Aluno::~Aluno()
{
}

void Aluno::set_ra(int ra)
{
    regAc = ra;
}

int Aluno::get_ra()
{
    return regAc;
}