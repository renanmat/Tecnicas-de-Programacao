#include "Conhecimento.hpp"

#include "string.h"

Conhecimento::Conhecimento()
{
    strcpy(dominio, "");
}
Conhecimento::~Conhecimento()
{
    strcpy(dominio, "");
}

void Conhecimento::set_id(int idC)
{
    id = idC;
}
int Conhecimento::get_id()
{
    return id;
}

void Conhecimento::set_dominio(const char* d)
{
    strcpy(dominio,d);
}
const char* Conhecimento::get_dominio()
{
    return dominio;
}