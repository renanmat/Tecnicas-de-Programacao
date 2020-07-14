#pragma once

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Pessoa{
    private:
        int dia;
        int mes;
        int ano;
        int idade;
        char nome[30];

    public:
        Pessoa(int diaNas, int mesNas, int anoNas, const char *nomep = "");
        Pessoa();
        ~Pessoa();
        void inicializa(int diaNas, int mesNas, int anoNas, const char *nomep = "");
        void calc_idade(int diaAt, int mesAt, int ano_atual);
        int getIdade();
};

