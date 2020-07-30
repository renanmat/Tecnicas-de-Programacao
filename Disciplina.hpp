#pragma once

#include "Departamento.hpp"
#include "Aluno.hpp"

class Disciplina
{
    private:
        int id;
        char nome[150];
        char area_conhecimento[150];
        Departamento* pDepartAssociado;
        Disciplina* pProx; 
        Disciplina* pAnt;

        //Ponteiros da lista encadiada de alunos
        Aluno* pAlunoPrim;
        Aluno* pAlunoAtual;
        int cont_alunos;

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

        //get e set pata ponteiros da Disciplina anterior e proxima de lista encadeada
        void set_pProx(Disciplina* pd);
        Disciplina* get_pProx();

        void set_pAnt(Disciplina* pd);
        Disciplina* get_pAnt();

        //Metodos da lista encadiada de Alunos
        void inclui_aluno(Aluno* pa);
        void exclui_aluno(Aluno* pa);
        void liste_alunos();
        void liste_alunos2();
};