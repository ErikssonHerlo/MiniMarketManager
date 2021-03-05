#ifndef COLAPAGAR_H
#define COLAPAGAR_H
#include "NodoColaPagar.h"
class ColaPagar{
    public:
        ColaPagar();
        NodoColaPagar *inicio;
        NodoColaPagar *fin;
        void push(Cliente*, Carreta*);
        void pop();
        void mostrarCola();
        bool colaVacia();
        int size;
        int getSize();
    
};
#endif