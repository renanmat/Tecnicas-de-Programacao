#pragma once

#include "Pessoa.hpp"

class Aluno: public Pessoa
{
    private:
        int regAc;

    public:
        Aluno(int ra, int diaNas, int mesNas, int anoNas, const char *nomep = "");
        Aluno();
        ~Aluno();

        void set_ra(int ra);
        int get_ra();
};