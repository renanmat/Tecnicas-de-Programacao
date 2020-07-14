#ifndef _DEPARTAMENTO_HPP_
#define _DEPARTAMENTO_HPP_
#include <string.h>

class Departamento
{
    private:
        char nome[30];
    
    public:
        Departamento(const char* pNome = "");
        ~Departamento();
        void setDepart(const char* pNome);
        char* getDepart();
};

#endif