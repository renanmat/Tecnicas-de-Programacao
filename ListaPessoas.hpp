#pragma once

#include "Pessoa.hpp"
#include "Lista.hpp"

class ListaPessoas
{
    private:
        Lista<Pessoa> LTPessoas;

    public:
        ListaPessoas();
        ~ListaPessoas();

        void inclua_pessoa(Pessoa* p);
        void liste_pessoas();

        void limpar_lista();

        void liste_proventos();
};