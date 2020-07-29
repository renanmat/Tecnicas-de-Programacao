#ifndef _UNIVERSIDADE_HPP_
#define _UNIVERSIDADE_HPP_

#include "Departamento.hpp"
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//#include <vector> 
#include <list>
using namespace std;


class Universidade
{
    private:
        char nome[100];

        //agregando(agregacao fraca) um obj Departamento na classe pessoa
        //vector <Departamento*> lpDepart;
        list <Departamento*> lpDepart;

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