#pragma once

#include "Pessoa.hpp"

class Aluno: public Pessoa
{
    private:
        int regAc;

        //Ponteiro para o anterior e proximo aluno
        Aluno* pProx;
        Aluno* pAnt;

    public:
        Aluno(int ra, int diaNas, int mesNas, int anoNas, const char *nomep = "");
        Aluno();
        ~Aluno();

        void set_ra(int ra);
        int get_ra();

        //gets e sets para o anterior e proximo aluno da lista encadeada
        void set_pProx(Aluno* pa);
        Aluno* get_pProx();

        void set_pAnt(Aluno* pa);
        Aluno* get_pAnt();
};