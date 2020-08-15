#pragma once

#include "ListaUniversidades.hpp"

class Menu
{
    private:
        ListaUniversidades objLUniver;
        ListaDepartamentos objLDepart;
        ListaDisciplinas objLDiscip;
    
    public:
        Menu();
        ~Menu();
        
        void cadastre_univer(Universidade* pu = nullptr);
        void cadastre_depart(Departamento* pd = nullptr);
        void cadastre_discp(Disciplina* pd = nullptr);

        void liste_univers();
        void liste_depart();
        void liste_discp();

        void menu_cad();
        void menu_exe();
        void menu_principal();
};