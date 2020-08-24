#include "ListaDisciplinas.hpp"
#include "Disciplina.hpp"

#include "string.h"
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;
#include <string>
using std::string;

void grava_stringDisc(const char* n, ofstream* arq)
{
    string nomeN(n); // nomeN recebe o nome  do elemento da lista
    int tamanho = nomeN.size(); // 'tamanho' recebe o tamnho da string

    arq->write((char*)&tamanho,sizeof(tamanho));//grava primeiro o tamnho da string
    arq->write((char*)&nomeN[0], tamanho);//depois grava a string
}

string recuperar_stringDisc(ifstream* arq)
{
    string nomeN;
    int tamanho = 0;

    arq->read((char*)&tamanho,sizeof(tamanho)); // recupera o tanho da string

    nomeN.resize(tamanho);// 'nomeDep' realoca o tamho para caber a string
    arq->read((char*)&nomeN[0],tamanho); // recupera a string
    
    return nomeN;
}

ListaDisciplinas::ListaDisciplinas(int nd, const char* n)
{
    strcpy(nome, n);
    pElDiscPrim = nullptr;
    pElDiscAtual = nullptr;
    numero_disciplinas = nd;
    cont = 0;
    id = 0;
}

ListaDisciplinas::~ListaDisciplinas()
{
    //Desaloca todos os elementos da lista(exclui a lista)
    limpa_lista();
}

void ListaDisciplinas::inclui_disciplina(Disciplina* pd)
{
    //verifica se o ponteiro  é valido e se nao atingiu o numero maximo de elementos na lista
    //"numero_disciplina === -1" server quando nao se quer especificar o numero maximo de disciplinas
    //-1 permite inserir um numero  infinito de disciplinas
    if( (pd != nullptr && cont < numero_disciplinas) || (pd != nullptr && numero_disciplinas == -1))
    {   
        //Cria um ponteiro e aloca dinamicamente um elemento Disciplina
        ElDisciplina* pAux = nullptr;
        pAux = new ElDisciplina();
        //agrega fracamente a Disciplina ao elemento disciplina
        pAux->set_disciplina(pd);

        //inclui elementos da diciplina na lista de disciplinas que esta agregada fracamente ao departamento
        //verifica se a lista esta vazia
        if(pElDiscPrim == nullptr)
        {
            //inclui o primeiro elemento da lista
            pElDiscPrim = pAux;
            pElDiscAtual = pAux;
        }
        else
        //se a lista nao estiver vazia
        {
            //inclui o elemento no final da lista
            pElDiscAtual->set_proxElDisc(pAux);
            pAux->set_antElDisc(pElDiscAtual);
            pElDiscAtual = pAux;
        }
         cont++; 
    }
    else
    {
        if(pd != nullptr)
        {
            cout<<"Departamento atingiu o numero maximo de Disciplinas!\nDisciplina NAO foi cadastrada"<<endl;
        }
        else
        {
            cout<<"Ponteiro para Disciplina é NULO!! Disciplina NAO foi cadastrada."<<endl;
        }
        
    }
    
}


void ListaDisciplinas::liste_disciplinas()
{
    ElDisciplina* pAux = pElDiscPrim;

    cout<<nome<<" lista de disciplinas:"<<endl;
    
    while(pAux != nullptr)
    {
        Disciplina* pDisc = pAux->get_disciplina();

        cout<<" - "<<pDisc->get_nome()<< endl;

        pAux = pAux->get_proxElDisc();
    }

}


void ListaDisciplinas::liste_disciplinas2()
{
    ElDisciplina* pAux = pElDiscAtual;

    cout<<nome<<" lista 2 de disciplinas:"<<endl;

    while(pAux)
    {
        Disciplina* pDisc = pAux->get_disciplina();

        cout<<" - "<<pDisc->get_nome()<< endl;

        pAux = pAux->get_antElDisc();
    }
}

void ListaDisciplinas::set_id(int i) { id = i; }
int ListaDisciplinas::get_id() { return id; }

void ListaDisciplinas::limpa_lista()
{
    //Desaloca todos os elementos da lista(exclui a lista)
    ElDisciplina* pAux = pElDiscPrim;

    while(pElDiscPrim != nullptr)
    {
        pElDiscPrim = pAux->get_proxElDisc();
        delete pAux;
        pAux = pElDiscPrim;
    }

    pElDiscAtual = nullptr;
}

void ListaDisciplinas::grava_disciplinas(int tamanhoL)
{
    ofstream gravador_disciplina("arquivos/disciplinas.dat", ios::binary | ios::out);// criando/abrindo arquivo
    if(!gravador_disciplina)//verifica se arquivo nao foi criado
    {
        std::cerr<<"Arquivo nao pode ser aberto/criado!"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    gravador_disciplina.write((char*)&tamanhoL, sizeof(tamanhoL));//gravando tamanho da lista

    ElDisciplina* pElD = pElDiscPrim;
    Disciplina* pD= nullptr;

    //percore lista de disciplina
    while(pElD != nullptr)
    {
        pD = pElD->get_disciplina();

        grava_stringDisc(pD->get_nome(), &gravador_disciplina);//gravando nome e tamanho do nome

        int i = pD->get_id();
        gravador_disciplina.write((char*)&i, sizeof(i));//gravando o id no arquivo

        pElD = pElD->get_proxElDisc();
    }
    gravador_disciplina.close();//fecha arquivo

    cout<<"Disciplinas gravada com sucesso!"<<endl;
    getchar();

}

void ListaDisciplinas::recupera_disciplinas (int* contId)
{
    ifstream recuperador_disc("arquivos/disciplinas.dat", ios::in);//abrindo arquivo
    if(!recuperador_disc)//se nao abrir
    {
        std::cerr<<"Aquivo nao pode ser aberto!"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    limpa_lista();

    int i = 0;
    string nomeDisc;
    Disciplina* pD = nullptr;
    *contId = 0;// zera o contador de ids de disciplina

    int tamanhoL = 0 ;
    recuperador_disc.read((char*)&tamanhoL, sizeof(tamanhoL));

    for(int j = 0; j < tamanhoL; j++ )
    {
        nomeDisc = recuperar_stringDisc(&recuperador_disc); // recupera o nome da disciplina
        recuperador_disc.read((char*)&i, sizeof(i)); // recupera o id da disciplina

        pD = new Disciplina();
        pD->set_id(i);
        pD->set_nome(nomeDisc.c_str());
        
        inclui_disciplina(pD); // inclui disciplina na lista atual
    }
    (*contId) = tamanhoL; // atualiza o contador de id de acordo com o tamanho da lista

    recuperador_disc.close();//fechando arquivo

    cout<<"Disciplinas recuperadas com sucesso!!"<<endl;
    getchar();
}