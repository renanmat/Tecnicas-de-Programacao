#ifndef _DEPARTAMENTO_HPP_
#define _DEPARTAMENTO_HPP_
#include <string.h>

class Universidade;

class Departamento
{
    private:
        char nome[30];
        Universidade* pUniversidade;
    
    public:
        Departamento(const char* pNome = "");
        ~Departamento();
        void setDepart(const char* pNome);
        char* getDepart();

        //reverencia a universidade que esta afiliada
        void setUniversidade(Universidade* pUni);
};

#endif