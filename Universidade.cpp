 #include "Universidade.hpp"
 
 
 Universidade::Universidade(const char *nome_uni)
 {
     strcpy(nome, nome_uni);
     pDepartamento = nullptr;
     //for(int i = 0; i<50; i++) pDepartamento[i] = nullptr; 
     cont_dep = 0;
 }

 Universidade::Universidade()
 {
      pDepartamento = nullptr;
     //for(int i = 0; i<50; i++) pDepartamento[i] = nullptr; 
     cont_dep = 0;
 }

Universidade::~Universidade()
{
    free(pDepartamento);
    pDepartamento = nullptr;
}

void Universidade::setNome(const char *nome_uni)
{
    strcpy(nome,nome_uni);
}

char* Universidade::getNome()
{
    return nome;
}

void Universidade::set_quant_depart(int quant)
{

    pDepartamento = (Departamento **) calloc(quant, sizeof(Departamento*));
    if(!pDepartamento) 
    {
        cout<<"Memoria indisponivel"<<endl;
        exit(1);
    }

}

void Universidade::setDepart(Departamento* pDepart)
{
    if(pDepart != NULL)
    {
        pDepartamento[cont_dep]= pDepart;
        cont_dep++;
    }else
    {
        cout<<"Departamento nao adicionado a universidade, ";
        cout<<"pois departamento é invalido(ponteiro para departamento é nulo)"<<endl;
    }
    
    
}
        
void Universidade::print_depart()
{
    
    for(int i = 0; i < cont_dep; i++)
    {
        cout<<nome<<" departamento "<<pDepartamento[i]->getNome()<<endl;
    }

}