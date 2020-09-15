#include "ListaDisciplinasGravadora.hpp"
#include "Disciplina.hpp"

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

ListaDisciplinasGravadora::ListaDisciplinasGravadora(int nD):
ListaDisciplinas(nD)
{
}
ListaDisciplinasGravadora::~ListaDisciplinasGravadora()
{ 
}

void ListaDisciplinasGravadora::grava_disciplinas(int tamanhoL)
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

    Lista<Disciplina>::Elemento* pElD = LTDisciplinas.get_primeiro();
    Disciplina* pD= nullptr;

    //percore lista de disciplina
    while(pElD != nullptr)
    {
        pD = pElD->get_info();

        grava_stringDisc(pD->get_nome(), &gravador_disciplina);//gravando nome e tamanho do nome

        int i = pD->get_id();
        gravador_disciplina.write((char*)&i, sizeof(i));//gravando o id no arquivo

        pElD = pElD->get_prox();
    }
    gravador_disciplina.close();//fecha arquivo

    cout<<"Lista de disciplinas gravada com sucesso!!"<<endl;
    getchar();

}
void ListaDisciplinasGravadora::recupera_disciplinas(int* contId)
{
    ifstream recuperador_disc("arquivos/disciplinas.dat", ios::in);//abrindo arquivo
    if(!recuperador_disc)//se nao abrir
    {
        std::cerr<<"Aquivo nao pode ser aberto!"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    limpar_lista();

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
        
        inclua_disciplina(pD); // inclui disciplina na lista atual
    }
    (*contId) = tamanhoL; // atualiza o contador de id de acordo com o tamanho da lista

    recuperador_disc.close();//fechando arquivo

    cout<<"Lista de disciplinas recuperada com sucesso!!"<<endl;
    getchar();

}