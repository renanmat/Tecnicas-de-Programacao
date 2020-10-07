#pragma once

//#include "Lista.hpp"
#include <list> //templaite list da stl(biblioteca padrao de templaites) - list->utiliza lista encadiada

class Universidade;

class ListaUniversidades
{
    protected:
        std::list<Universidade*> LTUniver;
        std::list<Universidade*>::iterator iteradorLUniv;
        std::list<Universidade*>::reverse_iterator rIterador;
    public:
        ListaUniversidades();
        ~ListaUniversidades();

        void inclui_univ(Universidade* pU);

        void liste_univ();
        void liste_univ2();

        Universidade* localiza_universidade(const char* nUniv);

        void limpar_lista();
};