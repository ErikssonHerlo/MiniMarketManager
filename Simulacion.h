#ifndef SIMULACION_H
#define SIMULACION_H
#include "Carreta.h"
#include "PilaCarretas.h"
#include "ColaEsperaEntrada.h"
#include "ListaCajas.h"
#include "ColaPagar.h"
#include "ListaCompradores.h"

#include <cstdlib>
#include <string>
class Simulacion {
    public:
        void menuInicial();
        void inicializacionPilaCarretas(PilaCarretas*, PilaCarretas*, int); 
        void inicializacionColaEsperaEntrada(ColaEsperaEntrada*, int);   
        void inicializacionCajas(ListaCajas*, int);
        void inicializacionCompradores(ListaCompradores*, int, int, int);
        void inicializacionColaPagos(ColaPagar*, int, int, int);
        void simulacionMiniMarket(PilaCarretas*,PilaCarretas*,ColaEsperaEntrada*,ColaPagar*,ListaCajas*,ListaCompradores*);
        int pasosSimulacion = 0;
        int cantClientesTotales = 0;
        int cantCarretasTotales = 0;
};
#endif

