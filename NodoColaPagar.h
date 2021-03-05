#ifndef NODOCOLAPAGAR_H
#define NODOCOLAPAGAR_H
#include "Cliente.h"
#include "Carreta.h"
class NodoColaPagar {
    public:
        NodoColaPagar(Cliente*, Carreta*);
        NodoColaPagar *siguiente;
        Cliente* idCliente;
        Carreta* idCarreta;
};
#endif