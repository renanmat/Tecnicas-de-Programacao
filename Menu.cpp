#include "Menu.hpp"
#include "Disciplina.hpp"

#include <iostream>
using std::cin;
#include <string>
using std::string;
using std::getline;

 Menu::Menu():
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
    }
    else
    {
        string nome;
        cout<<"Informe nome da Universidade: "<<endl;
        cin.ignore();
        getline(cin, nome);

        Universidade* pAux = new Universidade();
        pAux->setNome(nome.c_str());

        objLUniver.inclui_univ(pAux);
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
                cout<<"Obrigado! volte sempre!"<<endl;
                break;
            default:
                cout<<"Opçao invalida!!"<<endl;
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
                getchar();
                getchar();
                break;
            case 2:
                objLDepart.liste_depart();
                getchar();
                getchar();
                break;
            case 3:
                objLDiscip.liste_disciplinas();
                getchar();
                getchar();
                break;
            case 9:
                cout<<"Obrigado! volte sempre!"<<endl;
                break;
            default:
                cout<<"Opçao invalida!!"<<endl;
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
            case 9:
                cout<<"Obrigado! volte sempre!"<<endl;
                break;
            default:
                cout<<"Opçao invalida!!"<<endl;
                getchar();
        }

    }
}
