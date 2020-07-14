#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_

#include "Pessoa.hpp"
#include <time.h> // para pegar data atual do sistema

class Principal
{
    private:
        Pessoa Newton;
        Pessoa Einstein;

        //Objetos da classe Universidades sao agregados aos objetos dessa classe(classe Principal) 
        Universidade Princeton;
        Universidade Cambridge;

        //objeto classe departamento
        Departamento Fisica;
        Departamento Matematica;


        int diaAt, mesAt, anoAt;

    public:
        Principal();
        ~Principal();
        void executar(); 
};

#endif