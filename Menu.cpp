#include "Menu.hpp"
#include "Disciplina.hpp"

#include <iostream>
using std::cin;
#include <string>
using std::string;
using std::getline;

Menu::Menu():
 cont_idUniver{0},
 cont_idDepart{0},
 cont_idDiscip{0},
 cont_idAluno{0},
 cont_idProf{0},
 objLUniver(),
 objLDepart(),
 objLDiscip(),
 objLAluno(),
 objLProfesores()
 {
 }
 
Menu::~Menu()
{
}

void Menu::cadastre_univer(Universidade* pu)
{
    if(pu != nullptr)
    {
        objLUniver.inclui_univ(pu);
        cont_idUniver++;
    }
    else
    {
        string nome;
        cout<<"Informe nome da Universidade: "<<endl;
        cin.ignore();
        getline(cin, nome);

        Universidade* pAux = new Universidade();
        pAux->set_id(cont_idUniver++); // 'cont_idUniver++' id recebe +1 a cada nova universidade cadastrada
        pAux->setNome(nome.c_str());

        objLUniver.inclui_univ(pAux);

        cout<<"Universidade cadastrada"<<endl;
    }
}

void Menu::cadastre_depart(Departamento* pd)
{
    if(pd != nullptr)
    {
        objLDepart.inclui_depart(pd);
        cont_idDepart++;
    }
    else
    {
       string nomeUniv;
       cout<<"Informe o nome da Univesidade: "<<endl;
       cin.ignore();
       getline(cin, nomeUniv);


       Universidade* pUniv = objLUniver.localiza_universidade(nomeUniv.c_str());

       if(pUniv)
       {
           Departamento* pDep = nullptr;
           string nomeDep;

           cout<<"Informe o nome do departamento: "<<endl;
           getline(cin, nomeDep);

           pDep = new Departamento();
           pDep->set_id(cont_idDepart++); // 'cont_idDepart++' id recebe +1 a cada novo departamento cadastrado
           pDep->setNome(nomeDep.c_str());
           pDep->set_univerAssocida(pUniv);

           objLDepart.inclui_depart(pDep);
           cout<<"Departamento cadastrado!!"<<endl;
           
       }
       else
       {
           cout<<"Universidade nao cadastrada!"<<endl;
       }
       
    }
    
}
void Menu::cadastre_discp(Disciplina* pd)
{
    if(pd != nullptr)
    {
        objLDiscip.inclui_disciplina(pd);
        cont_idDiscip++;
    }
    else
    {
        string nomeDep;
        Departamento* pDepart = nullptr;

        cout<<"Informe o departamento: "<<endl;
        cin.ignore();
        getline(cin, nomeDep);

        pDepart = objLDepart.localiza_depart(nomeDep.c_str());

        if(pDepart != nullptr)
        {
            string nome;
            Disciplina* pDisc = new Disciplina();

            cout<<"Nome da disciplina: "<<endl;
            getline(cin, nome);
            pDisc->set_nome(nome.c_str());
            pDisc->set_departAssociado(pDepart);
            pDisc->set_id(cont_idDiscip++);//// 'cont_idDiscip++' o contador de id recebe +1 a cada nova disciplina cadastrada

            objLDiscip.inclui_disciplina(pDisc);

            cout<<"Disciplina cadastrada!"<<endl;
        }
        else
        {
            cout<<"Departamento nao cadastrado!!"<<endl;
        }   
    }
    
}

void Menu::cadastre_alunos(Aluno* pA)
{
    if(pA != nullptr)
    {
        objLAluno.inclui_aluno(pA);
        cont_idAluno++;
    }
    else
    {
        string nomeA;
        int ra = 0;
        Aluno* pA = nullptr;

        cout<<"Informe o nome do Aluno:"<<endl;
        cin.ignore();
        getline(cin, nomeA);
        
        cout<<"Informe o Registro Academico(RA):"<<endl;
        cin>>ra;

        pA = new Aluno(cont_idAluno++); // cria aluno e isere o id
        pA->set_nome(nomeA.c_str());

        objLAluno.inclui_aluno(pA);

        cout<<"Aluno cadastrado"<<endl;
        getchar();

    }
    
}

void Menu::cadastre_professor(Professor* pP)
{
    if(pP != nullptr)
    {
        objLProfesores.inclui_professor(pP);
        cont_idProf++;
    }
    else
    {
        string nomeP;
        Professor* pP = nullptr;

        cout<<"Informe o nome do Professor: "<<endl;
        cin.ignore();
        getline(cin, nomeP);

        pP = new Professor(cont_idProf++);// cria professor e isere o id
        pP->set_nome(nomeP.c_str());

        objLProfesores.inclui_professor(pP);

        cout<<"Professor cadastrado!"<<endl;
    }
    
}

void Menu::gravar_todos()
{
    objLUniver.gravar_universidades(cont_idUniver);
    objLDepart.grava_departamentos(cont_idDepart);
    objLDiscip.grava_disciplinas(cont_idDiscip);
    objLAluno.gravar_alunos(cont_idAluno);
    objLProfesores.gravar_professores(cont_idProf);
}
void Menu::recuperar_todos()
{
    objLUniver.recuperar_universidades(&cont_idDiscip);
    objLDepart.recuperar_departamentos(&cont_idDepart);
    objLDiscip.recupera_disciplinas(&cont_idDiscip);
    objLAluno.recuperar_alunos(&cont_idAluno);
    objLProfesores.recuperar_professores(&cont_idProf);
}
void Menu::menu_cad()
{
    int op = -1;
    
    while(op != 9)
    {
        system("clear");
        cout<<"####### Menu de cadastro #######"<<endl;
        cout<<"1 -   Cadastrar Universidade"<<endl;
        cout<<"2 -   Cadastrar Departamento"<<endl;
        cout<<"3 -   Cadastrar Disciplina"<<endl;
        cout<<"4 -   Cadastrar Aluno"<<endl;
        cout<<"5 -   Cadastrar Professor"<<endl;
        cout<<"9 -   Sair"<<endl;
        
        cin>>op;

        switch(op)
        {
            case 1:
                cadastre_univer();
                getchar();
                break;
            case 2:
                cadastre_depart();
                getchar();
                break;
            case 3:
                cadastre_discp();
                getchar();
                break;
            case 4:
                cadastre_alunos();
                getchar();
                break;
            case 5:
                cadastre_professor();
                getchar();
                break;
            case 9:
            break;
            default:
                cout<<"Opçao invalida!!"<<endl;
                getchar();
        }

    }
}

void Menu::menu_exe()
{
    int op = -1;
    
    while(op != 9)
    {  
        system("clear");
        cout<<"####### Menu de Execucao #######"<<endl;
        cout<<"1 -   Liste Universidades"<<endl;
        cout<<"2 -   Liste Departamentos"<<endl;
        cout<<"3 -   Liste Disciplina"<<endl;
        cout<<"4 -   Liste Alunos"<<endl;
        cout<<"5 -   Liste Professores"<<endl;
        cout<<"9 -   Sair"<<endl;
        
        cin>>op;

        switch(op)
        {
            case 1:
                objLUniver.liste_univ();
                cin.ignore();
                getchar();
                break;
            case 2:
                objLDepart.liste_depart();
                cin.ignore();
                getchar();
                break;
            case 3:
                objLDiscip.liste_disciplinas();
                cin.ignore();
                getchar();
                break;
            case 4:
                objLAluno.liste_alunos();
                cin.ignore();
                getchar();
                break;
            case 5:
                objLProfesores.liste_professores();
                cin.ignore();
                getchar();
                break;    
            case 9:
                break;
            default:
                cout<<"Opçao invalida!!"<<endl;
                cin.ignore();
                getchar();
        }

    }
}

void Menu::menu_grav()
{
    int op = -1;
    
    while(op != 9)
    {
        system("clear");
        cout<<"####### MENU GRAVAR#######"<<endl;
        cout<<"0 -   Gravar Todos"<<endl;
        cout<<"1 -   Gravar Universidades"<<endl;
        cout<<"2 -   Gravar Departamentos"<<endl;
        cout<<"3 -   Gravar Disciplinas"<<endl;
        cout<<"4 -   Gravar Alunos"<<endl;
        cout<<"5 -   Gravar Professores"<<endl;
        cout<<"9 -   Sair"<<endl;
        
        cin>>op;

        switch(op)
        {
            case 0:
                gravar_todos();
                break;
            case 1:
                objLUniver.gravar_universidades(cont_idUniver);
                getchar();
                break;
            case 2:
                objLDepart.grava_departamentos(cont_idDepart);
                getchar();
                break;
            case 3:
                objLDiscip.grava_disciplinas(cont_idDiscip);
                getchar();
                break;
            case 4:
                objLAluno.gravar_alunos(cont_idAluno);
                getchar();
                break;
            case 5:
                objLProfesores.gravar_professores(cont_idProf);
                getchar();
                break;
            case 9:
                break;
            default:
                cout<<"Opçao invalida!!"<<endl;
                getchar();
        }

    }
}

void Menu::menu_recup()
{
    int op = -1;
    
    while(op != 9)
    {
        system("clear");
        cout<<"####### MENU RECUPERAR #######"<<endl;
        cout<<"0 -   Recuperar Todos"<<endl;
        cout<<"1 -   Recuperar Universidades"<<endl;
        cout<<"2 -   Recuperar Departamentos"<<endl;
        cout<<"3 -   Recuperar Disciplinas"<<endl;
        cout<<"4 -   Recuperar Alunos"<<endl;
        cout<<"5 -   Recuperar Professores"<<endl;
        cout<<"9 -   Sair"<<endl;
        
        cin>>op;

        switch(op)
        {
            case 0:
                recuperar_todos();
                break;
            case 1:
            //passando o contador por referencia  para ser atualizado na hora de recuperar os aquivos
                objLUniver.recuperar_universidades(&cont_idUniver);
                getchar();
                break;
            case 2:
                objLDepart.recuperar_departamentos(&cont_idDepart);
                getchar();
                break;
            case 3:
                objLDiscip.recupera_disciplinas(&cont_idDiscip);
                getchar();
                break;
            case 4:
                objLAluno.recuperar_alunos(&cont_idAluno);
                getchar();
                break;
            case 5:
                objLProfesores.recuperar_professores(&cont_idProf);
                getchar();
                break;
            case 9:
                break;
            default:
                cout<<"Opçao invalida!!"<<endl;
                getchar();
        }

    }
}

void Menu::menu_principal()
{
    int op = -1;
    
    while(op != 9)
    {
        system("clear");
        cout<<"####### MENU #######"<<endl;
        cout<<"1 -   Cadastrar"<<endl;
        cout<<"2 -   Listar"<<endl;
        cout<<"3 -   Gravar"<<endl;
        cout<<"4 -   Recuperar"<<endl;
        cout<<"9 -   Sair"<<endl;
        
        cin>>op;

        switch(op)
        {
            case 1:
                menu_cad();
                break;
            case 2:
                menu_exe();
                break;
            case 3:
                menu_grav();
                break;
            case 4:
                menu_recup();
                break;
            case 9:
                cout<<"Obrigado! volte sempre!"<<endl;
                break;
            default:
                cout<<"Opçao invalida!!"<<endl;
                getchar();
        }

    }
}
