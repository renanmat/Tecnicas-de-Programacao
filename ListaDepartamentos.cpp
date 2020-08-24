#include "ListaDepartamentos.hpp"

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;
#include <string>
using std::string;

void grava_stringDep(const char* n, ofstream* arq)
{
    string nomeN(n); // nomeN recebe o nome  do elemento da lista
    int tamanho = nomeN.size(); // 'tamanho' recebe o tamnho da string

    arq->write((char*)&tamanho,sizeof(tamanho));//grava primeiro o tamnho da string
    arq->write((char*)&nomeN[0], tamanho);//depois grava a string
}

string recuperar_stringDep(ifstream* arq)
{
    string nomeN;
    int tamanho = 0;

    arq->read((char*)&tamanho,sizeof(tamanho)); // recupera o tanho da string

    nomeN.resize(tamanho);// 'nomeDep' realoca o tamho para caber a string
    arq->read((char*)&nomeN[0],tamanho); // recupera a string
    
    return nomeN;
}

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

void ListaDepartamentos::grava_departamentos(int tamanhoList)
{
    ofstream gravador_depart("arquivos/departamentos.dat", ios::binary | ios::out); //criando arquivo
    if(!gravador_depart)// verificando se o arquivo foi criado
    {
        std::cerr<<"Erro! arquivo nao pode ser criado!"<<endl;
        getchar();
        return;
    }

    gravador_depart.write((char*)&tamanhoList, sizeof(tamanhoList));//gravando a quantidade de itens da lista

    ElDepartamento* pElD = pElDepPrim;
    Departamento* pD = nullptr;
    // passa pelos elementos da lista 
    while(pElD != nullptr) 
    {
        pD = pElD->get_depart();
        
        grava_stringDep(pD->getNome(), &gravador_depart); //grava a string e o tamanho da string

        int i = pD->get_id();
        gravador_depart.write((char*)&i, sizeof(i)); // gravar o id

        pElD = pElD->get_prox();
    }
    gravador_depart.close(); // fechando arquivo
    cout<<"Departamentos gravados com Sucesso!!";
    getchar();

}
void ListaDepartamentos::recuperar_departamentos(int* c)
{

    ifstream recuperador_depart("arquivos/departamentos.dat", ios::binary | ios::in);//abre o arquivo tipo binario
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
    string nomeDepart;
    Departamento* pD = nullptr;

    int tamanhoL = 0;
    recuperador_depart.read((char*)&tamanhoL,sizeof(tamanhoL));//recuperando a quantidade de itens da lista

    for(int j = 0; j < tamanhoL; j++)
    {
        nomeDepart = recuperar_stringDep(&recuperador_depart);//recuperando o nome do arquivo
        recuperador_depart.read((char*)&i, sizeof(i));//recuperando o id do arquivo

        pD = new Departamento();
        pD->set_id(i);
        pD->setNome(nomeDepart.c_str());

        inclui_depart(pD);
    }
    (*c) = tamanhoL; // passando o tamanho da lista para o contador de ids de departamento

    recuperador_depart.close();//fecha o arquivo

    cout<<"Departamentos recuperados com sucesso!"<<endl;
    getchar();
}
