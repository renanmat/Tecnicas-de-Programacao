#pragma once

class Nota
{
    private:
        double primParcial;
        double secParcial;
        double parcFinal;
        int nFaltas;
    
    public:
        Nota();
        ~Nota();

        void set_primParcial(double nt);
        double get_primParcial();

        void set_secParcial(double nt);
        double get_secParcial();

        void set_final(double nt);
        double get_final();

        void set_nFaltas(int f);
        int get_nFaltas();
};