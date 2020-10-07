#pragma once

#include "Departamento.hpp"
#include <vector>

class ListaDepartamentos
{
    protected:
        std::vector<Departamento*> LTDepart;
        std::vector<Departamento*>::reverse_iterator rIterador;
        std::vector<Departamento*>::iterator iteradorDep;
        int numeroDepart;
        int contDP;

    public:
        ListaDepartamentos(int nD = -1);
        ~ListaDepartamentos();

        void inclua_depart(Departamento* pd);
        
        void liste_depart();
        void liste_depart2();

        Departamento* localiza_depart(const char* n);

        void limpar_lista();
};