#pragma once

#include "Departamento.hpp"

class Disciplina
{
    private:
        int id;
        char nome[150];
        char area_conhecimento[150];
        Departamento* pDepartAssociado;
        Disciplina* pProx; 
        Disciplina* pAnt;

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
};