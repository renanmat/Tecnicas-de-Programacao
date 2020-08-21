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

void ListaDisciplinas::grava_disciplinas()
{
    ofstream gravador_disciplina("arquivos/disciplinas.dat", ios::out);// criando/abrindo arquivo
    if(!gravador_disciplina)//verifica se arquivo nao foi criado
    {
        std::cerr<<"Arquivo nao pode ser aberto/criado!"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    ElDisciplina* pElD = pElDiscPrim;
    Disciplina* pD= nullptr;

    //percore lista de disciplina
    while(pElD != nullptr)
    {
        pD = pElD->get_disciplina();

        gravador_disciplina << pD->get_id()<<" "<<pD->get_nome()<<endl;//grava informaçoes no arquivo

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
    char nomeDisc[150];
    Disciplina* pD = nullptr;
    *contId = 0;// zera o contador de ids de disciplina

    while(!recuperador_disc.eof())//equanto nao encontra o fim do arquivo
    {
        recuperador_disc>>i>>nomeDisc;// passando dados do arquivo para as variaveis
        if(0 != strcmp(nomeDisc,""))// se nomeDisc nao estiver vazio
        {
            pD = new Disciplina();
            pD->set_id(i);
            pD->set_nome(nomeDisc);

            inclui_disciplina(pD);

            (*contId)++;// a cada disciplina no arquivo o contador aumenta 1
        }
        strcpy(nomeDisc,"");// nomeDisc recebe uma string vazia(zerando o nomeDisc)
    }
    recuperador_disc.close();//fechando arquivo

    cout<<"Disciplinas recuperadas com sucesso!!"<<endl;
    getchar();
}