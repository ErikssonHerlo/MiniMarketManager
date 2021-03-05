#ifndef NODOCOLAESPERAENTRADA_H
#define NODOCOLAESPERAENTRADA_H
#include "Cliente.h"
class NodoColaEsperaEntrada {
    public:
    NodoColaEsperaEntrada(Cliente*);
    NodoColaEsperaEntrada *siguiente;
    Cliente *idCliente;
};
#endif