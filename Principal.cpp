#include "Principal.hpp"


Principal::Principal():
    Newton(4,1,1643, "Newton"),
    Einstein(14,3,1879, "Einstein"),
    Renan(2189, 9, 5, 1995, "Renan M"),
    Matheus(1234,9,8,2000,"Matheus"),
    Princeton("Princeton"),
    Cambridge("Cambridge"),
    Fisica("Fisica"),
    Matematica("Matematica"),
    Astronomia("Astronomia")
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

    //os objetos da classe Universidade sao associados a classe Pessoa atravez de um ponteiro.
    Newton.setUniversidade(&Cambridge);
    Einstein.setUniversidade(&Princeton);

    //agrega departamento a uma ao obj Universidade
    Princeton.setDepart(&Fisica);
    Princeton.setDepart(&Astronomia);
    Cambridge.setDepart(&Matematica);

    //Departamento referencia a universidade que esta filiado
    Fisica.setUniversidade(&Princeton);
    Astronomia.setUniversidade(&Princeton);
    Matematica.setUniversidade(&Cambridge);

    //Associa os obj departamento a obj pessoa
    Einstein.setDepartamento(&Fisica);
    Newton.setDepartamento(&Matematica);

    executar();
}

Principal::~Principal()
{

}

void Principal::executar()
 {
    Newton.calc_imprime_idade(diaAt,mesAt,anoAt);
    Einstein.calc_imprime_idade(diaAt,mesAt,anoAt);
    
    cout<<endl;

    Newton.infoUniversidade();
    Einstein.infoUniversidade();

    cout<<endl;

    Newton.infoDepartamento();
    Einstein.infoDepartamento();

    cout<<endl;

    Princeton.print_depart();
    Cambridge.print_depart();

    cout<<endl;
    Renan.calc_imprime_idade(diaAt,mesAt,anoAt);
    Matheus.calc_imprime_idade(diaAt,mesAt,anoAt);

 }