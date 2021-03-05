#include "NodoColaEsperaEntrada.h"
#include <iostream>
#include <cstdlib>

NodoColaEsperaEntrada::NodoColaEsperaEntrada(Cliente* idCliente) {
    this->idCliente = idCliente;
    this->siguiente = NULL;
}