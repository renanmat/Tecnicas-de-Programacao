#pragma once

#include "ListaUniversidades.hpp"

class ListaUnivGravadora : public ListaUniversidades
{
    public:
        ListaUnivGravadora();
        ~ListaUnivGravadora();

        void gravar_universidades(int tamanhoL);
        void recuperar_universidades(int* contId);
};