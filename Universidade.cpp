 #include "Universidade.hpp"
 
 
 Universidade::Universidade(const char *nome_uni)
 {
     strcpy(nome, nome_uni);
     for(int i = 0; i<50; i++) pDepartamento[i] = nullptr; 
     cont_dep = 0;
 }

 Universidade::Universidade()
 {
 }

Universidade::~Universidade()
{
    for(int i = 0; i<50; i++) pDepartamento[i] = nullptr; 
}

void Universidade::setNome(const char *nome_uni)
{
    strcpy(nome,nome_uni);
}

char* Universidade::getNome()
{
    return nome;
}

void Universidade::setDepart(Departamento* pDepart)
{
    pDepartamento[cont_dep]= pDepart;
    cont_dep++;
}
        
void Universidade::print_depart()
{
    int cont = 0;
    //Imprime departamento ate encontrar um ponteiro nulo
    for(Departamento* i = pDepartamento[cont]; i != nullptr; i = pDepartamento[++cont])
    {
        cout<<nome<<" departamento "<<i->getDepart()<<endl;
    }
}