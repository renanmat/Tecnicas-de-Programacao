#include "Nota.hpp"

Nota::Nota()
{
    primParcial = 0;
    secParcial = 0;
    parcFinal = 0;
    nFaltas = 0;
}
Nota::~Nota()
{
    primParcial = 0;
    secParcial = 0;
    parcFinal = 0;
    nFaltas = 0;
}

void Nota::set_primParcial(double nt)
{
    primParcial = nt;
}
double Nota::get_primParcial()
{
    return primParcial;
}

void Nota::set_secParcial(double nt)
{
    secParcial = nt;
}
double Nota::get_secParcial()
{
    return secParcial;
}

void Nota::set_final(double nt)
{
    parcFinal = nt;
}

double Nota::get_final()
{
    return parcFinal;
}

void Nota::set_nFaltas(int f)
{
    nFaltas = f;
}
int Nota::get_nFaltas()
{
    return nFaltas;
}