
#include "FechaHistorica.h"


/**
  @file FechaHistorica.cpp
  @brief Implementación de la clase FechaHistórica.
*/


/**********Métodos privados*****************/

void FechaHistorica::Copiar(const FechaHistorica &otra) {
  this->pareja = otra.pareja;
}

/**********Métodos públicos*****************/

///////////////Constructores/////////////

FechaHistorica::FechaHistorica() {

}

FechaHistorica::FechaHistorica(const int anio, const string unacontecimiento) {
  pareja.first = anio;
  pareja.second.insert(unacontecimiento);
}
FechaHistorica::FechaHistorica(const int anio, const set<string> &conjunto) {
  pareja.first = anio;
  pareja.second = conjunto;
}

FechaHistorica::FechaHistorica(const FechaHistorica &otra) {
  Copiar(otra);
}

//////////////////////////////////////////////

///////////////////Destructor/////////////////

FechaHistorica::~FechaHistorica() {

}

/////////////////////////////////////////////

//////////////////Consultores////////////////

int FechaHistorica::GetAnio()const {
  return pareja.first;
}

int FechaHistorica::GetTamanio()const {
  return pareja.second.size();
}

bool FechaHistorica::Ocurrio(const string &acontecimiento) const {
  FechaHistorica::iterator it;
  for(it=this->begin();it!=this->end();++it)
    if((*it).find(acontecimiento) != string::npos)
      return true;
  return false;
}

set<string> FechaHistorica::GetAcontecimientos() const {
  return pareja.second;
}

/////////////////////////////////////////////

//////////////////Modificadores////////////////////

void FechaHistorica::SetAnio(const int a) {
  pareja.first = a;
}

/////////////////////////////////////////////

////////////////Sobrecarga de operadores/////////////

/*********Lógicos**************/

bool FechaHistorica::operator<(const FechaHistorica &otra) {
  return pareja.first < otra.GetAnio();
}

bool FechaHistorica::operator>=(const FechaHistorica &otra) {
  return !this->operator<(otra);
}

bool FechaHistorica::operator>(const FechaHistorica &otra) {
  return pareja.first > otra.GetAnio();
}

bool FechaHistorica::operator<=(const FechaHistorica &otra) {
  return !this->operator>(otra);
}

/*****************************/

/*********Aritméticos**************/

void FechaHistorica::operator+=(const string &acontecimiento) {
  pareja.second.insert(acontecimiento);
}


FechaHistorica& FechaHistorica::operator=(const FechaHistorica &otra) {
  Copiar(otra);
  return *this;
}

/*****************************/

////////Iteradores/////////////

FechaHistorica::iterator FechaHistorica::begin() {
  return pareja.second.begin();
}

FechaHistorica::iterator FechaHistorica::end() {
  return pareja.second.end();
}

FechaHistorica::const_iterator FechaHistorica::begin() const {
  return pareja.second.begin();
}

FechaHistorica::const_iterator FechaHistorica::end() const {
  return pareja.second.end();
}
