#pragma once

#include "Lista.hpp"

class Disciplina;

class ListaDisciplinas
{
    protected:
        Lista<Disciplina> LTDisciplinas;
        int numeroDisc;
        int contDisc;
    
    public:
        ListaDisciplinas(int nd = -1);
        ~ListaDisciplinas();

        void inclua_disciplina(Disciplina* pd);

        void liste_disciplinas();
        void liste_disciplinas2();

        void limpar_lista();

        void grava_disciplinas(int tamanhoL);
        void recupera_disciplinas(int* contId);
};