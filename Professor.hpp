#pragma once

#include "Pessoa.hpp"
#include "Conhecimento.hpp"

class Professor : public Pessoa, public Conhecimento
{
    private:
        //pUniversidade eh apenas uma referencia a um objeto associado(obj pessoa) atravez de um ponteiro
        Universidade* pUniversidade;

        //pDepartamento eh apenas uma referencia a um objeto associado(obj pessoa) atravez de um ponteiro
        Departamento* pDepartamento;

        float salario, bolsa_projeto;

    public:
        Professor(int diaNas, int mesNas, int anoNas, const char *nomep = "");
        Professor(int rg = -1, int idGeral = -1); // 'rg' id da class Pessoa  e 'idGeral' id da class Conhecimento
        ~Professor();

        //metodo que permite associar uma Universidade a uma Pessoa
        void setUniversidade(Universidade* pUni);
        void infoUniversidade();

        //metodo que permite associar um Departamento a uma Pessoa
        void setDepartamento(Departamento* pDep);
        void infoDepartamento();

        void set_salario(float s);
        float get_salario();

        void set_bolsaProjeto(float bp);
        float get_bolsaProjeto();

        void informa_proventos();

        void informa_antiguidade();
};