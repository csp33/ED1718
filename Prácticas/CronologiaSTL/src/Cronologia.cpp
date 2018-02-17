#include "Cronologia.h"
#include <string>
#include <fstream>

/**
  @file Cronologia.cpp
  @brief Implementación de la clase Cronología.
*/

/**********Métodos privados*****************/


void Cronologia::Copiar(const Cronologia &otra) {
  this->mapa = otra.mapa;
}

/**********Métodos públicos*****************/

//////////////Constructores/////////////

Cronologia::Cronologia() {

}
Cronologia::Cronologia(char *archivo) {
  Importar(archivo);
}

Cronologia::Cronologia(const Cronologia &otra) {
  Copiar(otra);
}

//////////////////////////////////////////////

///////////////////Destructor/////////////////

Cronologia::~Cronologia() {

}

/////////////////////////////////////////////

//////////////////Consultores////////////////


Cronologia  Cronologia::GetSubcronologia(int desde, int hasta) {
  Cronologia::const_iterator it;
  Cronologia::const_iterator from;
  Cronologia::const_iterator to;

  Cronologia resultado;
  if (mapa.count(desde) == 0)   //Si el año de inicio no existe, tomo el que hay justo después
    from = mapa.upper_bound(desde);
  else
    from = mapa.find(desde);

  if (mapa.count(hasta) == 0)  //Si el año de fin no existe, tomo el anterior.
    to = mapa.lower_bound(hasta);
  else
    to = mapa.find(hasta);
  to++;                       //Incremento to para que incluya al último año
  for (it = from; it != to; ++it)
    resultado += (*it).second;
  return resultado;
}



Cronologia Cronologia::GetSubcronologiaPalabraClave(string filtro) {
  //Declaro iteradores y resultado
  Cronologia::const_iterator itC;
  FechaHistorica::iterator itF;
  Cronologia resultado;

  for (itC = this->begin(); itC != this->end(); ++itC) {     //Itero entre las Fechas Históricas de this
    FechaHistorica aux;
    aux.SetAnio((*itC).second.GetAnio());
    for (itF = (*itC).second.begin(); itF != (*itC).second.end(); ++itF) { //Itero entre los acontecimientos de cada Fecha Histórica
      if ((*itF).find(filtro) != string::npos)                              //Si encuentro el filtro, añado el acontecimiento a la FH.
        aux += *itF;
    }
    if (aux.GetTamanio() > 0)                                               //Si he añadido algún acontecimiento, añado la FH.
      resultado += aux;
  }
  return resultado;
}

int Cronologia::GetTamanio()const {
  return mapa.size();
}

void Cronologia::MuestraEstadisticas() const {
  double numAconts = 0.0;
  double maxAconts = 0.0;
  double mediaAconts;
  Cronologia::const_iterator itC;
  FechaHistorica::const_iterator itF;
  cout << "Número de años en la cronología: " << GetTamanio() << endl;
  for (itC = this->begin(); itC != this->end(); ++itC) {
    int aux = 0;
    for (itF = (*itC).second.begin(); itF != (*itC).second.end(); ++itF) {
      numAconts++;
      aux++;
      if (aux > maxAconts)
        maxAconts = numAconts;
    }
  }
  mediaAconts = numAconts / GetTamanio();
  cout << "Número total de acontecimientos: " << numAconts << endl;
  cout << "Máximos acontecimientos en un año: " << maxAconts << endl;
  cout << "Media de acontecimientos por año: " << mediaAconts << endl;
  cout << endl;
}

//////////////////Modificadores////////////////////


void Cronologia::Importar(char* nombre) {
  ifstream buffer(nombre);
  if (buffer) {
    mapa.clear();
    while (!buffer.eof()) {
      FechaHistorica fechatemp;
      string lineaentera;
      string acontemp = "";
      string aniotemp;
      ///////Cojo el año y lo ajusto///////

      getline(buffer, aniotemp, '#');
      int anio = atoi(aniotemp.c_str());
      fechatemp.SetAnio(anio);

      getline(buffer, lineaentera);
      for (unsigned int i = 0; i < lineaentera.length(); i++) {
        ////Si estoy al final de un acontecimiento o una linea
        if (lineaentera[i] != '#' && i != lineaentera.length() - 1) {
          acontemp.push_back(lineaentera[i]);
        }
        else {
          fechatemp += acontemp;
          acontemp.erase();
        }//else
      }//for

      mapa.insert(pair<int, FechaHistorica>(anio, fechatemp)); //Añado la fecha a la Cronologia
    }// while
  }
  else
    cerr << "Fallo al abrir el archivo";
  buffer.close();
}

////////////////Métodos de salida/////////////

void Cronologia::Exportar(char* nombre) const {
  ofstream flujo(nombre);
  if (flujo) {
    Cronologia::const_iterator itC;
    FechaHistorica::const_iterator itF;
    for (itC = this->begin(); itC != this->end(); ++itC) {
      flujo << "\tAño " << (*itC).first << endl;
      flujo << endl;
      for (itF = (*itC).second.begin(); itF != (*itC).second.end(); ++itF)
        flujo << " -> " << *itF << endl;
      flujo << endl;
    }
    flujo << endl;

    flujo.close();
  }
  else {
    cerr << "No se puede crear el archivo de salida." << endl;
    exit (-1);
  }
}



/*********Aritméticos**************/

void Cronologia::operator+=(const FechaHistorica &fecha) {
  FechaHistorica::const_iterator it;    //Para moverme por los acontecimientos.
  for (it = fecha.begin(); it != fecha.end(); ++it)
    mapa[fecha.GetAnio()] += *it;   //Usando operator[] consigo que si el año no existe en el mapa se construya.
}

Cronologia& Cronologia::operator=(const Cronologia &otra) {
  Copiar(otra);
  return *this;
}

Cronologia Cronologia::operator+(const Cronologia &otra) {
  Cronologia aDevolver(*this);
  Cronologia::const_iterator it;
  for (it = otra.begin(); it != otra.end(); ++it)
    aDevolver += (*it).second;
  return aDevolver;
}
/*****************************/

//////Iteradores//////////////

Cronologia::iterator Cronologia::begin() {
  return mapa.begin();
}

Cronologia::iterator Cronologia::end() {
  return mapa.end();
}

Cronologia::const_iterator Cronologia::begin() const {
  return mapa.begin();
}

Cronologia::const_iterator Cronologia::end() const {
  return mapa.end();
}

///////////////////Operador de flujo/////////////////////////

ostream &operator<<(ostream &flujo, const Cronologia &crono) {
  Cronologia::const_iterator itC;
  FechaHistorica::const_iterator itF;
  for (itC = crono.begin(); itC != crono.end(); ++itC) {
    flujo << "\tAño " << (*itC).first << endl;
    flujo << endl;
    for (itF = (*itC).second.begin(); itF != (*itC).second.end(); ++itF)
      flujo << " -> " << *itF << endl;
    flujo << endl;
  }
  flujo << endl;
  return flujo;
}
