#ifndef _DEPARTAMENTO_HPP_
#define _DEPARTAMENTO_HPP_
#include <string.h>

#include "ListaDisciplinas.hpp"
class Universidade;
class Disciplina;

class Departamento
{
    private:
        int id;
        char nome[100];
        Universidade* pUniversidade;
        ListaDisciplinas objLDisciplinas;
    
    public:
        Departamento(const char* pNome = "", int i = 0);
        ~Departamento();

        void set_id(int i);
        int get_id();


        void setNome(const char* pNome);
        char* getNome();

        //referencia a universidade que esta afiliada
        void set_univerAssocida(Universidade* pUni);

        //agrega as disciplinas ao departamento
        //atraves de lista escadeada
        void inclui_disciplina(Disciplina* pd);
        //Os elementos sao listados do primeiro ate o ultimo
        void liste_disciplinas();
        //Os elementos sao listados do ultimo ate o primeiro
        void liste_disciplinas2();
};

#endif