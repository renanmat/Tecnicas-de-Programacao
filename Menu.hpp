#pragma once

#include "ListaUniversidades.hpp"
#include "ListaAlunos.hpp"
#include "ListaProfessores.hpp"

class Menu
{
    private:
        int cont_idUniver;
        int cont_idDepart;
        int cont_idDiscip;
        int cont_idAluno;
        int cont_idProf;

        ListaUniversidades objLUniver;
        ListaDepartamentos objLDepart;
        ListaDisciplinas objLDiscip;
        ListaAlunos objLAluno;
        ListaProfessores objLProfesores;
    
    public:
        Menu();
        ~Menu();
        
        void cadastre_univer(Universidade* pu = nullptr);
        void cadastre_depart(Departamento* pd = nullptr);
        void cadastre_discp(Disciplina* pd = nullptr);
        void cadastre_alunos(Aluno* pA = nullptr);
        void cadastre_professor(Professor* pP = nullptr);

        void gravar_todos();
        void recuperar_todos();

        void menu_cad();
        void menu_exe();
        void menu_grav();
        void menu_recup();
        void menu_principal();
};