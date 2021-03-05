#ifndef NODOLISTACOMPRADORES_H
#define NODOLISTACOMPRADORES_H
#include "Cliente.h"
#include "Carreta.h"
class NodoListaCompradores {
    public:
        NodoListaCompradores(Cliente*, Carreta*);
        Cliente* idCliente;
        Carreta* idCarreta;
        NodoListaCompradores *siguiente;
};
#endif