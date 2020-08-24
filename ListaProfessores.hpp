#pragma once

#include "ElProfessor.hpp"

class ListaProfessores
{
    private:
        char nome[150];
        ElProfessor* pElProfPrim;
        ElProfessor* pElProfAtual;

    public:
        ListaProfessores(const char* n = "");
        ~ListaProfessores();

        void inclui_professor(Professor* p);

        void liste_professores();
        void liste_professores2();

        void limpar_lista();

        void gravar_professores(int tamanhoL);
        void recuperar_professores(int* contId);
};