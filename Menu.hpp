#pragma once

#include "ListaUniversidades.hpp"

class Menu
{
    private:
        int cont_idUniver;
        ListaUniversidades objLUniver;
        ListaDepartamentos objLDepart;
        ListaDisciplinas objLDiscip;
    
    public:
        Menu();
        ~Menu();
        
        void cadastre_univer(Universidade* pu = nullptr);
        void cadastre_depart(Departamento* pd = nullptr);
        void cadastre_discp(Disciplina* pd = nullptr);

        void menu_cad();
        void menu_exe();
        void menu_grav();
        void menu_recup();
        void menu_principal();
};