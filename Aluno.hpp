#pragma once

#include "Pessoa.hpp"

class Aluno: public Pessoa
{
    protected:
        int regAc;

    public:
        Aluno(int ra, int diaNas, int mesNas, int anoNas, const char *nomep = "");
        Aluno(int i = -1);
        virtual ~Aluno();

        void set_ra(int ra);
        int get_ra();
};