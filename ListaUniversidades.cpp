#include "ListaUniversidades.hpp"
#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;

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

void ListaUniversidades::gravar_universidades()
{
    //criando arquivo com a class  orientada a fluxo 'fstream' 
    ofstream gravarUniver("arquivos/universidades.dat", ios::out);
    if(!gravarUniver)//caso nao coseguil criar o arquivo
    {
        std::cerr<<"Arquivo nao pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    //passando por todos os elementos da lista
    ElUniversidade* pElU = pElUnivPrim;
    Universidade* pU;
    while(pElU != nullptr)
    {
        pU = pElU->get_univ();
        // '<<' paramentro de fluxo para gravar em arquivo
        gravarUniver << pU->get_id()<<" "<< pU->getNome()<<endl;
        pElU = pElU->get_prox();
    }

    gravarUniver.close(); // fecha arquivo
    cout<<"Universidades gravadas com sucesso!"<<endl;
    getchar();
}

void ListaUniversidades::recuperar_universidades(int* cont)
{
    ifstream recuperaUniver("arquivos/universidades.dat", ios::in); // abre arquivo
    if(!recuperaUniver)// caso o aquivo nao foi aberto
    {
        std::cerr<<"Nao foi possivel abrir arquivo!"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    limpa_lista();//limpado a lista para nao ter elementos duplicados
    *cont = 0;

    while(!recuperaUniver.eof())//enquanto nao chegar o fim do arquivo
    {
        Universidade* pU = nullptr;
        char nomeUn[150];
        int id = 0;

        recuperaUniver >>id>>nomeUn;//'nome' recebe oque esta no arquivo
        
        if(0 != strcmp(nomeUn,""))//verifica se nome nao esta vazio
        {
            pU = new Universidade();
            pU->set_id(id);
            pU->setNome(nomeUn);

            inclui_univ(pU);
            (*cont)++;
        }
        strcpy(nomeUn,"");

    }
    recuperaUniver.close(); //fecha o arquivo

    cout<<"Universidades recuperadas com sucesso!"<<endl;
    getchar();
}