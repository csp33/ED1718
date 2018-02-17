/**
    @file pruebacronologia.cpp

    @brief Función main usada para probar la clase
 */

#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {

//Comprobamos los argumentos de entrada al programa.

  if (argc != 2) {
    cerr << "Dime el nombre del fichero con la cronologia" << endl;
    return 1;
  }

  ifstream f (argv[1]);
  if (!f) {
    cerr << "No puedo abrir el fichero " << argv[1] << endl;
    return 1;
  }
  f.close(); //Cerramos el archivo para no dejarlo bloqueado.
  //En el constructor de Cronología pasamos directamente argv[1].


  /************************Prueba de Cronología*************/

  //Creamos el objetos

  Cronologia unaCrono;

  //Llenamos el objeto con el archivo

  unaCrono.Importar(argv[1]);

  //Mostramos por pantalla

  cout << "Tamanio de unaCrono: " << unaCrono.GetTamanio() << "Contenido : " << endl;
  cout << unaCrono << endl;


  cout << "El programa finalizó sin errores." << endl;

}
