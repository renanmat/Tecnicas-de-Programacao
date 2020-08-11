#pragma once

#include "Aluno.hpp"
#include "Nota.hpp"

class ElAluno
{
    private:
        Aluno* pAluno;
        ElAluno* pProx;
        ElAluno* pAnt;
        Nota* pNota;
    
    public:
        ElAluno();
        ~ElAluno();

        void set_aluno(Aluno* pa);
        void set_prox(ElAluno* pElAluno);
        void set_ant(ElAluno* pElAluno);

        Aluno* get_aluno();
        ElAluno* get_prox();
        ElAluno* get_ant();

        Nota* get_notas();
        
};