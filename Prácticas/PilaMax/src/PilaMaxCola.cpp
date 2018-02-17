#include "PilaMaxCola.h"

/**
    @file PilaMaxCola.cpp
    @brief Impementación de la clase PilaMaxCola.
 */

void PilaMaxCola::Liberar(){
  if(c != 0)
    delete c;
}
void PilaMaxCola::Copiar(const PilaMaxCola &otra){
  this->c=otra.c;  //Delego en Cola<C>::operator=
}
void PilaMaxCola::Crear(){
  c= new Cola <DatoMax>;
}
PilaMaxCola::PilaMaxCola(){
  Crear();
}
PilaMaxCola::PilaMaxCola(const PilaMaxCola &otra){
  Crear();
  Copiar(otra);
}
PilaMaxCola::~PilaMaxCola(){
  Liberar();
}
int PilaMaxCola::GetTamanio() const{
  return c->GetTamanio();
}
int PilaMaxCola::GetMaximo() const{
  assert(!EstaVacia());
  Cola <DatoMax> aux(*c);
	for(int i=0;i<GetTamanio()-1;i++)
  	aux.SacarFrente();
	return aux.SacarFrente().max;

}
int PilaMaxCola::SacarTope() { 	//Crear otra cola, copiamos con el orden inverso (frente de aux= fondo de original) y miramos el máximo del frente de aux).

  Cola<DatoMax> *auxiliar= new Cola <DatoMax> ;

  int tam=GetTamanio();
  for(int i=0;i<tam-1;i++)
    auxiliar->operator+=(c->SacarFrente());
  //Guardo el dato a devolver
  int aDevolver=c->SacarFrente().dato;
  //Vuelvo a crear this
  Liberar();
  c=auxiliar;
  return aDevolver;
}
int PilaMaxCola::MirarTope() {
  Cola<DatoMax> *auxiliar= new Cola <DatoMax> ;

  int tam=GetTamanio();
  for(int i=0;i<tam-1;i++)
    auxiliar->operator+=(c->SacarFrente());
  //Guardo el dato a devolver
  DatoMax aDevolver=c->SacarFrente();
  auxiliar->operator+=(aDevolver);
  //Vuelvo a crear this
  Liberar();
  c=auxiliar;
  return aDevolver.dato;
}
void PilaMaxCola::Vaciar(){
  Liberar();
  Crear();
}
bool PilaMaxCola::EstaVacia() const{
  return c->Vacia();
}
void PilaMaxCola::operator+=(const int &aniadir){
  int maximo;
  if(EstaVacia())
    maximo=aniadir;
  else{
    maximo=GetMaximo();
    if(aniadir > maximo)
      maximo=aniadir;
  }
  DatoMax aInsertar;
  aInsertar.dato=aniadir;
  aInsertar.max=maximo;
  c->operator+=(aInsertar);
}
PilaMaxCola &PilaMaxCola::operator=(const PilaMaxCola &otra){
  if(this != &otra){
    Liberar();
    Crear();
    Copiar(otra);
  }
  return *this;
}
