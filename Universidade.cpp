 #include "Universidade.hpp"
 
 
 Universidade::Universidade(int i,int nd, const char *nome_uni):
 id(i), // set um id a universidade
 objListDepart(nd, nome_uni)//passa para lista o numero de departamentos e o nome da universidade
 {
     strcpy(nome, nome_uni);
 }

Universidade::~Universidade()
{
}

void Universidade::set_id(int i)
{
    id = i;
}
int Universidade::get_id()
{
    return id;
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