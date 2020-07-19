#pragma once

#include "Pessoa.hpp"

class Professor : public Pessoa
{
    private:
        //pUniversidade eh apenas uma referencia a um objeto associado(obj pessoa) atravez de um ponteiro
        Universidade* pUniversidade;

        //pDepartamento eh apenas uma referencia a um objeto associado(obj pessoa) atravez de um ponteiro
        Departamento* pDepartamento;

    public:
        Professor(int diaNas, int mesNas, int anoNas, const char *nomep = "");
        Professor();
        ~Professor();

        //metodo que permite associar uma Universidade a uma Pessoa
        void setUniversidade(Universidade* pUni);
        void infoUniversidade();

        //metodo que permite associar um Departamento a uma Pessoa
        void setDepartamento(Departamento* pDep);
        void infoDepartamento();
};