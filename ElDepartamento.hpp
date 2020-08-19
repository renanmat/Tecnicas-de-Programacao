#pragma once

#include "Departamento.hpp"

class ElDepartamento
{
    private:
        Departamento* pDepart;
        ElDepartamento* pProx;
        ElDepartamento* pAnt;
        int id;

    public:
        ElDepartamento();
        ~ElDepartamento();

        void set_prox(ElDepartamento* ped);
        ElDepartamento* get_prox();

        void set_ant(ElDepartamento* ped);
        ElDepartamento* get_ant();

        void set_depart(Departamento* pd);
        Departamento* get_depart();

        char* get_nomeDepart();

        void set_id(int i);
        int get_id();
};