#pragma once

#include "ListaProfessores.hpp"

class ListaProfessoresGravadora : public ListaProfessores
{
    public:
        ListaProfessoresGravadora(int np = -1);
        ~ListaProfessoresGravadora();

        void gravar_professores(int tamanhoL);
        void recuperar_professores(int* contId);
};