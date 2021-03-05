#include "ListaCompradores.h"
#include <iostream>
#include <cstdlib>
using namespace std;

ListaCompradores::ListaCompradores() {
    this->inicio = NULL;
    this->fin = NULL;
}

//Método utilizado para agregar un Cliente y una Carreta a la lista de Compradores
void ListaCompradores::push(Cliente* idCliente, Carreta* idCarreta) {
    NodoListaCompradores *tmp = new NodoListaCompradores(idCliente, idCarreta);
    if(inicio == NULL) {
        inicio = tmp;
        fin = tmp;
        fin->siguiente=inicio;
    } else {
        fin->siguiente = tmp;
        fin = tmp;
        tmp->siguiente=inicio;
    }   
}

/**
 * Método que sirve para eliminar un NodoListaCompradores de la Lista
*/
NodoListaCompradores* ListaCompradores::pop(int idCliente) {
    if(inicio == NULL) {
        return 0;
    } else {
        NodoListaCompradores *tmp = inicio;
        NodoListaCompradores *tmpAnterior = NULL;
        do {
            if(tmp->idCliente->idCliente == idCliente) {
                if(tmp == inicio) {
                    inicio = inicio->siguiente;
                    fin->siguiente = inicio;
                    return tmp;
                } else if (tmp == fin) {
                    tmpAnterior->siguiente = inicio;
                    fin=tmpAnterior;
                    return tmp;
                } else {
                    tmpAnterior->siguiente = tmp->siguiente;
                    return tmp;
                }
            }
            tmpAnterior = tmp;
            tmp = tmp->siguiente;
        } while(tmp != inicio);
        return NULL;
    }
}

//Metodo que nos sirve para mostrar la Lista de Compradores
void ListaCompradores::mostrarLista() {
    if(inicio == NULL) {
        cout << "La Lista de Compradores se encuentra Vacia" << endl;
    } else {
        NodoListaCompradores *tmp = inicio;
        cout << "Lista de los Compradores que se encuentran dentro del supermercado" << endl;
        do {
            cout << "Cliente No. " << tmp->idCliente->idCliente << " - Carreta No. " << tmp->idCarreta->id << endl;
            tmp = tmp->siguiente;
        } while(tmp->siguiente != inicio->siguiente);
    }
}
