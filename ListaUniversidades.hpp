#pragma once

#include "Lista.hpp"

class Universidade;

class ListaUniversidades
{
    protected:
        Lista<Universidade> LTUniver;

    public:
        ListaUniversidades();
        ~ListaUniversidades();

        void inclui_univ(Universidade* pU);

        void liste_univ();
        void liste_univ2();

        Universidade* localiza_universidade(const char* nUniv);

        void limpar_lista();
};