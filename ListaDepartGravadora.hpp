#pragma once

#include "ListaDepartamentos.hpp"

class ListaDepartGravadora : public ListaDepartamentos
{
    public:
        ListaDepartGravadora(int nd = -1);
        ~ListaDepartGravadora();

        void grava_departamentos(int tamanhoList);
        void recuperar_departamentos(int* cont);
};