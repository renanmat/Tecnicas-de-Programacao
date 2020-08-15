#pragma once

#include "ElUniversidade.hpp"

class ListaUniversidades
{
    private:
        ElUniversidade* pElUnivPrim;
        ElUniversidade* pElUnivAtual;

    public:
        ListaUniversidades();
        ~ListaUniversidades();

        void inclui_univ(Universidade* pu);
        void liste_univ();
        void liste_univ2();

        Universidade* localiza_universidade(const char* nUniv);
};