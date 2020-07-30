#ifndef _DEPARTAMENTO_HPP_
#define _DEPARTAMENTO_HPP_
#include <string.h>

class Universidade;
class Disciplina;

class Departamento
{
    private:
        int id;
        char nome[100];
        Universidade* pUniversidade;
        
        //ponteiros para lista encadeada de disciplinas
        Disciplina* pDiscPrim;
        Disciplina* pDiscAtual;
    
    public:
        Departamento(const char* pNome = "", int i = 0);
        Departamento();
        ~Departamento();

        void setId(int i);
        int getId();


        void setNome(const char* pNome);
        char* getNome();

        //reverencia a universidade que esta afiliada
        void setUniversidade(Universidade* pUni);

        //agrega as disciplinas ao departamento
        //atraves de lista escadeada
        void inclui_disciplina(Disciplina* pd);
        void liste_disciplinas();
        void liste_disciplinas2();
};

#endif