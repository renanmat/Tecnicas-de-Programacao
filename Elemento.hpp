#pragma once

//Um gabarito se define inteiramente no .h

//-=definição=-
template<class TIPO>
class Elemento
{
    private:
        Elemento<TIPO>* pProximo;
        Elemento<TIPO>* pAnterior;
        TIPO* pInfo;

    public:
        Elemento();
        ~Elemento();

        void set_prox(Elemento<TIPO>* pE);
        Elemento<TIPO>* get_prox();

        void set_ant(Elemento<TIPO>* pE);
        Elemento<TIPO>* get_ant();

        void set_info(TIPO* pI);
        TIPO* get_info();

};

//-=Implementação=-
template<class TIPO>
Elemento<TIPO>::Elemento()
{
    pProximo = nullptr;
    pAnterior = nullptr;
    pInfo = nullptr;
}
template<class TIPO>
Elemento<TIPO>::~Elemento()
{
    pProximo = nullptr;
    pAnterior = nullptr;
    pInfo = nullptr;
}

template<class TIPO>
void Elemento<TIPO>::set_prox(Elemento<TIPO>* pE)
{
    pProximo = pE;
}
template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::get_prox()
{
    return pProximo;
}

template<class TIPO>
void Elemento<TIPO>::set_ant(Elemento<TIPO>* pE)
{
    pAnterior = pE;
}
template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::get_ant()
{
    return pAnterior;
}

template<class TIPO>
void Elemento<TIPO>::set_info(TIPO* pI)
{
    pInfo = pI;
}
template<class TIPO>
TIPO* Elemento<TIPO>::get_info()
{
    return pInfo;
}
