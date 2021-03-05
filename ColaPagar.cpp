#include "ColaPagar.h"
#include <iostream>
#include <cstdlib>
using namespace std;

/*
 * Inicializacion del Constructor
 */ 
ColaPagar::ColaPagar() {
    this->inicio = NULL;
    this->fin = NULL;
    this->size = 0;
}

/*
 * Método utilizado para agregar a un Cliente a la Cola de pagos en Caja
 */
void ColaPagar::push(Cliente* idCliente, Carreta* idCarreta) {
    NodoColaPagar *tmp = new NodoColaPagar(idCliente, idCarreta);
    if(inicio == NULL) {
        inicio = tmp;
    } else {
        fin->siguiente = tmp;
    }

    fin = tmp;
    size++;
}

/*
* Método utilizado para eliminar al cliente que viene en primera posicion de la cola
*/
void ColaPagar::pop() {
    if(inicio != NULL) {
        NodoColaPagar *tmp = inicio;
        inicio = inicio->siguiente;
        delete tmp;
        size--;
    }
}

/*
* Método que sive para mostrar la información de los clientes que están en la cola de pagos
*/
void ColaPagar::mostrarCola() {
    if(colaVacia()) {
        cout << "La Cola de Clientes esperando a Pagar esta Vacia" << endl;
    } else {
        NodoColaPagar *tmp = inicio;
        cout << "Cola de Clientes en espera de entrar a pagar a la Caja:" << endl;
        while(tmp != NULL) {
            cout << "Cliente: " << tmp->idCliente->idCliente << " - Carreta: " << tmp->idCarreta->id << endl;
            tmp = tmp->siguiente;
        }
    }
}

/*
 * Método que nos sirve para obtener el tamaño de la cola de Clientes en Espera de Pago
 */
int ColaPagar::getSize() {
    return size;
}
/*
 * Metodo para verificar que la Cola no este vacia 
 */
bool ColaPagar::colaVacia() {
    return (inicio == NULL)? true:false;

}