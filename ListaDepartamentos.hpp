#pragma once

#include "ElDepartamento.hpp"

class ListaDepartamentos
{
    private:
        char nome[150];
        ElDepartamento* pElDepPrim;
        ElDepartamento* pElDepAtual;
        int numero_depart;
        int cont;
        int id;
    
    public:
        ListaDepartamentos(int nd = 100, const char* n = "");
        ~ListaDepartamentos();

        void set_nome(const char* n); 

        void inclui_depart(Departamento* pd);
        void liste_depart();
        void liste_depart2();

        Departamento* localiza_depart(const char* n);

        void set_id(int i);
        int get_id();
};