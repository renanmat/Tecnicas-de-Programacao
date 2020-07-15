#ifndef _UNIVERSIDADE_HPP_
#define _UNIVERSIDADE_HPP_

#include "Departamento.hpp"
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class Universidade
{
    private:
        char nome[30];

        //agregando um obj Departamento na classe pessoa
        Departamento *pDepartamento[50];
        int cont_dep; // conta quantos departamentos foram agregados(agregaçao fraca por ponteiro) a universidade

    public:
        Universidade(const char *nome_uni = "");
        Universidade();
        ~Universidade();
        void setNome(const char *nome_uni);
        char *getNome();

        //metodo para agregar departamento
        void setDepart(Departamento *pDepart);
        void print_depart();

    
};



#endif