#pragma once

#include "ListaDisciplinas.hpp"

class ListaDisciplinasGravadora : public ListaDisciplinas
{
    public:
        ListaDisciplinasGravadora(int nD = -1);
        ~ListaDisciplinasGravadora();

        void grava_disciplinas(int tamanhoL);
        void recupera_disciplinas(int* contId);
};