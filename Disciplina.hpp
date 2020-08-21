#pragma once

#include "ListaAlunos.hpp"

class Departamento;

class Disciplina
{
    private:
        int id;
        char nome[150];
        char area_conhecimento[150];
        Departamento* pDepartAssociado;

        ListaAlunos objLAlunos;

    public:
        Disciplina(int i = -1, int numAlunos = 45, const char* n = "");
        ~Disciplina();

        //gets e sets para atributos
        void set_nome(const char* n);
        void set_id(int i);
        void set_area_conhecimento(const char* ac);
        char* get_nome();
        int get_id();
        char* get_are_conhecimento();
        
        //agregaçao fraca via ponteiro
        //agregando Disciplina ao Departamento
        void set_departAssociado(Departamento* pd);
        Departamento* get_departAssociado();

        //Metodos da lista encadiada de Alunos
        void inclui_aluno(Aluno* pa);
        void liste_alunos();
        void liste_alunos2();

        //recebe as notas e faltas do aluno
        void set_notas(int ra, double n1, double n2, double f, int nFalt);
        //informa as notas e faltas do alunoS
        void info_aluno(int ra);


};