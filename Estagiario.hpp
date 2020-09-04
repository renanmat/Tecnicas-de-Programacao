#pragma once

#include "Aluno.hpp"

class Estagiario : public Aluno
{
    private:
        float bolsaEstudo;
    
    public:
        Estagiario(int ra, int diaNas, int mesNas, int anoNas, const char* nomep = "");
        Estagiario(int i = -1);
        ~Estagiario();

        void inicializa();

        void set_bolsaEstudo(float be);
        float get_bolsaEstudo();

        void informa_proventos();
};