#include "Simulacion.h"
#include "Carreta.h"
#include "PilaCarretas.h"
#include "ColaEsperaEntrada.h"
#include "ListaCajas.h"
#include "ListaCompradores.h"
#include "ColaPagar.h"
#include "Cliente.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

void Simulacion::menuInicial() {

    //Declaramos las principales variables que utilizaremos
    int cajasTotales, clientesComprando, clientesPorPagar;
    

    //Inicializacion de Estructuras a Utilizar
    PilaCarretas *pilaCarretas1 = new PilaCarretas();
    PilaCarretas *pilaCarretas2 = new PilaCarretas();
    ColaEsperaEntrada *ColaEsperaEntradaCarretas = new ColaEsperaEntrada();
    ColaPagar *colaPagar = new ColaPagar();
    ListaCajas *listaCajas = new ListaCajas();
    ListaCompradores *listaCompradores = new ListaCompradores();

    //Mostramos el menú inicial
    cout<< "BIENVENIDO A LA SIMULACION DEL MINIMARKET MANAGER" << endl;
    cout<<"Por favor, ingrese los datos que se le solicitan, utilizando Numeros Enteros Unicamente"<<endl;
    cout<< "\nIngrese la cantidad de carretas con las que el supermercado contará: ";
    cin>> cantCarretasTotales;
    cout<< "Ingrese la cantidad de cajas con las que el supermercado contará: ";
    cin>> cajasTotales;
    cout<< "Ingrese la cantidad de clientes que estarán en la Cola de Espera de Carretas: ";
    cin>> cantClientesTotales;
    cout<< "Ingrese la cantidad de clientes que están dentro del Supermercado: ";
    cin>> clientesComprando;
    cout << "Ingrese la cantidad de clientes que hay en la cola de pagos: ";
    cin >> clientesPorPagar;



    cout<<"\n\n\n******************SIMULACION DEL MINIMARKET MANAGER******************"<<endl;
    cout<<"INVENTARIO: "<<endl;

    //INICIALIZACION DE LAS PILAS DE CARRETAS
    inicializacionPilaCarretas(pilaCarretas1, pilaCarretas2, cantCarretasTotales);
    cout << "CARRETAS UBICADAS EN LA PILA 1: "<<endl;
    pilaCarretas1->mostrarPila();
    cout<<"\n\nCARRETAS UBICADAS EN LA PILA 2:" << endl;
    pilaCarretas2->mostrarPila();
    cout <<"\n\n";

    //INICIALIZACION DE LAS CAJAS DEL SUPERMERCADO
    inicializacionCajas(listaCajas, cajasTotales);
    cout << "CAJAS EXISTENTES EN EL SUPERMERCADO:" << endl;
    listaCajas->mostrarLista();
    cout << endl << endl;

    //INICIALIZACION DE LA COLA DE ESPERA DE CLIENTES
    inicializacionColaEsperaEntrada(ColaEsperaEntradaCarretas, cantClientesTotales);
    
    ColaEsperaEntradaCarretas->mostrarCola();
    cout <<"\n\n";

    //INICIALIZACION DE LA LISTA DE COMPRADORES
    cout <<"DATOS DE LA SIMULACION: "<<endl;
    
    cantClientesTotales += clientesComprando;
   // cantCarretasTotales 
    inicializacionCompradores(listaCompradores, cantClientesTotales, cantCarretasTotales, clientesComprando);
    //cout << "Información de las Clientes que están comprando:" << endl;
    listaCompradores->mostrarLista();
    cout <<"\n\n";

    //Inicializamos a los clientes que están en la cola de pagos
    //INICIALIZACION DE LOS CLIENTES QUE ESTAN EN LA COLA DE PAGOS
    cantClientesTotales = clientesComprando;
    cantCarretasTotales = clientesComprando;
    inicializacionColaPagos(colaPagar, cantClientesTotales, cantCarretasTotales, clientesPorPagar);
    colaPagar->mostrarCola();
    cout <<"\n\n";

    
    char repeticion = 's';
    while(repeticion == 's') {
        switch(toupper(repeticion)) {
            case 'S':
                simulacionMiniMarket(pilaCarretas1, pilaCarretas2, ColaEsperaEntradaCarretas, colaPagar, listaCajas, listaCompradores);
                break;
            case 'N':
                break;
        }
        cout <<"n\n¿Desea continuar con la simulación? (s/n): ";
        cin >> repeticion;
    } 
    simulacionMiniMarket(pilaCarretas1, pilaCarretas2, ColaEsperaEntradaCarretas, colaPagar, listaCajas, listaCompradores);
    
}

//Método que nos sirve para introducir las carretas a una pila cuando se inicia la ejecución de la simulación
void Simulacion::inicializacionPilaCarretas(PilaCarretas *pilaCarretas1, PilaCarretas *pilaCarretas2, int cantCarretasTotales) {
    for(int i = 1; i <= cantCarretasTotales; i++) {
        int ubicacionCarretas = rand()%(2)+1;
        if (ubicacionCarretas == 1) {
            pilaCarretas1->push(new Carreta(i));
        } else {
            pilaCarretas2->push(new Carreta(i));
        }
    }
}

void Simulacion::inicializacionColaEsperaEntrada(ColaEsperaEntrada* ColaEsperaEntradaCarretas, int cantClientesTotales) {
    for(int i = 1; i <= cantClientesTotales; i++) {
        ColaEsperaEntradaCarretas->push(new Cliente(i));
    }
}

void Simulacion::inicializacionCajas(ListaCajas *listaCajas, int cajasTotales) {
    for(int i = 1; i <= cajasTotales; i++) {
        listaCajas->push(i);
    }
}

void Simulacion::inicializacionCompradores(ListaCompradores *ListaCompradores, int cantClientesTotales, int cantCarretasTotales, int clientesComprando) {
    int SimulacionClientes = cantClientesTotales - clientesComprando + 1;
    int indicadorCarreta = cantCarretasTotales - clientesComprando + 1;
    for(int i = SimulacionClientes; i <= cantClientesTotales; i++) {
        ListaCompradores->push(new Cliente(i), new Carreta(indicadorCarreta));
        indicadorCarreta++;
    }
}

void Simulacion::inicializacionColaPagos(ColaPagar *colaPagar, int cantClientesTotales, int cantCarretasTotales, int clientesPorPagar) {
    int SimulacionClientes = cantClientesTotales - clientesPorPagar + 1;
    int indicadorCarreta = cantCarretasTotales - clientesPorPagar + 1;
    for(int i = SimulacionClientes; i <= cantClientesTotales; i++) {
        colaPagar->push(new Cliente(i), new Carreta(indicadorCarreta));
        indicadorCarreta++;
    }
}

void Simulacion::simulacionMiniMarket(PilaCarretas *pilaCarretas1, PilaCarretas *pilaCarretas2, ColaEsperaEntrada *ColaEsperaEntradaCarretas, ColaPagar *colaPagar, ListaCajas *listaCajas, ListaCompradores *ListaCompradores) {
    //Iniciaomos con la simulación
    pasosSimulacion++;
    cout << "***************************************PASO " << pasosSimulacion << "***************************************" << endl;
    
    //Ingresamos clientes a la cola de compras si hay carretas disponibles y clientes en la cola de espera
    int clientesEnEspera = ColaEsperaEntradaCarretas->getSize(), carretasEnPila1 = pilaCarretas1->getSize(), carretasEnPila2 = pilaCarretas2->getSize();
    while (clientesEnEspera > 0 && (carretasEnPila1 > 0 || carretasEnPila2 > 0)) {
        if(clientesEnEspera > 0) {
            int tomarCarreta = rand()%(2)+1;
            
            if(tomarCarreta == 1) { 
                if(carretasEnPila1 > 0) {
                    Cliente* clienteIngresado = ColaEsperaEntradaCarretas->pop(); 
                    Carreta* carretaIngresada = pilaCarretas1->pop();
                    ListaCompradores->push(clienteIngresado, carretaIngresada);
                    cout << "El Cliente No. " << clienteIngresado->idCliente << " ha ingresado a Comprar en el Supermercado con la Carreta No. " << carretaIngresada->id <<" tomada de la Pila 1"<<endl;
                    sleep(1);
                } else if (carretasEnPila2 > 0) {
                    Cliente* clienteIngresado = ColaEsperaEntradaCarretas->pop(); 
                    Carreta* carretaIngresada = pilaCarretas2->pop();
                    ListaCompradores->push(clienteIngresado, carretaIngresada);
                        cout << "El Cliente No. " << clienteIngresado->idCliente << "ha ingresado a Comprar en el Supermercado con la Carreta No. " << carretaIngresada->id <<" tomada de la Pila 1"<<endl;
                    sleep(1);
               }
            } else { 
                if(carretasEnPila2 > 0) {
                    Cliente* clienteIngresado = ColaEsperaEntradaCarretas->pop(); 
                    Carreta* carretaIngresada = pilaCarretas2->pop();
                    ListaCompradores->push(clienteIngresado, carretaIngresada);
                        cout << "El Cliente No. " << clienteIngresado->idCliente << "ha ingresado a Comprar en el Supermercado con la Carreta No. " << carretaIngresada->id <<" tomada de la Pila 2"<<endl;
                    sleep(1);
                 } else if (carretasEnPila1 > 0) {
                    Cliente* clienteIngresado = ColaEsperaEntradaCarretas->pop(); 
                    Carreta* carretaIngresada = pilaCarretas1->pop();
                    ListaCompradores->push(clienteIngresado, carretaIngresada);
                        cout << "El Cliente No. " << clienteIngresado->idCliente << "ha ingresado a Comprar en el Supermercado con la Carreta No. " << carretaIngresada->id <<" tomada de la Pila 2"<<endl;
                    sleep(1);
                   }
            }
        }
        clientesEnEspera = ColaEsperaEntradaCarretas->getSize();
        carretasEnPila1 = pilaCarretas1->getSize();
        carretasEnPila2 = pilaCarretas2->getSize();
    }

    //Los clientes que han terminado de comprar pasan a la cola para pagar en cajas
    int clienteAleatorio = rand()%(cantClientesTotales)+1;
    cout << "\nNúmero de Cliente que debe pasar a la Cola de Pago en Caja: " << clienteAleatorio << endl<<endl;
    sleep(1);
    NodoListaCompradores* nodoAleatorio = ListaCompradores->pop(clienteAleatorio);
    if(nodoAleatorio == NULL) {
        cout << "Ningún cliente pasa a la Cola de Pago en Caja" << endl; 
        sleep(1);
    } else {
        int clientePagando = nodoAleatorio->idCliente->idCliente;
        int carretaPagando = nodoAleatorio->idCarreta->id;
        colaPagar->push(nodoAleatorio->idCliente, nodoAleatorio->idCarreta);
        cout << "El cliente No. " << clientePagando << " ha ingresado a la Cola para pagar en Caja, con la carreta No." << carretaPagando << endl;
        sleep(1);
        delete nodoAleatorio;
    }

    //Se verifica si los clientes de la cola pueden pagar en cajas
    bool repetir = true;
    while(repetir) {
        if(colaPagar->inicio != NULL && listaCajas->disponibilidadCaja(colaPagar->inicio->idCliente,colaPagar->inicio->idCarreta)) {
            colaPagar->pop();
        } else {
            repetir = false;
        }
    }

    //Verificamos que los clientes paguen
    listaCajas->verificarTurnos(pilaCarretas1,pilaCarretas2);

}