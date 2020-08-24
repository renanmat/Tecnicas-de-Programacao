#include "ListaProfessores.hpp"

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;
#include <string>
using std::string;

void grava_stringProf(const char* n, ofstream* arq)
{
    string nomeN(n); // nomeN recebe o nome  do elemento da lista
    int tamanho = nomeN.size(); // 'tamanho' recebe o tamanho da string

    arq->write((char*)&tamanho,sizeof(tamanho));//grava primeiro o tamasnho da string
    arq->write((char*)&nomeN[0], tamanho);//depois grava a string
}

string recuperar_stringProf(ifstream* arq)
{
    string nomeN;
    int tamanho = 0;

    arq->read((char*)&tamanho,sizeof(tamanho)); // recupera o tanho da string

    nomeN.resize(tamanho);// 'nomeDep' realoca o tamho para caber a string
    arq->read((char*)&nomeN[0],tamanho); // recupera a string
    
    return nomeN;
}

ListaProfessores::ListaProfessores(const char* n)
{
    strcpy(nome, n);
    pElProfPrim = nullptr;
    pElProfAtual = nullptr;
}
ListaProfessores::~ListaProfessores()
{
    limpar_lista();
}

void ListaProfessores::inclui_professor(Professor* p)
{
    if(p != nullptr) 
    {
        ElProfessor* pEl = new ElProfessor(p);

        if(pElProfPrim == nullptr) // se a lista estiver vazia
        {
            pElProfPrim = pEl;
            pElProfAtual = pEl;
        }
        else
        {
            pElProfAtual->set_prox(pEl);//o elemento atual aponta para o novo elemento
            pEl->set_ant(pElProfAtual);// o novo elemento aponta para o elemento atual
            pElProfAtual = pEl;// o elemento atual é atulizado
        } 
    }
    else
    {
        cout<<"Ponteiro para professor é nulo!!"<<endl;
        getchar();
    }
    
}

void ListaProfessores::liste_professores()
{
    ElProfessor* pAux = pElProfPrim;

    cout<<nome<<" Lista de Professores:"<<endl;

    while(pAux != nullptr)
    {
        cout<<" - "<<pAux->get_nomeProf()<<endl;

        pAux = pAux->get_prox();
    }
}
void ListaProfessores::liste_professores2()
{
    ElProfessor* pAux = pElProfAtual;

    cout<<nome<<" Lista de Professores:"<<endl;

    while(pAux != nullptr)
    {
        cout<<" - "<<pAux->get_nomeProf()<<endl;

        pAux = pAux->get_ant();
    }
}

void ListaProfessores::limpar_lista()
{
    ElProfessor* pAux = pElProfPrim;
    while(pElProfPrim != nullptr)
    {
        pElProfPrim = pAux->get_prox();
        delete pAux;
        pAux = pElProfPrim;
    }

    pElProfAtual = nullptr;
}

void ListaProfessores::gravar_professores(int tamanhoL)
{
    ofstream gravador_prof("arquivos/professores.dat", ios::binary | ios::out);//abrindo arquivo
    if(!gravador_prof)//se nao coseguil abrir arquivo retorna uma menssagem de erro
    {
        std::cerr<<"Aquivo nao pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    gravador_prof.write((char*)&tamanhoL, sizeof(tamanhoL));// gravando o tamanho da lista

    Professor* pP = nullptr;
    ElProfessor* pEl = pElProfPrim;
    //percore a lista de professores
    while(pEl != nullptr)
    {
        pP = pEl->get_professor();

        grava_stringProf(pP->get_nome(), &gravador_prof); // grava o nome do professor
        int i = pP->get_id();
        gravador_prof.write((char*)&i, sizeof(i)); // grava o id do professor
        
        pEl = pEl->get_prox();
    }
    gravador_prof.close(); //fecha arquivo

    cout<<"Professores gravados com sucesso!!"<<endl;
    getchar();

}

void ListaProfessores::recuperar_professores(int* contId)
{
    ifstream recuperador_prof("arquivos/professores.dat", ios::binary | ios::in);//abre o arquivo
    if(!recuperador_prof)// se nao conseguil abrir arquivo retorna uma menssagem de erro
    {
        std::cerr<<"Arquivo nao pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    limpar_lista(); // zera a lista para nao ter duplicatas de professores

    int tamanhoL = 0;
    recuperador_prof.read((char*)&tamanhoL, sizeof(tamanhoL));//recupera o tamanho da lista

    *contId = tamanhoL; // atualiza o contador de ids de acordo com o tamanho da lista

    Professor* pP = nullptr;
    int i = 0;
    string nomeP;
    
    for(int j = 0; j < tamanhoL; j++)
    {
        nomeP = recuperar_stringProf(&recuperador_prof);//recupera o nome do professor
        recuperador_prof.read((char*)&i, sizeof(i));// recupera id do professor

        pP = new Professor();
        pP->set_id(i);
        pP->set_nome(nomeP.c_str());

        inclui_professor(pP);

    }
    recuperador_prof.close();//fecha arquivo

    cout<<"Professores recuperados com sucesso!"<<endl;
    getchar();
}