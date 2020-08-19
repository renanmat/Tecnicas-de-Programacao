#pragma once

#include "Universidade.hpp"

class ElUniversidade 
{
    private:
        Universidade* pUniv;
        ElUniversidade* pProx;
        ElUniversidade* pAnt;
        int id;

    public:
        ElUniversidade();
        ~ElUniversidade();

        void set_univ(Universidade* pu);
        Universidade* get_univ();

        void set_prox(ElUniversidade* peu);
        ElUniversidade* get_prox();

        void set_ant(ElUniversidade* peu);
        ElUniversidade* get_ant();

        char* get_nomeUniv();

        void set_id(int i);
        int get_id();

};