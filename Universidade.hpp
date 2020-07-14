#ifndef _UNIVERSIDADE_HPP_
#define _UNIVERSIDADE_HPP_

#include "Departamento.hpp"
#include <string.h>


class Universidade
{
    private:
        char nome[30];

        //agregando um obj Departamento na classe pessoa
        Departamento objDepartamento;

    public:
        Universidade(const char *nome_uni = "");
        ~Universidade();
        void setNome(const char *nome_uni);
        char *getNome();

        //metodo para agregar departamento
        void setDepart(Departamento depart);
        Departamento getDepart();
    
};



#endif