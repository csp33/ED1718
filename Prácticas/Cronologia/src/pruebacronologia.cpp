/**
    @file pruebacronologia.cpp

    @brief Función main usada para probar la clase
 */

#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

/************Sobrecarga de operadores de flujo*****************/

template <class T>
ostream &operator<<(ostream &flujo, const VectorDinamico<T> &vector){
  flujo<<endl<<endl;
  for(int i=0;i<vector.GetTamanio();i++)
    flujo<<vector[i]<<endl;
    return flujo;
}

ostream &operator<<(ostream &flujo,const FechaHistorica &fecha){
  flujo<<endl<<endl;
  flujo<<"Anio "<<fecha.GetAnio()<<".\nAcontecimientos: \n";
  for(int i=0;i<fecha.GetTamanio();i++)
	 flujo<<fecha[i]<<endl;
	return flujo;
}

ostream &operator<<(ostream &flujo, const Cronologia &crono){
  flujo<<endl<<endl;
  for(int i=0;i<crono.GetTamanio();i++)
    flujo<<crono[i]<<endl;
  return flujo;
}
/**********************************************************************/

int main(int argc, char * argv[]){

//Comprobamos los argumentos de entrada al programa.

  if (argc!=2){
      cout<<"Dime el nombre del fichero con la cronologia"<<endl;
      return 1;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 1;
   }
   f.close(); //Cerramos el archivo para no dejarlo bloqueado.
                //En el constructor de Cronología pasamos directamente argv[1].



/***********Prueba de VectorDinamico***************/

  cout<<endl<<endl<<"\t***Comienza la prueba de VectorDinamico***"<<endl<<endl;


  //Construimos los objetos

  VectorDinamico<string> unVector,otroVector;
  unVector+="Cadena 1";
  unVector+="Cadena 2";
  otroVector=unVector;
  VectorDinamico<string> vectorCopia(unVector);

  //Mostramos por pantalla el resultado

  cout<<"unVector: "<<unVector;
  cout<<"otroVector: "<<otroVector;
  cout<<"vectorCopia: "<<vectorCopia;

  //Hacemos cambios

  vectorCopia.Vaciar();
  vectorCopia+="Carlos";

  //Mostramos por pantalla

  cout<<"vectorCopia: "<<vectorCopia;
  cout<<"Tamanio de unVector: "<<unVector.GetTamanio()<<endl;

  cout<<endl<<endl<<"\t***Fin de la prueba***"<<endl<<endl;

/************************************************************************/

/************************Prueba de FechaHistórica*************/


cout<<endl<<endl<<"\t***Comienza la prueba de FechaHistorica***"<<endl<<endl;

  //Construimos los objetos

  FechaHistorica otraFecha(-500,"Constructor con parametros");
  FechaHistorica unaFecha(1500,unVector);
  FechaHistorica fechaCopia(otraFecha);
  unaFecha.SetAnio(1200);
  unaFecha+="Aniadimos a unaFecha";
  bool ocurrio=otraFecha.Ocurrio("parametros");
  bool no_ocurrio=unaFecha.Ocurrio("Einstein");
  bool unaFechaMayor=unaFecha>otraFecha;

  //Mostramos por pantalla

  cout<<"Contenido de unaFecha: "<<unaFecha<<endl;
  cout<<"Contenido de otraFecha: "<<otraFecha<<endl;
  cout<<"Contenido de fechaCopia: "<<fechaCopia<<endl;
  cout<<"El anio de unaFecha es "<<unaFecha.GetAnio()<<" y su tamanio, "<<unaFecha.GetTamanio()<<endl;
  cout<<"Ocurrio es ..."<<(ocurrio != 0 ? "true" : "false")<<endl;
  cout<<"No_ocurrio es ..."<<(no_ocurrio != 0 ? "true" : "false")<<endl;
  cout<<"unaFecha es mayor que otraFecha ... "<<(unaFechaMayor != 0 ? "true" : "false")<<endl;


  cout<<endl<<endl<<"\t***Fin de la prueba***"<<endl<<endl;


/******************Prueba conjunta******************************************/

  cout<<endl<<endl<<"\t***Comienza la prueba conjunta***"<<endl<<endl;

  //Creamos los objetos

  VectorDinamico<FechaHistorica> misFechas;
  FechaHistorica vacia;
  misFechas+=unaFecha;
  misFechas+=otraFecha;

  //Mostramos por pantalla

  cout<<"Vector misFechas: "<<misFechas<<endl;

  cout<<endl<<endl<<"\t***Fin de la prueba***"<<endl<<endl;

   /************************************************************************/


   /************************Prueba de Cronología*************/

   cout<<endl<<endl<<"\t***Comienza la prueba de Cronologia***"<<endl<<endl;

   //Creamos los objetos

   Cronologia unaCrono;
   Cronologia otraCrono;
   Cronologia cronoCopia(unaCrono);

   Cronologia aniosOchentaNoventa;
   Cronologia aniosStarWars;
   Cronologia aniosLordRings;
   Cronologia mejoresPeliculas;

   //Hacemos operaciones

   unaCrono.Importar(argv[1]);
   otraCrono=unaCrono;
   aniosOchentaNoventa=unaCrono.GetSubcronologia(1980,1990);
   aniosStarWars=unaCrono.GetSubcronologiaPalabraClave("Star Wars");
   aniosLordRings=unaCrono.GetSubcronologiaPalabraClave("The Lord of the Rings");
   mejoresPeliculas=aniosLordRings+aniosStarWars;

   //Mostramos por pantalla

   cout<<"Tamanio de unaCrono: "<<unaCrono.GetTamanio()<<"Contenido : "<<unaCrono<<endl;
   cout<<"Tamanio de cronoCopia: "<<cronoCopia.GetTamanio()<<"Contenido : "<<cronoCopia<<endl;
   cout<<"La fecha historica 3 en unaCrono es "<<endl<<unaCrono[3]<<endl;
   cout<<"Cronologia otraCrono (asignacion de unaCrono): "<<otraCrono<<endl;
   cout<<"Cronologia entre los anios 80 y 90: "<<aniosOchentaNoventa<<endl;
   cout<<"Cronologia con anios de Star Wars: "<<endl<<aniosStarWars<<endl;
   cout<<"Cronologia mejoresPeliculas: "<<endl<<mejoresPeliculas<<endl;



   cout<<endl<<endl<<"\t***Fin de la prueba***"<<endl<<endl;

  /************************************************************************/

   cout<<"\tFin del programa"<<endl;

}
