#ifndef NODOLISTACAJAS_H
#define NODOLISTACAJAS_H
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Carreta.h"
using namespace std;
class NodoListaCajas {
    public:
        NodoListaCajas(int);
        int idCaja;
        Cliente* idCliente;
        Carreta* idCarreta;
        int turnosOcupados;
        string estado;
        NodoListaCajas *siguiente;
        NodoListaCajas *anterior;
        
};
#endif