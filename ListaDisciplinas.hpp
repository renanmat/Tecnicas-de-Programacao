#pragma once

#include "ElDisciplina.hpp"


class ListaDisciplinas
{
    private:
        char nome[100];
        ElDisciplina* pElDiscPrim;
        ElDisciplina* pElDiscAtual;
        int numero_disciplinas;
        int cont;
        int id;
    
    public:
        ListaDisciplinas(int nd = 200, const char* n = "");
        ~ListaDisciplinas();

        void set_nome(const char* n);

        //agrega as disciplinas ao departamento
        //atraves de lista escadeada
        void inclui_disciplina(Disciplina* pd);
        //Os elementos sao listados do primeiro ate o ultimo
        void liste_disciplinas();
        //Os elementos sao listados do ultimo ate o primeiro
        void liste_disciplinas2();

        void set_id(int i);
        int get_id();

        void limpa_lista();

        void grava_disciplinas(int tamanhoL);
        void recupera_disciplinas(int* contId);
};