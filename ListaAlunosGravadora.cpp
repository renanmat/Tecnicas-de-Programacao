#include "ListaAlunosGravadora.hpp"

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;
#include <string>
using std::string;

void grava_stringAluno(const char* n, ofstream* arq)
{
    string nomeN(n); // nomeN recebe o nome  do elemento da lista
    int tamanho = nomeN.size(); // 'tamanho' recebe o tamanho da string

    arq->write((char*)&tamanho,sizeof(tamanho));//grava primeiro o tamasnho da string
    arq->write((char*)&nomeN[0], tamanho);//depois grava a string
}

string recuperar_stringAluno(ifstream* arq)
{
    string nomeN;
    int tamanho = 0;

    arq->read((char*)&tamanho,sizeof(tamanho)); // recupera o tanho da string

    nomeN.resize(tamanho);// 'nomeDep' realoca o tamho para caber a string
    arq->read((char*)&nomeN[0],tamanho); // recupera a string
    
    return nomeN;
}

ListaAlunosGravadora::ListaAlunosGravadora(int nA):
ListaAlunos(nA)
{
}
ListaAlunosGravadora::~ListaAlunosGravadora()
{
}

void ListaAlunosGravadora::gravar_alunos(int tamanhoL)
{
    ofstream gravadorAluno("arquivos/alunos.dat", ios::binary | ios::out);//abrindo/criando arquivo
    if(!gravadorAluno)//se nao abriu/criou o aquivo da uma menssagem de erro
    {
        std::cerr<<"Aquivo nao pode ser aberto!!"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    gravadorAluno.write((char*)&tamanhoL, sizeof(tamanhoL));//gravando o tamanho da lista

    Lista<Aluno>::Elemento* pElA = LTAlunos.get_primeiro();
    Aluno* pA = nullptr;
    //percore a lista
    while(pElA != nullptr)
    {
        pA = pElA->get_info();
        
        grava_stringAluno(pA->get_nome(), &gravadorAluno); // gravando o nome e o tamanho do nome

        int i = pA->get_id();
        gravadorAluno.write((char*)&i, sizeof(i));//gravando o id do aluno

        pElA = pElA->get_prox();
    }
    gravadorAluno.close();//fechado arquivo

    cout<<"Lista de alunos gravada com sucesso!!"<<endl;
    getchar();
}

void ListaAlunosGravadora::recuperar_alunos(int* contId)
{
    ifstream recuperador_alunos("arquivos/alunos.dat", ios::binary | ios::in);//abre o aquivo
    if(!recuperador_alunos)//se nao abriu da uma mensagem de erro
    {
        std::cerr<<"Arquivo nao pode ser aberto!"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    limpar_lista();//limpa a lista para nao aver duplicatas de alunos

    int tamanhoL = 0;
    recuperador_alunos.read((char*)&tamanhoL, sizeof(tamanhoL));

    *contId = tamanhoL; // contador de ids é atualizado de acordo com o tamanho de elementos do arquivo

    string nomeAl;
    int i = 0;
    Aluno* pA = nullptr;

    for(int j = 0; j < tamanhoL; j++)
    {
        nomeAl = recuperar_stringAluno(&recuperador_alunos);//recupera o nome do aluno
        recuperador_alunos.read((char*)&i, sizeof(i));//recupera o id do aluno

        pA = new Aluno();
        pA->set_id(i);
        pA->set_nome(nomeAl.c_str());

        inclua_aluno(pA); // inclui aluno na lista principal
    }
    recuperador_alunos.close();//fecha o aquivo

    cout<<"Lista de alunos recuperada com sucesso!!"<<endl;
    getchar();
}