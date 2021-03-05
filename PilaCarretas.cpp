#include "PilaCarretas.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
//Inicializa el Constructor
PilaCarretas::PilaCarretas() {
    this->cabeza = NULL;
    this->size = 0;
}

//Agrega una Carreta a la Pila de Carretas
void PilaCarretas::push(Carreta* id) {
    NodoPilaCarretas *tmp;
    tmp = new NodoPilaCarretas(id);
    tmp->siguiente = cabeza;
    cabeza = tmp;
    size++;
}

//Elimina una Carreta de la Pila
Carreta* PilaCarretas::pop() {
    if(cabeza == NULL) {
        return 0;
    } else {
        Carreta* idCarreta = cabeza->carreta;
        NodoPilaCarretas *tmp = cabeza;
        //MANTENER LA CABEZA SIEMPRE
        cabeza = cabeza->siguiente;
        delete tmp;
        size--;
        return idCarreta;
    }
}

// Muestra las Carretas que estan dentro de la Pila
void PilaCarretas::mostrarPila() {
    if(cabeza == NULL) {
        cout << "No hay Carretas dentro de la Pila" << endl;
    } else {
        NodoPilaCarretas *tmp = cabeza;
        while(tmp != NULL) {
            cout << "Carreta No. " << tmp->carreta->id << endl;
            tmp = tmp->siguiente;
        }
    }
}

//Metodo que nos sirve para saber la cantidad de Carretas que posee la Pila
int PilaCarretas::getSize() {
    return size;
}