#include "Principal.hpp"



Principal::Principal():
    //Professore
    Newton(4,1,1643, "Newton"),
    Einstein(14,3,1879, "Einstein"),

    //Aluno
    Renan(2189, 9, 5, 1995, "RenanM"),
    Matheus(1234,9,8,2000,"Matheus"),
    Daniel(1985, 8, 8, 1988, "Daniel"),
    Ana(698745, 20, 1 , 200, "Ana" ),

    //Universidade
    Princeton(0, -1,"Princeton"),
    Cambridge(1, -1,"Cambridge"),
    UTFPR(2, -1,"UTFPR"),

    //Departamento
    Fisica("Fisica", 0),
    Matematica("Matematica", 1),
    Astronomia("Astronomia", 2),
    DAELN("EletronicaUTFPR", 3),

    //Disciplina
    Computacao1_2006(0),
    Computacao2_2007(1),
    Introd_alg_2007(2),
    Metodos2_2007(3),

    //Estagiario
    Marcos(),
    Lucas(),
    
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
    inicializa_aluno();
    inicializa_estagiario();
}

void Principal::inicializa_professor()
{
    //os objetos da classe Universidade sao associados a classe Pessoa atravez de um ponteiro.
    Newton.setUniversidade(&Cambridge);
    Einstein.setUniversidade(&Princeton);

    //Associa os obj departamento a obj pessoa
    Newton.setDepartamento(&Matematica);
    Einstein.setDepartamento(&Fisica);

    //isere id
    Newton.Pessoa::set_id(0);
    Einstein.Pessoa::set_id(1);

    //inserir o conhecimento que o prof domina
    Newton.set_dominio("Matematica");
    Einstein.set_dominio("Fisica");


    //inserindo salario e bolsa projeto
    Newton.set_salario(25000);
    Newton.set_bolsaProjeto(2000);

    Einstein.set_salario(50000);

    //cadastra professor na lista principal
    objMenu.cadastre_professor(&Newton);
    objMenu.cadastre_professor(&Einstein);

    //cadastrar professores na lista de pessoas
    Professor* pProfessor = nullptr;
    Pessoa* pPessoa = nullptr;

    pProfessor = &Newton;
    pPessoa = static_cast<Pessoa*>(pProfessor);//'static_cast' verifica se a conversao é valida
    objMenu.cadastre_pessoa(pPessoa);

    pProfessor = &Einstein;
    pPessoa = static_cast<Pessoa*>(pProfessor);//'static_cast' verifica se a conversao é valida
    objMenu.cadastre_pessoa(pPessoa);

}


void Principal::inicializa_universidade()
{
    //agrega departamento a uma ao obj Universidade
    Princeton.inclui_depart(&Fisica);
    Princeton.inclui_depart(&Astronomia);
    Cambridge.inclui_depart(&Matematica);
    UTFPR.inclui_depart(&DAELN);

    //Cadastra universidade na lista principal do sistema
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

    //Cadastra departamento na lista principal do sistema
    objMenu.cadastre_depart(&Fisica);
    objMenu.cadastre_depart(&Matematica);
    objMenu.cadastre_depart(&Astronomia);
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
    // Metodos2_2007.set_notas(2189, 7.5, 8.0, 0, 7 );
    // Metodos2_2007.set_notas(1985, 9.45, 3.0, 10.0, 15);

    //Cadastra disciplina na lista principal do sistema
    objMenu.cadastre_discp(&Computacao1_2006);
    objMenu.cadastre_discp(&Computacao2_2007);
    objMenu.cadastre_discp(&Introd_alg_2007);
    objMenu.cadastre_discp(&Metodos2_2007);
}

void Principal::inicializa_aluno()
{
    //set ids
    Renan.set_id(0);
    Matheus.set_id(1);
    Daniel.set_id(2);
    Ana.set_id(3);

    //adiciona na lista principal de alunos
    objMenu.cadastre_alunos(&Renan);
    objMenu.cadastre_alunos(&Matheus);
    objMenu.cadastre_alunos(&Daniel);
    objMenu.cadastre_alunos(&Ana);

    //cadastrando alunos na lista pessoas
    Pessoa* pPessoa = nullptr;
    Aluno* pAluno = nullptr;
    //metodo para fazer cast mais seguro(ha uma verificacao) de aluno para pessoa
    pAluno = &Renan;
    pPessoa = static_cast<Pessoa*>(pAluno);
    objMenu.cadastre_pessoa(pPessoa);

    pAluno = &Matheus;
    pPessoa = static_cast<Pessoa*>(pAluno);
    objMenu.cadastre_pessoa(pPessoa);

    pAluno = &Daniel;
    pPessoa = static_cast<Pessoa*>(pAluno);
    objMenu.cadastre_pessoa(pPessoa);

    pAluno = &Ana;
    pPessoa = static_cast<Pessoa*>(pAluno);
    objMenu.cadastre_pessoa(pPessoa);

}

void Principal::inicializa_estagiario()
{
    Estagiario* pEstagiario = nullptr;
    Aluno* pAluno = nullptr;
    Pessoa* pPessoa = nullptr;

    //***********************
    Marcos.set_nome("Marcos");
    Marcos.set_bolsaEstudo(800);
    pEstagiario = &Marcos;//pegando o endereço da variavel
    pAluno = static_cast<Aluno*>(pEstagiario);//vazendo cast de estagiario para aluno
    objMenu.cadastre_alunos(pAluno);//cadastrando na lista de alunos
    pPessoa = static_cast<Pessoa*>(pEstagiario);//vazendo cast de estagiario para pessoa
    objMenu.cadastre_pessoa(pPessoa);//cadastrando na lista de pessoas

    //************************
    Lucas.set_nome("Lucas");
    Lucas.set_bolsaEstudo(600);
    pEstagiario = &Lucas;
    pAluno = static_cast<Aluno*>(pEstagiario);
    objMenu.cadastre_alunos(pAluno);
    pPessoa = static_cast<Pessoa*>(pEstagiario);
    objMenu.cadastre_pessoa(pPessoa);

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

    DAELN.liste_disciplinas();
    cout<<endl;
}

void Principal::liste_alunos_de_disciplina()
{
    Computacao1_2006.liste_alunos();
    cout<<endl;

    Metodos2_2007.liste_alunos2();
    cout<<endl;
    
}

// void Principal::informe_notasAlunos()
// {
//     Metodos2_2007.info_aluno(1985);
//     cout<<endl;
//     Metodos2_2007.info_aluno(2189);
//     cout<<endl;
// }

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