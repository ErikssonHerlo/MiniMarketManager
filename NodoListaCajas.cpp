#include "NodoListaCajas.h"
#include <iostream>
#include <cstdlib>
using namespace std;
NodoListaCajas::NodoListaCajas(int idCaja) {
    this->idCaja = idCaja;
    this->siguiente = NULL;
    this->anterior = NULL;
    this->turnosOcupados = 1;
    this->estado = "DISPONIBLE";
    this->idCarreta = NULL;
    this->idCliente = NULL;
}