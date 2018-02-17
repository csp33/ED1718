
#include "FechaHistorica.h"

/**
  @file FechaHistorica.cpp
  @brief Implementación de la clase FechaHistórica.
*/


/**********Métodos privados*****************/

void FechaHistorica::Liberar(){
  if(acontecimientos!=0)
    delete acontecimientos;
}
void FechaHistorica::Copiar(const FechaHistorica &otra){
  for(int i=0;i<otra.GetTamanio();i++)
    *acontecimientos+=otra[i];
  anio=otra.GetAnio();
}

/**********Métodos públicos*****************/

///////////////Constructores/////////////

FechaHistorica::FechaHistorica(){
  acontecimientos=0;
  anio=0;
}

FechaHistorica::FechaHistorica(const int anio,const string unacontecimiento){
  this->anio=anio;
  acontecimientos= new VectorDinamico<string>;
  acontecimientos->operator+=(unacontecimiento);
}
FechaHistorica::FechaHistorica(const int anio,const VectorDinamico<string> vector){
  this->anio=anio;
  acontecimientos= new VectorDinamico<string>;
  *acontecimientos=vector;
}

FechaHistorica::FechaHistorica(const FechaHistorica &otra){
  acontecimientos=new VectorDinamico<string>;
  Copiar(otra);
}

//////////////////////////////////////////////

///////////////////Destructor/////////////////

FechaHistorica::~FechaHistorica(){
  Liberar();
}

/////////////////////////////////////////////

//////////////////Consultores////////////////

int FechaHistorica::GetAnio()const{
  return anio;
}

int FechaHistorica::GetTamanio()const{
  return acontecimientos->GetTamanio();
}

bool FechaHistorica::Ocurrio(const string &acontecimiento) const{
  assert(acontecimientos!=0);
  int pos=-1;
  for(int i=0;i<acontecimientos->GetTamanio() && pos==-1;i++)
    pos=acontecimientos->operator[](i).find(acontecimiento);
  return pos !=-1; //False si no existe. True si existe
}

/////////////////////////////////////////////

//////////////////Modificadores////////////////////

void FechaHistorica::SetAnio(const int a){
  anio=a;
}

/////////////////////////////////////////////

////////////////Sobrecarga de operadores/////////////

/*********Lógicos**************/

bool FechaHistorica::operator<(const FechaHistorica &otra){
  return this->anio < otra.GetAnio();
}

bool FechaHistorica::operator>=(const FechaHistorica &otra){
  return !this->operator<(otra);
}

bool FechaHistorica::operator>(const FechaHistorica &otra){
  return this->anio > otra.GetAnio();
}

bool FechaHistorica::operator<=(const FechaHistorica &otra){
  return !this->operator>(otra);
}

/*****************************/

/*********Aritméticos**************/

void FechaHistorica::operator+=(const string &acontecimiento){
  if(acontecimientos==0)
    acontecimientos=new VectorDinamico<string>;
  acontecimientos->operator+=(acontecimiento);
}


FechaHistorica& FechaHistorica::operator=(const FechaHistorica &otra){
  if(this!=&otra){
    Liberar();
    acontecimientos=new VectorDinamico<string>;
    Copiar(otra);
  }
  return *this;
}

/*****************************/

/*************De acceso********************/
string &FechaHistorica::operator[](const int indice)const{
  return acontecimientos->operator[](indice);
}
