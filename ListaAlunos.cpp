#include "ListaAlunos.hpp"

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;


ListaAlunos::ListaAlunos(int quatAl, const char* n)
{ 
    cont_alunos = 0;
    num_alunos = quatAl;
    strcpy(nome, n);
    pElAlunoPrim = nullptr;
    pElAlunoAtual = nullptr;
    id = 0;
}
ListaAlunos::~ListaAlunos()
{
    //deleta elementos da lista encadiada
    limpa_lista();

    cont_alunos = 0;
}

void ListaAlunos::set_nome(const char* n){ strcpy(nome, n); }


void ListaAlunos::inclui_aluno(Aluno* pa)
{
    //verifica se o ponteiro pa de aluno é nulo e verifica se qunatidade de alunos ainda é menor que 45  
    if((pa != nullptr && cont_alunos < num_alunos) || (pa != nullptr && num_alunos == -1) )
    {
        //Cria ponteiro tipo ElAluno
        ElAluno* pAux;
        //Aloca dinamicamente com o operador NEW
        pAux = new ElAluno();
        //seta o aluno em elemento aluno.
        pAux->set_aluno(pa);

        if(pElAlunoPrim == nullptr)
        {
            pElAlunoPrim = pAux;
            pElAlunoAtual = pAux;
        }
        else
        {
            pElAlunoAtual->set_prox(pAux);
            pAux->set_ant(pElAlunoAtual);
            pElAlunoAtual = pAux;
        } 
           
        cont_alunos++;
    }
    else
    {
        if(pa != nullptr)
        {
            cout<<"Numero maximo de alunos atingido."<<endl;
        }
        else
        {
            cout<<"ponteiro para aluno eh NULL."<<endl;
        }
        
        
    }
    
}


void ListaAlunos::liste_alunos()
{
    //pAux recebe o primeiro elemento da lista
    ElAluno* pAux = pElAlunoPrim;

    cout<<nome<<" lista de Alunos:"<<endl;

    //verifica se nao é nulo
    while(pAux)
    {
        // pAluno recebe o ponteiro para aluno
        Aluno* pAluno = pAux->get_aluno();
        //mostra nome do aluno
        cout<<" - "<<pAluno->get_nome()<<endl;
        //pAux recebe o proximo elemento da lista
        pAux = pAux->get_prox();
    }
}

void ListaAlunos::liste_alunos2()
{
    //pAux recebe o ultimo elemento da lista
     ElAluno* pAux = pElAlunoAtual;

    cout<<nome<<" lista 2 de Alunos:"<<endl;
    //verifica se nao é nulo
    while(pAux)
    {
        // pAluno recebe o ponteiro para aluno
        Aluno* pAluno = pAux->get_aluno();
        //mostra nome do aluno
        cout<<" - "<<pAluno->get_nome()<<endl;
        //pAux recebe o elemento anterior da lista
        pAux = pAux->get_ant();
    }
}

ElAluno* ListaAlunos::get_alunoList(int ra)
{
    ElAluno* pAux = pElAlunoPrim;
    while(pAux)
    {
        Aluno* pAluno = pAux->get_aluno();

        if(pAluno->get_ra() == ra)
        {
            return pAux;
        }

        pAux = pAux->get_prox();
    }
    return nullptr;
}

void ListaAlunos::set_notas(int ra, double n1, double n2, double f, int nFalt)
{
    ElAluno* pAux = get_alunoList(ra);
    Nota* pNota = pAux->get_notas();

    pNota->set_primParcial(n1);
    pNota->set_secParcial(n2);
    pNota->set_final(f);
    pNota->set_nFaltas(nFalt);
}

void ListaAlunos::info_aluno(int ra)
{
    ElAluno* pAux = get_alunoList(ra);

    if(pAux != nullptr)
    {
        Aluno* pAluno = pAux->get_aluno();
        Nota* pNotas = pAux->get_notas();

        cout<<"Diciplina: "<< nome<<endl;
        cout<<"RA: "<<pAluno->get_ra()<<" Nome: "<<pAluno->get_nome()<<endl;
        cout<<"Notas: "<<"\n- Primeira parcial: "<< pNotas->get_primParcial()<<endl;
        cout<<"- Segunda parcial: "<<pNotas->get_secParcial()<<"\n- Final: "<<pNotas->get_final()<<endl;
        cout<<"- Numero de faltas: "<<pNotas->get_nFaltas()<<endl;
    }
    else
    {
        cout<<"Aluno nao encontrado!!!"<<endl;
    }
    
}

void ListaAlunos::set_id(int i) { id = i; }
int ListaAlunos::get_id() { return id; }


void ListaAlunos::limpa_lista()
{
    //deleta elementos da lista encadiada
    ElAluno* pAux = pElAlunoPrim;
    while(pElAlunoPrim)
    {
        pElAlunoPrim = pAux->get_prox();
        delete pAux;
        pAux = pElAlunoPrim;
    }

    //Aterra ponteiros
    pElAlunoAtual = nullptr;
}

void ListaAlunos::gravar_alunos()
{
    ofstream gravadorAluno("arquivos/alunos.dat", ios::out);//abrindo/criando arquivo
    if(!gravadorAluno)//se nao abriu/criou o aquivo da uma menssagem de erro
    {
        std::cerr<<"Aquivo nao pode ser aberto!!"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    ElAluno* pElA = pElAlunoPrim;
    Aluno* pA = nullptr;
    //percore a lista
    while(pElA != nullptr)
    {
        pA = pElA->get_aluno();
        
        gravadorAluno<< pA->get_id()<<" "<<pA->get_nome()<<endl;//gravando dados no arquivo

        pElA = pElA->get_prox();
    }
    gravadorAluno.close();//fechado arquivo

    cout<<"Alunos gravados com sucesso!"<<endl;
    getchar();
}

void ListaAlunos::recuperar_alunos(int* contId)
{
    ifstream recuperador_alunos("arquivos/alunos.dat", ios::in);//abre o aquivo
    if(!recuperador_alunos)//se nao abriu da uma mensagem de erro
    {
        std::cerr<<"Arquivo nao pode ser aberto!"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    limpa_lista();//limpa a lista para nao aver duplicatas de alunos

    *contId = 0;
    char nomeAl[150];
    int i = 0;
    Aluno* pA = nullptr;

    while(!recuperador_alunos.eof())//enquanto nao chegar o fim do aquivo
    {
        recuperador_alunos>>i>>nomeAl;//isere os dados do aquivo nas variaveis
        if(0 != strcmp(nomeAl,""))//verifica se a variavel nao esta vazia
        {
            pA = new Aluno();//cria um novo aluno
            pA->set_id(i);
            pA->set_nome(nomeAl);

            inclui_aluno(pA);//inclui aluno na lista
            (*contId)++;
        }
        strcpy(nomeAl, "");//limpa a variavel 'nomeAL'
    }
    recuperador_alunos.close();//fecha o aquivo

    cout<<"Alunos recuperados com sucesso!"<<endl;
    getchar();
}