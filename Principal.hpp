#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_

#include "Professor.hpp"
#include "Aluno.hpp"
#include <time.h> // para pegar data atual do sistema

class Principal
{
    private:
        //obj da classe professor que é dirivada da classe Pessoa
        Professor Newton;
        Professor Einstein;

        // objs da classe aluno que é dirivada da classe pessoa
        Aluno Renan, Matheus;

        //Objetos da classe Universidades sao agregados aos objetos dessa classe(classe Principal) 
        Universidade Princeton;
        Universidade Cambridge;

        //objeto classe departamento
        Departamento Fisica;
        Departamento Matematica;
        Departamento Astronomia;


        int diaAt, mesAt, anoAt;

    public:
        Principal();
        ~Principal();
        void executar(); 
};

#endif