#include "Menu.hpp"
#include "Disciplina.hpp"

#include <iostream>
using std::cin;
#include <string>
using std::string;
using std::getline;


 Menu::Menu():
 cont_idUniver{0},
 objLUniver(),
 objLDepart(),
 objLDiscip()
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
        pAux->set_id(cont_idUniver++);
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
           pDep->setNome(nomeDep.c_str());
           pDep->set_univerAssocida(pUniv);

           objLDepart.inclui_depart(pDep);
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

            objLDiscip.inclui_disciplina(pDisc);
        }
        else
        {
            cout<<"Departamento nao cadastrado!!"<<endl;
        }   
    }
    
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
        cout<<"1 -   Gravar Universidades"<<endl;
        // cout<<"2 -   Listar"<<endl;
        // cout<<"3 -   Gravar"<<endl;
        cout<<"9 -   Sair"<<endl;
        
        cin>>op;

        switch(op)
        {
            case 1:
                objLUniver.gravar_universidades();
                getchar();
                break;
            // case 2:
            //     menu_exe();
            //     break;
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
        cout<<"1 -   Recuperar Universidades"<<endl;
        // cout<<"2 -   Listar"<<endl;
        // cout<<"3 -   Gravar"<<endl;
        // cout<<"4 -   Ler arquivo de lista"<<endl;
        cout<<"9 -   Sair"<<endl;
        
        cin>>op;

        switch(op)
        {
            case 1:
            //passando o contador por referencia  para ser atualizado na hora de recuperar os aquivos
                objLUniver.recuperar_universidades(&cont_idUniver);
                break;
            // case 2:
            //     menu_exe();
            //     break;
            // case 3:
            //     menu_grav();
            //     break;
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
