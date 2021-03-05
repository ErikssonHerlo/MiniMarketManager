#ifndef LISTACOMPRAS_H
#define LISTACOMPRAS_H
#include "NodoListaCompradores.h"
#include <cstdlib>

class ListaCompradores {
    public:
        ListaCompradores();
        NodoListaCompradores *inicio;
        NodoListaCompradores *fin;
        void push(Cliente*, Carreta*);
        NodoListaCompradores* pop(int);
        void mostrarLista();
};
#endif
