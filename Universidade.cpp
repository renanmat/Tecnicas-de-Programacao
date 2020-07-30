 #include "Universidade.hpp"
 
 
 Universidade::Universidade(const char *nome_uni)
 {
     strcpy(nome, nome_uni);
 }

 Universidade::Universidade()
 {

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


void Universidade::setDepart(Departamento* pDepart)
{
    if(pDepart != NULL)
    {
       lpDepart.push_back(pDepart);
    }else
    {
        cout<<"Departamento nao adicionado a universidade, ";
        cout<<"pois departamento é invalido(ponteiro para departamento é nulo)"<<endl;
    }
    
    
}
        
void Universidade::print_depart()
{
    //print usando <vector>
    /*int tam = (int)lpDepart.size();
    for(int i = 0; i < tam; i++)
    {
        cout<<nome<<" departamento "<<lpDepart[i]->getNome()<<endl;
    }*/

    //print usando <list>
    list<Departamento*>::iterator iterador;

    cout<<"Universidade "<<nome<<" departamento(s):"<<endl;

    for(iterador = lpDepart.begin(); iterador != lpDepart.end(); iterador++)
    {
        cout<<" - "<<(*iterador)->getNome()<<endl;
    }

}