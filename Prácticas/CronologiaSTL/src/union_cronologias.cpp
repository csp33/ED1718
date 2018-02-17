/**
  @file union_cronologias.cpp

  @brief Programa une dos cronologías en una sola.
*/

#include "Cronologia.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv) {
	if (argc != 3 && argc != 4) {
		cerr << "Argumentos del programa: <cronologia1> <cronologia2> <salida (opcional)>" << endl;;
		return -1;
	}

	//Comprobamos que los archivos se pueden abrir.
	for (int i = 1; i <= 2; i++) {
		ifstream f(argv[i]);
		if (!f) {
			cerr << "No puedo abrir el fichero " << argv[i] << endl;
			return -1;
		}
		f.close(); //Cerramos el archivo para no dejarlo bloqueado.
	}

	bool salidaArchivo = argc == 4;		//Si guardamos la salida en un archivo

	Cronologia primera, segunda, resultado;
	primera.Importar(argv[1]);
	segunda.Importar(argv[2]);

	resultado = primera + segunda;

	if (salidaArchivo) {
		cout << "Guardando unión en " << argv[3] << endl;
		resultado.Exportar(argv[3]);
	}
	else
		cout << resultado << endl;


	cout << "El programa finalizó sin errores." << endl;
}


