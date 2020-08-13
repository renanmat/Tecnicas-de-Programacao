#pragma once

class Disciplina;

class ElDisciplina
{
    private:
        Disciplina* pDisciplina;
        ElDisciplina* pProx;
        ElDisciplina* pAnt;
    
    public:
        ElDisciplina();
        ~ElDisciplina();

        //recebe disciplina
        void set_disciplina(Disciplina* pd);
        //retorna um ponteiro para uma disciplina
        Disciplina* get_disciplina();


        //recebe o proximo elemento de Disciplina da lista
        void set_proxElDisc(ElDisciplina* pEd);
        //retorna um ponteiro para o proximo elemento da lista
        ElDisciplina* get_proxElDisc();


        //recebe o elemento Disciplina anterior da lista
        void set_antElDisc(ElDisciplina* pEd);
        //retorna um ponteiro para o elemento anterior da lista
        ElDisciplina* get_antElDisc();
};