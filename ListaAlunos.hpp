#pragma once

#include "Aluno.hpp"
#include "Lista.hpp"

class ListaAlunos
{
    protected:
        Lista<Aluno> LTAlunos;
        int numeroAlunos;
        int contAluno;

    public:
        ListaAlunos(int nA = -1);
        ~ListaAlunos();

        void inclua_aluno(Aluno* pa);
        
        void liste_alunos();
        void liste_alunos2();

        void limpar_lista();
};