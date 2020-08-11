#pragma once

#include "ElAluno.hpp"

class Departamento;



class Disciplina
{
    private:
        int id;
        char nome[150];
        char area_conhecimento[150];
        Departamento* pDepartAssociado;

        //Ponteiros da lista encadiada de alunos
        ElAluno* pElAlunoPrim;
        ElAluno* pElAlunoAtual;
        int cont_alunos;

        //metodo interno para buscar aluno dentro da lista
        ElAluno* get_alunoList(int ra);

    public:
        Disciplina(const char* ac = "");
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
        //informa as notas e faltas do aluno
        void info_aluno(int ra);


};