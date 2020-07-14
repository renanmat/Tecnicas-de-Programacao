#ifndef PRINCIPAL_HPP
#define PRINCIPAL_HPP

#include "Pessoa.hpp"
#include <time.h> // para pegar data atual do sistema

class Principal
{
    private:
        Pessoa Newton;
        Pessoa Einstein;
        int diaAt, mesAt, anoAt;

    public:
        Principal();
        ~Principal();
        void executar(); 
};

#endif