#pragma once

class Conhecimento
{
    protected:
        int id;
        char dominio[150];

    public:
        Conhecimento();
        virtual ~Conhecimento();

        void set_id(int idC);
        int get_id();

        void set_dominio(const char* d);
        const char* get_dominio();
        
        /*funcao virtual pura - nao é implementada nessa classe, mas deve ser imprementada nas classes
        derivadas*/
        virtual void informa_antiguidade() = 0;

};