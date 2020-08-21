#include "ListaDepartamentos.hpp"

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;

ListaDepartamentos::ListaDepartamentos(int nd, const char* n)
{
    strcpy(nome, n);
    pElDepPrim = nullptr;
    pElDepAtual = nullptr;
    numero_depart = nd;
    cont = 0;
    id = 0;
}

ListaDepartamentos::~ListaDepartamentos()
{
    limpa_lista();
    cont = 0;
    numero_depart = 0;
}

void ListaDepartamentos::set_nome(const char* n)
{
    strcpy(nome,n);
}

void ListaDepartamentos::inclui_depart(Departamento* pd)
{
    if( (pd != nullptr && cont < numero_depart) || (pd != nullptr && numero_depart == -1) ) 
    {
        ElDepartamento* pAux = new ElDepartamento();
        pAux->set_depart(pd);

        if(pElDepPrim == nullptr)
        {
            pElDepPrim = pAux;
            pElDepAtual = pAux;
        }
        else
        {
            pElDepAtual->set_prox(pAux);
            pAux->set_ant(pElDepAtual);
            pElDepAtual = pAux;
        }
        cont++;
    }
    else
    {
        if (pd != nullptr)
        {
            cout<<"Numero maximo de departamentos atingido!\nDepartamento NAO foi cadastrado!"<<endl;
        }
        else
        {
            cout<<"Ponteiro para departamento é nulo!\nDepartamento NAO foi cadastrado"<<endl;
        }     
    }  
}

void ListaDepartamentos::liste_depart()
{
    cout<<nome<<" lista de departamentos:"<<endl;

    ElDepartamento* pAux = pElDepPrim;
    while(pAux)
    {
        cout<<" - "<< pAux->get_nomeDepart()<<endl;

        pAux = pAux->get_prox();
    }
}

void ListaDepartamentos::liste_depart2()
{
    cout<<"Universidade "<<nome<<" - lista 2 de departamentos:"<<endl;

    ElDepartamento* pAux = pElDepAtual;
    while(pAux)
    {
        cout<<" - "<< pAux->get_nomeDepart()<<endl;

        pAux = pAux->get_ant();
    }
}

Departamento* ListaDepartamentos::localiza_depart(const char* n)
{
    ElDepartamento* pAux = pElDepPrim;
    while(pAux)
    {
        if(0 == strcmp(n, pAux->get_nomeDepart()) )
        {
            return pAux->get_depart();
        }
        pAux = pAux->get_prox();
    }
    return nullptr;
}

void ListaDepartamentos::set_id(int i) { id = i; }
int ListaDepartamentos::get_id() { return id; }

void ListaDepartamentos::limpa_lista() // desaloca os elementos da lista
{
    ElDepartamento* pAux = pElDepPrim;
    while(pElDepPrim != nullptr)
    {
        pElDepPrim = pAux->get_prox();
        delete pAux;
        pAux = pElDepPrim;
    }

    pElDepAtual = nullptr;
}

void ListaDepartamentos::grava_departamentos()
{
    ofstream gravador_depart("arquivos/departamentos.dat", ios::out); //criando arquivo
    if(!gravador_depart)// verificando se o arquivo foi criado
    {
        std::cerr<<"Erro! arquivo nao pode ser criado!"<<endl;
        getchar();
        return;
    }

    ElDepartamento* pElD = pElDepPrim;
    Departamento* pD = nullptr;
    // passa pelos elementos da lista 
    while(pElD != nullptr) 
    {
        pD = pElD->get_depart();
        gravador_depart << pD->get_id()<<" "<<pD->getNome()<<endl; // gravando informaçoes no arquivo

        pElD = pElD->get_prox();
    }
    gravador_depart.close(); // fechando arquivo
    cout<<"Departamentos gravados com Sucesso!!";
    getchar();

}
void ListaDepartamentos::recuperar_departamentos(int* c)
{

    ifstream recuperador_depart("arquivos/departamentos.dat", ios::in);//abre o arquivo
    if(!recuperador_depart)//verifica se foi aberto
    {
        std::cerr<<"Arquivo nao pode ser aberto!"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    limpa_lista();
    *c = 0; //zerando o contador de  ids de departamentos

    int i = 0;// id
    char nomeDepart[150];
    Departamento* pD = nullptr;

    while(!recuperador_depart.eof())//enquanto nao chega no fim do arquivo
    {
        
        recuperador_depart>>i>>nomeDepart; //passa os dados do arquivo para as variaveis

        if(0 != strcmp(nomeDepart,"")) // verifica se a variavel nao esta vazia
        {
            pD = new Departamento();
            pD->set_id(i);
            pD->setNome(nomeDepart);

            inclui_depart(pD);
            (*c)++;
        }
        strcpy(nomeDepart, "");
    }
    recuperador_depart.close();//fecha o arquivo

    cout<<"Departamentos recuperados com sucesso!"<<endl;
    getchar();
}