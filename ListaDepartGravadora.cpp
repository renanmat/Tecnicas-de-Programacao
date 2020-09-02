#include "ListaDepartGravadora.hpp"

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;
#include <string>
using std::string;


void gravar_stringDep(ofstream* arq, string n)
{
    int tamanho = n.size(); // pega o tamanho do nome

    arq->write((char*)&tamanho,sizeof(tamanho));// grava o tamanho do nome
    arq->write((char*)&n[0], tamanho);//grava o nome
}

string recupera_stringDep(ifstream* arq)
{
    string nomeD;
    int tamanhoS = 0;

    arq->read((char*)&tamanhoS,sizeof(tamanhoS));//recupera o tamanho do nome

    nomeD.resize(tamanhoS);//realoca a variavel para caber o nome
    arq->read((char*)&nomeD[0],tamanhoS);//recupera o nome

    return nomeD;
}

ListaDepartGravadora::ListaDepartGravadora(int nd):
ListaDepartamentos(nd)
{    
}
ListaDepartGravadora::~ListaDepartGravadora()
{
}

void ListaDepartGravadora::grava_departamentos(int tamanhoList)
{
    ofstream gravadorDep("arquivos/departamentos.dat", ios::binary | ios::out);//abrindo arquivo
    if(!gravadorDep)//se nao conseguir abrir retorna uma menssagem de erro
    {
        std::cerr<<"Arquivo nao pode ser aberto!!"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    gravadorDep.write((char*)&tamanhoList,sizeof(tamanhoList));//gravando a quantidade de itens da lista

    Elemento<Departamento>* pAux = LTDepart.get_primeiro();
    Departamento* pD = nullptr;
    int idDep = 0;
    while(pAux != nullptr)
    {
        pD = pAux->get_info();
        
        string nomeDep(pD->getNome()); 
        gravar_stringDep(&gravadorDep, nomeDep);//grava o nome do departamento

        idDep = pD->get_id();
        gravadorDep.write((char*)&idDep, sizeof(idDep));//grava o id do departamento

        pAux = pAux->get_prox();
    }
    gravadorDep.close(); // fecha o arquivo

    cout<<"Lista de departamentos gravado com sucesso!!"<<endl;
    getchar();
}

void ListaDepartGravadora::recuperar_departamentos(int* cont)
{
    ifstream recuperaDep("arquivos/departamentos.dat", ios::binary | ios::in);//tenta abrir o arquivo
    if(!recuperaDep)//se nao conseguir abrir o aquivo retorna uma menssagem de erro
    {
        std::cerr<<"Arquivo nao pode ser aberto!!"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    limpar_lista();

    int tamanhoL = 0;
    recuperaDep.read((char*)&tamanhoL,sizeof(tamanhoL));//recupera a quantidade de itens da lista

    string nomeDep;
    int idDep = 0;
    Departamento* pD = nullptr;

    for(int j; j < tamanhoL; j++)
    {
        nomeDep = recupera_stringDep(&recuperaDep); // recupera o nome do departamento
        recuperaDep.read((char*)&idDep, sizeof(idDep));//recupera o id

        pD = new Departamento();
        pD->set_id(idDep);
        pD->setNome(nomeDep.c_str());

        inclua_depart(pD); // incluindo o departamento na lista
    }
    (*cont) = tamanhoL;// o Contador de ids de departamentos é atualizado
    recuperaDep.close();//fecha o arquivo

    cout<<"Lista de departamentos recuperada com sucesso!!"<<endl;
    getchar();
}