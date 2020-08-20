#pragma once

#include "ElUniversidade.hpp"

class ListaUniversidades
{
    private:
        ElUniversidade* pElUnivPrim;
        ElUniversidade* pElUnivAtual;

        int id;

    public:
        ListaUniversidades();
        ~ListaUniversidades();

        void inclui_univ(Universidade* pu);
        void liste_univ();
        void liste_univ2();

        Universidade* localiza_universidade(const char* nUniv);

        void set_id(int i);
        int get_id();

        void limpa_lista();

        void gravar_universidades();
        void recuperar_universidades(int* cont);
};