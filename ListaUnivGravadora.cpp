#include "ListaUnivGravadora.hpp"
#include "Universidade.hpp"

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;
#include <string>
using std::string;

void gravar_stringUniv(ofstream* arq, const char* n)
{
    string nomeUni(n);

    int tamanhoS = nomeUni.size();

    arq->write((char*)&tamanhoS, sizeof(tamanhoS));
    arq->write((char*)&nomeUni[0], tamanhoS);
}

string recupera_stringUniv(ifstream* arq)
{
    string nomeU;
    int tamanhoS = 0;
    arq->read((char*)&tamanhoS, sizeof(tamanhoS));//recuperando o tamanho do nome da universidade

    nomeU.resize(tamanhoS);//redefinindo o tamanho da string para receber o nome da universidade
    arq->read((char*)&nomeU[0], tamanhoS);//recuperando o nome da universidade

    return nomeU;
}

ListaUnivGravadora::ListaUnivGravadora():
ListaUniversidades()
{
}
ListaUnivGravadora::~ListaUnivGravadora()
{
}

void ListaUnivGravadora::gravar_universidades(int tamanhoL)
{
    ofstream gravadoraUniv("arquivos/universidades.dat", ios::binary | ios::out); // abrindo arquivo
    if(!gravadoraUniv)//se nao conseguir abrir
    {
        std::cerr<<"Arquivo nao pode ser aberto!!"<<endl;
        getchar();
        return;
    }

    gravadoraUniv.write((char*)&tamanhoL, sizeof(tamanhoL)); // gravando o tamanho(numero de elementos) da lista

    iteradorLUniv = LTUniver.begin();
    Universidade* pU = nullptr;
    while(iteradorLUniv != LTUniver.end())
    {
        pU = *iteradorLUniv;

        gravar_stringUniv(&gravadoraUniv, pU->getNome());

        int i = pU->get_id();
        gravadoraUniv.write((char*)&i, sizeof(i));

        iteradorLUniv++;
    }
    gravadoraUniv.close();//fecha o arquivo

    cout<<"Lista de universidades gravada com sucesso!!"<<endl;
    getchar();

}

void ListaUnivGravadora::recuperar_universidades(int* contId)
{
    ifstream recuperaUniv("arquivos/universidades.dat", ios::binary | ios::in);//abrindo arquivo
    if(!recuperaUniv)//se nao conseguir abrir mostra menssagem de erro
    {
        std::cerr<<"Arquivo nao pode ser aberto!!"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    limpar_lista();

    
    string nomeUni;
    int idUni = 0;
    Universidade* pU = nullptr;

    int tamanhoL = 0;
    recuperaUniv.read((char*)&tamanhoL, sizeof(tamanhoL));//recupera o tamanho da lista

    for(int j = 0; j < tamanhoL ; j++)
    {
        nomeUni = recupera_stringUniv(&recuperaUniv);//recuperando nome da universidade
        recuperaUniv.read((char*)&idUni, sizeof(idUni));;//recuperando o id

        pU = new Universidade();
        pU->setNome(nomeUni.c_str());
        pU->set_id(idUni);

        inclui_univ(pU); // incluindo universidade na lista
    }
    (*contId) = tamanhoL;//atualizando o numero do id da lista principal

    recuperaUniv.close();//fechando arquivo

    cout<<"Lista de Universidades recuperada com sucesso!!"<<endl;
    getchar();

}