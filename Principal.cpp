#include "Principal.hpp"


Principal::Principal():
    //Professore
    Newton(4,1,1643, "Newton"),
    Einstein(14,3,1879, "Einstein"),

    //Aluno
    Renan(2189, 9, 5, 1995, "Renan M"),
    Matheus(1234,9,8,2000,"Matheus"),

    //Universidade
    Princeton("Princeton"),
    Cambridge("Cambridge"),
    UTFPR("UTFPR"),

    //Departamento
    Fisica("Fisica"),
    Matematica("Matematica"),
    Astronomia("Astronomia"),
    DAELN("Eletronica UTFPR"),

    //Disciplina
    Computacao1_2006(),
    Computacao2_2007(),
    Introd_alg_2007(),
    Metodos2_2007()

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
    Princeton.setDepart(&Fisica);
    Princeton.setDepart(&Astronomia);
    Cambridge.setDepart(&Matematica);
    UTFPR.setDepart(&DAELN);
}

void Principal::inicializa_departamento()
{
    //Departamento referencia a universidade que esta filiado
    Fisica.setUniversidade(&Princeton);
    Astronomia.setUniversidade(&Princeton);
    Matematica.setUniversidade(&Cambridge);
    DAELN.setUniversidade(&UTFPR);
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

void Principal::infor_DepartsUniver()
{
    Princeton.print_depart();
    cout<<endl;
    
    Cambridge.print_depart();
    cout<<endl;

    UTFPR.print_depart();
}

//Lista as diciplinas do departamento
void Principal::liste_Discp_de_Depart()
{
    DAELN.liste_disciplinas();
    cout<<endl;
}

void Principal::executar()
 {
    infor_idadeProf(); 
    cout<<endl;

    infor_ondeProfTrab();
    cout<<endl;

    infor_DepartProf();
    cout<<endl;

    infor_idadeAluno();
    cout<<endl;

    infor_DepartsUniver();
    cout<<endl;

    liste_Discp_de_Depart();
 }