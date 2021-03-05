#include "ColaEsperaEntrada.h"
#include <iostream>
#include <cstdlib>
using namespace std;

ColaEsperaEntrada::ColaEsperaEntrada() {
    this->inicio = NULL;
    this->fin = NULL;
    this->size = 0;
}

/*
*Metodo para agregar al cliente a la cola de espera de Entrada para obtener una Carreta
*/
void ColaEsperaEntrada::push(Cliente *idCliente) {
    NodoColaEsperaEntrada *tmp = new NodoColaEsperaEntrada(idCliente);
    if(inicio == NULL) {
        inicio = tmp;
    } else  {
        fin->siguiente = tmp;
    }
    fin = tmp;
    size++;
}

/**
 * Método que saca al cliente de la cola de Espera de Entrada y retorna su id, para ingresar al supermercado
*/
Cliente* ColaEsperaEntrada::pop() {
    if (inicio != NULL) {
        NodoColaEsperaEntrada *tmp = inicio;
        Cliente* idClienteIngresado;
        idClienteIngresado = inicio->idCliente;
        inicio = inicio->siguiente;
        delete tmp;
        size--;
        return idClienteIngresado;
    } else {
        return 0;
    }
    
}

/*
*Método utilizado para mostrar el id de los clientes que están en la Cola de Espera de la Entrada
*/
void ColaEsperaEntrada::mostrarCola() {
    if(inicio == NULL) {
        cout << "La Cola de Clientes que esperan por ingresar al Supermercado, está vacía" << endl;
    } else  {
        NodoColaEsperaEntrada *tmp = inicio;
        cout << "Cola de Clientes en espera de una Carreta para ingresar al Supermercado: " << endl;
        while(tmp != NULL) {
            cout << "Cliente No. " << tmp->idCliente->idCliente << endl;
            tmp = tmp->siguiente;
        }
    }
}
/*
* Metodo que retorna el tamanio de la Cola de Espera de Entrada al Supermercado
*/
int ColaEsperaEntrada::getSize() {
    return size;
}