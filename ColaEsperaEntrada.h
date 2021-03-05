#ifndef COLAESPERA_H
#define COLAESPERA_H
#include "Cliente.h"
#include "NodoColaEsperaEntrada.h"

class ColaEsperaEntrada {
    public:
        ColaEsperaEntrada();
        NodoColaEsperaEntrada *inicio;
        NodoColaEsperaEntrada *fin;
        void push(Cliente*);
        Cliente* pop();
        void mostrarCola();
        
        int size;
        int getSize();
};
#endif