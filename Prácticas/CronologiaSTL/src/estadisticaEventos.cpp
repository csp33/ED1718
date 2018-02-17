/**
  @file estadisticaEventos.cpp

  @brief Programa que obtiene una estadística sobre la cronología proporcionada.
*/
#include "Cronologia.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	//Comprobación de argumentos
	//
	if (argc != 2) {
		cerr << "Argumento del programa: <cronologia> " << endl;;
		return -1;
	}

	//Apertura de archivos

	ifstream f (argv[1]);
	if (!f) {
		cerr << "No puedo abrir el fichero " << argv[1] << endl;
		return 1;
	}
	f.close();

	Cronologia crono(argv[1]);
	crono.MuestraEstadisticas();

	cout << "El programa finalizó sin errores." << endl;


}