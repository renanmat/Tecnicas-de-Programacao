#pragma once

#include "Universidade.hpp"
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Pessoa{
    protected:
        int dia,mes,ano;
        int idade;
        char nome[30];

    public:
        Pessoa(int diaNas, int mesNas, int anoNas, const char *nomep = "");
        Pessoa();
        ~Pessoa();
        void inicializa(int diaNas, int mesNas, int anoNas, const char *nomep = "");

        void set_nome(const char* n);
        char* get_nome();
        
        //calcular e imprimir idade
        void calc_idade(int diaAt, int mesAt, int ano_atual);
        void imprime_idade();
        void calc_imprime_idade(int diaAt, int mesAt, int ano_atual);
        int getIdade();


};

