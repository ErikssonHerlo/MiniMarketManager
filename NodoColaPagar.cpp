#include "NodoColaPagar.h"
#include <iostream>
#include <cstdlib>
using namespace std;
 NodoColaPagar::NodoColaPagar(Cliente* idCliente, Carreta* idCarreta) {
    this->idCliente = idCliente;
    this->idCarreta = idCarreta;
    this->siguiente = NULL;
 }