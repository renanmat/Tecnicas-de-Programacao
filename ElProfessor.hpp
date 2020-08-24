#pragma once

#include "Professor.hpp"

class ElProfessor
{
    private:
        Professor* pProf;
        ElProfessor* pProx;
        ElProfessor* pAnt;
    
    public:
        ElProfessor(Professor* p = nullptr);
        ~ElProfessor();
        
        void set_professor(Professor* p);
        Professor* get_professor();

        void set_prox(ElProfessor* elp);
        ElProfessor* get_prox();

        void set_ant(ElProfessor* elp);
        ElProfessor* get_ant();

        char* get_nomeProf();
};