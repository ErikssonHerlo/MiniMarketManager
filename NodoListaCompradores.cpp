#include "NodoListaCompradores.h"
#include <iostream>
#include <cstdlib>
using namespace std;

NodoListaCompradores::NodoListaCompradores(Cliente *idCliente, Carreta *idCarreta) {
    this->idCliente = idCliente;
    this->idCarreta = idCarreta;
    this->siguiente = NULL;
}
