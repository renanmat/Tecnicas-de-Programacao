#include "ListaUniversidades.hpp"
#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;
#include <string>
using std::string;

void grava_string(const char* n, ofstream* arq)
{
    string nomeU(n);
    int tamanho = nomeU.size();

    arq->write((char*)&tamanho, sizeof(tamanho));
    arq->write((char*)&nomeU[0],tamanho);
}

string recuperar_string(ifstream* arq)
{
    string nomeU;
    int tamanho = 0;

    arq->read((char*)&tamanho, sizeof(tamanho));
    nomeU.resize(tamanho);

    arq->read((char*)&nomeU[0], tamanho);

    return nomeU;
}

ListaUniversidades::ListaUniversidades()
{
    pElUnivPrim = nullptr;
    pElUnivAtual = nullptr;
    id = 0;
}
ListaUniversidades::~ListaUniversidades()
{
    limpa_lista();
}

void ListaUniversidades::inclui_univ(Universidade* pu)
{
    if(pu != nullptr)
    {
        ElUniversidade* pAux = new ElUniversidade();
        pAux->set_univ(pu);

        if(pElUnivPrim == nullptr)
        {
            pElUnivPrim = pAux;
            pElUnivAtual = pAux;
        }
        else
        {
            pElUnivAtual->set_prox(pAux);
            pAux->set_ant(pElUnivAtual);
            pElUnivAtual = pAux;
        }
        
    }
    else
    {
        cout<<"Ponteiro de universidade é NULO!\nUniversidade NAO foi cadastrada!"<<endl;
    }
    
}

void ListaUniversidades::liste_univ()
{
    ElUniversidade* pAux = pElUnivPrim;

    cout<<"Lista de Universidades:"<<endl;
    while(pAux)
    {
        cout<<"- "<<pAux->get_nomeUniv()<<endl;
        pAux = pAux->get_prox();
    }
}

void ListaUniversidades::liste_univ2()
{
    ElUniversidade* pAux = pElUnivAtual;

    cout<<"Lista de Universidades:"<<endl;
    while(pAux)
    {
        cout<<"- "<<pAux->get_nomeUniv()<<endl;
        pAux = pAux->get_ant();
    }
}


Universidade* ListaUniversidades::localiza_universidade(const char* nUniv)
{
    ElUniversidade* pAux = pElUnivPrim;
    while(pAux)
    {
        if( 0 == strcmp(nUniv, pAux->get_nomeUniv() ) )
        {
            return pAux->get_univ();
        }

        pAux = pAux->get_prox();
    }
    
    return nullptr;
}

void ListaUniversidades::set_id(int i) { id = i; }
int ListaUniversidades::get_id() { return id; }

void ListaUniversidades::limpa_lista()
{
    //desaloca(deleta) elementos da lista
    ElUniversidade* pAux = pElUnivPrim;
    while(pElUnivPrim != nullptr)
    {
        pElUnivPrim = pAux->get_prox();
        delete pAux;
        pAux = pElUnivPrim;
    }

    pElUnivAtual = nullptr;
}

void ListaUniversidades::gravar_universidades(int tamList)
{
    //criando arquivo com a class  orientada a fluxo 'fstream' 
    ofstream gravarUniver("arquivos/universidades.dat", ios::binary | ios::out);
    if(!gravarUniver)//caso nao coseguil criar o arquivo
    {
        std::cerr<<"Arquivo nao pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    gravarUniver.write((char*)&tamList, sizeof(tamList));
    //passando por todos os elementos da lista
    ElUniversidade* pElU = pElUnivPrim;
    Universidade* pU;
    int i = 0;
    while(pElU != nullptr)
    {
        pU = pElU->get_univ();

        grava_string(pU->getNome(), &gravarUniver);
        
        i = pU->get_id();

        gravarUniver.write((char*)&i, sizeof(i)); 

        pElU = pElU->get_prox();
    }

    gravarUniver.close(); // fecha arquivo
    cout<<"Universidades gravadas com sucesso!"<<endl;
    getchar();
}

void ListaUniversidades::recuperar_universidades(int* cont)
{
    ifstream recuperaUniver("arquivos/universidades.dat", ios::binary | ios::in); // abre arquivo
    if(!recuperaUniver)// caso o aquivo nao foi aberto
    {
        std::cerr<<"Nao foi possivel abrir arquivo!"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    limpa_lista();//limpado a lista para nao ter elementos duplicados
    *cont = 0;

   
    
    Universidade* pU = nullptr;
    string nomeUni;
    int id = 0;

    int tamanho_lista = 0;
    recuperaUniver.read((char*)&tamanho_lista, sizeof(tamanho_lista));

    for(int j = 0; j < tamanho_lista; j++)
    {
        pU = new Universidade();
        nomeUni = recuperar_string(&recuperaUniver);
        recuperaUniver.read((char*)&id,sizeof(id));

        pU->set_id(id);
        pU->setNome(nomeUni.c_str());

        inclui_univ(pU);

    }     
    (*cont) = tamanho_lista;
        
    recuperaUniver.close(); //fecha o arquivo

    cout<<"Universidades recuperadas com sucesso!"<<endl;
    getchar();
}