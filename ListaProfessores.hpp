#pragma once

#include "Professor.hpp"
#include "Lista.hpp"

class ListaProfessores
{
    protected:
        Lista<Professor> LTProf;
        int numeroProf;
        int contProf;

    public:
        ListaProfessores(int nP = -1);
        ~ListaProfessores();

        void inclua_professor(Professor* pP);

        void liste_professores();
        void liste_professores2();
        void liste_conhecimento();

        void limpar_lista();
};