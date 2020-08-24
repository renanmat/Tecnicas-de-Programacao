#pragma once

#include "ElAluno.hpp"

class ListaAlunos
{
    private:
        //Ponteiros da lista encadiada de alunos
        ElAluno* pElAlunoPrim;
        ElAluno* pElAlunoAtual;
        int cont_alunos;
        int num_alunos;
        char nome[150];
        int id;
    
    public:
        ListaAlunos(int quatAl = -1, const char* n = "");
        ~ListaAlunos();

        void set_nome(const char* n);

        //Metodos da lista encadiada de Alunos
        void inclui_aluno(Aluno* pa);
        void liste_alunos();
        void liste_alunos2();

        //metodo interno para buscar aluno dentro da lista
        ElAluno* get_alunoList(int ra);
        //recebe as notas e faltas do aluno
        void set_notas(int ra, double n1, double n2, double f, int nFalt);
        //informa as notas e faltas do aluno
        void info_aluno(int ra);

        void set_id(int i);
        int get_id();

        void limpa_lista();

        void gravar_alunos(int tamanhoL);
        void recuperar_alunos(int* contId);
};