 #include "Universidade.hpp"
 
 
 Universidade::Universidade(int nd, const char *nome_uni):
 objListDepart(-1, nome_uni)
 {
     strcpy(nome, nome_uni);
 }

Universidade::~Universidade()
{
}

void Universidade::setNome(const char *nome_uni)
{
    strcpy(nome,nome_uni);
    objListDepart.set_nome(nome_uni);
}

char* Universidade::getNome()
{
    return nome;
}


void Universidade::inclui_depart(Departamento* pDepart)
{
    objListDepart.inclui_depart(pDepart);
}
        
void Universidade::liste_departamentos()
{
    objListDepart.liste_depart();
}

void Universidade::liste_departamentos2()
{
    objListDepart.liste_depart2();
}