#include "ListaProfessores.hpp"

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;

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

void ListaProfessores::gravar_professores()
{
    ofstream gravador_prof("arquivos/professores.dat", ios::out);//abrindo arquivo
    if(!gravador_prof)//se nao coseguil abrir arquivo retorna uma menssagem de erro
    {
        std::cerr<<"Aquivo nao pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    Professor* pP = nullptr;
    ElProfessor* pEl = pElProfPrim;
    //percore a lista de professores
    while(pEl != nullptr)
    {
        pP = pEl->get_professor();

        gravador_prof<<pP->get_id()<<" "<<pP->get_nome()<<endl; // grava dados no arquivo

        pEl = pEl->get_prox();
    }
    gravador_prof.close(); //fecha arquivo

    cout<<"Professores gravados com sucesso!!"<<endl;
    getchar();

}

void ListaProfessores::recuperar_professores(int* contId)
{
    ifstream recuperador_prof("arquivos/professores.dat", ios::in);//abre o arquivo
    if(!recuperador_prof)// se nao conseguil abrir arquivo retorna uma menssagem de erro
    {
        std::cerr<<"Arquivo nao pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    limpar_lista(); // zera a lista para nao ter duplicatas de professores

    Professor* pP = nullptr;
    int i = 0;
    char nomeP[150];
    *contId = 0; // zera o contador de ids de professores

    while(!recuperador_prof.eof())// enquanto nao chega no fim do arquivo
    {
        recuperador_prof>>i>>nomeP; // passa os dados do arquivo para as variaveis

        if(0 != strcmp(nomeP, ""))//verifica se a variavel 'nomeP' nao esta vazia
        {
            pP = new Professor(i); // cria e isere o id em professore
            pP->set_nome(nomeP);

            inclui_professor(pP); //inclui professor na lista

            (*contId)++;// atualiza o contador de ids
        }
        strcpy(nomeP, ""); //esvazia a varivel 'nomeP'

    }
    recuperador_prof.close();//fecha arquivo

    cout<<"Professores recuperados com sucesso!"<<endl;
    getchar();
}