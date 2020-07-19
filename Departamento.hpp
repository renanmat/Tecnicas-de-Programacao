#ifndef _DEPARTAMENTO_HPP_
#define _DEPARTAMENTO_HPP_
#include <string.h>

class Universidade;

class Departamento
{
    private:
        int id;
        char nome[100];
        Universidade* pUniversidade;
    
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
};

#endif