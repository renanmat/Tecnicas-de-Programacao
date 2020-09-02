#pragma once

#include "Departamento.hpp"
#include "Lista.hpp"

class ListaDepartamentos
{
    protected:
        Lista<Departamento> LTDepart;
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