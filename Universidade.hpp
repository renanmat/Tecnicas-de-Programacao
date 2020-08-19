#ifndef _UNIVERSIDADE_HPP_
#define _UNIVERSIDADE_HPP_

#include "ListaDepartamentos.hpp"

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;




class Universidade
{
    private:
        int id;
        char nome[100];
        ListaDepartamentos objListDepart;

    public:
        Universidade(int nd = 150, const char *nome_uni = "");
        ~Universidade();

        void set_id(int i);
        int get_id();
        void setNome(const char *nome_uni);
        char *getNome();

        //metodo para agregar departamento
        void inclui_depart(Departamento *pDepart);
        void liste_departamentos();
        void liste_departamentos2();

    
};



#endif