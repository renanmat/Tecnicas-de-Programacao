#pragma once

#include "Universidade.hpp"
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Pessoa{
    private:
        int dia,mes,ano;
        int idade;
        char nome[30];

        //pUniversidade eh apenas uma referencia a um objeto associado(obj pessoa) atravez de um ponteiro
        Universidade* pUniversidade;

        //pDepartamento eh apenas uma referencia a um objeto associado(obj pessoa) atravez de um ponteiro
        Departamento* pDepartamento;


    public:
        Pessoa(int diaNas, int mesNas, int anoNas, const char *nomep = "");
        Pessoa();
        ~Pessoa();
        void inicializa(int diaNas, int mesNas, int anoNas, const char *nomep = "");
        void calc_idade(int diaAt, int mesAt, int ano_atual);
        int getIdade();

        //metodo que permite associar uma Universidade a uma Pessoa
        void setUniversidade(Universidade* uni);
        void infoUniversidade();

        //metodo que permite associar um Departamento a uma Pessoa
        void setDepartamento(Departamento* pDep);
        void infoDepartamento();
};

