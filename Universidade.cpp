 #include "Universidade.hpp"
 
 
 Universidade::Universidade(const char *nome_uni)
 {
     strcpy(nome, nome_uni);
 }

Universidade::~Universidade()
{

}

void Universidade::setNome(const char *nome_uni)
{
    strcpy(nome,nome_uni);
}

char* Universidade::getNome()
{
    return nome;
}

void Universidade::setDepart(Departamento depart)
{
    objDepartamento = depart;
}
        
Departamento Universidade::getDepart()
{
    return objDepartamento;
}