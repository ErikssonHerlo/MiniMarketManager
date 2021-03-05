#include "ListaCajas.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;

// INICIALIZACION DEL CONSTRUCTOR
ListaCajas::ListaCajas() {
    this->inicio = NULL;
    this->fin = NULL;
    this->size = 0;
}

// Metodo para agregar una Nueva Caja a la Lista
void ListaCajas::push(int idCaja) {
    NodoListaCajas *tmp = new NodoListaCajas(idCaja);
    if(inicio == NULL) {
        this->inicio = tmp;
        this->fin = tmp;
    } else {
        fin->siguiente = tmp;
        tmp->anterior = fin;
        fin = tmp;
    }
    size++;
}

// Metodo para mostrar la Lista de Cajas 
void ListaCajas::mostrarLista() {
    if(inicio == NULL) {
        cout << "No hay Cajas de Pago registradas en la Lista" << endl;
    } else {
        NodoListaCajas *tmp = inicio;
        cout << "Las Cajas de Pago existentes en el supermercado son las siguiente: " << endl;
        while(tmp != NULL) {
            cout << "Caja No. " << tmp->idCaja << endl;
            tmp = tmp->siguiente;
        } 
    }
}

/*
* Metodo que verifica la Disponibilidad de la Caja de Pagos, asi como le asigna una cantidad de turnos ocupando la Caja
*/
bool ListaCajas::disponibilidadCaja(Cliente* idCliente,Carreta* idCarreta) {
    if(inicio == NULL) {
        cout << "\nNo hay cajas de Pago Disponibles";
        return false;
    } else {
        NodoListaCajas *tmp = inicio;
        while(tmp != NULL) {
            if (tmp->estado == "DISPONIBLE") {
                tmp->idCliente = idCliente;
                tmp->idCarreta = idCarreta;
                srand(time(NULL));
                tmp->turnosOcupados = 1 + rand()%(4-1);
                //tmp->turnosOcupados++;
                tmp->estado = "OCUPADA";
                cout << "El cliente No. " << idCliente->idCliente << " ha ocupado la Caja No." << tmp->idCaja << " con la Carreta No." << idCarreta->id << " durante los siguientes " << tmp->turnosOcupados << " turnos" << endl;
                sleep(1);
                return true;
            }
            tmp = tmp->siguiente;
        }
    }
    return false;
}

int ListaCajas::getSize() {
    return size;
}

// Metodo que verifica los turnos que un Cliente utiliza una Caja, para asi liberarlo
void ListaCajas::verificarTurnos(PilaCarretas *pilaCarretas1, PilaCarretas *pilaCarretas2) {
    if(inicio != NULL) {
        NodoListaCajas *tmp = inicio;
        while(tmp != NULL) {
            if(tmp->estado == "OCUPADA") {
                tmp->turnosOcupados--;
                if(tmp->turnosOcupados == 0) {
                    tmp->estado = "DISPONIBLE";
                    int ubicacionCarreta = rand()%(2)+1;
                    cout << "El cliente No. " << tmp->idCliente->idCliente << " ha pagado y se retira del supermercado. "<<"La carreta No. " << tmp->idCarreta->id << " es colocada en la ";
                    if (ubicacionCarreta == 1) {
                        pilaCarretas1->push(tmp->idCarreta);
                        cout << "Pila de Carretas No. 1" << endl;
                        sleep(1);
                    } else {
                        pilaCarretas2->push(tmp->idCarreta);
                        cout << "Pila de Carretas No. 2" << endl;
                        sleep(1);
                    }
                    delete tmp->idCliente;
                }
            }
            tmp = tmp->siguiente;
        }
    }
}