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
        Departamento **pDepartamento;
        int cont_dep; // conta quantos departamentos foram agregados(agregaçao fraca por ponteiro) a universidade

    public:
        Universidade(const char *nome_uni = "");
        Universidade();
        ~Universidade();
        void setNome(const char *nome_uni);
        char *getNome();

        //metodo para agregar departamento
        // set_quant_depart aloca dinamicamente a quantidade de departamentos sendo no maximo 50
        void set_quant_depart(int quant);
        void setDepart(Departamento *pDepart);
        void print_depart();

    
};



#endif