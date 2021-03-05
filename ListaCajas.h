#ifndef LISTACAJAS_H
#define LISTACAJAS_H
#include "NodoListaCajas.h"
#include "PilaCarretas.h"
#include "Cliente.h"
#include "Carreta.h"
class ListaCajas {
    public:
        ListaCajas();
        NodoListaCajas *inicio;
        NodoListaCajas *fin;
        void push(int);
        void mostrarLista();
        void verificarTurnos(PilaCarretas*, PilaCarretas*);
        bool disponibilidadCaja(Cliente*,Carreta*);
        int size;
        int getSize();
    
};
#endif