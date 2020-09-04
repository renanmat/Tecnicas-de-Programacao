#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_

#include "Aluno.hpp"
#include "Disciplina.hpp"
#include "Menu.hpp"


#include <time.h> // para pegar data atual do sistema



class Principal
{
    private:
        //Professores
        Professor Newton;
        Professor Einstein;

        // Alunos
        Aluno Renan, Matheus, Daniel, Ana;

        //Universidade
        Universidade Princeton;
        Universidade Cambridge;
        Universidade UTFPR;

        //Departamento
        Departamento Fisica;
        Departamento Matematica;
        Departamento Astronomia;
        Departamento DAELN;

        //Disciplina
        Disciplina Computacao1_2006;
        Disciplina Computacao2_2007;
        Disciplina Introd_alg_2007;
        Disciplina Metodos2_2007;

        //Estagiario
        Estagiario Marcos;
        Estagiario Lucas;

        Menu objMenu;
        
        //Dia, mes e ano atuais(data informada pelo sistema)
        int diaAt, mesAt, anoAt;

    public:
        Principal();
        ~Principal();

        void inicializa();
        void inicializa_professor();
        void inicializa_universidade();
        void inicializa_departamento();
        void inicializa_disciplina();
        void inicializa_aluno();
        void inicializa_estagiario();

        void infor_idadeProf();
        void infor_idadeAluno();
        void infor_ondeProfTrab();
        void infor_DepartProf();
        void liste_DepartsUniver();
        void liste_Discp_de_Depart();
        void liste_alunos_de_disciplina();
        // void informe_notasAlunos();
        void liste_univs();

        void executar(); 
};

#endif