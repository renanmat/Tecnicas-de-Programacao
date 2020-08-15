#include "ElUniversidade.hpp"

ElUniversidade::ElUniversidade()
{
    pUniv = nullptr;
    pProx = nullptr;
    pAnt = nullptr;
}
ElUniversidade::~ElUniversidade()
{
    pUniv = nullptr;
    pProx = nullptr;
    pAnt = nullptr;
}

void ElUniversidade::set_univ(Universidade* pu)
{
    pUniv = pu;
}
Universidade* ElUniversidade::get_univ()
{
    return pUniv;
}

void ElUniversidade::set_prox(ElUniversidade* peu)
{
    pProx = peu;
}
ElUniversidade* ElUniversidade::get_prox()
{
    return pProx;
}

void ElUniversidade::set_ant(ElUniversidade* peu)
{
    pAnt = peu;
}
ElUniversidade* ElUniversidade::get_ant()
{
    return pAnt;
}

char* ElUniversidade::get_nomeUniv()
{
    return pUniv->getNome();
}