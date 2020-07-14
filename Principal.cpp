#include "Principal.hpp"


Principal::Principal():
    Newton(4,1,1643, "Newton"),
    Einstein(14,3,1879, "Einstein"),
    Princeton("Princeton"),
    Cambridge("Cambridge"),
    Fisica("Fisica"),
    Matematica("Matematica")
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
    Princeton.setDepart(Fisica);
    Cambridge.setDepart(Matematica);

    //Associa os obj departamento a obj pessoa
    Einstein.setDepartamento(&Fisica);
    Newton.setDepartamento(&Matematica);
}

Principal::~Principal()
{

}

void Principal::executar()
 {
    Newton.calc_idade(diaAt,mesAt,anoAt);
    Einstein.calc_idade(diaAt,mesAt,anoAt);
    
    cout<<endl;

    Newton.infoUniversidade();
    Einstein.infoUniversidade();

    cout<<endl;

    Newton.infoDepartamento();
    Einstein.infoDepartamento();
 }