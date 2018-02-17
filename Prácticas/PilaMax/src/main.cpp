/**
    @file main.cpp
    @brief Prueba para los contenedores PilaMaxVD, PilaMaxCola y Cola
 */

#include "PilaMaxVD.h"
#include "PilaMaxCola.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &flujo, PilaMaxVD &pila){
  int tam=pila.GetTamanio()-1;
  for(int i=0;i<tam;i++){
    flujo<<"Desapilamos el elemento numero "<<i<<":"<<endl;
    flujo<<"\tEl elemento es "<<pila.SacarTope()<<"."<<endl;
    flujo<<"\tMaximo de la pila: "<<pila.GetMaximo()<<endl;
  }
  flujo<<"Desapilamos el elemento numero "<<tam<<":"<<endl;
  flujo<<"\tEl elemento es "<<pila.SacarTope()<<"."<<endl;
  flujo<<endl;
  return flujo;
}

ostream &operator<<(ostream &flujo, PilaMaxCola &pila){
  int tam=pila.GetTamanio()-1;
  for(int i=0;i<tam;i++){
    flujo<<"Desapilamos el elemento numero "<<i<<":"<<endl;
    flujo<<"\tEl elemento es "<<pila.SacarTope()<<"."<<endl;
    flujo<<"\tMaximo de la pila: "<<pila.GetMaximo()<<endl;
  }
  flujo<<"Desapilamos el elemento numero "<<tam<<":"<<endl;
  flujo<<"\tEl elemento es "<<pila.SacarTope()<<"."<<endl;
  flujo<<endl;
  return flujo;
}

template <class C>
ostream &operator<<(ostream &flujo, Cola<C> &cola){
  for(int i=0;!cola.Vacia();i++)
    flujo<<"Elemento numero "<<i<<": "<<cola.SacarFrente()<<endl;
  flujo<<endl;
  return flujo;
}


const int N_ELEMENTOS=10;
const string START= "\n\t************Comienzan las pruebas de ",SEP="*****************\n",
              END="\t*******************Fin de las pruebas************************";
int main () {
  /******************Pilamax*************************/

  cout<<START<<"PilaMaxVD"<<SEP<<endl;

  PilaMaxVD pilaVD;

  //Comprobamos vacía
  cout<<"Esta vacia ?: "<<(pilaVD.EstaVacia()? "true" : "false" )<<endl;

  //Inicializamos el objeto
  cout<<"Inicializamos la pila con valores 0...9"<<endl;
  for(int i=0;i<N_ELEMENTOS;i++)
    pilaVD+=i;

  cout<<"El tamanio de la pila es "<<pilaVD.GetTamanio()<<endl;

  cout<<"Vamos desapilando y mostrando el maximo de la pila:"<<endl<<endl;
  cout<<pilaVD<<endl;

  cout<<"Esta vacia ?: "<<(pilaVD.EstaVacia()? "true" : "false" )<<endl;



  cout<<endl<<endl<<END<<endl<<endl;

/*****************************************************/

/********************Cola*******************************/

  cout<<START<<"Cola"<<SEP<<endl;

  Cola<int> unaCola;

  cout<<"Esta vacia ?: "<<(unaCola.Vacia() ? "true" : "false" )<<endl;

  //Relleno la cola
  cout<<"Inicializamos la cola con valores 0...9"<<endl;
  for(int i=0;i<N_ELEMENTOS;i++) {
    unaCola+=i;
  }
  cout<<"El tamanio de la cola es "<<unaCola.GetTamanio()<<endl;

  cout<<"Mostramos el contenido de la cola"<<endl;
  cout<<unaCola<<endl;

  cout<<endl<<endl<<END<<endl<<endl;

/******************PilaMaxCola*************************/

  cout<<START<<"PilaMaxCola"<<SEP<<endl;

  PilaMaxCola pilaCola;

  //Comprobamos vacía
  cout<<"Esta vacia ?: "<<(pilaCola.EstaVacia() ? "true" : "false" )<<endl;

  //Inicializamos el objeto
  cout<<"Inicializamos la pila con valores 0...9"<<endl;
  for(int i=0;i<N_ELEMENTOS;i++)
    pilaCola+=i;

  cout<<"El tamanio de la pila es "<<pilaCola.GetTamanio()<<endl;

  cout<<"Vamos desapilando y mostrando el maximo de la pila:"<<endl<<endl;
  cout<<pilaCola<<endl;

  cout<<"Esta vacia ?: "<<(pilaCola.EstaVacia() ? "true" : "false" )<<endl;



  cout<<endl<<endl<<END<<endl<<endl;


  }
