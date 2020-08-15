#include "Principal.hpp"


Principal::Principal():
    //Professore
    Newton(4,1,1643, "Newton"),
    Einstein(14,3,1879, "Einstein"),

    //Aluno
    Renan(2189, 9, 5, 1995, "Renan M"),
    Matheus(1234,9,8,2000,"Matheus"),
    Daniel(1985, 8, 8, 1988, "Daniel"),
    Ana(698745, 20, 1 , 200, "Ana" ),

    //Universidade
    Princeton(-1,"Princeton"),
    Cambridge(-1,"Cambridge"),
    UTFPR(-1,"UTFPR"),

    //Departamento
    Fisica("Fisica"),
    Matematica("Matematica"),
    Astronomia("Astronomia"),
    DAELN("Eletronica UTFPR"),

    //Disciplina
    Computacao1_2006(),
    Computacao2_2007(),
    Introd_alg_2007(),
    Metodos2_2007(),
    
    //Menu
    objMenu()

{  
    //Ponteiro que armazena data e hora
    struct tm *data_hora_atual;
    // variavel do tipo time_t para armazenar o tempo em segundos
    time_t segundos;
    // obtendo o tempo em segundos
    time(&segundos);
    //localtime converte os segundos em tempo local
    data_hora_atual = localtime(&segundos);
    //armazena dia, mes e ano do sistema
    diaAt = data_hora_atual->tm_mday;
    mesAt = data_hora_atual->tm_mon + 1;
    anoAt = data_hora_atual->tm_year + 1900;

    inicializa();
    executar();
}

Principal::~Principal()
{
}

void Principal::inicializa()
{
    inicializa_professor();
    inicializa_universidade();
    inicializa_departamento();
    inicializa_disciplina();
}

void Principal::inicializa_professor()
{
    //os objetos da classe Universidade sao associados a classe Pessoa atravez de um ponteiro.
    Newton.setUniversidade(&Cambridge);
    Einstein.setUniversidade(&Princeton);

    //Associa os obj departamento a obj pessoa
    Einstein.setDepartamento(&Fisica);
    Newton.setDepartamento(&Matematica);
}


void Principal::inicializa_universidade()
{
    //agrega departamento a uma ao obj Universidade
    Princeton.inclui_depart(&Fisica);
    Princeton.inclui_depart(&Astronomia);
    Cambridge.inclui_depart(&Matematica);
    UTFPR.inclui_depart(&DAELN);

    objMenu.cadastre_univer(&Princeton);
    objMenu.cadastre_univer(&Cambridge);
    objMenu.cadastre_univer(&UTFPR);

}

void Principal::inicializa_departamento()
{
    //Departamento referencia a universidade que esta filiado
    Fisica.set_univerAssocida(&Princeton);
    Astronomia.set_univerAssocida(&Princeton);
    Matematica.set_univerAssocida(&Cambridge);
    DAELN.set_univerAssocida(&UTFPR);

    objMenu.cadastre_depart(&Fisica);
    objMenu.cadastre_depart(&Astronomia);
    objMenu.cadastre_depart(&Matematica);
    objMenu.cadastre_depart(&DAELN);
}

void Principal::inicializa_disciplina()
{
    //set nomes
    Computacao1_2006.set_nome("Computacao 1 2006");
    Computacao2_2007.set_nome("Computacao 2 2007");
    Introd_alg_2007.set_nome("Introducao a algoritmos 2007");
    Metodos2_2007.set_nome("Metodos II");

    // agrega (agregaçao fraca) as disciplinas ao departamento
    Computacao1_2006.set_departAssociado(&DAELN);
    Computacao2_2007.set_departAssociado(&DAELN);
    Introd_alg_2007.set_departAssociado(&DAELN);
    Metodos2_2007.set_departAssociado(&DAELN);

    //Associa alunos a uma disciplina
    Computacao1_2006.inclui_aluno(&Renan);
    Computacao1_2006.inclui_aluno(&Matheus);
    Computacao1_2006.inclui_aluno(&Daniel);

    Metodos2_2007.inclui_aluno(&Renan);
    Metodos2_2007.inclui_aluno(&Ana);
    Metodos2_2007.inclui_aluno(&Daniel);

    //inserir notas e faltas de alunos
    Metodos2_2007.set_notas(2189, 7.5, 8.0, 0, 7 );
    Metodos2_2007.set_notas(1985, 9.45, 3.0, 10.0, 15);

    objMenu.cadastre_discp(&Computacao1_2006);
    objMenu.cadastre_discp(&Computacao2_2007);
    objMenu.cadastre_discp(&Introd_alg_2007);
    objMenu.cadastre_discp(&Metodos2_2007);
}

void Principal::inicializa_aluno()
{
}

//# # # # # # Executar # # # # # #
 
void Principal::infor_idadeProf()
{
    Newton.calc_imprime_idade(diaAt,mesAt,anoAt);
    Einstein.calc_imprime_idade(diaAt,mesAt,anoAt);
}

void Principal::infor_idadeAluno()
{
    Renan.calc_imprime_idade(diaAt,mesAt,anoAt);
    Matheus.calc_imprime_idade(diaAt,mesAt,anoAt);
}

void Principal::infor_ondeProfTrab()
{
    Newton.infoUniversidade();
    Einstein.infoUniversidade();
}

void Principal::infor_DepartProf()
{
    Newton.infoDepartamento();
    Einstein.infoDepartamento();
}

void Principal::liste_DepartsUniver()
{
    Princeton.liste_departamentos();
    cout<<endl;
    
    Cambridge.liste_departamentos2();
    cout<<endl;

    UTFPR.liste_departamentos();
}

//Lista as diciplinas do departamento
void Principal::liste_Discp_de_Depart()
{
    DAELN.liste_disciplinas();
    cout<<endl;

    DAELN.liste_disciplinas2();
    cout<<endl;
}

void Principal::liste_alunos_de_disciplina()
{
    Computacao1_2006.liste_alunos();
    cout<<endl;

    Metodos2_2007.liste_alunos2();
    cout<<endl;
    
}

void Principal::informe_notasAlunos()
{
    Metodos2_2007.info_aluno(1985);
    cout<<endl;
    Metodos2_2007.info_aluno(2189);
    cout<<endl;
}

void Principal::executar()
 {
    // infor_idadeProf(); 
    // cout<<endl;

    // infor_ondeProfTrab();
    // cout<<endl;

    // infor_DepartProf();
    // cout<<endl;

    // infor_idadeAluno();
    // cout<<endl;
    
    // informe_notasAlunos();

    objMenu.menu_principal();
 }