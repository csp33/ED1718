/**
  @file filtradoIntervalo.cpp

  @brief Programa que obtiene una cronología restringida a un intervalo.
*/

#include "Cronologia.h"
#include <stdlib.h>     /* atoi */
#include <iostream>
using namespace std;

int main(int argc, char **argv) {

	//Comprobación de argumentos
	if (argc < 4 || argc > 5) {
		cerr << "Argumentos del programa: <cronologia> <limite inf> <limite sup> <salida (opcional)>" << endl;;
		return -1;
	}

	//Apertura de archivos

	ifstream f (argv[1]);
	if (!f) {
		cerr << "No puedo abrir el fichero " << argv[1] << endl;
		return 1;
	}
	f.close();

	bool salidaArchivo = argc == 5;
	Cronologia crono(argv[1]);
	Cronologia resultado;

	resultado = crono.GetSubcronologia(atoi(argv[2]), atoi(argv[3]));
	if (salidaArchivo)
		resultado.Exportar(argv[4]);
	else
		cout << resultado << endl;

	cout << "El programa finalizó sin errores." << endl;

}

