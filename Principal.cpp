#include "Principal.hpp"


Principal::Principal():
    Newton(4,1,1643, "Newton"),
    Einstein(14,3,1879, "Einstein")
{  

    //Ponteiro que armazena data e hora
    struct tm *data_hora_atual;
    // variavel do tipo time_t para armazenar o tempo em segundos
    time_t segundos;
    // obtendo o tempo em segundos
    time(&segundos);
    //localtime converte os segundos em tempo local
    data_hora_atual = localtime(&segundos);

    diaAt = data_hora_atual->tm_mday;
    mesAt = data_hora_atual->tm_mon + 1;
    anoAt = data_hora_atual->tm_year + 1900;
}

Principal::~Principal()
{
    
}

void Principal::executar()
 {
    Newton.calc_idade(diaAt,mesAt,anoAt);
    Einstein.calc_idade(diaAt,mesAt,anoAt);
 }