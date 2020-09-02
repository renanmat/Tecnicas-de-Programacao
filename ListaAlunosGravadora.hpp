#pragma once

#include "ListaAlunos.hpp"

class ListaAlunosGravadora : public ListaAlunos
{
    public:
        ListaAlunosGravadora(int nA = -1);
        ~ListaAlunosGravadora();

        void gravar_alunos(int tamanhoL);
        void recuperar_alunos(int* contId);
};