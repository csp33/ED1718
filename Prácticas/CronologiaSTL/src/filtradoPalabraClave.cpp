/**
  @file filtradoPalabraClave.cpp

  @brief Programa que obtiene una cronología restringida a los acontecimientos que contengan una palabra clave.
*/


#include "Cronologia.h"
#include <fstream>
#include <iostream>
using namespace std;

string pedirFiltro() {
	string filtro;
	cout << "Introduzca la palabra para el filtrado" << endl;
	cin >> filtro;
	return filtro;
}
int main(int argc, char **argv) {

	//Comprobación de argumentos

	if (argc < 2 || argc > 5 ) {
		cerr << "Argumentos del programa: <cronologia> <palabra (opcional)> <salida (opcional)>" << endl;;
		return -1;
	}

	//Apertura de archivos

	ifstream f (argv[1]);
	if (!f) {
		cerr << "No puedo abrir el fichero " << argv[1] << endl;
		return 1;
	}
	f.close();

	bool pidoFiltro = argc == 2;
	bool salidaArchivo = argc == 4;
	string filtro;
	Cronologia crono(argv[1]), filtrada;

	if (pidoFiltro) {
		filtro = pedirFiltro();
	}
	else
		filtro = argv[2];

	filtrada = crono.GetSubcronologiaPalabraClave(filtro);

	if (salidaArchivo)
		filtrada.Exportar(argv[3]);
	else
		cout << filtrada << endl;

	cout << "El programa finalizó sin errores." << endl;

}